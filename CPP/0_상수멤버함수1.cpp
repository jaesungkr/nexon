
// github.com/codenuri/nexon ���� CPP.zip ��������

// ���� Ǯ��, VC ���� ���ø� �˴ϴ�.
// "X86", "Debug" �� ����

// ������Ʈ => �Ӽ� �޴� 
// �÷��� ���� ���� : 
// Windows SDK ���� ����

// ������ ���� ( smkang @ codenuri.co.kr )







#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// �ٽ� : �Ʒ� print ��� �Լ��� �ݵ�� �������Լ��� �Ǿ�� �մϴ�
	void print()  const
	{
//		x = 10;	// error. ��� ��� �Լ� �ȿ��� ��� ����� ��� ��� �˴ϴ�

		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
	const Point pt(1, 2);

	pt.x = 10;		// error. x�� public ������ ��� �̹Ƿ�
	pt.set(10, 20);	// error.
	pt.print();		// error. 
					// ��, ��� ��� �Լ��� ����� ������ �ƴϴ�.

	// �ٽ� : ��� ��ü�� ��� ��� �Լ��� ȣ���Ҽ� �ִ�.
}


