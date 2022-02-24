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

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
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
	//wall
	texture = ResourceManagers::GetInstance()->GetTexture("wall.tga");
	std::shared_ptr<Wall>  wall = std::make_shared<Wall>(model, shader, texture);
	wall->Set2DPosition(200, 200);
	wall->SetSize(50, 50);
	m_listwall.push_back(wall);
	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TextColor::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));
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
			break;
		case KEY_MOVE_RIGHT:
			x_val = 1;
			break;		
		case KEY_MOVE_FORWORD:
			y_val = -1;
			break;
		case KEY_MOVE_BACKWORD:
			y_val = 1;
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
	for (auto it : m_listwall)
	{
		it->Draw();
	}
}