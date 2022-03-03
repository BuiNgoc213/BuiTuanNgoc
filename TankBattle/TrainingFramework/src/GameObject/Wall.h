//#pragma once 
//#include "Sprite2D.h"
//#define MAX_MAP_X  40
//#define MAX_MAP_Y  30
//class Wall : public Sprite2D
//{
//public:   
//    Wall(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
//    Wall(double x, double y);
//    ~Wall();
//    void Update(GLfloat deltatime) override;
//    void LoadMap(char* name);
//    
//private:   
//    int Tile[MAX_MAP_X][MAX_MAP_Y];
//    char* file_name_;
//    int m_collision_count;
//    int m_state_code;
//};
#pragma once 
#include "Sprite2D.h"

class Wall : public Sprite2D
{
public:
	Wall() : Sprite2D(), m_pBtClick(nullptr), m_isHolding(false) {}
	Wall(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~Wall();
	void	SetOnClick(void	(*pBtClick)());
	bool	HandleTouchEvents(GLint x, GLint y, bool bIsPressed);
	bool	IsHolding();

private:
	void	(*m_pBtClick)();
	bool	m_isHolding;
};
