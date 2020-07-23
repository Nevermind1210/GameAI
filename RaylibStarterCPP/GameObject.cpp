#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Update(float deletaTime)
{
	//ApplyForce(-m_velocity * m)firction);
	ApplyForce(Vector2Scale(Vector2Negate(m_velocity), m_friction));

	//m_vel += m_acceleration * deletaTime;
	m_velocity = Vector2Add(m_velocity, Vector2Scale(m_acceleration, deletaTime));

	//m_pos += m_velocity * deletaTime;
	m_position = Vector2Add(m_velocity, Vector2Scale(m_velocity, deletaTime));

	//CLEAR ACCERLERATION
	m_acceleration = Vector2Zero();
}

void GameObject::Draw()
{
	//Debug draw
	Vector2 targetHeading = Vector2Add(m_position, m_velocity);
	DrawCircle(m_position.x, m_position.y, 8, GRAY);

	DrawLine(m_position.x, m_position.y,
		targetHeading.x, targetHeading.y, DARKGRAY);
}

const Vector2& GameObject::GetPosition() const
{
	return m_position;
}

const Vector2& GameObject::SetVelocity() const
{
	return m_velocity;
}

const float& GameObject::GetFriction() const
{
	return m_friction;
}

void GameObject::SetPosition(const Vector2& pos)
{
	m_position = pos;
}

void GameObject::SetVelocity(const Vector2& vel)
{
	m_velocity = vel;
}


void GameObject::SetFriction(const float& friction)
{
	m_friction = friction;
}

void GameObject::ApplyForce(const Vector2& force)
{
	m_acceleration = force;
}
