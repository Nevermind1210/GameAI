#include "StandingGuard.h"
#include "FollowPathBehaviour.h"
#include "Player.h"
#include <iostream>
StandingGuard::StandingGuard()
{
	m_followPathBehaviour = new FollowPathBehaviour();
	m_player = new Player();
}

StandingGuard::~StandingGuard()
{
	SetBehaviour(nullptr);

	delete m_followPathBehaviour;
}

void StandingGuard::Update(float deltaTime)
{
	//You can insert any sort of logic that relates to the player
	if (IsKeyPressed(KEY_TWO))
	{
		std::vector<Vector2> hardCodedPath = {
			{10, 10}, {200, 10}, {300, 10}, {400, 10}, {400, 100}, {400, 200}, {400, 300}, {400, 400}
		};
		m_followPathBehaviour->SetPath(hardCodedPath);
		SetBehaviour(m_followPathBehaviour);
	}
	if (m_player->GetPosition())

	GameObject::Update(deltaTime);
}

void StandingGuard::Draw()
{
	GameObject::Draw();

	//Debug draw
	Vector2 targetHeading = Vector2Add(m_position, m_velocity);
	DrawCircle(m_position.x, m_position.y, 8, RED);

	DrawLine(m_position.x, m_position.y,
		targetHeading.x, targetHeading.y, DARKGRAY);
}
