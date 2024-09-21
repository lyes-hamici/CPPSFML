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

    Vector2 brickSize(50, 20); 
    Vector2 spacing(5, 3);  

    for (int i = 0; i < 6; ++i) {  
        for (int j = 0; j < 12; ++j) { 
            int hp = layout[i][j]; 
            if (hp > 0) {  
                Brick brick;
                brick.health = hp;  

                
                brick.position = Vector2(
                    j * (brickSize.x + spacing.x), 
                    i * (brickSize.y + spacing.y)   
                );
                
                brick.size = brickSize;  

                brick.Start();
                this->bricks.push_back(brick);  
            }
        }
    }
}




