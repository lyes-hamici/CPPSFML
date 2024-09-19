#include "Levels.hpp"
#include <iostream>


Levels Levels::LoadFromFile(const std::string& path) {
    Levels levels;
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << path << std::endl;
        return levels;
    }

    std::string line;
    int row = 0;

    std::cout << "Contenu du fichier texte :\n";

    while (std::getline(file, line) && row < 6) { 
        std::cout << line << std::endl;  

        std::istringstream iss(line);
        int value;
        int col = 0;

        while (iss >> value && col < 12) {  
            levels.layout[row][col] = value;
            col++;
        }
        row++;
    }

    file.close();
    return levels;
}


void Levels::Setup() {
    bricks.clear();  

    for (int i = 0; i < 6; ++i) {  
        for (int j = 0; j < 12; ++j) { 
            int hp = layout[i][j];  
            if (hp > 0) {  
                Brick brick(i, j, hp);  
                bricks.push_back(brick);  
            }
        }
    }
}


void Levels::PrintLayout() const {
    std::cout << "\nGrille des points de vie (layout) :\n";
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 12; ++j) {
            std::cout << layout[i][j] << " ";  
        }
        std::cout << std::endl;  
    }
}
