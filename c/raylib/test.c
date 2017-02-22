#include <stdio.h>
#include <raylib.h>

int main()
{
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);

    while(!WindowShouldClose()) {

        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 0.8f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 0.8f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 0.8f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 0.8f;

    BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawCircleV(ballPosition, 50, MAROON);

    EndDrawing();
    }

    CloseWindow();
    return 0;
}

