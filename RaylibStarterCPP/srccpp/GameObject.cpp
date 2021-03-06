#include "GameObject.h"
#include "Behaviour.h"

GameObject::GameObject(Application* app)
{
	m_app = app;
}

GameObject::~GameObject()
{
	
}

void GameObject::Update(float deltaTime)
{

	if (m_behaviour != nullptr)
		m_behaviour->Update(this, deltaTime);

	//ApplyForce(-m_velocity * m)friction);
	ApplyForce(Vector2Scale(Vector2Negate(m_velocity), m_friction));

	//m_vel += m_acceleration * deltaTime;
	m_velocity = Vector2Add(m_velocity, Vector2Scale(m_acceleration, deltaTime));

	//m_pos += m_velocity * deletaTime;
	m_position = Vector2Add(m_position, Vector2Scale(m_velocity, deltaTime));

	//CLEAR ACCERLERATION
	m_acceleration = { 0, 0 };
}

void GameObject::Draw()
{

}


//The Getters
const Vector2& GameObject::GetPosition() const
{
	return m_position;
}

const Vector2& GameObject::GetVelocity() const
{
	return m_velocity;
}

const float& GameObject::GetFriction() const
{
	return m_friction;
}

Behaviour* GameObject::GetBehaviour()
{
	return m_behaviour;
}



//The Setter

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
	//m_accerleration += force;
	m_acceleration = Vector2Add(m_acceleration, force);
}

void GameObject::SetBehaviour(Behaviour* behaviour)
{
	m_behaviour = behaviour;
}

Application* GameObject::GetApp()
{
	return m_app;
}