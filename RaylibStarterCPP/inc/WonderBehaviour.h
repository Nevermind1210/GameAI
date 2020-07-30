#pragma once
#include "raymath.h"
#include "Behaviour.h"
#define volatile


class WonderBehaviour : public Behaviour
{
public:
	WonderBehaviour();
	virtual ~WonderBehaviour();

	const Vector2& GetTarget() const;
	void SetTarget(const Vector2& target);

	const float& GetTargetRadius() const;
	void SetTargetRadius(const float& radius);

protected:

	Vector2 m_target;
	float m_targetRadius = 1.0f;
private:
};