#pragma once

#include "GameObject.h"

class Player;
class FollowPathBehaviour;
class StandingGuard : public GameObject
{
public:
	StandingGuard();
	virtual ~StandingGuard();

	virtual void Update(float deltaTime);
	virtual void Draw();
protected:

	Player* m_player;
	FollowPathBehaviour* m_followPathBehaviour;


private:
};