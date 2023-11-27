#include "pch.h"

#include "Script.h"

#include "../Squawk/Log.h"
#include "Branch.h"
#include <cassert>

using namespace std;
using namespace Perch;
using namespace Squawk;

Script::Script(Engine* engine)
{
	EngineRef = engine;
}

shared_ptr<Script> Script::GetScript(Script* script)
{
	return std::shared_ptr<Script>(script);
}

shared_ptr<Script> Script::GetScript()
{
	return GetScript(this);
}

void Script::Init(Engine* engine)
{}

void Script::Ready(Engine* engine)
{}

void Script::Update(Engine* engine)
{}

void Script::PhysicsUpdate(Engine* engine)
{}

void Script::Draw(Engine* engine, SDL_Renderer* renderer)
{}

void Script::OnDestroy(Engine* engine)
{}

void Script::OnCollision2D(Engine* engine, Collider2D* collider)
{}
