#pragma once
#include "raymath.h"
#include "Behaviour.h"
#include <list>
#include <vector>
struct Edge {
	Node* target;
	float cost;
};

struct Node {
	Vector2 pos;

	float gScore;
	Node* parent;

	std::vector<Edge> connections;
};

class FollowPathBehaviour : public Behaviour
{
public:

	FollowPathBehaviour();
	virtual ~FollowPathBehaviour();
	
	virtual void dijkstrasSearch(Node* startNode, const std::list<Node*> &endNodes, std::list<Node*> &outPath);
	virtual void Update(GameObject* obj, float deltaTime);
	virtual void Draw(GameObject* obj);

	const Vector2& GetTarget() const;
	void SetTarget(const Vector2& target);

	const float& GetTargetRadius() const;
	void SetTargetRadius(const float& radius);

protected:
	Vector2 m_target;
	float m_targetRadius = 1.0f;
private:
};