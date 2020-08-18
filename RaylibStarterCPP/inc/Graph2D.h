#pragma once
#include "raymath.h"
#include "Graph.h"

class Graph2D : public Graph<Vector2, float>
{
public:

	Graph2D();
	virtual ~Graph2D();

	bool FindPathDijk(Node* startNode, std::function<bool(Node*)>isGoalNode, std::list<Node*>& out_path);
	bool FindPathAStar(Node* startNode, Node* endNode, std::list<Node*>& out_path);
	void GetNearbyNodes(Vector2 position, float radius, std::vector<Graph2D::Node*>& out_nodes);

protected:

	struct PFNode
	{
		Node* graphNode;
		PFNode* parent;
		float gScore;
		float hScore;
		float fScore;
	};

private:
};