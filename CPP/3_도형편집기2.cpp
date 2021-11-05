#include <iostream>
#include <vector>

// 5. OCP ��Ģ
// ��� Ȯ�忡�� ���� �ְ�(Open, Ŭ����/����� ���߿� �߰� �Ǿ)
// �ڵ� �������� ���� �־��(Close, ���� �ڵ�� ������� �ʰ� �ض�)
// �� �̷�(Principle)

// Open Close Principle ( OCP )
// ���� ����� ��Ģ
// 5�� ��Ģ : SRP, OCP, LSP, ISP, DIP ( SOLID )

// 6. ���� ���Ǵ� �ڵ� ����� �̸��� ������...
//    ��ü���⿡�� �θ� ���Ǵ� �ڵ� ��Ÿ���� "�̸�"�� �ο��Ѱ�

// ������ ���� "23������ �̸�" ..

// 7. prototype ����
//   => �ߺ� ��ü�� ����� �����ؼ� ��ü�� ����� ���
//     clone()�����Լ�
// C# �� IClonable �������̽�, java �� clonable() �޼ҵ尡 
// swift �� copy �޼ҵ尡 

// ��� �� ������ ���� ����Դϴ�.





class Shape
{
public:
	int type;
	virtual void Draw() { std::cout << "Draw Shape" << std::endl; }

	// �ڽ��� �������� ����� �����Լ��� �׻� �����ϰ� Ȱ��˴ϴ�.
	virtual Shape* Clone() { return new Shape(*this); }
};



class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }
	Shape* Clone() override { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }
	Shape* Clone() override { return new Circle(*this); }
};

class Triangle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Triangle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v; 

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 8)
		{
			std::cout << "���° ������ �����ұ�� ? >>";
			
			int k;
			std::cin >> k;

			// k ��° ������ ���纻�� ���� v�� �߰� �մϴ�.
			// �׷��� k��° ������ ����� ??
			// ��� �ؾ� �ұ�� ?

			// �Ʒ� �ڵ�� OCP�� �������� ���ϴ� �������� �ڵ� �Դϴ�.
			/*
			switch (v[k]->type)
			{
			case 1: v.push_back(new Rect(*v[k])); break;
			case 2: v.push_back(new Circle(*v[k])); break;
			}
			*/

			// �����丵 ���
			// Replace Conditional With Polymorphism
			// ���ǹ��� ������(�����Լ�)���� �����ض�!!

			v.push_back(v[k]->Clone()); // ������. OCP�� �����ϴ� ���� ���� �ڵ�. 


		}


		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();  // ������(Polymorphism)
						// ������ �Լ� ȣ�� �ڵ尡 ��Ȳ(��ü)�� ����
						// �ٸ��� �����ϴ� ��.
		}
	}
}





