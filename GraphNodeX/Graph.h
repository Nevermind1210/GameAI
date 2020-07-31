#pragma once
#include <vector>
#include <functional>

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

	Node* AddNode(const TNodeData& data)
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

	Node* ForEachBFS(Node* startNode, std::function<bool(Node * n)> process)
	{
		std::vector<Node*>stack;
		std::vector<Node*>visted;
		if (startNode == nullptr)
		{
			startNode = m_nodes[0];
		}

		while (stack.empty() == false)
		{
			Node* n = stack.back();
			stack.pop_back();
			visted.push_back(n);

			process(n);

			for (Edge& edge: n->connections)
			{
				bool isStack = std::find(stack.begin(), stack.end(), edge.to) != stack.end();
				bool inVisted = std::find(visted.begin(), visted.end(), edge.to) != visted.end();
				if (isStack || inVisted) {
					continue;
				}
				stack.insert(stack.begin(), edge.to);
			}
		}
		return nullptr;
	}

	const std::vector<Node*>& GetNodes()
	{
		return m_nodes;
	}

protected:

	std::vector<Node*> m_nodes;
private:
};