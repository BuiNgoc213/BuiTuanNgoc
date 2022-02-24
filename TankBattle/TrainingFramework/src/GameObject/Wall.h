#pragma once 
#include "Sprite2D.h"

class Wall : public Sprite2D
{
public:
	Wall() : Sprite2D() {}
	Wall(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~Wall();
};
