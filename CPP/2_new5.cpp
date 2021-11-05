#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

// STL �� vector �� ��� ������ ?
template<typename T, typename Alloc = std::allocator<T> > class vector
{
	T* buff;
	int size;
	int capacity;

	Alloc ax; // �޸� �Ҵ��
public:
	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
		// 1. �޸� �Ҵ��� �޸� �Ҵ�
		buff = ax.allocate(sz);

		// 2. ������ ȣ�⵵ �޸� �Ҵ���� �Լ� ���
		for (int i = 0; i < sz; i++)
		{
			// new(&buff[i], value);
			//ax.construct(&buff[i], value); // C++98 ����
			std::allocator_traits<Alloc>::construct(ax, &buff[i], value);//C++11
		}
	}
};

int main()
{
	Point p(0, 0);
	vector<Point> v(10, p);
}