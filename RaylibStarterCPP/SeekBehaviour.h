#pragma once
#include "GameObject.h"
class SeekBehaviour
{
public:
	SeekBehaviour();
	virtual ~SeekBehaviour();

	void Update(GameObject* obj, float deltaTime);
private:
protected:
};

