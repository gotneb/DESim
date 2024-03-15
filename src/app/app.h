#pragma once

#include <raylib.h>
#include <cstdint>
#include <string>
#include <memory>
#include <raymath.h>
#include "../render/board.h"

// Avoid ciclic-dependency...
class Board;

class App {
public:
    App(std::string title, 
        uint32_t width = 720, 
        uint32_t height = 480, 
        float initial_zoom = 1.0f)
        : title_(title), 
          width_(width), 
          height_(height),
          camera_(Camera2D{.zoom = initial_zoom}) {}

    void Run();


private:
    void ApplyZoom();
    void MoveCamera();
    void Setup();
    void Close() const;

private:
    std::string title_;
    uint32_t width_;
    uint32_t height_;

    Camera2D camera_;
    std::unique_ptr<Board> board_;

    Texture2D and_gate_texture_;

private:
    static constexpr int kFPS = 60;
};