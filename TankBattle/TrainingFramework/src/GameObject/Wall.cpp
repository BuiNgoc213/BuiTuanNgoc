//#include "Wall.h"
//Wall::Wall(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
//	: Sprite2D(-1, model, shader, texture)
//{
//}
//Wall::~Wall()
//{
//}
//void Wall::LoadMap(char* name) {
//	FILE* fp = NULL;
//	fopen_s(&fp, name, "rb");
//	if (fp == 0) {
//		return;
//	}
//	for (int i = 0; i < MAX_MAP_Y; i++) {
//		for (int j = 0; j < MAX_MAP_X; j++) {
//			fscanf_s(fp,"%d")
//		}
//	}
//}
#include "Wall.h"

Wall::Wall(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(-1, model, shader, texture), m_pBtClick(nullptr), m_isHolding(false)
{
}

Wall::~Wall()
{
}

void Wall::SetOnClick(void(*pBtClickFun)())
{
	m_pBtClick = pBtClickFun;
}

bool Wall::HandleTouchEvents(GLint x, GLint y, bool bIsPressed)
{
	bool isHandled = false;
	if (bIsPressed)
	{
		if ((x > m_position.x - m_iWidth / 2) && (x < m_position.x + m_iWidth / 2)
			&& (y > m_position.y - m_iHeight / 2) && (y < m_position.y + m_iHeight / 2))
		{
			// The button is being pressed down
			m_isHolding = true;
		}
	}
	else
	{
		if ((x > m_position.x - m_iWidth / 2) && (x < m_position.x + m_iWidth / 2)
			&& (y > m_position.y - m_iHeight / 2) && (y < m_position.y + m_iHeight / 2)
			&& m_isHolding == true)
		{
			// Only perform click action when the same button was pressed down and released
			m_pBtClick();
			isHandled = true;
		}
		m_isHolding = false;
	}
	return isHandled;
}

bool Wall::IsHolding()
{
	return m_isHolding;
}
