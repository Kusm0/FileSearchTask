#include "file_search_lib.h"
#include <iostream>

int main() {
    const std::string rootDir = "C:\\";
    const std::string targetFile = "filename.txt";

    FileSearch::search(rootDir, targetFile);

    return 0;
}
