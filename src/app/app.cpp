#include "app.h"

void App::Run() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width_, height_, title_.c_str());
    MaximizeWindow();

    SetTargetFPS(kFPS);

    while (!WindowShouldClose())
    {
        // Update
        // =================================
        board_.Update();

        // Draw
        // ==================================
        BeginDrawing();
        board_.Draw();
        EndDrawing();
    }

    Close();
}

void App::Close() const {
    CloseWindow();
}