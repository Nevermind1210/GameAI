#pragma once
#include <vector>

template<class TNodeData, class TEdgeData>
class Graph
{
public:
	struct Edge;
	struct Node;

	//List
	struct Node
	{
		TNodeData data;
		std::vector<Edge> connections;

	};

	struct Edge
	{
		Node* to;
		TEdgeData data;
	};

public:
	// Constructor!
	Graph()
	{

	}
	//Destructor!
	virtual ~Graph()
	{
		for (auto node : m_nodes)
		{
			delete node;
		}
		m_nodes.clear();
	}

	Node* AddNodes(const TNodeData& data)
	{
		Node* node = new Node();
		node->data = data;

		m_nodes.push_back(node); // returns list
		return node;
	}

	void AddEdge(Node* nodeA, Node* nodeB, const TEdgeData& data)
	{
		nodeA->connections.push_back({nodeB, data});
	}

	const std::vector<Node*>& GetNodes()
	{
		return m_nodes;
	}

protected:

	std::vector<Node*> m_nodes;
private:
};