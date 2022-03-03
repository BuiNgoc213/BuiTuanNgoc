#include "GSPlay.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "Tank.h"
#include "Wall.h"
#include "Bullet.h"
#include "Enemy.h"
#include <math.h>

GSPlay::GSPlay() : GameStateBase(StateType::STATE_PLAY)
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	status_ = -1;
	x_val = 0;
	y_val = 0;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("map.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button clode
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);
	//tank
	texture = ResourceManagers::GetInstance()->GetTexture("Tank_1.tga");
	m_tank = std::make_shared<Tank>(model, shader, texture);
	m_tank->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight - 25);
	m_tank->SetSize(50, 50);
	//
	//texture = ResourceManagers::GetInstance()->GetTexture("wall.tga");
	//m_wall = std::make_shared<Wall>(model, shader, texture);
	////m_wall->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight - 25);
	//m_wall->SetSize(50, 50);
	// Enemy
	texture = ResourceManagers::GetInstance()->GetTexture("Enemy1.tga");
	m_enemy = std::make_shared<Enemy>(model, shader, texture);
	m_enemy->Set2DPosition(500, 200);
	m_enemy->SetSize(50, 50);
	//bullet
	texture = ResourceManagers::GetInstance()->GetTexture("bullet.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_bullet = std::make_shared<Bullet>(model, shader, texture);
	//m_bullet->Set2DPosition(Globals::screenWidth - 100, Globals::screenHeight - 100);
	m_bullet->SetSize(20, 20);
	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TextColor::RED, 1.0);
	m_score->Set2DPosition(0,25);
}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed) {
		switch (key) {
		case KEY_MOVE_LEFT:
			x_val = -1;	
			status_ = DIR_LEFT;
			m_tank->SetTexture(ResourceManagers::GetInstance()->GetTexture("Tank_2.tga"));
			
			break;
		case KEY_MOVE_RIGHT:
			x_val = 1;
			status_ = DIR_RIGHT;
			m_tank->SetTexture(ResourceManagers::GetInstance()->GetTexture("Tank_3.tga"));
			break;		
		case KEY_MOVE_FORWORD:
			y_val = -1;
			status_ = DIR_UP;
			m_tank->SetTexture(ResourceManagers::GetInstance()->GetTexture("Tank_1.tga"));
			break;
		case KEY_MOVE_BACKWORD:
			y_val = 1;
			status_ = DIR_DOWN;
			m_tank->SetTexture(ResourceManagers::GetInstance()->GetTexture("Tank_4.tga"));
			break;
		}
	}
	else
	{
		x_val = 0;
		y_val = 0;
	}
	
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}if (bIsPressed && !m_bullet->GetMoving())
	{
		if (status_==DIR_RIGHT) {
			m_bullet->set_bullet_dir(Bullet::BULLETDIR_RIGHT);
			m_bullet->Set2DPosition(m_tank->GetPosition().x, m_tank->GetPosition().y);
			m_bullet->Cal(m_bullet->GetPosition().x, m_bullet->GetPosition().y);
		}
		if(status_==DIR_LEFT)
		{
			m_bullet->set_bullet_dir(Bullet::BULLETDIR_LEFT);
			m_bullet->Set2DPosition(m_tank->GetPosition().x, m_tank->GetPosition().y);
			m_bullet->Cal(m_bullet->GetPosition().x, m_bullet->GetPosition().y);
		}
		if (status_ == DIR_UP) {
			m_bullet->set_bullet_dir(Bullet::BULLETDIR_UP);
			m_bullet->Set2DPosition(m_tank->GetPosition().x, m_tank->GetPosition().y);
			m_bullet->Cal(m_bullet->GetPosition().x, m_bullet->GetPosition().y);
		}
		if (status_ == DIR_DOWN) {
			m_bullet->set_bullet_dir(Bullet::BULLETDIR_DOWN);
			m_bullet->Set2DPosition(m_tank->GetPosition().x, m_tank->GetPosition().y);
			m_bullet->Cal(m_bullet->GetPosition().x, m_bullet->GetPosition().y);
		}
		
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}

void GSPlay::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	int speed = 2;
	m_tank->Move(x_val, y_val, speed);
	m_bullet->Update(deltaTime);
	m_enemy->Update(deltaTime);
}
int GSPlay::Random(int max, int min) {
	srand(time(NULL));
	int res = rand() % (max - min + 1) - min;
	return res;
}
void GSPlay::Draw()
{
	m_background->Draw();
	m_score->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_tank->Draw();
	m_enemy->Draw();
	m_bullet->Draw();
}