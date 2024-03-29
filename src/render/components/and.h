#pragma once

#include <format>
#include "../element.h"

class AndGate : public Element {
public:
    AndGate(Vector2 position, Texture2D& texture)
        : Element(position, {4 * 34, 4*34}),
          texture_(texture) {}

    void Update() override;
    void Draw() override;

private:
    bool IsMouseInside() const;
    void Move();
    void CheckMoveState();

private:
    Texture2D& texture_;
    bool canFollowMouse_;
};