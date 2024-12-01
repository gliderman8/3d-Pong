#pragma once
#include "raylib.h"
#include <cmath>
#include <vector>
#include <iostream>
namespace Ball {
    Vector3 BallPosition = { 0.0f, 1.0f, 0.0f };
    Vector3 BallVelocity = { 0.0f, 0.0f, 0.1f };
    const float BallRadius = 0.5f;
    bool bounced = false;
    bool DetectPaddle(Vector3 paddleMin, Vector3 paddleMax) {
        // Find the closest point on the paddle to the sphere's center
        float closestX = fmaxf(paddleMin.x, fminf(BallPosition.x, paddleMax.x));
        float closestY = fmaxf(paddleMin.y, fminf(BallPosition.y, paddleMax.y));
        float closestZ = fmaxf(paddleMin.z, fminf(BallPosition.z, paddleMax.z));

        // Calculate the distance between the sphere center and the closest point
        float distance = sqrtf(
            (BallPosition.x - closestX) * (BallPosition.x - closestX) +
            (BallPosition.y - closestY) * (BallPosition.y - closestY) +
            (BallPosition.z - closestZ) * (BallPosition.z - closestZ)
        );

        // Check if the distance is less than or equal to the sphere radius
        return distance <= BallRadius;
    }
    void FlipIfCollision(Vector3 paddleMin, Vector3 paddleMax) {
        if (DetectPaddle(paddleMin, paddleMax)) {
            BallPosition.y += 0.5;
            BallVelocity.z *= -1.01;
        }
    }
    void UpdateBall() {
        BallPosition.x += BallVelocity.x;
        BallPosition.y += BallVelocity.y;
        BallPosition.z += BallVelocity.z;
        //Ball isn't going up, so it's going down
        if (!bounced) {
            if (BallVelocity.y > -1.0f) {
                BallVelocity.y -= 0.05f;
            }
            if (BallPosition.y - BallRadius <= 0) {
                bounced = true;
            }
        }
        //Ball touched the ground and it's now going up
        else {
            bounced = false;
            BallVelocity.y = 0.5f;
            BallVelocity.z += -BallVelocity.z * 0.01f;
        }
    }
}