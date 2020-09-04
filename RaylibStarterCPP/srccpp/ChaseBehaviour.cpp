#include "ChaseBehaviour.h"
#include "GameObject.h"
#include "Player.h"
#include "Graph2D.h"
#include "Application.h"

ChaseBehaviour::ChaseBehaviour()
{
}

ChaseBehaviour::~ChaseBehaviour()
{
}

void ChaseBehaviour::Update(GameObject* obj, float deltaTime)
{

	auto graph = obj->GetApp()->GetGraph();

	std::vector<Graph2D::Node*>GuardNode;
	graph->GetNearbyNodes(obj->GetPosition(), 40, GuardNode);
	std::vector<Graph2D::Node*>PlayerNode;
	graph->GetNearbyNodes(m_target, 40, PlayerNode);
	std::list<Graph2D::Node*>PathFound;
	graph->FindPathAStar(GuardNode[0], PlayerNode[0], PathFound);

	std::vector<Vector2>FinalDes;

	for (auto node : PathFound)
	{
		FinalDes.push_back(node->data);
	}

	m_path = FinalDes;

	if (!m_path.empty())
	{
		float distToTarget = Vector2Distance(obj->GetPosition(), m_path[0]);
		if (distToTarget < m_targetRadius) {
			m_path.push_back(m_path[0]);
			m_path.erase(m_path.begin());
		}
		Vector2 heading = Vector2Add(obj->GetPosition(), obj->GetVelocity());
		float headingLen = 500.0f;

		Vector2 dirToTarget = Vector2Normalize(Vector2Subtract(m_path[0], obj->GetPosition()));
		Vector2 vecToTarget = Vector2Scale(dirToTarget, headingLen);

		Vector2 targetForcePos = Vector2Add(vecToTarget, obj->GetPosition());
		Vector2 forceDir = Vector2Subtract(targetForcePos, heading);

		obj->ApplyForce(forceDir);
	}
	
}

void ChaseBehaviour::Draw(GameObject* obj)
{
	//For debugging to see the path of the Guards.
	if (IsKeyDown(KEY_TAB))
	{
		DrawCircle(m_path[0].x, m_path[0].y, m_targetRadius, { 0,255,0,100 });
		for (int i = 0; i < m_path.size() - 1; i++)
		{
			DrawLineEx(m_path[i], m_path[i + 1], 5, RED);
		}
	}
}

const Vector2& ChaseBehaviour::GetTarget() const
{
	return m_target;
}

void ChaseBehaviour::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& ChaseBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void ChaseBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}

