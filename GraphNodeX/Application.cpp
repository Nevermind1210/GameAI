#include "Application.h"
#include "GameObject.h"
#include "KeyboardBehaviour.h"
#include "raylib.h"

Application::Application(int windowWidth, int windowHeight, const char* title) :
	m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_windowTitle(title)
{

}

Application::~Application()
{
}


void Application::Update(float deltaTime)
{


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

	//m_player->SetBehaviour (new SeekBehaviour());
	//m_player->SetBehaviour (new FleeBehaviour());


}

void Application::Unload()
{

}


void Application::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	EndDrawing();
}


