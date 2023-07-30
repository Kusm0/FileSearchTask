#include "file_search_lib.h"
#include <iostream>
#include <filesystem>
#include <thread>
#include <mutex>

namespace fs = std::filesystem;

static std::mutex mtx;

void searchRecursive(const fs::path& rootDir, const std::string& targetFile, std::atomic<bool>& found) {
    for (const auto& entry : fs::directory_iterator(rootDir)) {
        if (found) return; // Exit if the file is found by another thread
        if (fs::is_directory(entry)) {
            std::thread worker(searchRecursive, entry.path(), targetFile, std::ref(found));
            worker.detach();
        } else if (entry.path().filename() == targetFile) {
            std::lock_guard<std::mutex> lock(mtx);
            found = true;
            std::cout << "File found: " << entry.path() << std::endl;
        }
    }
}

void FileSearch::search(const std::string& rootDir, const std::string& targetFile) {
    std::atomic<bool> found(false);

    searchRecursive(rootDir, targetFile, found);

    if (!found) {
        std::cout << "File not found." << std::endl;
    }
}
