#include "Graph2DEditor.h"
#include "Graph2D.h"

Graph2DEditor::Graph2DEditor()
{

}

Graph2DEditor::~Graph2DEditor()
{

}

void Graph2DEditor::Update(float deltaTime)
{
	if (IsMouseButtonPressed(0))
	{
		auto mousePos = GetMousePosition();

		auto newNode = m_graph->AddNode(mousePos);

		std::vector<Graph2D::Node*> nearbyNodes;
		m_graph->GetNearbyNodes(mousePos, 60, nearbyNodes);

		for (auto nearbyNodes : nearbyNodes)
		{
			float dist = Vector2Distance(newNode->data, nearbyNodes->data);
			m_graph->AddEdge(newNode, nearbyNodes, dist);
			m_graph->AddEdge(nearbyNodes, newNode, dist);

		}

	}
}

void Graph2DEditor::Draw()
{
	//Debugging draw connections
	for (auto node : m_graph->GetNodes())
	{
		for (auto connection : node->connections)
		{
			DrawLine(node->data.x, node->data.y, connection.to->data.x, connection.to->data.y, GRAY);
		}
	}

	// Drawing all Nodes.
	for (auto node : m_graph->GetNodes())
	{
		DrawCircle(node->data.x, node->data.y, 8, LIGHTGRAY);
		DrawCircleLines(node->data.x, node->data.y, 8, RED);
	}

	//Draw a "Preview" node where mouse is.

	auto mousePos = GetMousePosition();
	DrawCircle(mousePos.x, mousePos.y, 8, LIGHTGRAY);

	std::vector<Graph2D::Node*> nearbyNodes;
	m_graph->GetNearbyNodes(mousePos, 60, nearbyNodes);

	for (auto nearbyNodes : nearbyNodes)
	{
		DrawLine(mousePos.x, mousePos.y, nearbyNodes->data.x, nearbyNodes->data.y, LIGHTGRAY);
	}

}


Graph2D* Graph2DEditor::GetGraph()
{
	return m_graph;
}

void Graph2DEditor::SetGraph(Graph2D* graph)
{
	m_graph = graph;
}
