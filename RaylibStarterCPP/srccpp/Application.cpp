#include "Application.h"
#include "GameObject.h"
#include "Player.h"
#include "KeyboardBehaviour.h"
#include "raylib.h"
#include "Graph2D.h"
#include "Graph2DEditor.h"
#include "StandingGuard.h"

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
	m_standingGuard->Update(deltaTime);
	m_player3->Update(deltaTime);
	m_graphEditor->Update(deltaTime);

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
	m_standingGuard = new StandingGuard();
	m_player3 = new Player();
	m_graph = new Graph2D();
	m_graphEditor = new Graph2DEditor();
	m_player1->SetPosition({ m_windowWidth * 0.25f , m_windowHeight / 2.0f });
	m_standingGuard->SetPosition({ m_windowWidth * 0.45f , m_windowHeight / 2.0f });
	m_player3->SetPosition({ m_windowWidth * 0.65f , m_windowHeight / 2.0f });
	m_player1->SetFriction(1.0f);
	m_standingGuard->SetFriction(1.0f);
	m_player3->SetFriction(1.0f);

	int numRows = 23;
	int numCols = 41;
	float xOffSet = 30;
	float yOFSet = 30;
	float spacing = 30;

	for (int y = 0; y < numRows; y++)
	{
		for (int x = 0; x < numCols; x++)
		{
			m_graph->AddNode({
				x * spacing + xOffSet,
				y * spacing + yOFSet
				});
		}
	}

	for (auto node : m_graph->GetNodes())
	{
		std::vector<Graph2D::Node*> nearbyNodes;
		m_graph->GetNearbyNodes(node->data, 60, nearbyNodes);

		for (auto connectedNode : nearbyNodes)
		{
			if (connectedNode == node)
				continue;
			float dist = Vector2Distance(node->data, connectedNode->data);
			m_graph->AddEdge(node, connectedNode, dist);
			m_graph->AddEdge(connectedNode, node, dist);
		}
	}

	m_graphEditor = new Graph2DEditor();
	m_graphEditor->SetGraph(m_graph);
}

void Application::Unload()
{
	m_player1 = nullptr;
	m_standingGuard = nullptr;
	m_player3 = nullptr;
	m_graphEditor = nullptr;
	m_graph = nullptr;
	delete m_player1;
	delete m_standingGuard;
	delete m_player3;
	delete m_graphEditor;
	delete m_graph;
}


void Application::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	m_player1->Draw();
	m_standingGuard->Draw();
	m_player3->Draw();
	m_graphEditor->Draw();

	m_graph = new Graph2D();


	EndDrawing();
}


