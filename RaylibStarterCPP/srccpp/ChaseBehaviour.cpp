#include "ChaseBehaviour.h"
#include "GameObject.h"
#include "Player.h"
#include "Graph2D.h"
ChaseBehaviour::ChaseBehaviour()
{
}

ChaseBehaviour::~ChaseBehaviour()
{
}

void ChaseBehaviour::Update(GameObject* obj, float deltaTime)
{
	if (!m_path.empty())
	{
		std::vector<Graph2D::Node*>GuardNode;
		m_graph->GetNearbyNodes(obj->GetPosition(), 40, GuardNode);
		std::vector<Graph2D::Node*>PlayerNode;
		m_graph->GetNearbyNodes(m_player->GetPosition(), 40, PlayerNode);
		std::list<Graph2D::Node*>PathFound;
		m_graph->FindPathAStar(GuardNode[0], PlayerNode[0], PathFound);

		std::vector<Vector2>FinalDes;

		for (auto node : PathFound)
		{
			FinalDes.push_back(node->data);
		}
	}
}

void ChaseBehaviour::Draw(GameObject* obj)
{

}

const std::vector<Vector2>& ChaseBehaviour::GetPath() const
{
	return m_path;
}

void ChaseBehaviour::SetPath(const std::vector<Vector2>& path)
{
	m_path = path;
}

const float& ChaseBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void ChaseBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}
