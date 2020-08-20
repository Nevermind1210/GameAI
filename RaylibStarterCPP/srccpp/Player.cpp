#include "Player.h"
#include "KeyboardBehaviour.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include "WonderBehaviour.h"
#include "FollowPathBehaviour.h"
#include <iostream>
Player::Player()
{
	m_kbBehaviour = new KeyboardBehaviour();
	

	//Seek
	//m_seekBehaviour->SetTargetRadius(25.0f);
	//m_seekBehaviour->OnArrive([this]() {
	//	SetVelocity({ 0,0 }); // this slice of code is to STOP at radius when seeking
	//	SetBehaviour(m_kbBehaviour);// Swap back to WASD.
	//	});

	//Flee
	// m_fleeBehaviour->SetTargetRadius(100);


	//Wonder
	//m_wonderBehaviour->SetTargetRadius(14.0f);
	//m_wonderBehaviour->OnArrive([this]() {
	//	SetVelocity({ 0,0 }); // this slice of code is to STOP at radius when seeking
	//	});
	SetBehaviour(m_kbBehaviour);
}

Player::~Player()
{
	SetBehaviour(nullptr);

	delete m_kbBehaviour;
}

void Player::Update(float deltaTime)
{
	//You can insert any sort of logic that relates to the player
	//if (IsMouseButtonPressed(0))
	//{
	//	m_seekBehaviour->SetTarget(GetMousePosition());
	//	SetBehaviour(m_seekBehaviour);
	//}
	if (IsKeyPressed(KEY_I))
	{
		std::cout << GetPosition().x << std::endl;
	}
	if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_D))
	{
		SetBehaviour(m_kbBehaviour);
	}
	
	//if (IsMouseButtonDown(1))
	//{
	//	m_fleeBehaviour->SetTarget(GetMousePosition());
	//	SetBehaviour(m_fleeBehaviour);
	//}
	//if (IsKeyPressed(KEY_ONE))
	//{
	//	m_wonderBehaviour->SetTarget(GetMousePosition());
	//	SetBehaviour(m_wonderBehaviour);
	//}


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
