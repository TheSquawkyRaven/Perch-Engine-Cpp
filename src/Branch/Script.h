#pragma once

#ifdef PERCHENGINECPP_EXPORTS
#define PERCH_API __declspec(dllexport)
#else
#define PERCH_API __declspec(dllimport)
#endif


// Main SDL Window
#include <SDL.h>

#include "../Engine.h"

#include <memory>

namespace Perch
{

	// For bool return functions, true represents success
	class Script
	{

		// # Variables + Getters/Setters

	private:


	protected:

		Engine* EngineRef;

	public:



		// ###


		// # Functions

	private:


	public:

		PERCH_API Script(Engine* engine);

		// Init - Called right after constructor is ran, from Engine::CreateScript
		PERCH_API virtual void Init(Engine* engine);

		// Ready - Preorder, Called upon attaching to a branch of the main tree or when the tree is run. Only called once
		PERCH_API virtual void Ready(Engine* engine);

		// Update - Preorder, Called every frame
		PERCH_API virtual void Update(Engine* engine);

		// Update - Preorder, Called every frame after update, before draw
		PERCH_API virtual void PhysicsUpdate(Engine* engine);

		// Draw - Preorder, Called every frame. Update first, then draw
		PERCH_API virtual void Draw(Engine* engine, SDL_Renderer* renderer);

		// OnDestroy - POSTorder, Called while destroying. Uninitialize pointers here.
		PERCH_API virtual void OnDestroy(Engine* engine);

		// OnCollision2D - Called when it receives a collision2D event
		PERCH_API virtual void OnCollision2D(Engine* engine, Collider2D* collider);
		
		// ###
	};
}
