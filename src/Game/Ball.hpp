#ifndef BALL_HEADER
#define BALL_HEADER

#include "../Core/Vector2.hpp"
#include "../Physics/Hit.hpp"
#include <string>
#include "../Renderer/Renderer.hpp"
#include "../Renderer/Transform2D.hpp"


class Ball : public Transform2D{
    public:
        Vector2 velocity;
		std::string name;
		Ball();
		Ball(std::string name);
		void Start();
		void Update();
		void SetEnabled(bool enabled);
		bool IsEnabled();
        bool renderingEnabled; //Property; may call events and perform changes
        std::string imageName;
        FilterMode filteringMode; //Enum
        WrapMode wrapMode; //Enum
        float radius;
        void OnHitEnter(Hit hit) ; //Hit stores collision info
        void OnHitStay(Hit hit) ; //May not be needed
        void OnHitExit(Hit hit) ; //May not be needed
};
#endif