#include "board.h"

void Board::Update() 
{
    for (auto& e: elements_)
    {
        e->Update();
    }
}

void Board::DrawElements() const
{
    for (auto& e: elements_)
    {
        e->Draw();
    }
}

void Board::Draw() const 
{
    ClearBackground(bg_);

    DrawGrid();
    DrawElements();
}

void Board::DrawGrid() const
{
    // TODO: Get this values from `App` class...
    const int width = kCellSize * 120;
    const int height = kCellSize * 120;

    // Draw columns
    for (float x = 0; x <= width; x += kCellSize)
    {
        DrawLineV(
            {x, 0},
            {x, height},
            grid_color_
        );
    }

    // Draw rows
    for (float y = 0; y <= height; y += kCellSize)
    {
        DrawLineV(
            {0, y},
            {width, y},
            grid_color_
        );
    }
}