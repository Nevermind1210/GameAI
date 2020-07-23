#pragma once

#include "raymath.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Load() {};
	virtual void Unload() { }


	virtual void Update(float deletaTime);
	virtual void Draw();


	//The Getters
	const Vector2& GetPosition() const;
	const Vector2& SetVelocity() const;
	const float& GetFriction() const;

	//The Setters
	void SetPosition(const Vector2& pos);
	void SetVelocity(const Vector2& val);
	void SetFriction(const float& friction);

	void ApplyForce(const Vector2& force);


protected:

	Vector2 m_position = { 0, 0 };
	Vector2 m_velocity = { 0, 0 };
	Vector2 m_acceleration = { 0, 0 };
	float m_friction = 0.0f;

private:
};

