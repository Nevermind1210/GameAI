#include "FleeBehaviour.h"
#include "GameObject.h"

FleeBehaviour::FleeBehaviour() : Behaviour()
{
}

FleeBehaviour::~FleeBehaviour()
{
}

void FleeBehaviour::Update(GameObject* obj, float deltaTime)
{
	float distToTarget = Vector2Distance(obj->GetPosition(), m_target);

	Vector2 heading = Vector2Add(obj->GetPosition(), obj->GetVelocity());
	float headingLen = Vector2Length(heading);

	Vector2 dirToTarget = Vector2Normalize(Vector2Subtract(m_target, obj->GetPosition()));
	Vector2 vecToTarget = Vector2Scale(dirToTarget, headingLen);

	Vector2 targetForcePos = Vector2Add(vecToTarget, obj->GetPosition());
	Vector2 forceDir = Vector2Subtract(heading, targetForcePos);
	if (distToTarget < m_targetRadius)
	{
		obj->ApplyForce(forceDir);
	}

}

void FleeBehaviour::Draw(GameObject* obj)
{

}

const Vector2& FleeBehaviour::GetTarget() const
{
	return m_target;
}

void FleeBehaviour::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& FleeBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void FleeBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}