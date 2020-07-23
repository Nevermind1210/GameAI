#include "KeyboardBehaviour.h"
#include "GameObject.h"
#include "raylib.h"

KeyboardBehaviour::KeyboardBehaviour()
{
}

KeyboardBehaviour::~KeyboardBehaviour()
{
}

void KeyboardBehaviour::Update(GameObject* obj, float deltaTime)
{
    if (IsKeyDown(KEY_A)) obj->ApplyForce({ -1000, 0 });
    if (IsKeyDown(KEY_D)) obj->ApplyForce({ 1000, 0 });
    if (IsKeyDown(KEY_W)) obj->ApplyForce({ 0,  -1000 });
    if (IsKeyDown(KEY_S)) obj->ApplyForce({ 0,   1000 });
}

void KeyboardBehaviour::SetKeys(int up, int down, int right, int left)
{
   
}
