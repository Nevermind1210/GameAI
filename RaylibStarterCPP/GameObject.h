#pragma once

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void Update(float deletaTime);
	virtual void Draw();


	//The Getters
	const Vector2& GetPosition(const Vector2& pos);
	const Vector2& SetVelocity(const Vector2& vel);


protected:

	Vector2 m_position;
	Vector2 m_velocity;

private:
};

