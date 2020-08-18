#pragma once

#include "GameObject.h"

class FleeBehaviour;
class KeyboardBehaviour;
class SeekBehaviour;
class WonderBehaviour;
class Player : public GameObject
{
public: 
	Player();
	virtual ~Player();

	virtual void Update(float deltaTime);
	virtual void Draw();
protected:

	KeyboardBehaviour* m_kbBehaviour;
	SeekBehaviour* m_seekBehaviour;
	FleeBehaviour* m_fleeBehaviour;
	WonderBehaviour* m_wonderBehaviour;

private:
};