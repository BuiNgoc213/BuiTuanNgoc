#pragma once 
#include "Sprite2D.h"
#define WEIHT_TANK 50;
#define HIGHT_TANK 50;
class Tank : public Sprite2D
{
public:
	Tank() : Sprite2D() {}
	Tank(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~Tank();
	enum TankDir
	{
		DIR_LEFT = 0,
		DIR_RIGHT = 1,
		DIR_UP = 2,
		DIR_DOWN = 3,
	};
	void Update(GLfloat deltatime) override;
	void Move(int x, int y, int speed);
	int status_;
};
