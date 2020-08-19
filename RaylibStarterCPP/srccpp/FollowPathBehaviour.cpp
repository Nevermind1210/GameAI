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
	// TODO: 
	// to start with, apply a force in the direction of the first point in the m_path
	// once we are done, we can figure out how to move to the next point



}

void FollowPathBehaviour::Draw(GameObject* obj)
{
	// TODO: write code to draw a line from each point in the path
	// to the next point in the path
	DrawLine(10, 10, 193, 40, GREEN);

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
