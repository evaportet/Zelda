#pragma once

class Vector2
{
public:
    Vector2() = default;
    Vector2(int _x, int _y);

    int x;
    int y;

    Vector2 operator+ (Vector2 a);
    Vector2 operator- (Vector2 a);
    Vector2 operator/ (int a);
    Vector2 operator* (int a);
    bool operator == (Vector2 a);
    bool operator != (Vector2 a);
};