#ifndef ENTITY_HEADER
#define ENTITY_HEADER
#include <string>
#include <map>
#include "../Renderer/Transform2D.hpp"
class Entity : public Transform2D{
	public:
		static std::map<std::string,Entity> all;
		static int count;
		std::string name;
		Entity();
		~Entity();
		explicit Entity(std::string name);
		virtual void Start();
		virtual void Update();
		virtual void SetEnabled(bool enabled);
		bool IsEnabled();
};
#endif