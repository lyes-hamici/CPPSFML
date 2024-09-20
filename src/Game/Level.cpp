#include "Level.hpp"
#include <iostream>


bool Level::LoadFromFile(const std::string& path) {
    

    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << path << std::endl;
        return false;
    }

    std::string line;
    int row = 0;


    while (std::getline(file, line) && row < 6) { 
       

        std::istringstream iss(line);
        int value;
        int col = 0;

        while (iss >> value && col < 12) {  
            this->layout[row][col] = value;
            col++;
        }
        row++;
    }

    file.close();
    return true;
}


void Level::Setup() {
    bricks.clear();  

    for (int i = 0; i < 6; ++i) {  
        for (int j = 0; j < 12; ++j) { 
            int hp = layout[i][j];  
            if (hp > 0) {  
                Brick brick;
                brick.position;
                this->bricks.push_back(brick);  
            }
        }
    }
}


