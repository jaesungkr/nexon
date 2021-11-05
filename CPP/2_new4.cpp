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
template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
//		buff = new T[sz]; // �̷��� �ϸ� T Ÿ�Կ��� ����Ʈ �����ڰ� �־�� �Ѵٴ�
							// ���������� ����ϴ�.

		// �׷��� 
		// 1. �޸� �Ҵ�
		buff = static_cast<T*>(operator new(sizeof(T)* sz));

		// 2. ������ ȣ��
		for (int i = 0; i < sz; i++)
		{
//			new(&buff[i]) T; // ����Ʈ ������
			new(&buff[i]) T(value); // ���� ������ ���
		}
							
	}
};

int main()
{
	Point p(0, 0);
	vector<Point> v(10, p);
}