#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Shape {
public:
	Shape(const string& color = "White") { this->color = color; }
	
	// 把area定义为"纯虚函数"
	virtual float area() = 0;
	string getColor() { return color; }

private:
	string color;
};

class Circle : public Shape {
public:
	Circle(float radius = 0, const string& color = "White") : Shape(color), r(radius) {};
	float area() { return 3.14 * r * r; }
private:
	float r;  // 半径
};

int main(void) {
	Circle c1(10);
	cout << c1.area() << endl;

	system("pause");
	return 0;
}