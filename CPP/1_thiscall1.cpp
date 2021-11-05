#include <iostream>

// 핵심 
// 1. 멤버 함수는 1번째 인자로 this가 추가됩니다.
// 2. static 멤버 함수는 1번째 인자로 this가 추가 안됩니다.
class Point
{
	int x, y;
public:
	void set(int a, int b) // void set(Point* this, int a, int b)
	{					  
		x = a;			   // this->x = a
		y = b;			   // this->y = b
	}		

	static void foo(int a) // void foo(int a)
	{
		x = a;				// this->x = a 로 변경되야 하는데... this가 없습니다.
	}						// 그래서 static 멤버함수에서는 멤버 데이타 접근 안됩니다.
};						
						
int main()
{
	Point::foo(10); // 객체 없이 호출가능한 함수.


	Point p1, p2;

	p1.set(10, 20);	// set(&p1, 10, 20) 의 원리로 컴파일 됩니다.
					// 32bit
					// push  20
					// push  10  // 진짜 인자는 스택으로
					// mov   ecx, &p1 // 객체 주소는 ecx 레지스터에
				    // call  Point::set
					// 64 비트는 => 인자도 스택이 아닌 레지스터로!!
	
}



