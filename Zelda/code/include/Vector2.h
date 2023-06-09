#pragma once

class Vector2
{
public:
    Vector2() = default;
    Vector2(int _x, int _y);
    ~Vector2() = default;

    int x;
    int y;

    Vector2 operator+ (Vector2 a);
    Vector2 operator- (Vector2 a);
    Vector2 operator/ (int a);
    Vector2 operator* (int a);
};