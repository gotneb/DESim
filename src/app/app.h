#pragma once

#include <raylib.h>
#include <cstdint>
#include <string>
#include "../render/board.h"
#include <raymath.h>

class App {
public:
    App(std::string title, uint32_t width = 720, uint32_t height = 480)
        : title_(title), width_(width), height_(height),
          camera_(Camera2D{.zoom = 1.0f}) {}
    void Run();

private:
    void ApplyZoom();
    void MoveCamera();
    void Close() const;

private:
    std::string title_;
    uint32_t width_;
    uint32_t height_;

    Camera2D camera_;
    Board board_;

private:
    static constexpr int kFPS = 60;
};