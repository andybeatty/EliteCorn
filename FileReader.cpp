#include "FileReader.h"
#include <fstream>
#include <iostream>

std::vector<std::vector<int>> FileReader::readFile(const std::string& filePath) {
    std::vector<std::vector<int>> grid;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return grid;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        for (char c : line) {
            if (isdigit(c)) {
                row.push_back(c - '0');
            }
            else if (!std::isspace(c)) { // Allow whitespace (like newlines), but reject non-digit characters
                std::cerr << "invalid charactor found: "<< c << ", file must contain only number 0 - 9" << std::endl;
                return {{-1}};  // Return a single element of -1 to indicate an invalid character found
            }
        }
        grid.push_back(row);
    }

    file.close();
    return grid;
}
