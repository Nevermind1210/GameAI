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
	float distToTarget = Vector2Distance(m_target, obj->GetPosition());
	if (distToTarget < m_targetRadius)
	{
		m_target.x = rand() % 1280;
		m_target.y = rand() % 720;
	}
	Vector2 dirToTarget = Vector2Subtract(m_target, obj->GetPosition());
	dirToTarget = Vector2MultiplyV(Vector2Normalize(dirToTarget), { 100,100 });
	obj->ApplyForce(dirToTarget);

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

void WonderBehaviour::OnArrive(std::function<void()> callback)
{
	m_onArriveFn = callback;
}
