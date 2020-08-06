/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include "Graph.h"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

#include "Application.h"
#include <iostream>

void TestGraph()
{
    // setup
    Graph<char, int> graph;
    auto a = graph.AddNode('A');
    auto b = graph.AddNode('B');
    auto c = graph.AddNode('C');
    auto d = graph.AddNode('D');
    auto e = graph.AddNode('E');
    auto f = graph.AddNode('F');
    auto g = graph.AddNode('G');
    auto h = graph.AddNode('H');
    auto i = graph.AddNode('I');
    graph.AddEdge(a, b, 0); graph.AddEdge(b, a, 0);     // AB
    graph.AddEdge(a, i, 0); graph.AddEdge(i, a, 0);     // AS
    graph.AddEdge(c, i, 0); graph.AddEdge(i, c, 0);     // SC
    graph.AddEdge(g, i, 0); graph.AddEdge(i, g, 0);     // SG
    graph.AddEdge(f, c, 0); graph.AddEdge(c, f, 0);     // FC
    graph.AddEdge(f, g, 0); graph.AddEdge(g, f, 0);     // FG
    graph.AddEdge(d, c, 0); graph.AddEdge(c, d, 0);     // CD
    graph.AddEdge(c, e, 0); graph.AddEdge(e, c, 0);     // CE
    graph.AddEdge(g, h, 0); graph.AddEdge(h, g, 0);     // GH
    graph.AddEdge(e, h, 0); graph.AddEdge(h, e, 0);     // EH
    // This is a BFS traversal.
    // if the method returns true, the traversal will stop
    // if the method returns false, the traversal will continue
    graph.ForEachBFS(nullptr, [](Graph<char, int>::Node* node) {
        std::cout << node->data << std::endl;
        return false;
        });
    std::cout << "------------" << std::endl;
    // This is a BFS traversal.
    // if the method returns true, the traversal will stop
    // if the method returns false, the traversal will continue
    graph.ForEachDFS(f, [](Graph<char, int>::Node* node) {
        std::cout << node->data << std::endl;
        return false;
        });

    system("pause");
}


int main(int argc, char* argv[])
{
    TestGraph();
    {
        Application app(800, 450, "Game AI");
        app.Run();
    }

    return 0;
}