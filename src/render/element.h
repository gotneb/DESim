#pragma once

#include <raylib.h>
#include <raymath.h>

// A 2D entity with width and height
typedef struct {
    float width;
    float height;
} Size2;

// A 2D entity with position and size on the plane
typedef struct {
    Vector2 position;
    Size2 size;
} Shape;

/*
 *  A `Element` represents the abstraction of anything that can be emulated inside on the program.
 *
 *  That being said, everything MUST inherit from `Element`.
 *  e.g: electronic gates, wires, plexers, boxes and so on.
 */
class Element {
public:
    explicit
    Element(float x, float y, float width, float height)
        :   
        shape_({
            (Vector2){x, y},
            (Size2){width, height}
        }) {}

    explicit
    Element(Vector2 position, Size2 size): shape_({position, size}) {}

    explicit
    Element(Shape shape): shape_(shape) {}

    virtual void Update() = 0;
    virtual void Draw() = 0;

    // ******************************************
    // *             HANDY METHODS              *
    // ******************************************

    // Returns the `x` position
    inline
    float X() const { return shape_.position.x; }
    // Returns the `y` position
    inline
    float Y() const { return shape_.position.y; }
    // Returns the `position`
    inline
    Vector2 Position() const { return shape_.position; }

    // Returns the `width`
    inline
    float Width() const { return shape_.size.width; }
    // Returns the `height`
    inline
    float Height() const { return shape_.size.height; }

private:
    Shape shape_;
};