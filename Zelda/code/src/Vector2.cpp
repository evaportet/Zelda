#include "../include/Vector2.h"

Vector2::Vector2(int _x, int _y): x(_x), y(_y)
{
}

Vector2 Vector2::operator+ (Vector2 a){
    Vector2 c;
    c.x=x+a.x;
    c.y=y+a.y;
    return c;
}  

Vector2 Vector2::operator- (Vector2 a){
    Vector2 c;
    c.x=x-a.x;
    c.y=y-a.y;
    return c;
}  

Vector2 Vector2::operator/ (int a){
    Vector2 c;
    c.x=x/a;
    c.y=y/a;
    return c;
}  

Vector2 Vector2::operator* (int a) {
    Vector2 c;
    c.x = x * a;
    c.y = y * a;
    return c;
}

bool Vector2::operator ==(Vector2 a)
{
    return (x == a.x) && (y == a.y);
}

bool Vector2::operator !=(Vector2 a)
{
    return !((x == a.x) && (y == a.y));
}
