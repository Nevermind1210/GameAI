#include "PatrollingGuard.h"
#include "FollowPathBehaviour.h"
#include <iostream>
#include "raylib.h"
#include "Player.h"
#include "Graph2D.h"
#include "ChaseBehaviour.h"
#include "Application.h"

PatrollingGuard::PatrollingGuard(Application* app) : GameObject(app)
{
	m_followPathBehaviourHCP = new FollowPathBehaviour();
	m_chasePlayerBehaviour = new ChaseBehaviour();

	m_followPathBehaviourHCP->SetPath(hardCodedPath);
	SetBehaviour(m_followPathBehaviourHCP);

	//The Texture Setup!
	PGuardImg = LoadImage("../Sprites/PGuard.png");
	PGuardTex = LoadTextureFromImage(PGuardImg);
}

PatrollingGuard::~PatrollingGuard()
{
	SetBehaviour(nullptr);
	m_followPathBehaviourHCP= nullptr;
	m_chasePlayerBehaviour = nullptr;

	delete m_chasePlayerBehaviour;
	delete m_followPathBehaviourHCP;
}

void PatrollingGuard::Update(float deltaTime)
{
	float distToTarget = Vector2Distance(GetPosition(), m_player->GetPosition());
	if (distToTarget < GuardRadius)
	{
		m_chasePlayerBehaviour->SetTarget(m_player->GetPosition());
		SetBehaviour(m_chasePlayerBehaviour);
	}
	else
	{
		//This if statement, checks for the behaviour and sets it.
		if (GetBehaviour() != m_followPathBehaviourHCP)
		{
			m_followPathBehaviourHCP->SetPath(hardCodedPath);
			SetBehaviour(m_followPathBehaviourHCP);
		}
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

