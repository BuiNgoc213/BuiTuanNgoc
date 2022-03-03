#pragma once
#include "GameStateBase.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class Tank;
class Wall;
class Bullet;
class Enemy;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();
	enum TankDir
	{
		DIR_LEFT = 0,
		DIR_RIGHT = 1,
		DIR_UP = 2,
		DIR_DOWN = 3,
	};
	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	int     Random(int max, int min);
	void	Draw() override;

private:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Text>		m_score;
	std::shared_ptr<Tank>		m_tank;
	std::shared_ptr<Bullet>			m_bullet;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::shared_ptr<Wall>		m_wall;
	std::shared_ptr<Enemy>		m_enemy;
	int x_val, y_val;
	int status_;
};

