#include "Player.h"

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
	//You can insert any sort of logic that relates to the player


	GameObject::Update(deltaTime);
}

void Player::Draw()
{
	GameObject::Draw();
}
