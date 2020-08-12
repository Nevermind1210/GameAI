#include "Graph2D.h"

Graph2D::Graph2D()
{
}

Graph2D::~Graph2D()
{
}

void Graph2D::GetNearbyNodes(Vector2 position, float radius, std::vector<Graph2D::Node*>& out_nodes)
{
	for (auto node : m_nodes)
	{
		float dist = Vector2Distance(position, node->data);
		if (dist < radius)
		{
			out_nodes.push_back(node);
		}
	}
}

bool Graph2D::FindPath(Node* startNode, std::function<bool(Node*)>isGoalNode, std::list<Node*> out_path)
{
	//stubbing for the Dijstra's short path
	//Its similar to the BFS and DFS too! But now I need to refactor it into a lengthier version.
	std::list<Node*>stack;
	std::list<Node*>visted;
	if (startNode == nullptr)
	{
		startNode = m_nodes[0];
	}


	
}