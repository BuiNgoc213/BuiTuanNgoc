#pragma once
#pragma once 
#include "Sprite2D.h"

class Enemy : public Sprite2D
{
public:
	Enemy() : Sprite2D() {}
	Enemy(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~Enemy();
	void Update(GLfloat deltatime) override;
	void Moving(int x, int y, int speed);
	int RandomNumber(int min, int max);
private:
	int currentTime = 0;
	std::shared_ptr<Enemy>		m_enemy;
};