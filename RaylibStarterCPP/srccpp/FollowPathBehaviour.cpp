#include "FollowPathBehaviour.h"
#include <GameObject.h>

FollowPathBehaviour::FollowPathBehaviour()
{

}

FollowPathBehaviour::~FollowPathBehaviour()
{

}


void FollowPathBehaviour::dijkstrasSearch(Node* startNode, const std::list<Node*>& endNodes, std::list<Node*>& outPath)
{
	int currentStep = 0;
	std::list<Node*> openList; // open list is accessed as a queue
	std::list<Node*> closedList;

	Node* endNode = nullptr;

	openList.push_back(startNode);

	while (openList.empty() == false) {
		openList.sort()
	}
}

void FollowPathBehaviour::Update(GameObject* obj, float deltaTime)
{
	float distToTarget = Vector2Distance(obj->GetPosition(), m_target);

}

void FollowPathBehaviour::Draw(GameObject* obj)
{
	DrawCircle(m_target.x, m_target.y, m_targetRadius, LIGHTGRAY);
	DrawCircle(m_target.x, m_target.y, 4, RED);
}

const Vector2& FollowPathBehaviour::GetTarget() const
{
	return m_target;
}

void FollowPathBehaviour::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& FollowPathBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void FollowPathBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}
