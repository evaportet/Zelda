#pragma once

class Vector2
{
public:
    Vector2() = default;
    Vector2(int x, int y);
    ~Vector2() = default;

    int x;
    int y;
    //TODO comparators
    public static Vector2 operator+ (Vector2 a, Vector2 b);
    public static Vector2 operator- (Vector2 a, Vector2 b);
    public static Vector2 operator/ (Vector2 a, int b);
    public static Vector2 operator* (Vector2 a, int b);

}