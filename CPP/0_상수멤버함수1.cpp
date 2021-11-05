
// github.com/codenuri/nexon 에서 CPP.zip 받으세요

// 압축 풀고, VC 에서 여시면 됩니다.
// "X86", "Debug" 로 설정

// 프로젝트 => 속성 메뉴 
// 플랫폼 도구 집합 : 
// Windows SDK 버전 설정

// 강석민 강사 ( smkang @ codenuri.co.kr )







#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// 핵심 : 아래 print 멤버 함수는 반드시 상수멤버함수가 되어야 합니다
	void print()  const
	{
//		x = 10;	// error. 상수 멤버 함수 안에서 모든 멤버는 상수 취급 됩니다

		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
	const Point pt(1, 2);

	pt.x = 10;		// error. x는 public 이지만 상수 이므로
	pt.set(10, 20);	// error.
	pt.print();		// error. 
					// 단, 상수 멤버 함수로 만들면 에러가 아니다.

	// 핵심 : 상수 객체는 상수 멤버 함수만 호출할수 있다.
}


