#include <iostream>

using namespace std;

class Box
{
    public:
        double length;
        double breadth;
        double height;
};

int main(void)
{
    Box box1;
    Box box2;
    double volume = 0.0;

    box1.length = 6.0;
    box1.breadth = 7.0;
    box1.height = 5.0;

    box2.length = 12.0;
    box2.breadth = 13.0;
    box2.height = 10.0;

    volume = box1.length * box1.breadth * box1.height;
    cout << "box1 的体积：" << volume <<endl;

    volume = box2.length * box2.breadth * box2.height;
    cout << "box2 的体积：" << volume <<endl;

    return 0;
}
