#include "PatrollingGuard.h"
#include "FollowPathBehaviour.h"
#include <iostream>
#include "raylib.h"

PatrollingGuard::PatrollingGuard()
{
	m_followPathBehaviour = new FollowPathBehaviour();

	std::vector<Vector2> hardCodedPath = {
	{100, 100}, {(float)GetScreenWidth() - 100, 100}, {(float)GetScreenWidth() - 100, (float)GetScreenHeight() - 100}, {100, (float)GetScreenHeight() - 100}
	};
	m_followPathBehaviour->SetPath(hardCodedPath);
	SetBehaviour(m_followPathBehaviour);

}

PatrollingGuard::~PatrollingGuard()
{
	SetBehaviour(nullptr);

	delete m_followPathBehaviour;
}

void PatrollingGuard::Update(GameObject* obj, float deltaTime)
{
	//You can insert any sort of logic that relates to the player
	//float distToTarget = Vector2Distance(GetPosition(), m_player->GetPosition());
	//if player near guard
	//if (distToTarget < GuardRadius)
	//{
	//	//chases player
	//	std::vector<Graph2D::Node*>GuardNode;
	//	m_Graph->GetNearbyNodes(GetPosition(), 40, GuardNode);
	//	std::vector<Graph2D::Node*>PlayerNode;
	//	m_player->m_graph->GetNearbyNodes(m_player->GetPosition(), 40, PlayerNode);
	//	std::list<Graph2D::Node*>PathFound;
	//	m_Graph->FindPathAStar(GuardNode[0], PlayerNode[0], PathFound);

	//	std::vector<Vector2>FinalDes;

	//	for (auto node : PathFound)
	//	{
	//		FinalDes.push_back(node->data);
	//	}
	//	m_followPathBehaviour->SetPath(FinalDes);
	//	SetBehaviour(m_followPathBehaviour);
	//}
	GameObject::Update(deltaTime);
}

void PatrollingGuard::Draw()
{
	//GameObject::Draw();
	m_behaviour->Draw(this);
	//Debug draw
	Vector2 targetHeading = Vector2Add(m_position, m_velocity);
	DrawCircle(m_position.x, m_position.y, 8, RED);

	DrawLine(m_position.x, m_position.y,
		targetHeading.x, targetHeading.y, DARKGRAY);
}
