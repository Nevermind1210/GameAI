#include <WonderBehaviour.h>
#include <GameObject.h>
#include <random>

WonderBehaviour::WonderBehaviour()
{
}

WonderBehaviour::~WonderBehaviour()
{
}



void WonderBehaviour::Update(GameObject* obj, float deltaTime)
{
	float distToTarget = Vector2Distance(obj->GetPosition(), m_target);

	


}

void WonderBehaviour::Draw(GameObject* obj)
{
	DrawCircle(m_target.x, m_target.y, m_targetRadius, LIGHTGRAY);
	DrawCircle(m_target.x, m_target.y, 4, RED);
}

const Vector2& WonderBehaviour::GetTarget() const
{
	return m_target;
}

void WonderBehaviour::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& WonderBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void WonderBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}
