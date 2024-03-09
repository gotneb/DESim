#pragma once

#include <raylib.h>
#include <cstdint>
#include <string>
#include "../render/board.h"

class App {
public:
    App(std::string title, uint32_t width = 720, uint32_t height = 480)
        : title_(title), width_(width), height_(height) {}
    void Run();

private:
    void Close() const;

private:
    std::string title_;
    uint32_t width_;
    uint32_t height_;

    Board board_;

private:
    static constexpr int kFPS = 60;
};