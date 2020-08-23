#include "WonderBehaviour.h"
#include "WonderingGuard.h"
#include "FollowPathBehaviour.h"
#include <iostream>

WonderingGuard::WonderingGuard()
{
	m_followPathBehaviour = new FollowPathBehaviour();
	m_wonderBehaviour = new WonderBehaviour();

	SetBehaviour(m_wonderBehaviour);
	
	//Setting up the images.
	WGuardImg = LoadImage("../Sprites/WGuard.png");
	WGuardTex = LoadTextureFromImage(WGuardImg);

}

WonderingGuard::~WonderingGuard()
{
	SetBehaviour(nullptr);

	delete m_wonderBehaviour;
	delete m_followPathBehaviour;
}

void WonderingGuard::Update(float deltaTime)
{
	//You can insert any sort of logic that relates to the player
	SetBehaviour(m_wonderBehaviour);


	GameObject::Update(deltaTime);
}

void WonderingGuard::Draw()
{
	//GameObject::Draw();
	m_behaviour->Draw(this);
	//Debug draw
	Vector2 targetHeading = Vector2Add(m_position, m_velocity);

	//Drawing the WGuard Texture!
	DrawTexture(WGuardTex, m_position.x - WGuardTex.width / 2, m_position.y - WGuardTex.width / 2, GREEN);

	DrawLine(m_position.x, m_position.y,
		targetHeading.x, targetHeading.y, DARKGRAY);
}
