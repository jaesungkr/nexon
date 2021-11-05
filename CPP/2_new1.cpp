#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	// new 의 정확한 동작 방식
	// 1. 메모리를 먼저 할당하고 - operator new()
	// 2. 생성자 호출
//	Point* p1 = new Point(1, 2);

	// delete
	// 1. 소멸자 호출
	// 2. 메모리 해지. - operator delete()
//	delete p1;

	// 1. 생성자 호출없이 메모리만 할당하는 코드
	// 결국 operator new()는 malloc()의 C++ 버전이라고 생각하면 됩니다.
	Point* p2 = static_cast<Point*>( operator new(sizeof(Point)));

	// 2. 이미 할당된 메모리에 객체 생성(생성자 호출이라는 의미)
//	Point* p1 = new Point(1, 2);     // 새로운 메모리에 객체를 만들어 달라.
	new(p2) Point(1, 2); // p2라는 메모리 공간에 객체를 만들어 달라(생성자 호출해달라)
						 // "placement new" 라는 기술 입니다.

	// 3. 메모리 해지 않고 소멸자만 호출
	p2->~Point(); 

	// 4. 소멸자 호출없이 메모리만 제거하는 코드
	operator delete(p2);
}
