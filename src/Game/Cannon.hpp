#ifndef CANNON_HEADER
#define CANNON_HEADER

#include <string>
#include "../Renderer/Renderer.hpp"
#include "../Core/Vector2.hpp"

class Cannon {
    public:
        float turnSpeed; //Keyboard only
		static int count;
		std::string name;
		Cannon();
		Cannon(std::string name);
		void Start();
		void Update();
		void SetEnabled(bool enabled);
		bool IsEnabled();
        bool renderingEnabled; //Property; may call events and perform changes
        std::string imageName;
        FilterMode filteringMode; //Enum
        WrapMode wrapMode; //Enum
		Vector2 position;
        Vector2 scale;
        float angle;
};
#endif