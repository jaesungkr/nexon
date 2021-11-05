#include <iostream>
#include <vector>

// 8. template method ����
//    => ��� Ŭ������ ��ü���� Ʋ�� ���� �ڵ带 �����ϰ�
//    => ���ؾ� �ϴ� �κ�(protected, �����Լ�)�� 
//    => ����Ŭ������ �ٽ� �����Ҽ� �ִ� ��ȸ�� �ִ� ����.
//    => �Ʒ� �ڵ忡�� DrawImp �� "��" �Լ� �Դϴ�.

class Shape
{
public:
	int type;

	// ���뼺�� �������� �и�
	// ������ ���� ��ü �帧(�˰���)�ӿ� �ִ� ���ϴ� ���� �и� �Ǿ�� �Ѵ�.
	// ���ϴ� ���� �����Լ��� �и� �Ѵ�.
protected:
	virtual void DrawImp()
	{
		std::cout << "Draw Shape" << std::endl; 
	}

public:
	// C++11 final : �Ļ�Ŭ������ ������ ���ϰ� �ϴ� ����
	virtual void Draw() final
	{
		std::cout << "Mutex lock" << std::endl;
		DrawImp();
		std::cout << "Mutex unlock" << std::endl;
	}

	
	virtual Shape* Clone() { return new Shape(*this); }
};



class Rect : public Shape
{
public:
	void DrawImp() override { std::cout << "Draw Rect" << std::endl; }
	Shape* Clone() override { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void DrawImp() override { std::cout << "Draw Circle" << std::endl; }
	Shape* Clone() override { return new Circle(*this); }
};

class Triangle : public Shape
{
public:
	void DrawImp() override { std::cout << "Draw Triangle" << std::endl; }
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

			v.push_back(v[k]->Clone()); 


		}


		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw(); 
		}
	}
}



