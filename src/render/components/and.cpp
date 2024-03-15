#include "and.h"

void AndGate::Draw()
{
    DrawTextureV(texture_, Position(), RAYWHITE);
    // That's for debug
    DrawRectangleLines(
        X(), Y(),
        Width(), Height(),
        RED
    );
}