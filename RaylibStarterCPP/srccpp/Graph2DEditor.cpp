#include "Graph2DEditor.h"
#include "Graph2D.h"
#include <iostream>

Graph2DEditor::Graph2DEditor()
{

}

Graph2DEditor::~Graph2DEditor()
{

}

void Graph2DEditor::Update(float deltaTime)
{
	/*std::cout << "This is X value: " << GetMousePosition().x << std::endl;
	std::cout << "This is Y value: " << GetMousePosition().y << std::endl;*/
	if (IsMouseButtonPressed(KEY_N))
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
	if (IsMouseButtonPressed(KEY_K))
	{
		//get the first node that we click on.
		std::vector<Graph2D::Node*> neighbouringNodes;
		m_graph->GetNearbyNodes(GetMousePosition(), 8, neighbouringNodes);
		if (neighbouringNodes.empty() == false)
		{
			if (m_startNode == nullptr) m_startNode = neighbouringNodes[0];
			else if (m_endNode == nullptr) m_endNode = neighbouringNodes[0];
			else { m_startNode = neighbouringNodes[0]; m_endNode = nullptr; }
			//Begin Search
			std::list<Graph2D::Node*> path; // stores the path
			auto isGoalNode = [this](Graph2D::Node* node) {
				return node == m_endNode;
			};
			//call the FindPath method
			std::list<Graph2D::Node*> Path;
			std::vector<Graph2D::Node*> NearbyStartNode;
			GetGraph()->GetNearbyNodes({ 100,100 }, 30, NearbyStartNode);
			std::vector<Graph2D::Node*> NearbyGoalNode;
			GetGraph()->GetNearbyNodes({ 350,250 }, 30, NearbyGoalNode);

			if (m_endNode != nullptr && m_graph->FindPathAStar(NearbyStartNode[0], NearbyGoalNode[0], path) == true)
			{
				//populate the std::vector<Vetor2> path with our path data.
				m_path.clear();
				for (auto pathnode : path)
				{
					m_path.push_back(pathnode->data);
				}
			}
		}
	}
	if (IsKeyPressed(KEY_TAB))
	{

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

	if (m_startNode != nullptr)
	{
		DrawCircle(m_startNode->data.x, m_startNode->data.y, 6, GREEN);
	}
	if (m_endNode != nullptr)
	{
		DrawCircle(m_endNode->data.x, m_endNode->data.y, 4, RED);
	}
	if (!m_path.empty())
	{
		for (int i = 0; i < m_path.size() - 1; i++)
		{
			DrawLineEx(m_path[i], m_path[i + 1], 5, GREEN);
		}
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
