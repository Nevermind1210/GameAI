#include "Player.h"
#include "KeyboardBehaviour.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include"WonderBehaviour.h"
Player::Player()
{
	m_kbBehaviour = new KeyboardBehaviour();
	m_seekBehaviour = new SeekBehaviour();
	m_seekBehaviour->SetTargetRadius(25.0f);
	m_seekBehaviour->OnArrive([this]() {
		SetVelocity({ 0,0 }); // this slice of code is to STOP at radius when seeking
		SetBehaviour(m_kbBehaviour);// Swap back to WASD.
		});
	m_fleeBehaviour = new FleeBehaviour();
	m_fleeBehaviour->SetTargetRadius(100);
	SetBehaviour(m_kbBehaviour);
}

Player::~Player()
{
	SetBehaviour(nullptr);

	delete m_seekBehaviour;
	delete m_kbBehaviour;
	delete m_fleeBehaviour;
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
	if (IsKeyPressed(KEY_ONE))//len was here
	{
		m_wonderBehaviour->SetTarget();
		SetBehaviour(m_wonderBehaviour);
	}
	

	GameObject::Update(deltaTime);
}

void Player::Draw()
{
	GameObject::Draw();
}
