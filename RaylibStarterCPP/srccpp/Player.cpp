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
	m_seekBehaviour = new SeekBehaviour();
	m_wonderBehaviour = new WonderBehaviour();
	m_fleeBehaviour = new FleeBehaviour();
	m_followPathBehaviour = new FollowPathBehaviour();
	

	//Seek
	m_seekBehaviour->SetTargetRadius(25.0f);
	m_seekBehaviour->OnArrive([this]() {
		SetVelocity({ 0,0 }); // this slice of code is to STOP at radius when seeking
		SetBehaviour(m_kbBehaviour);// Swap back to WASD.
		});

	//Flee
	m_fleeBehaviour->SetTargetRadius(100);


	//Wonder
	m_wonderBehaviour->SetTargetRadius(14.0f);
	m_wonderBehaviour->OnArrive([this]() {
		SetVelocity({ 0,0 }); // this slice of code is to STOP at radius when seeking
		});
	SetBehaviour(m_kbBehaviour);
}

Player::~Player()
{
	SetBehaviour(nullptr);

	delete m_seekBehaviour;
	delete m_kbBehaviour;
	delete m_fleeBehaviour;
	delete m_wonderBehaviour;
	delete m_followPathBehaviour;
}

void Player::Update(float deltaTime)
{
	//You can insert any sort of logic that relates to the player
	if (IsMouseButtonPressed(0))
	{
		m_seekBehaviour->SetTarget(GetMousePosition() );
		SetBehaviour(m_seekBehaviour);
	}
	if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_D))
	{
		SetBehaviour(m_kbBehaviour);
	}
	if (IsMouseButtonDown(1))//len was here
	{
		m_fleeBehaviour->SetTarget(GetMousePosition());
		SetBehaviour(m_fleeBehaviour);
	}
	if (IsKeyPressed(KEY_ONE))
	{
		m_wonderBehaviour->SetTarget(GetMousePosition());
		SetBehaviour(m_wonderBehaviour);
	}
	if (IsKeyPressed(KEY_TWO))
	{
		std::vector<Vector2> hardCodedPath = {
			{10, 10}, {100, 10}, {200, 10}, {300, 10}, {400, 10}, {400, 100}, {400, 200}, {400, 300}, {400, 400}
		};

		m_followPathBehaviour->SetPath(hardCodedPath);
		SetBehaviour(m_followPathBehaviour);
	}
	std::cout << "This is X value: " << GetMousePosition().x << std::endl;
	std::cout << "This is Y value: " << GetMousePosition().y << std::endl;

	GameObject::Update(deltaTime);
}

void Player::Draw()
{
	GameObject::Draw();
}
