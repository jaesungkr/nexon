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
template<typename T, typename Alloc = std::allocator<T> > class vector
{
	T* buff;
	int size;
	int capacity;

	Alloc ax; // 메모리 할당기
public:
	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
		// 1. 메모리 할당기로 메모리 할당
		buff = ax.allocate(sz);

		// 2. 생성자 호출도 메모리 할당기의 함수 사용
		for (int i = 0; i < sz; i++)
		{
			// new(&buff[i], value);
			//ax.construct(&buff[i], value); // C++98 시절
			std::allocator_traits<Alloc>::construct(ax, &buff[i], value);//C++11
		}
	}
};

int main()
{
	Point p(0, 0);
	vector<Point> v(10, p);
}