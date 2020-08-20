#pragma once
#include "GameObject.h"

class WonderingBehaviour;
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

