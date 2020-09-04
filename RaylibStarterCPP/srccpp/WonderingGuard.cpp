#include "WonderBehaviour.h"
#include "WonderingGuard.h"
#include "ChaseBehaviour.h"
#include <iostream>
#include "Player.h"

WonderingGuard::WonderingGuard(Application* app) : GameObject(app)
{
	m_chaseBehaviour = new ChaseBehaviour();
	m_wonderBehaviour = new WonderBehaviour();

	//SetBehaviour(m_wonderBehaviour);
	
	//Setting up the images.
	WGuardImg = LoadImage("../Sprites/WGuard.png");
	WGuardTex = LoadTextureFromImage(WGuardImg);

}

WonderingGuard::~WonderingGuard()
{
	SetBehaviour(nullptr);
	m_wonderBehaviour = nullptr;
	m_chaseBehaviour = nullptr;

	delete m_wonderBehaviour;
	delete m_chaseBehaviour;
}

void WonderingGuard::Update(float deltaTime)
{
	float distToTarget = Vector2Distance(GetPosition(), m_player->GetPosition());
	if (distToTarget < m_guardRadius)
	{
		m_chaseBehaviour->SetTarget(m_player->GetPosition());
		SetBehaviour(m_chaseBehaviour);
	}
	else
	{
		//You can insert any sort of logic that relates to the player
		SetBehaviour(m_wonderBehaviour);
	}


	GameObject::Update(deltaTime);
}

void WonderingGuard::Draw()
{
	//GameObject::Draw();
	m_behaviour->Draw(this);
	//Debug draw
	Vector2 targetHeading = Vector2Add(m_position, m_velocity);
	//Draws line of sight
	DrawCircle(GetPosition().x, GetPosition().y, 200, { 255,215,68,100 });
	//Drawing the WGuard Texture!
	DrawTexture(WGuardTex, m_position.x - WGuardTex.width / 2, m_position.y - WGuardTex.width / 2, GREEN);

	DrawLine(m_position.x, m_position.y,
		targetHeading.x, targetHeading.y, DARKGRAY);
}
