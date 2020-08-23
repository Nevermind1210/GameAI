#include "Player.h"
#include "KeyboardBehaviour.h"
#include <iostream>
Player::Player()
{
	m_kbBehaviour = new KeyboardBehaviour();
	SetBehaviour(m_kbBehaviour);
	
	//Setting up the images.
	PlayerImg = LoadImage("../Sprites/player.png");
	PlayerTex = LoadTextureFromImage(PlayerImg);
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
	//Debug draw
	Vector2 targetHeading = Vector2Add(m_position, m_velocity);

	//This is the player texture.
	DrawTexture(PlayerTex, m_position.x - PlayerTex.width / 2, m_position.y - PlayerTex.width / 2, LIGHTGRAY);

	DrawLine(m_position.x, m_position.y,
		targetHeading.x, targetHeading.y, DARKGRAY);
}