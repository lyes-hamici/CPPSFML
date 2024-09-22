#include "Level.hpp"
#include <iostream>
bool Level::LoadFromFile(const std::string& path) {
	std::ifstream file(path);
	auto lastScope = std::min(path.find_last_of('/'),path.find_last_of('\\')) + 1;
	this->name = path.substr(lastScope,path.find_last_of('.') - lastScope);
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
void Level::Start() {
	this->bricks.clear();
	this->empty = false;
	auto resolution = Renderer::getResolution();
	auto spacing = Vector2(5,3);
	auto brickSize = resolution / Vector2(12,25) - spacing;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 12; ++j) {
			int hp = layout[i][j]; 
			if(hp < 1){continue;}
			auto brick = Brick();
			brick.health = hp;
			brick.position = Vector2(j,i) * (brickSize + spacing);
			brick.scale = brickSize;
			brick.angle = 0;
			brick.Start();
			this->bricks.push_back(brick);
		}
	}
}
void Level::Update(){
	this->empty = true;
	for(auto index = 0;index < this->bricks.size();index += 1){
		if(this->bricks[index].health < 1){continue;}
		this->empty = false;
	}
}