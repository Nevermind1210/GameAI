#include "StandingGuard.h"
#include "FollowPathBehaviour.h"
#include "WonderBehaviour.h"
#include "Player.h"
#include "Graph2D.h"
#include <iostream>
#include "raylib.h"

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

	if(distToTarget < GuardRadius)
	{		
		std::vector<Graph2D::Node*>GuardNode;
		m_graph->GetNearbyNodes(GetPosition(), 40, GuardNode);
		std::vector<Graph2D::Node*>PlayerNode;
		m_graph->GetNearbyNodes(m_player->GetPosition(), 40, PlayerNode);
		std::list<Graph2D::Node*>PathFound;
		m_graph->FindPathAStar(GuardNode[0], PlayerNode[0], PathFound);

		std::vector<Vector2>FinalDes;

		for(auto node: PathFound)
		{
			FinalDes.push_back(node->data);
		}
		m_followPathBehaviour->SetPath(FinalDes);
		SetBehaviour(m_followPathBehaviour);		
	}
	else
	{
		std::vector<Graph2D::Node*>GuardNode;
		m_graph->GetNearbyNodes(GetPosition(), 40, GuardNode);
		std::vector<Graph2D::Node*>PlayerNode;
		m_graph->GetNearbyNodes({ GetScreenWidth() * 0.45f , GetScreenHeight() / 2.0f }, 40, PlayerNode);
		std::list<Graph2D::Node*>PathFound;
		m_graph->FindPathAStar(GuardNode[0], PlayerNode[0], PathFound);

		std::vector<Vector2>FinalDes;

		for (auto node : PathFound)
		{
			FinalDes.push_back(node->data);
		}
		m_followPathBehaviour->SetPath(FinalDes);
		SetBehaviour(m_followPathBehaviour);

		if (distToTarget == distToTarget)
		{
			SetBehaviour(nullptr);
		}
		//TODO: TRY AND MAKE A ONARRIVE FUNCTION TO SET BEHVAIOUR BACK TO NULL SO HE GOES BACK TO JUST STANDING
	}

	//I need this logic to be agent awaiting player to hit a certain range and once reached range is to chase(seek)
	//the player to a certain distance, if player successfully loses range he returns to his old position.
	//otherwise just stay standing until then.

	GameObject::Update(deltaTime);
}

void StandingGuard::Draw()
{
	if (m_behaviour != nullptr)
	{
	m_behaviour->Draw(this);
	}
	DrawCircle(GetPosition().x, GetPosition().y, 200, {255,215,68,100});
	//Debug draw
	Vector2 targetHeading = Vector2Add(m_position, m_velocity);
	DrawCircle(m_position.x, m_position.y, 8, PURPLE);

	DrawLine(m_position.x, m_position.y,
		targetHeading.x, targetHeading.y, DARKGRAY);
}
