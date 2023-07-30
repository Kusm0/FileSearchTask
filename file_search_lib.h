#ifndef FILE_SEARCH_LIB_H
#define FILE_SEARCH_LIB_H

#include <string>
#include <vector>

class FileSearch {
public:
    static void search(const std::string& rootDir, const std::string& targetFile);
};

#endif // FILE_SEARCH_LIB_H
