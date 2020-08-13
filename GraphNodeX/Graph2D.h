#pragma once
#include "raymath.h"
#include "Graph.h"

class Graph2D : public Graph<Vector2, float>
{
public:

	Graph2D();
	virtual ~Graph2D();
	
	bool FindPath(Node* startNode, std::function<bool(Node*)>isGoalNode, std::list<Node*> out_path);
	void GetNearbyNodes(Vector2 position, float radius, std::vector<Graph2D::Node*>& out_nodes);

protected:
private:
};