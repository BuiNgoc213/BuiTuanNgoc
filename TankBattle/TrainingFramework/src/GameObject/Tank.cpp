#include "Tank.h"

Tank::Tank(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(-1, model, shader, texture)
{

}

Tank::~Tank()
{
}
void Tank::Update(GLfloat deltatime)
{

}
void Tank::Move(int x,int y,int speed) {
	if (this->m_position.y == 50 && y == -1)
		y = 0;

	if (this->m_position.y == Globals::screenHeight - 50 && y == 1)
		y = 0;
	if (this->m_position.x == 50 && x == -1)
		x = 0;
	if (this->m_position.x == Globals::screenWidth - 50 && x == 1)
		x = 0;

	this->Set2DPosition(m_position.x + x * speed, m_position.y + y * speed);
}