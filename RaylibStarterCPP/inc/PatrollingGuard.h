#pragma once
#include <vector>
#include "GameObject.h"

class Player;
class FollowPathBehaviour;
class Graph2D;
class SeekBehaviour;

class PatrollingGuard : public GameObject
{
public:
	PatrollingGuard();
	virtual ~PatrollingGuard();

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

	std::vector<Vector2> hardCodedPath = {
	{100, 100},
	{(float)GetScreenWidth() - 100, 100},
	{(float)GetScreenWidth() - 100, (float)GetScreenHeight() - 100},
	{100, (float)GetScreenHeight() - 100}
	};

protected:
	float GuardRadius = 200.0f;

	Player* m_player;
	FollowPathBehaviour* m_followPathBehaviourAStar;
	FollowPathBehaviour* m_followPathBehaviourHCP;
	SeekBehaviour* m_seekBehaviour;

	Graph2D* m_graph;



private:
	Image PGuardImg;
	Texture2D PGuardTex;

};

