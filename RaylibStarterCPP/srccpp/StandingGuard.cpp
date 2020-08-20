#include "StandingGuard.h"
#include "FollowPathBehaviour.h"
#include "WonderBehaviour.h"
#include "Player.h"
#include "Graph2D.h"
#include <iostream>

StandingGuard::StandingGuard() : GameObject()
{
	m_followPathBehaviour = new FollowPathBehaviour();
	m_followPathBehaviour->SetTargetRadius(20);


	
	SetBehaviour(nullptr);
}

StandingGuard::~StandingGuard()
{
	SetBehaviour(nullptr);

	delete m_followPathBehaviour;
}

void StandingGuard::Update(float deltaTime)
{
	//You can insert any sort of logic that relates to the player/agent
	float distToTarget = Vector2Distance(GetPosition(), m_player->GetPosition());
	
	std::cout << GetPosition().x << std::endl;

	if(distToTarget < GuardRadius)
	{		
		std::vector<Graph2D::Node*>GuardNode;
		m_Graph->GetNearbyNodes(GetPosition(), 40, GuardNode);
		std::vector<Graph2D::Node*>PlayerNode;
		m_player->m_graph->GetNearbyNodes(m_player->GetPosition(), 40, PlayerNode);
		std::list<Graph2D::Node*>PathFound;
		m_Graph->FindPathAStar(GuardNode[0], PlayerNode[0], PathFound);

		std::vector<Vector2>FinalDes;

		for(auto node: PathFound)
		{
			FinalDes.push_back(node->data);
		}
		m_followPathBehaviour->SetPath(FinalDes);
		SetBehaviour(m_followPathBehaviour);
	}



	//I need this logic to be agent awaiting player to hit a certain range and once reached range is to chase(seek)
	//the player to a certain distance, if player successfully loses range he returns to his old position.
	//otherwise just stay standing until then.
}

void StandingGuard::Draw()
{
	DrawCircle(GetPosition().x, GetPosition().y, 200, RED);
	//Debug draw
	Vector2 targetHeading = Vector2Add(m_position, m_velocity);
	DrawCircle(m_position.x, m_position.y, 8, PURPLE);

	DrawLine(m_position.x, m_position.y,
		targetHeading.x, targetHeading.y, DARKGRAY);
}
