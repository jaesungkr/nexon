#include <iostream>

// �ٽ� 
// 1. ��� �Լ��� 1��° ���ڷ� this�� �߰��˴ϴ�.
// 2. static ��� �Լ��� 1��° ���ڷ� this�� �߰� �ȵ˴ϴ�.
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
		x = a;				// this->x = a �� ����Ǿ� �ϴµ�... this�� �����ϴ�.
	}						// �׷��� static ����Լ������� ��� ����Ÿ ���� �ȵ˴ϴ�.
};						
						
int main()
{
	Point::foo(10); // ��ü ���� ȣ�Ⱑ���� �Լ�.


	Point p1, p2;

	p1.set(10, 20);	// set(&p1, 10, 20) �� ������ ������ �˴ϴ�.
					// 32bit
					// push  20
					// push  10  // ��¥ ���ڴ� ��������
					// mov   ecx, &p1 // ��ü �ּҴ� ecx �������Ϳ�
				    // call  Point::set
					// 64 ��Ʈ�� => ���ڵ� ������ �ƴ� �������ͷ�!!
	
}



