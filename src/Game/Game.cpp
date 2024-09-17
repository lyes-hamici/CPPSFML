#include <windows.h>
#include <cctype>
#include <iostream>
#include <format>
#include <filesystem>
#include <chrono>
#include "Game.hpp"
#include "File.hpp"
#include "../Input/Input.hpp"
#include "../Renderer/Renderer.hpp"
float Game::deltaTime;
Game::Game(){
	this->currentScore = 0;
	this->texturesPath = "Images/";
	this->fontsPath = "Fonts/";
	for(auto& file : std::filesystem::directory_iterator(this->texturesPath)){
		Renderer::loadTexture(file.path().string());
	}
	for(auto& file : std::filesystem::directory_iterator(this->fontsPath)){
		Renderer::loadFont(file.path().string());
	}
	bestScore = File::loadScore("Score.save");
	this->run();
}
Game::~Game(){}
void Game::run(){
	//Board board = Board();
	while(true){
		auto startTime = std::chrono::high_resolution_clock::now();
		Renderer::clear();
		if(Input::getPressed("Escape")){
			std::cout << "Closing Programm" << std::endl;
			break;
		}
		if(Input::getPressed("r")){
			//board.initialize();
			checkScore();
			currentScore = 0;
		}
        Renderer::display();
		auto endTime = std::chrono::high_resolution_clock::now();
		Game::deltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(endTime - startTime).count();
		Sleep(16);
	}
}
void Game::checkScore(){
	if(currentScore <= bestScore){return;}
	File::saveScore(currentScore, "Score.save");
	bestScore = currentScore;
}
