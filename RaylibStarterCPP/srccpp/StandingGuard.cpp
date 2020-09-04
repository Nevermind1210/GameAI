#include "StandingGuard.h"
#include "FollowPathBehaviour.h"
#include "Player.h"
#include "Graph2D.h"
#include <iostream>
#include "Application.h"
#include "raylib.h"

StandingGuard::StandingGuard(Application* app) : GameObject(app)
{
	m_followPathBehaviour = new FollowPathBehaviour();
	m_followPathBehaviour->SetTargetRadius(20);

	//Setting up images ᵃᵍᵃᶦⁿ...
	SGuardImg = LoadImage("../Sprites/SGuard.png");
	SGuardTex = LoadTextureFromImage(SGuardImg);
}

StandingGuard::~StandingGuard()
{
	SetBehaviour(nullptr);
	m_followPathBehaviour = nullptr;

	delete m_followPathBehaviour;
}

void StandingGuard::Update(float deltaTime)
{
	//You can insert any sort of logic that relates to the player/agent
	float distToTarget = Vector2Distance(GetPosition(), m_player->GetPosition());
	auto graph = GetApp()->GetGraph();
	if(distToTarget < GuardRadius)
	{	
		//This collects the data of the Guard
		std::vector<Graph2D::Node*>GuardNode;
		graph->GetNearbyNodes(GetPosition(), 40, GuardNode); // Grabs itself
		std::vector<Graph2D::Node*>PlayerNode;
		graph->GetNearbyNodes(m_player->GetPosition(), 40, PlayerNode); //Grabs player info
		std::list<Graph2D::Node*>PathFound;
		graph->FindPathAStar(GuardNode[0], PlayerNode[0], PathFound); // combine it

		std::vector<Vector2>FinalDes; // The combination.

		for (auto node : PathFound) // comparing
		{
			FinalDes.push_back(node->data); // and pushing the nodes 
		}
		m_followPathBehaviour->SetPath(FinalDes); // and volia it follows the player
		SetBehaviour(m_followPathBehaviour);
	}
	else
	{
		SetBehaviour(nullptr);
	}

	//this logic to be agent awaiting player to hit a certain range and once reached range is to chase(seek)
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

	//Drawing texture here!
	DrawTexture(SGuardTex, m_position.x - SGuardTex.width / 2, m_position.y - SGuardTex.width / 2, PURPLE);

	DrawLine(m_position.x, m_position.y,
		targetHeading.x, targetHeading.y, DARKGRAY);
}
