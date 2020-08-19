#pragma once
#include "raymath.h"
#include "Behaviour.h"
#include <vector>
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

protected:

	Player* m_player;
	std::vector<Vector2> m_path;
	float m_targetRadius = 1.0f;
private:
};