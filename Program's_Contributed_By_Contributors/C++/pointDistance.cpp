#include<iostream>
#include<math.h>
using namespace std;

class Point
{
    int x, y;
    public:
        friend void distance(Point, Point);
        Point(int a, int b)
        {
            x = a;
            y = b;
        }
        void display()
        {
            cout << "The point is (" << x << ", " << y << ")" << endl;
        }
};

void distance(Point p1, Point p2)
{
    float dis = sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2));
    cout << "The distance between two points is " << dis << endl;
}

int main()
{
    // implicit call
    Point p(0, 1);
    p.display();

    // explicit call 
    Point q = Point(0, 6);
    q.display();
    distance(p, q);
    return 0;
}
