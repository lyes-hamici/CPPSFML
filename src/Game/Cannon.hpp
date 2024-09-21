#ifndef CANNON_HEADER
#define CANNON_HEADER
#include <string>
#include "../Renderer/Renderer.hpp"
#include "../Renderer/Transform2D.hpp"
#include "../Core/Vector2.hpp"
#include "Ball.hpp"
#include <chrono>
class Cannon : public Transform2D{
    public:
        float turnSpeed; //Keyboard only
		std::chrono::high_resolution_clock::time_point lastShot;
		float cooldown;
		Ball ballPool[10];
		//Entity
		std::string name;
		Cannon();
		Cannon(std::string name);
		void Start();
		void Update();
		void SetEnabled(bool enabled);
		bool IsEnabled();
		//RenderObject2D
        bool renderingEnabled; //Property; may call events and perform changes
        std::string imageName;
        FilterMode filteringMode; //Enum
        WrapMode wrapMode; //Enum
};
#endif