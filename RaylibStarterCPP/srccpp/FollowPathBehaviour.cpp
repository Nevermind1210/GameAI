#include "FollowPathBehaviour.h"
#include <GameObject.h>
#include "Player.h"

FollowPathBehaviour::FollowPathBehaviour()
{

}

FollowPathBehaviour::~FollowPathBehaviour()
{
}

void FollowPathBehaviour::Update(GameObject* obj, float deltaTime)
{
	// to start with, apply a force in the direction of the first point in the m_path
	// once we are done, we can figure out how to move to the next point
	if (!m_path.empty())
	{
		float distToTarget = Vector2Distance(obj->GetPosition(), m_path[0]);
		if (distToTarget < m_targetRadius) {
			m_path.push_back(m_path[0]);
			m_path.erase(m_path.begin());
		}
		Vector2 heading = Vector2Add(obj->GetPosition(), obj->GetVelocity());
		float headingLen = 500.0f;

		Vector2 dirToTarget = Vector2Normalize(Vector2Subtract(m_path[0], obj->GetPosition()));
		Vector2 vecToTarget = Vector2Scale(dirToTarget, headingLen);

		Vector2 targetForcePos = Vector2Add(vecToTarget, obj->GetPosition());
		Vector2 forceDir = Vector2Subtract(targetForcePos, heading);

		obj->ApplyForce(forceDir);
	}
}

void FollowPathBehaviour::Draw(GameObject* obj)
{
	//For debugging to see the path of the Guards.
	if (IsKeyDown(KEY_TAB))
	{
		DrawCircle(m_path[0].x, m_path[0].y, m_targetRadius, { 0,255,0,100 });
		for (int i = 0; i < m_path.size() - 1; i++)
		{
			DrawLineEx(m_path[i], m_path[i + 1], 5, RED);
		}
	}
}

const std::vector<Vector2>& FollowPathBehaviour::GetPath() const
{
	return m_path;
}

void FollowPathBehaviour::SetPath(const std::vector<Vector2>& path)
{
	m_path = path;
}

const float& FollowPathBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void FollowPathBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}
