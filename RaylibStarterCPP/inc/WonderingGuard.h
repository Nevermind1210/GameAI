#pragma once
#include "GameObject.h"

class WonderBehaviour;
class ChaseBehaviour;

class WonderingGuard : public GameObject
{
public:
	WonderingGuard(Application* app);
	virtual ~WonderingGuard();

	void SetPlayer(Player* player)
	{
		m_player = player;
	}

	virtual void Update(float deltaTime);
	virtual void Draw();
protected:
	float m_guardRadius = 200.0f;

	Player* m_player;
	WonderBehaviour* m_wonderBehaviour;
	ChaseBehaviour* m_chaseBehaviour;
private:

	Image WGuardImg;
	Texture2D WGuardTex;
};

