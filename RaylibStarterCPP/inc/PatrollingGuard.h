#pragma once

#include "GameObject.h"

class Player;
class FollowPathBehaviour;
class Graph2D;
class PatrollingGuard : public GameObject
{
public:
	PatrollingGuard();
	virtual ~PatrollingGuard();

	virtual void Update(GameObject* obj, float deltaTime);
	virtual void Draw();
protected:

	Player* m_player;
	FollowPathBehaviour* m_followPathBehaviour;

	Graph2D* m_graph;
private:
};

