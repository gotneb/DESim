#pragma once

#include <raylib.h>
#include <raymath.h>

/*
 *  A `Element` represents the abstraction of anything that can be emulated inside on the program.
 *
 *  That being said, everything MUST inherit from `Element`.
 *  e.g: electronic gates, wires, plexers, boxes and so on.
 */
class Element {
public:
    Element(float x = 0, float y = 0) : position_({x, y}) {} 
    Element(Vector2 position) : position_(position) {}

    virtual void Update() = 0;
    virtual void Draw() = 0;

protected:
    Vector2 position_;
};