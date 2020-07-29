#pragma once

class GameObject;

class Application
{
public:
	Application(int windowWidth, int windowHeight, const char* title);
	~Application();

	virtual void Run();
	virtual void Update(float deltaTime);
	virtual void Draw();

	virtual void Load();
	virtual void Unload();


protected:
private:

	int m_windowWidth;
	int m_windowHeight;
	const char* m_windowTitle;
};

