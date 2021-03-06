#pragma once
#include "raymath.h"
#include "Behaviour.h"
#include "GameObject.h"
#include <vector>
class Player;
class Graph2D;
class ChaseBehaviour : public Behaviour
{
public:
	ChaseBehaviour();
	virtual ~ChaseBehaviour();

	virtual void Update(GameObject* obj, float deltaTime);
	virtual void Draw(GameObject* obj);

	void SetPlayer(Player* player)
	{
		m_player = player;
	}

	const Vector2& GetTarget() const;
	void SetTarget(const Vector2& target);

	const float& GetTargetRadius() const;
	void SetTargetRadius(const float& radius);

	std::vector<Vector2> m_path;

protected:
	float m_targetRadius = 35.0f;
	Vector2 m_target;
	Player* m_player;
	ChaseBehaviour* m_chasePlayerBehaviour;


private:
	Image PGuardImg;
	Texture2D PGuardTex;
};

