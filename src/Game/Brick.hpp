#ifndef BRICK_HEADER
#define BRICK_HEADER

#include "../Renderer/Renderer.hpp"
#include "../Renderer/Transform2D.hpp"
#include "../Core/Vector2.hpp"
#include "../Physics/Bounds2D.hpp"
#include "../Physics/Hit.hpp"
#include <string>

class Brick : public Transform2D{
    public:
        int health;
		std::string name;
		Brick();
		Brick(std::string name);
		void Start();
		void SetEnabled(bool enabled);
		bool IsEnabled();
        bool renderingEnabled; //Property; may call events and perform changes
        std::string imageName;
        FilterMode filteringMode; //Enum
        WrapMode wrapMode; //Enum
        Vector2 size; //Property; will affect bounds
        Bounds2D bounds;
        // hit events
        void OnHitEnter(Hit hit) ; //Hit stores collision info
        void OnHitStay(Hit hit) ; //May not be needed
        void OnHitExit(Hit hit) ; //May not be needed
        bool colliderEnabled; //Property; may call events and perform changes
        bool isStatic;
        int layer;
};
#endif