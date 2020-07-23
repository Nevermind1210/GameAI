#pragma once
class Application
{
public:
	Application(int windowWidth, int windowHeight);
	~Application();

	virtual void Run();
	virtual void Update(float deletaTime);
	virtual void Draw();

	virtual void Load();
	virtual void Unload();

	
protected:
private:

	void m_player1;
	void m_player2;


	int m_windowWidth;
	int m_windowHeight;

};

