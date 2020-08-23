#pragma once
#include "raymath.h"
#include "Behaviour.h"
#include "GameObject.h"
#include <vector>e
class Player;
class FollowPathBehaviour : public Behaviour
{
public:

	FollowPathBehaviour();
	virtual ~FollowPathBehaviour();

	virtual void Update(GameObject* obj, float deltaTime);
	virtual void Draw(GameObject* obj);

	const std::vector<Vector2>& GetPath() const;
	void SetPath(const std::vector<Vector2>& path);

	const float& GetTargetRadius() const;
	void SetTargetRadius(const float& radius);

	std::vector<Vector2> m_path;

protected:

	Player* m_player;
	FollowPathBehaviour* m_followPathBehaviour;
	float m_targetRadius = 35.0f;
private:
};