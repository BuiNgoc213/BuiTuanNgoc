#include "Bullet.h"
Bullet::Bullet(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(-1, model, shader, texture)
{
}
Bullet::~Bullet()
{
}
void Bullet::Update(GLfloat deltatime)
{

	if (bullet_dir == DIR_RIGHT) {
		for (int i = 0; i < 7; i++)
		{
			x += 1;
			Set2DPosition(int(x), int(y));
		}
		if (this->m_position.x <= 10 || this->m_position.x >= Globals::screenWidth - 10 ||
			this->m_position.y <= 10 || this->m_position.y >= Globals::screenHeight - 10
			)
		{
			SetMoving(false);
		}
	}
	if (bullet_dir == DIR_LEFT) {
		for (int i = 0; i < 7; i++)
		{
			x -= 1;
			Set2DPosition(int(x), int(y));
		}
		if (this->m_position.x <= 10 || this->m_position.x >= Globals::screenWidth - 10 ||
			this->m_position.y <= 10 || this->m_position.y >= Globals::screenHeight - 10
			)
		{
			SetMoving(false);
		}
	}
	
}

void Bullet::Cal(int x1, int y1)
{
	x = x1, y = y1;
	SetMoving(true);
}
void Bullet::SetMoving(bool moving)
{
	this->moving = moving;
}
bool Bullet::GetMoving()
{
	return this->moving;
}