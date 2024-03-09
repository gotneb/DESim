#include "app.h"

void App::Run() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width_, height_, title_.c_str());
    MaximizeWindow();

    SetTargetFPS(kFPS);

    while (!WindowShouldClose()) {
        // Update
        // =================================
        MoveCamera();
        ApplyZoom();
        board_.Update();

        // Draw
        // ==================================
        BeginDrawing();
        BeginMode2D(camera_);

        board_.Draw();

        EndMode2D();
        EndDrawing();
    }

    Close();
}

void App::ApplyZoom() {
    auto scroll = GetMouseWheelMove();
    if (scroll == 0) return;

    /*
     * The following was extracted direct from raylib examples
     */

    auto mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera_);
    camera_.offset = GetMousePosition();
    camera_.target = mouseWorldPos;
    const float zoomIncrement = 0.125f;
    camera_.zoom += scroll * zoomIncrement;

    if (camera_.zoom < zoomIncrement) camera_.zoom = zoomIncrement;
}

void App::MoveCamera() {
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        auto delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f/camera_.zoom);
        if (delta.x == 0 && delta.y == 0) return;

        camera_.target = Vector2Add(camera_.target, delta);
    }
}

void App::Close() const {
    CloseWindow();
}