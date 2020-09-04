#pragma once
#include <vector>
#include "GameObject.h"

class Player;
class FollowPathBehaviour;
class Graph2D;
class ChaseBehaviour;

class PatrollingGuard : public GameObject
{
public:
	PatrollingGuard(Application* app);
	virtual ~PatrollingGuard();

	virtual void Update(float deltaTime);
	virtual void Draw();


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
	ChaseBehaviour* m_chasePlayerBehaviour;
	FollowPathBehaviour* m_followPathBehaviourHCP;


private:
	Image PGuardImg;
	Texture2D PGuardTex;
};

