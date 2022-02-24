#include "Wall.h"
Wall::Wall(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(-1, model, shader, texture)
{
}
Wall::~Wall()
{
}
