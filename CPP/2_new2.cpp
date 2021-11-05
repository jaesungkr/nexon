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

// �ٽ� : Point Ŭ������ "����Ʈ������"�� �����ϴ�.

int main()
{
	// ���� Point �� �Ѱ��� ����� ������. 
	Point* p1 = new Point(0, 0);

	// ���� Point �� 10�� ����� ������. 
//	Point* p2 = new Point*[10]; // error. ����Ʈ �����ڸ� 10�� ȣ���ؾ� �ϴ� ǥ����ε�
							// ����Ʈ �����ڰ� �����ϴ�.

	// �׻� �޸� �Ҵ�� ������ ȣ���� �и��ϸ� �������� ���� ���ϴ�
	// 1. ��ü�� �����ϱ� ���� 10���� �޸� ������ Ȯ��
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// 2. �Ҵ�� �޸� ������ 10���� ��ü�� �����մϴ�.
	for (int i = 0; i < 10; i++)
	{
		new(&p2[i]) Point(0, 0); // placement new ���.
	}

	// 3. ������ ���� �Ҹ��� ȣ��
	for (int i = 0; i < 10; i++)
	{
		p2[i].~Point();
	}

	// 4. �޸� ����
	operator delete(p2);
}





