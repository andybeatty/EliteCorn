#include <iostream>
#include "FileReader.h"
#include "Field.h"

int main(int argc, char* argv[]) {

    if(argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string filepath = argv[1];

    FileReader fileReader;
    

    // Read the file
    std::vector<std::vector<int>> grid = fileReader.readFile(filepath);
    
    if (grid.empty()) { //todo update to have 1 error if empty and different error if file contained invalid char
        std::cerr << "No data in the file or failed to read." << std::endl;
        return 1;
    }
    else if (grid.size() == 1 && grid[0].size() == 1 && grid[0][0] == -1) {
        std::cerr << "Error: File contains invalid characters. Please ensure the file has only digits (0-9)." << std::endl;
        return 1;
    }

    // Create the field
    Field field(grid);

    // Display the grid (for debugging)
    // std::cout << "Grid:\n";
    // field.displayGrid();

    // Calculate visible plants
    int visiblePlants = field.countVisiblePlantsFromOutside();
    std::cout << "Number of visible plants: " << visiblePlants << std::endl;

    field.CalculateScores();

    // Find the most elite plant
    PlantScore most_elite = field.CurrentElitePlant();
    std::cout << "Most elite plant at row: " << most_elite.row 
              << " col: " << most_elite.col 
              << " with score: " << most_elite.score
              << " and height: " << most_elite.height << std::endl;

    return 0;
}
