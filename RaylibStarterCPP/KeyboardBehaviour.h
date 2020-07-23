#pragma once
class KeyboardBehaviour
{
public:
	KeyboardBehaviour();
	virtual ~KeyboardBehaviour();

	void Update(GameObject* obj, float deltaTime);
	void SetKeys(int up, int down, int right, int left);
protected:
private:
};

