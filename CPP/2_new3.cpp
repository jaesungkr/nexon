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
	// 아래와 같은 코드가 있을때 
	// 그런데.. 메모리 할당 방식을 "malloc" 또는 다른 방식으로 변경하고 싶었습니다.
	// 몇군데를 수정해야 할까요 ? => 아래 4줄을 모두 변경해야 합니다.
//	Point* p1 = new Point(1, 2);
//	delete p1;
//	Point* p2 = new Point(1, 2);
//	delete p2;

	// 메모리 할당 방식의 교체를 편리하게 하고 싶다.
	// 메모리 할당을 책임지는 클래스를 제공하자 => allocator
	std::allocator<Point> ax; // Point 타입의 메모리 할당을 담당
						// 표준 allocator는 operator new 사용

	// 사용자 정의 allocator 를 사용하면 메모리 할당 방식을 변경할수 있다는 철학입니다.
	// 그때 사용자 정의 allocator 는 "allocate", "deallocate" 가 있어야 합니다.
	// "cppreference.com" 에 접속해서 왼쪽 에서 "named requirement" 클릭해 보세요
//	MyAlloc<Point> ax;

	Point* p1 = ax.allocate(1); // 1개 할당

	ax.deallocate(p1, 1); // p1주소에 있는 한개를 해지
}