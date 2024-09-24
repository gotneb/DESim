#include "and.h"

void AndGate::Update() 
{
    CheckMoveState();
    if (canFollowMouse_) {
        Move();
    }
}

void AndGate::Draw()
{
    // Debug
    DrawText(
        std::format("BOX: ({}, {})", X(), Y()).c_str(),
        GetScreenWidth() - 300, 10, 20, BLACK
    );
    DrawText(
        std::format("MOUSE: ({}, {})", GetMousePosition().x, GetMousePosition().y).c_str(), 
        GetScreenWidth() - 300, 30, 20, RED
    );

    DrawTextureV(texture_, Position(), RAYWHITE);
    // That's for debug
    if (IsMouseInside())
    {
        DrawRectangleLines(
            X(), Y(),
            Width(), Height(),
            RED
        );
    }
}

bool AndGate::IsMouseInside() const
{
    return CheckCollisionPointRec(
        GetMousePosition(),
        {X(), Y(), Width(), Height()}
    );
}

void AndGate::CheckMoveState()
{
    if (IsMouseInside() && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        canFollowMouse_ = true;
    } else if (IsMouseButtonUp(MOUSE_BUTTON_LEFT) && canFollowMouse_) {
        canFollowMouse_ = false;
    }
}

void AndGate::Move()
{
    auto mouse_x = GetMousePosition().x;
    auto mouse_y = GetMousePosition().y;
    auto x = mouse_x - Width() / 2;
    auto y = mouse_y - Height() / 2;
    // Only moviments into the X and Y axis
    x = int(x/34.0f)*34.0f;
    y = int(y/34.0f)*34.0f;
    SetPosition({ x, y});
}