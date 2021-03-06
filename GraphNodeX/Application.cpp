#include "Application.h"
#include "GameObject.h"
#include "raylib.h"
#include "Graph2D.h"
#include "Graph2DEditor.h"

Application::Application(int windowWidth, int windowHeight, const char* title) :
	m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_windowTitle(title)
{

}

Application::~Application()
{
}


void Application::Update(float deltaTime)
{
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

	m_graph = new Graph2D();

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
	delete m_graphEditor;
	m_graphEditor = nullptr;

	delete m_graph;
	m_graph = nullptr;
}


void Application::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	m_graphEditor->Draw();

	EndDrawing();
}

//TODO;
// - Fix hard coded "60"  value representing the radius of our nearby nodes connecting
// - add variable to customise the Graph2DEditior
// - - Node color
// - - Node outline
// - - line color
// - - node radius

// - Prevent nodes node spammed on top of each other


//IF ALL ABOVE IS DONE OR HALF WAY DONE ATTEMPT SAVING NODE POSITIONS

//SAVE EITHER IN XML, JSON, OR CUSTOM BINARY FILE (like in the database assessment)