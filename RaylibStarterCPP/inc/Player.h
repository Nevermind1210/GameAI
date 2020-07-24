#pragma once

#include "GameObject.h"
#include "KeyboardBehaviour.h"

class Player : public GameObject
{
public: 
	Player();
	virtual ~Player();

	virtual void Update(float deltaTime);
	virtual void Draw();
protected:

	KeyboardBehaviour* m_kbBehaviour;

private:
};