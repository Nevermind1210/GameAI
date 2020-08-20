#pragma once

#include "raymath.h"

class Behaviour;
class Player;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(float deltaTime);
	virtual void Draw();

	void ApplyForce(const Vector2& force);

	//The Getters
	const Vector2& GetPosition() const;
	const Vector2& GetVelocity() const;
	const float& GetFriction() const;

	Behaviour* GetBehaviour();

	//The Setters
	void SetPosition(const Vector2& pos);
	void SetVelocity(const Vector2& val);
	void SetFriction(const float& friction);

	void SetBehaviour(Behaviour* behaviour);


protected:

	Vector2 m_position = { 0.0f,  0.0f };
	Vector2 m_velocity = { 0.0f,  0.0f };
	Vector2 m_acceleration = { 0.0f,  0.0f };
	float m_friction = 0.0f;

	Player* m_player;
	Behaviour* m_behaviour = nullptr;

private:
};

