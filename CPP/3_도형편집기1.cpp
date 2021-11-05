#include <iostream>
#include <vector>

// 1. 각 도형을 타입화 하면 편리하다.
// 2. 모든 도형의 공통의 기반 클래스가 있다면 모든 도형을 묶어서 관리할수 있다.
// 3. 모든 도형의 공통의 특징은 반드시 기반 클래스에도 있어야 한다
//   ==> 그래야 기반 클래스 포인터로 묶어서 사용할때 해당 특징을 쓸수 있다.

// 4. 파생클래스가 재정의 하게 되는 함수는 반드시 가상함수로 해야 한다.

class Shape
{
public:
	virtual void Draw() { std::cout << "Draw Shape" << std::endl; }
};

class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }
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
				// 방법 1. p를 Rect, Circle로 캐스팅하자.
				//     => 그런데, 코드를 작성할때는 알수 없다.
				// 방법 2. Shape에 Draw를 넣는다.
				p->Draw(); // 왜 에러일까요 ?
		}
	}
}





