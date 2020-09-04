#pragma once

class GameObject;
class Graph2D;
class Graph2DEditor;


class Application
{
public:
	Application(int windowWidth, int windowHeight, const char *title);
	~Application();

	virtual void Run();
	virtual void Update(float deltaTime);
	virtual void Draw();

	virtual void Load();
	virtual void Unload();

	Graph2D* GetGraph() { return m_graph;  }
	
protected:
private:

	int m_windowWidth;
	int m_windowHeight;
	const char* m_windowTitle;

	GameObject* m_player1 = nullptr;
	GameObject* m_standingGuard = nullptr;
	GameObject* m_patrollingGuard = nullptr;
	GameObject* m_wonderingGuard = nullptr;

	
	Graph2DEditor* m_graphEditor = nullptr;
	Graph2D* m_graph = nullptr;
	
};

