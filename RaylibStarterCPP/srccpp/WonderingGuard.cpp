#include "WonderBehaviour.h"
#include "WonderingGuard.h"
#include "FollowPathBehaviour.h"
#include <iostream>

WonderingGuard::WonderingGuard()
{
	m_followPathBehaviour = new FollowPathBehaviour();
	m_wonderBehaviour = new WonderBehaviour();

	SetBehaviour(m_wonderBehaviour);
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
	DrawCircle(m_position.x, m_position.y, 8, GREEN);

	DrawLine(m_position.x, m_position.y,
		targetHeading.x, targetHeading.y, DARKGRAY);
}
