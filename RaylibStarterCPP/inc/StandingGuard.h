#pragma once

#include "GameObject.h"
#include <functional>

class FollowPathBehaviour;
class SeekBehaviour;
class Player;
class Graph2D;

class StandingGuard : public GameObject  
{
public:
	StandingGuard();
	virtual ~StandingGuard();

	virtual void Update(float deltaTime);
	virtual void Draw();

	void SetGraph(Graph2D* graph)
	{
		m_graph = graph;
	}

	void SetPlayer(Player* player)
	{
		m_player = player;
	}

protected:
	float GuardRadius = 200.0f;

	FollowPathBehaviour* m_followPathBehaviour;
	SeekBehaviour* m_seekBehaviour;
	Player* m_player;
	Graph2D* m_graph;

private:
	Image SGuardImg;
	Texture2D SGuardTex;
};