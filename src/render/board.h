#pragma once

#include <vector>
#include <stdexcept>
#include <raylib.h>
#include "element.h"

class Board {
public:
    Board(Color background = RAYWHITE, Color grid_color = LIGHTGRAY)
        : bg_(background), grid_color_(grid_color) {}

    void Update();
    void Draw() const;

private:
    void DrawGrid() const;
    void DrawElements() const;

private:
    Color bg_;
    Color grid_color_;
    std::vector<Element> elements_;

private:
    static const int kCellSize = 24;
};