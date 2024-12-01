#pragma once
#include "raylib.h"
namespace Logic {
	Camera camera;
	bool playing;
	void InitLogic() {
		camera = { 0 };
		camera.position = { 0.0f, 12.0f, 12.0f }; // Camera position
		camera.target = { 0.0f, 0.0f, 0.0f };     // Where the camera looks
		camera.up = { 0.0f, 1.0f, 0.0f };         // Up vector
		camera.fovy = 45.0f;                      // Field of view
	}
}