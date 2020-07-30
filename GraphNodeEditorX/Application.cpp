#include "Application.h"
#include "GameObject.h"
#include "Player.h"
#include "KeyboardBehaviour.h"
#include "raylib.h"

Application::Application(int windowWidth, int windowHeight , const char *title) :
	m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_windowTitle(title)
{

}

Application::~Application()
{
}


void Application::Update(float deltaTime)
{

	m_player1->Update(deltaTime);

}


void Application::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, m_windowTitle);
	SetTargetFPS(60);

	Load();

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();
		Update(dt);
		Draw();
	}

	Unload();

	CloseWindow();        // Close window and OpenGL context
}

void Application::Load()
{
	m_player1 = new Player();
	m_player1->SetPosition({ m_windowWidth * 0.25f , m_windowHeight / 2.0f });
	m_player1->SetFriction(1.0f);


	//m_player->SetBehaviour (new SeekBehaviour());
	//m_player->SetBehaviour (new FleeBehaviour());


}

void Application::Unload()
{
	delete m_player1;
	m_player1 = nullptr;

}


void Application::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	m_player1->Draw();

	EndDrawing();
}


