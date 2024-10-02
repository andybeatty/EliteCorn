#include "Field.h"
#include <iostream>
#include <algorithm>
#include <vector>

void Field::displayGrid() const {
    for (const auto& row : grid) {
        for (int height : row) {
            std::cout << height << " ";
        }
        std::cout << std::endl;
    }
}

int Field::countVisiblePlantsFromOutside() const {
    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());
    int visibleCount = 2 * (rows + cols - 2); // Count outer edge plants

    // Create a vector to track visibility of inner plants
    std::vector<std::vector<bool>> isVisible(rows, std::vector<bool>(cols, false));

    // Mark visibility from the left and right sides
    for (int i = 1; i < rows - 1; ++i) {
        int maxHeightLeft = grid[i][0];
        int maxHeightRight = grid[i][cols - 1];

        for (int j = 1; j < cols - 1; ++j) {
            // From the left
            if (grid[i][j] > maxHeightLeft) {
                maxHeightLeft = grid[i][j];
                isVisible[i][j] = true; // Mark visible
            }

            // From the right
            if (grid[i][(cols - j) - 1] > maxHeightRight) {
                maxHeightRight = grid[i][(cols - j) - 1];
                isVisible[i][(cols - j) - 1] = true; // Mark visible
            }
        }
    }

    // Mark visibility from the top and bottom
    for (int j = 1; j < cols - 1; ++j) {
        int maxHeightTop = grid[0][j];
        int maxHeightBottom = grid[rows - 1][j];

        for (int i = 1; i < rows - 1; ++i) {
            // From the top
            if (grid[i][j] > maxHeightTop) {
                maxHeightTop = grid[i][j];
                isVisible[i][j] = true; // Mark visible
            }

            // From the bottom
            if (grid[(rows - i) - 1][j] > maxHeightBottom) {
                maxHeightBottom = grid[(rows - i) - 1][j];
                isVisible[(rows - i) - 1][j] = true; // Mark visible
            }
        }
    }

    // Count the total visible plants
    for (int i = 1; i < rows - 1; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            if (isVisible[i][j]) {
                visibleCount++;
            }
        }
    }

    return visibleCount;
}

void Field::CalculateScores() {
    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());
    score_map.resize(rows, std::vector<int>(cols, 0));

    // Calculate scores for each plant
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 0) {
                continue; // Skip edge plants
            }

            // Calculate seeing distances
            int rightDistance = 0, leftDistance = 0, upDistance = 0, downDistance = 0;

            // Right
            for (int k = j + 1; k < cols; k++) {

                if (grid[i][k] < grid[i][j]) {
                    rightDistance++;
                }
                else {
                    rightDistance++;
                    break;
                }
            }
            
            // Left
            for (int k = j - 1; k >= 0; --k) {
                if (grid[i][k] < grid[i][j]) {
                    leftDistance++;
                }
                else {
                    leftDistance++;
                    break;
                }
            }

            // Up
            for (int k = i - 1; k >= 0; --k) {
                if (grid[k][j] < grid[i][j]) {
                    upDistance++;
                }
                else {
                    upDistance++;
                    break;
                }
            }

            // Down
            for (int k = i + 1; k < rows; ++k) {
                if (grid[k][j] < grid[i][j]) {
                    downDistance++;
                }
                else {
                    downDistance++;
                    break;
                }
            }

            // Calculate the Elite Score
            score_map[i][j] = rightDistance * leftDistance * upDistance * downDistance;
        }
    }
}

PlantScore Field::CurrentElitePlant() const {
    PlantScore elitePlant = {0, 0, 0, 0}; // Initialize with default values
    int maxScore = 0;

    // Find the plant with the highest score
    for (int i = 0; i < score_map.size(); ++i) {
        for (int j = 0; j < score_map[i].size(); ++j) {
            if (score_map[i][j] > maxScore) {
                maxScore = score_map[i][j];
                elitePlant = {i, j, maxScore, grid[i][j]};
            }
        }
    }

    return elitePlant;
}