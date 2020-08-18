#include <WonderBehaviour.h>
#include <GameObject.h>
#include <random>

WonderBehaviour::WonderBehaviour()

{
	WanderList[0] = { 50,50 };
	WanderList[1] = { 500,50 };
	WanderList[2] = { 50,200 };
	SetTarget(WanderList[0]);


}

WonderBehaviour::~WonderBehaviour()
{
}

void WonderBehaviour::Update(GameObject* obj, float deltaTime)
{
	float distToTarget = Vector2Distance(obj->GetPosition(), m_target);
	if (distToTarget < m_targetRadius) {
		if (m_onArriveFn)
			m_onArriveFn();

		WanderList.push_back(WanderList[0]);
	}

	Vector2 heading = Vector2Add(obj->GetPosition(), obj->GetVelocity());
	float headingLen = 500.0f;

	Vector2 dirToTarget = Vector2Normalize(Vector2Subtract(m_target, obj->GetPosition()));
	Vector2 vecToTarget = Vector2Scale(dirToTarget, headingLen);

	Vector2 targetForcePos = Vector2Add(vecToTarget, obj->GetPosition());
	Vector2 forceDir = Vector2Subtract(targetForcePos, heading);

	obj->ApplyForce(forceDir);
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
