#include "Player.h"
#include "KeyboardBehaviour.h"
#include <iostream>
Player::Player()
{
	m_kbBehaviour = new KeyboardBehaviour();
	SetBehaviour(m_kbBehaviour);
}

Player::~Player()
{
	SetBehaviour(nullptr);

	delete m_kbBehaviour;
}

void Player::Update(float deltaTime)
{
	if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_D))
	{
		SetBehaviour(m_kbBehaviour);
	}
	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		
	}
	GameObject::Update(deltaTime);
}

void Player::Draw()
{
	//GameObject::Draw();

	//Debug draw
	Vector2 targetHeading = Vector2Add(m_position, m_velocity);
	DrawCircle(m_position.x, m_position.y, 8, GRAY);

	DrawLine(m_position.x, m_position.y,
		targetHeading.x, targetHeading.y, DARKGRAY);
}
