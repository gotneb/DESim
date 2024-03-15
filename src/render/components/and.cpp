#include "and.h"

void AndGate::Draw()
{
    DrawTextureV(texture_, position_, RAYWHITE);
    // That's for debug
    // DrawRectangleLines(
    //     position_.x, position_.y,
    //     64, 64,
    //     RED
    // );
}