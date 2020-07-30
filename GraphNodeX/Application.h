#pragma once

class GameObject;
class Graph2D;
class Graph2DEditor;

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

	Graph2DEditor* m_graphEditor = nullptr;
	Graph2D* m_graph = nullptr;
};

