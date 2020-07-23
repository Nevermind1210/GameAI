#pragma once
#include "GameObject.h"

class Behaviour
{
public:
	Behaviour();
	virtual ~Behaviour();

	virtual Vector2 Update(GameObject* obj, float deletaTime) = 0;
protected:
private:

};