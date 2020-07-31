#pragma once
#include "raymath.h"
#include "Behaviour.h"


class WonderBehaviour : public Behaviour
{
public:
	WonderBehaviour();
	virtual ~WonderBehaviour();

	virtual void Update(GameObject* obj, float deltaTime);
	virtual void Draw(GameObject* obj);

	const Vector2& GetTarget() const;
	void SetTarget(const Vector2& target);

	const float& GetTargetRadius() const;
	void SetTargetRadius(const float& radius);

protected:

	Vector2 m_target;
	float m_targetRadius = 1.0f;
private:
};