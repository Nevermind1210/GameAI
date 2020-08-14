#include "Graph2D.h"
#include "Graph.h"

Graph2D::Graph2D()
{
}

Graph2D::~Graph2D()
{
}

bool Graph2D::FindPathDijk(Node* startNode, std::function<bool(Node*)> isGoalNode, std::list<Node*> &out_path)
{
	//int currentStep = 0;
	std::list<PFNode*>stack;
	std::list<PFNode*>visted;
	
	//this is if there is a Node to find 
	auto GetNodeList = [&](Node* nodeToFind)->PFNode*
	{
		for (auto& n : stack)
			if (n->graphNode == nodeToFind)
				return n;
		for (auto& n : visted)
			if (n->graphNode == nodeToFind)
				return n;
		return nullptr; //else null
	};

	//Intializing values.
	PFNode* startPFNode = new PFNode();
	startPFNode->graphNode = startNode;
	startPFNode->gScore = 0;
	startPFNode->parent = nullptr;

	stack.push_back(startPFNode);

	while (stack.empty() == false)
	{
		stack.sort([&](PFNode* a, PFNode* b)
			{
				return a->gScore > b->gScore;
			});

		PFNode* currentNode = stack.back();
		stack.pop_back();
		visted.push_back(currentNode);

		if (isGoalNode(currentNode->graphNode))
		{
			// we have found what we are looking for
			// we need to calculate a path back to the start node
			// by tracking back through the "parent"
			PFNode* currentN = currentNode;
			while (currentN != nullptr)
			{
				out_path.push_back(currentN->graphNode);
				currentN = currentN->parent;
			}
			return true;
		}

		for (Edge& edge : currentNode->graphNode->connections)
		{
			float gScore = currentNode->gScore + edge.data;

			auto PFNodeChild = GetNodeList(edge.to);
			/*	bool isStack = std::find(stack.begin(), stack.end(), edge.to) != stack.end();
				bool inVisted = std::find(visted.begin(), visted.end(), edge.to) != visted.end();*/

			if (PFNodeChild == nullptr)
			{
				PFNode* PFNodeChild = new PFNode;
				PFNodeChild->parent = currentNode;
				PFNodeChild->graphNode = edge.to;
				PFNodeChild->gScore = gScore;

				stack.push_back(PFNodeChild);
			}
			else
			{
				if (PFNodeChild->gScore > gScore)
				{
					PFNodeChild->parent = currentNode;
					PFNodeChild->gScore = gScore;
				}
			}
		}
	}
	return false;
}

bool Graph2D::FindPath(Node* startNode, Node* endNode, std::list<Node*>& out_path)
{
	std::list<ANode*>stack;
	std::list<ANode*>visted;

	auto Heuristic(ANode*);


	//this is if there is a Node to find 
	auto GetNodeList = [&](Node* nodeToFind)->ANode*
	{
		for (auto& n : stack)
			if (n->graphNode == nodeToFind)
				return n;
		for (auto& n : visted)
			if (n->graphNode == nodeToFind)
				return n;
		return nullptr; //else null
	};

	//Intializing values.
	ANode* startANode = new ANode();
	startANode->graphNode = startNode;
	startANode->hScore = 0;
	startANode->fScore = 0;
	startANode->gScore = 0;

	startANode->prev = nullptr;

	stack.push_back(startANode);

	while (stack.empty() == false)
	{
		stack.sort([&](ANode* a, ANode* b)
			{
				return a->fScore > b->fScore;
			});

		ANode* currentNode = stack.back();
		stack.pop_back();
		visted.push_back(currentNode);

		if (currentNode->graphNode)
		{
			// we have found what we are looking for
			// we need to calculate a path back to the start node
			// by tracking back through the "parent"
			ANode* currentN = currentNode;
			while (currentN != nullptr)
			{
				out_path.push_back(currentN->graphNode);
				currentN = currentN->prev;
			}
			return true;
		}

		for (Edge& edge : currentNode->graphNode->connections)
		{
			float gScore = currentNode->gScore + edge.data;
			auto hScore = 
			float fScore = gScore + hScore;

			auto ANodeChild = GetNodeList(edge.to);

			if (ANodeChild == nullptr)
			{
				ANode* ANodeChild = new ANode;
				ANodeChild->prev = currentNode;
				ANodeChild->graphNode = edge.to;
				ANodeChild->gScore = gScore;

				stack.push_back(ANodeChild);
			}
			else
			{
				if (ANodeChild->fScore > gScore)
				{
					ANodeChild->prev = currentNode;
					ANodeChild->gScore = gScore;
				}
			}
		}
	}
	return false;
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

