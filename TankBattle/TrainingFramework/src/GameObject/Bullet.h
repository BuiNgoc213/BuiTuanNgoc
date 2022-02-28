#pragma once
#include "Sprite2D.h"

class Bullet : public Sprite2D
{
public:
	Bullet(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~Bullet();
	enum BulletDir
	{
		DIR_LEFT=0,
		DIR_RIGHT=1,
	};
	void Update(GLfloat deltatime) override;
	void Cal(int x1, int y1);
	void SetMoving(bool moving);
	bool GetMoving();
	void set_bullet_dir(const unsigned bulletdir) { bullet_dir = bulletdir; }
	int get_bullet_dir()const { return bullet_dir; }
	//
private:
	float x, y, x_val, y_val;
	bool moving = false;
	unsigned int bullet_dir;
};