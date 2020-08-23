#pragma once

#include "GameObject.h"

class KeyboardBehaviour;
class Graph2D;

class Player : public GameObject
{
public: 
	Player();
	virtual ~Player();

	virtual void Update(float deltaTime);
	virtual void Draw();
	Graph2D* m_graph;
protected:

	KeyboardBehaviour* m_kbBehaviour;
private:
	Image PlayerImg;
	Texture2D PlayerTex;
};