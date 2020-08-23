#include "PatrollingGuard.h"
#include "FollowPathBehaviour.h"
#include "SeekBehaviour.h"
#include <iostream>
#include "raylib.h"
#include "Player.h"
#include "Graph2D.h"
PatrollingGuard::PatrollingGuard()
{
	m_followPathBehaviour = new FollowPathBehaviour();
	m_seekBehaviour = new SeekBehaviour();
	
	//The Texture Setup!
	PGuardImg = LoadImage("../Sprites/PGuard.png");
	PGuardTex = LoadTextureFromImage(PGuardImg);
}

PatrollingGuard::~PatrollingGuard()
{
	SetBehaviour(nullptr);
	m_followPathBehaviour = nullptr;
	m_followPathBehaviour = nullptr;

	delete m_followPathBehaviour;
	delete m_followPathBehaviour;
}

void PatrollingGuard::Update(float deltaTime)
{
	std::vector<Vector2> hardCodedPath = {
{100, 100}, {(float)GetScreenWidth() - 100, 100}, {(float)GetScreenWidth() - 100, (float)GetScreenHeight() - 100}, {100, (float)GetScreenHeight() - 100}
		};

	float distToTarget = Vector2Distance(GetPosition(), m_player->GetPosition());
	if (distToTarget < GuardRadius)
	{
		std::vector<Graph2D::Node*>GuardNode;
		m_graph->GetNearbyNodes(GetPosition(), 40, GuardNode);
		std::vector<Graph2D::Node*>PlayerNode;
		m_graph->GetNearbyNodes(m_player->GetPosition(), 40, PlayerNode);
		std::list<Graph2D::Node*>PathFound;
		m_graph->FindPathAStar(GuardNode[0], PlayerNode[0], PathFound);

		std::vector<Vector2>FinalDes;

		for (auto node : PathFound)
		{
			FinalDes.push_back(node->data);
		}
		m_followPathBehaviour->SetPath(FinalDes);
		SetBehaviour(m_followPathBehaviour);
	}
	else if (distToTarget < GuardRadius)
	{
		
		m_followPathBehaviour->SetPath(hardCodedPath);
		SetBehaviour(m_followPathBehaviour);
	}
	GameObject::Update(deltaTime);
}

void PatrollingGuard::Draw()
{
	if (m_behaviour != nullptr)
	{
		m_behaviour->Draw(this);
	}
	//Debug draw
	Vector2 targetHeading = Vector2Add(m_position, m_velocity);
	//Draws the sight of PGuard
	DrawCircle(GetPosition().x, GetPosition().y, 200, { 255,215,68,100 });
	//The texture drawn
	DrawTexture(PGuardTex, m_position.x - PGuardTex.width / 2, m_position.y - PGuardTex.width / 2,RED);

	DrawLine(m_position.x, m_position.y,
		targetHeading.x, targetHeading.y, DARKGRAY);
}

