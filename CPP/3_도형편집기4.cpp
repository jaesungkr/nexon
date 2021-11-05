#include <iostream>
#include <vector>
#include <exception>

class NotImplemented : public std::exception {};

class Shape
{
public:
	int type;

protected:
	// �����Լ� : �Ļ�Ŭ������ ������ ���ϸ� ������ �����ְڴٴ� �ǵ�.
	/*
	virtual void DrawImp()
	{
		std::cout << "Draw Shape" << std::endl;
	}
	*/
	// �Ʒ� �ڵ�� "DrawImp"�� �ݵ�� ������!!
	// ���� ��Ȳ�� �������� ���ڵ尡 �� �½��ϴ�.
	virtual void DrawImp() = 0;
public:
	virtual void Draw() final
	{
		std::cout << "Mutex lock" << std::endl;
		DrawImp();
		std::cout << "Mutex unlock" << std::endl;
	}


//	virtual Shape* Clone() = 0; // �̷��� �ϰų�..
	// �Ʒ� �ڵ� �ǵ��� 
	// ������ ���ϰ�, ��������� ������ ���� ����.
	// ������ ���ϰ�, ����ϸ� ���� �߻��Ѵ�.
	virtual Shape* Clone()
	{
		throw NotImplemented();
	}

	virtual ~Shape() {} // ��� Ŭ������ �ݵ�� ����Ҹ��� �̾�� �Ѵ�. (C++��Ģ)
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
// 1. C++�⺻����, C# �⺻����
// 2. ������ ���� �� ���� ��ü�� ������ ������
// 3. C++�߱�, C# �߱�
int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// ���� ���� 1. ��ü ���������� OCP �� �����ϰ� �Ҽ� ������ ?
		//          => Factory �̾߱�!
		// 2. Undo/Redo ����� �������� ��� �ڵ��ؾ� �ұ� ?
		//     => Command ����
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



