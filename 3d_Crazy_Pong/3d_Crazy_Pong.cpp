// 3d_Crazy_Pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "raylib.h"
#include "Logic.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
int main()
{
	InitWindow(800, 600, "Crazy Pong");
	SetTargetFPS(60);
	Logic::InitLogic();
	while (!WindowShouldClose()) {
		Ball::FlipIfCollision(Paddle::MinsAndMaxes(1.1).at(0).first, Paddle::MinsAndMaxes(1.1).at(0).second);
		Ball::FlipIfCollision(Paddle::MinsAndMaxes(1.1).at(1).first, Paddle::MinsAndMaxes(1.1).at(1).second);
		Ball::UpdateBall();
		BeginDrawing();
		DrawRectangle(0, 0, 800, 600, BLUE);
		ClearBackground(BLANK);
		BeginMode3D(Logic::camera);
		DrawGrid(12, 1.5f);
		DrawSphere(Ball::BallPosition, Ball::BallRadius, WHITE);
		DrawCube(Paddle::vectors[0], 5.0f, 1.0f, 1.0f, WHITE);
		DrawCube(Paddle::vectors[1], 5.0f, 1.0f, 1.0f, WHITE);
		EndMode3D();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
