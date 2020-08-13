#include "Graph2D.h"

Graph2D::Graph2D()
{
}

Graph2D::~Graph2D()
{
}

bool Graph2D::FindPath(Node* startNode, std::function<bool(Node*)> isGoalNode, std::list<Node*> out_path)
{
	//Intializing values.
	std::list<Node*>stack;
	std::list<Node*>visted;
	int currentStep = 0;

	PFNode* startPFNode = new PFNode();
	Node* endNode = nullptr;

	startPFNode->gScore = 0;
	startPFNode->parent = nullptr;

	stack.push_back(startNode);

	while (stack.empty() == false)
	{
		visted.sort(startPFNode->gScore);

		Node* n = stack.back();
		if (n == endNode)
			return false;

		n = nullptr;
		delete n;

		n = visted.back();

		for (auto it = out_path.begin(); it != out_path.end(); it++) {
			if (n == *it) {
				endNode = n;
				break;
			}
		}

		visted.push_back(n);

		for (auto it = n->connections.begin(); it != n->connections.end(); it++) {
			Node* connection = (*it).to;
			if (connection == nullptr)
				continue;

			for (Edge& edge : n->connections)
			{
				bool isStack = std::find(stack.begin(), stack.end(), edge.to) != stack.end();
				bool inVisted = std::find(visted.begin(), visted.end(), edge.to) != visted.end();
				if (isStack || inVisted) {
					continue;
				}
				stack.insert(stack.begin(), edge.to);
			}

			std::list<PFNode*> Path;
			n = endNode;

			while (startPFNode != nullptr)
			{
				Path.push_back(startPFNode);
				startPFNode = startPFNode->parent;
			}
		}
		return;
	}
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

