#include <iostream>

class Point
{
	int x;
	int y;
public:
//	Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 핵심 : Point 클래스는 "디폴트생성자"가 없습니다.

int main()
{
	// 힙에 Point 를 한개만 만들어 보세요. 
	Point* p1 = new Point(0, 0);

	// 힙에 Point 를 10개 만들어 보세요. 
//	Point* p2 = new Point*[10]; // error. 디폴트 생성자를 10번 호출해야 하는 표기법인데
							// 디폴트 생성자가 없습니다.

	// 항상 메모리 할당과 생성자 호출을 분리하면 유연성이 높아 집니다
	// 1. 객체를 생성하기 위한 10개의 메모리 공간만 확보
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// 2. 할당된 메모리 공간에 10개의 객체를 생성합니다.
	for (int i = 0; i < 10; i++)
	{
		new(&p2[i]) Point(0, 0); // placement new 사용.
	}

	// 3. 해지를 위한 소멸자 호출
	for (int i = 0; i < 10; i++)
	{
		p2[i].~Point();
	}

	// 4. 메모리 해지
	operator delete(p2);
}





