#pragma once
#include "raylib.h"
#include <vector>
namespace Paddle {
	Vector3 vectors[] = { {0.0f, 0.0f, 6.0f}, {0.0f, 0.0f, -7.0f} };
	const Vector3 PaddleSize = { 5.0f, 1.0f, 1.0f };
    std::vector<std::pair<Vector3, Vector3>> MinsAndMaxes(float margin) {
        std::vector<std::pair<Vector3, Vector3>> mins_and_maxes;

        // Loop through each paddle
        for (const auto& paddle : vectors) {
            // Compute the minimum and maximum bounds
            Vector3 min = {
                paddle.x - (PaddleSize.x / 2),
                paddle.y - (PaddleSize.y / 2),
                paddle.z - (PaddleSize.z / 2)
            };
            Vector3 max = {
                paddle.x + (PaddleSize.x / 2),
                paddle.y + (PaddleSize.y / 2),
                paddle.z + (PaddleSize.z / 2)
            };

            min.x -= margin;
            min.y -= margin;
            min.z -= margin;
            max.x += margin;
            max.y += margin;
            max.z += margin;

            // Store the pair of bounds in the vector
            mins_and_maxes.push_back({ min, max });
        }

        return mins_and_maxes;
    }

}