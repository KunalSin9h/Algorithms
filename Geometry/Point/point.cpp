#include <bits/stdc++.h>
using namespace std;

struct Point{
    int64_t x, y;

    explicit Point(int64_t _x = 0, int64_t _y = 0) : x{_x}, y{_y}{} 

    bool operator==(const Point& p)const{return x == p.x && y == p.y;} 
    bool operator!=(const Point& p)const{return x != p.x || y != p.y;} 

    Point& operator+=(const Point &p){x += p.x;y += p.y;return *this;}
    Point& operator-=(const Point &p){x -= p.x;y -= p.y;return *this;}
    Point& operator*=(int64_t f){x *= f;y *= f;return *this;}
    Point& operator/=(int64_t f){x /= f;y /= f;return *this;}

    Point operator+(const Point &p)const{return  Point(*this) += p;}
    Point operator-(const Point &p)const{return  Point(*this) -= p;}
    Point operator*(int64_t f)const{return  Point(*this) *= f;}
    Point operator/(int64_t f)const{return  Point(*this) /= f;}

    Point operator-()const{return Point(-x, -y);}
    Point rotate90(bool clock = false)const{return Point(y*(-1*!clock), x*(-1*clock));}  // +-90 deg
    Point rotate(double a)const{
        return Point(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a));
    };

    int64_t norm(){
        return (int64_t)x*x + (int64_t)y*y;
    };
    double dist(){
        return sqrt((double)norm()); 
    };
    double angle()const{
        return atan2(double(y), double(x));
    };
    int64_t dot(const Point &p)const{
        return (int64_t)x*p.x + (int64_t)y*p.y;
    };
    int64_t cross(const Point &p)const{
        return (int64_t)x*p.y - (int64_t)y*p.x;
    };
    int64_t cross(const Point &p1, const Point &p2)const{
        return (p1 - *this).cross(p2 - *this);
    };

    friend ostream& operator<<(ostream &os, const Point &p) {
        return os << '(' << p.x << ", " << p.y << ')';
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}
