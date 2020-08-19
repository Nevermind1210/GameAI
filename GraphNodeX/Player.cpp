#include "Player.h"
#include "KeyboardBehaviour.h"
//#include "SeekBehaviour.h"

Player::Player()
{
	m_kbBehaviour = new KeyboardBehaviour();
}

Player::~Player()
{
	SetBehaviour(nullptr);

	//delete m_seekBehaviour;
	delete m_kbBehaviour;
}

void Player::Update(float deltaTime)
{
	//You can insert any sort of logic that relates to the player
	if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_D))
	{
		SetBehaviour(m_kbBehaviour);
	}

	GameObject::Update(deltaTime);
}

void Player::Draw()
{
	GameObject::Draw();
}
