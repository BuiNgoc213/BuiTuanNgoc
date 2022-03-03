#include "Enemy.h"
#include <cstdlib>
#include <ctime>

Enemy::Enemy(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(-1, model, shader, texture)
{
}
Enemy::~Enemy()
{
}
void Enemy::Update(GLfloat deltatime)
{
	currentTime += 1;
	int speed = 2;
	if (currentTime >= 10)
	{
		switch (int  sw = RandomNumber(0, 8))
		{
		case 0:
			Moving(0, 0, speed);
		case 1:
			Moving(1, 0, speed);
			break;
		case 2:
			Moving(-1, 0, speed);
			break;
		case 3:
			Moving(0, 1, speed);
			break;
		case 4:
			Moving(0, -1, speed);
			break;
		default:
			break;
		}
		currentTime = 0;
	}
}

void Enemy::Moving(int x, int y, int speed)
{
	if (this->m_position.y <= 100 && y == -1)
		y = 0;

	if (this->m_position.y >= Globals::screenHeight - 100 && y == 1)
		y = 0;
	if (this->m_position.x <= 100 && x == -1)
		x = 0;
	if (this->m_position.x >= Globals::screenWidth - 100 && x == 1)
		x = 0;
	for (int i = 0; i < 5; i++)
		this->Set2DPosition(m_position.x + x * speed, m_position.y + y * speed);
}



int Enemy::RandomNumber(int min, int max)
{
	srand(time(NULL));
	int res = rand() % (max - min + 1) - min;
	return res;
}