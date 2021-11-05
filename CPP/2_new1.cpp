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
	// new �� ��Ȯ�� ���� ���
	// 1. �޸𸮸� ���� �Ҵ��ϰ� - operator new()
	// 2. ������ ȣ��
//	Point* p1 = new Point(1, 2);

	// delete
	// 1. �Ҹ��� ȣ��
	// 2. �޸� ����. - operator delete()
//	delete p1;

	// 1. ������ ȣ����� �޸𸮸� �Ҵ��ϴ� �ڵ�
	// �ᱹ operator new()�� malloc()�� C++ �����̶�� �����ϸ� �˴ϴ�.
	Point* p2 = static_cast<Point*>( operator new(sizeof(Point)));

	// 2. �̹� �Ҵ�� �޸𸮿� ��ü ����(������ ȣ���̶�� �ǹ�)
//	Point* p1 = new Point(1, 2);     // ���ο� �޸𸮿� ��ü�� ����� �޶�.
	new(p2) Point(1, 2); // p2��� �޸� ������ ��ü�� ����� �޶�(������ ȣ���ش޶�)
						 // "placement new" ��� ��� �Դϴ�.

	// 3. �޸� ���� �ʰ� �Ҹ��ڸ� ȣ��
	p2->~Point(); 

	// 4. �Ҹ��� ȣ����� �޸𸮸� �����ϴ� �ڵ�
	operator delete(p2);
}
