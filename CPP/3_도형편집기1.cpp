#include <iostream>
#include <vector>

// 1. �� ������ Ÿ��ȭ �ϸ� ���ϴ�.
// 2. ��� ������ ������ ��� Ŭ������ �ִٸ� ��� ������ ��� �����Ҽ� �ִ�.
class Shape
{
};
class Rect : public Shape
{
public:
	void Draw() { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void Draw() { std::cout << "Draw Circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v; // Rect �� �����ϴ� �����̳�.

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw(); // �� �����ϱ�� ?
		}
	}
}





