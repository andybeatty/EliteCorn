#ifndef FIELD_H
#define FIELD_H

#include <vector>

struct PlantScore {
    int row;
    int col;
    int score;
    int height;
};

class Field {
public:
    Field(const std::vector<std::vector<int>>& gridData) : grid(gridData) {}
    int countVisiblePlantsFromOutside() const;
    void CalculateScores(); 
    PlantScore CurrentElitePlant() const;
    void displayGrid() const;
private:
    std::vector<std::vector<int>> score_map;
    std::vector<std::vector<int>> grid;

};

#endif
