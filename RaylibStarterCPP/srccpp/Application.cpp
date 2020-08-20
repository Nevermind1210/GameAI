#include "Application.h"
#include "GameObject.h"
#include "Player.h"
#include "KeyboardBehaviour.h"
#include "raylib.h"
#include "Graph2D.h"
#include "Graph2DEditor.h"
#include "StandingGuard.h"
#include "PatrollingGuard.h"
#include "WonderingGuard.h"

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
	m_patrollingGuard->Update(deltaTime);
	m_wonderingGuard->Update(deltaTime);

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
	//Loading All Player related stuff
	auto player = new Player();
	player->SetPosition({ m_windowWidth * 0.25f , m_windowHeight / 2.0f });
	player->SetFriction(1.0f);
	m_player1 = player;

	//Loading All Standing Guard Stuff
	auto Sguard = new StandingGuard();
	Sguard = new StandingGuard();
	Sguard->SetPlayer(player);
	Sguard->SetGraph(m_graph);
	Sguard->SetPosition({ m_windowWidth * 0.45f , m_windowHeight / 2.0f });
	Sguard->SetFriction(1.0f);
	m_standingGuard = Sguard;

	//Loading All Patrolling Guard Stuff
	auto Pguard = new PatrollingGuard(); 
	Pguard->SetPosition({ m_windowWidth * 0.65f , m_windowHeight / 2.0f });
	Pguard->SetFriction(1.0f);
	m_patrollingGuard = Pguard;

	//Loading All Wondering Guard Stuff
	auto WGuard = new WonderingGuard();
	WGuard->SetPosition({ m_windowWidth * 0.95f , m_windowHeight / 5.0f });
	WGuard->SetFriction(1.0f);
	m_wonderingGuard = WGuard;


	//Node related stuff here. 
	m_graph = new Graph2D();
	
	m_graphEditor = new Graph2DEditor();

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
	m_patrollingGuard = nullptr;
	m_graphEditor = nullptr;
	m_graph = nullptr;
	delete m_player1;
	delete m_standingGuard;
	delete m_patrollingGuard;
	delete m_graphEditor;
	delete m_graph;
}


void Application::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	m_player1->Draw();
	m_standingGuard->Draw();
	m_patrollingGuard->Draw();
	m_wonderingGuard->Draw();
	m_graphEditor->Draw();

	m_graph = new Graph2D();


	EndDrawing();
}


