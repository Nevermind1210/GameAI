#include "FollowPathBehaviour.h"
#include <GameObject.h>

FollowPathBehaviour::FollowPathBehaviour()
{

}

FollowPathBehaviour::~FollowPathBehaviour()
{

}

void FollowPathBehaviour::Update(GameObject* obj, float deltaTime)
{
	float distToTarget = Vector2Distance(obj->GetPosition(), m_target);

}

void FollowPathBehaviour::Draw(GameObject* obj)
{
	DrawCircle(m_target.x, m_target.y, m_targetRadius, LIGHTGRAY);
	DrawCircle(m_target.x, m_target.y, 4, RED);
}

const Vector2& FollowPathBehaviour::GetTarget() const
{
	return m_target;
}

void FollowPathBehaviour::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& FollowPathBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void FollowPathBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}
