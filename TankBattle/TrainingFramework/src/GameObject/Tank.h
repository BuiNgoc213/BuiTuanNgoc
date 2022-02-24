#pragma once 
#include "Sprite2D.h"

class Tank : public Sprite2D
{
public:
	Tank() : Sprite2D() {}
	Tank(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~Tank();
	void Update(GLfloat deltatime) override;
	void Move(int x, int y, int speed);
};
