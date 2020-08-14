#pragma once
#include "Graph2D.h"

class Graph2D;

class Graph2DEditor
{
public:
	Graph2DEditor();
	~Graph2DEditor();

	void Update(float deltaTime);
	void Draw();

	Graph2D* GetGraph();
	void SetGraph(Graph2D* graph);

	std::vector<Vector2> m_path;
protected:

	Graph2D* m_graph;
	Graph2D::Node* m_startNode;
	Graph2D::Node* m_endNode;


private:
};

