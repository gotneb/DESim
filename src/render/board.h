#pragma once

// Internal
#include <raylib.h>
#include <stdexcept>
#include <vector>
#include <memory>
// Mine
#include "element.h"
#include "components/and.h"
#include "../app/app.h"

class Board {
public:
    Board(
        // REFACTOR: `App` should handle a way to give textures to elements
        // It's not wrong as it's now, but it's cumbersome and ugly...
        Texture2D& texture,
        Color background = RAYWHITE, 
        Color grid_color = LIGHTGRAY
    ):  bg_(background), 
        grid_color_(grid_color) {
            elements_ = { 
                std::make_shared<AndGate>(
                    Vector2{20 * kCellSize, 8 * kCellSize},
                    texture
                )
            };
        }

    void Update();
    void Draw() const;

private:
    void DrawGrid() const;
    void DrawElements() const;

private:
    Color bg_;
    Color grid_color_;
    std::vector<std::shared_ptr<Element>> elements_;

public:
    static constexpr float kCellSize = 34.0f;
};