#include "Application.h"
#include "GameObject.h"
#include "KeyboardBehaviour.h"
#include "raylib.h"

Application::Application(int windowWidth, int windowHeight) :
	m_windowWidth(windowWidth), m_windowHeight(windowHeight)
{

}

Application::~Application()
{
}

void Application::Load()
{
	auto kb1 = new KeyboardBehaviour();
	kb1->SetKeys(KEY_W, KEY_S, KEY_A, KEY_D);

	auto kb2 = new KeyboardBehaviour();
	kb2->SetKeys(KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT);

	m_player1 = new GameObject();
	m_player1->SetFriction(1.0f);
	m_player1->SetPosition({ m_windowWidth * 0.25f, m_windowHeight * 0.5f });
	m_player1->SetBehaviour(kb1);

	m_player2 = new GameObject();
	m_player2->SetFriction(1.0f);
	m_player2->SetPosition({ m_windowWidth * 0.25f, m_windowHeight * 0.5f });
	m_player2->SetBehaviour(kb1);
	
}

void Application::Unload()
{
	delete m_player1; m_player1 = nullptr;
	delete m_player2; m_player2 = nullptr;
}

void Application::Update(float deletaTime)
{
	m_player1->Update(deletaTime);
	m_player2->Update(deletaTime);
}


void Application::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "AIE Game State Manager Tut!");

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();
		Update(dt);
		Draw();
	}

	CloseWindow();        // Close window and OpenGL context
}


void Application::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

	EndDrawing();
}


