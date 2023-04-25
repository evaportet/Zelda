#include "../include/Vector2.h"

Vector2::Vector2(int x, int y): this->x(x), this->y(y)
{
}

Vector2 Vector2::operator+ (Vector2 a, Vector2 b){
    Vector2 c;
    c.x=a.x+b.x;
    c.y=a.y+b.y;
    return c;
}  

Vector2 Vector2::operator- (Vector2 a, Vector2 b){
    Vector2 c;
    c.x=a.x-b.x;
    c.y=a.y-b.y;
    return c;
}  

Vector2 Vector2::operator/ (Vector2 a, int b){
    Vector2 c;
    c.x=a.x/b;
    c.y=a.y/b;
    return c;
}  

Vector2 Vector2::operator* (Vector2 a, int b){
    Vector2 c;
    c.x=a.x*b;
    c.y=a.y*b;
    return c;
}  