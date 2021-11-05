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
	// �Ʒ��� ���� �ڵ尡 ������ 
	// �׷���.. �޸� �Ҵ� ����� "malloc" �Ǵ� �ٸ� ������� �����ϰ� �;����ϴ�.
	// ����� �����ؾ� �ұ�� ? => �Ʒ� 4���� ��� �����ؾ� �մϴ�.
//	Point* p1 = new Point(1, 2);
//	delete p1;
//	Point* p2 = new Point(1, 2);
//	delete p2;

	// �޸� �Ҵ� ����� ��ü�� ���ϰ� �ϰ� �ʹ�.
	// �޸� �Ҵ��� å������ Ŭ������ �������� => allocator
	std::allocator<Point> ax; // Point Ÿ���� �޸� �Ҵ��� ���
						// ǥ�� allocator�� operator new ���

	// ����� ���� allocator �� ����ϸ� �޸� �Ҵ� ����� �����Ҽ� �ִٴ� ö���Դϴ�.
	// �׶� ����� ���� allocator �� "allocate", "deallocate" �� �־�� �մϴ�.
	// "cppreference.com" �� �����ؼ� ���� ���� "named requirement" Ŭ���� ������
//	MyAlloc<Point> ax;

	Point* p1 = ax.allocate(1); // 1�� �Ҵ�

	ax.deallocate(p1, 1); // p1�ּҿ� �ִ� �Ѱ��� ����
}