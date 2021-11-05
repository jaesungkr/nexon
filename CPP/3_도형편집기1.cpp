#include <iostream>
#include <vector>

// 1. 각 도형을 타입화 하면 편리하다.
// 2. 모든 도형의 공통의 기반 클래스가 있다면 모든 도형을 묶어서 관리할수 있다.
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
	std::vector<Shape*> v; // Rect 만 보관하는 컨테이너.

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw(); // 왜 에러일까요 ?
		}
	}
}





