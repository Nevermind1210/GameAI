#pragma once
#include "GameObject.h"

class WonderBehaviour;
class FollowPathBehaviour;

class WonderingGuard : public GameObject
{
public:
	WonderingGuard();
	virtual ~WonderingGuard();

	virtual void Update(float deltaTime);
	virtual void Draw();
protected:

	WonderBehaviour* m_wonderBehaviour;
	FollowPathBehaviour* m_followPathBehaviour;
private:


};

