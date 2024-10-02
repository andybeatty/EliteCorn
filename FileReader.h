#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <string>

class FileReader {
public:
    std::vector<std::vector<int>> readFile(const std::string& filePath);
};

#endif
