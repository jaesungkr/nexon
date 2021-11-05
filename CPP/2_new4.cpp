#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

// STL 의 vector 는 어떻게 만들까요 ?
template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
//		buff = new T[sz]; // 이렇게 하면 T 타입에는 디폴트 생성자가 있어야 한다는
							// 제약조건이 생깁니다.

		// 그래서 
		// 1. 메모리 할당
		buff = static_cast<T*>(operator new(sizeof(T)* sz));

		// 2. 생성자 호출
		for (int i = 0; i < sz; i++)
		{
//			new(&buff[i]) T; // 디폴트 생성자
			new(&buff[i]) T(value); // 복사 생성자 사용
		}
							
	}
};

int main()
{
	Point p(0, 0);
	vector<Point> v(10, p);
}