#include <iostream>
#include <vector>
#include <exception>

class NotImplemented : public std::exception {};

class Shape
{
public:
	int type;

protected:
	// 가상함수 : 파생클래스가 재정의 안하면 구현을 물려주겠다는 의도.
	/*
	virtual void DrawImp()
	{
		std::cout << "Draw Shape" << std::endl;
	}
	*/
	// 아래 코드는 "DrawImp"를 반드시 만들어라!!
	// 현재 상황은 논리적으로 이코드가 더 맞습니다.
	virtual void DrawImp() = 0;
public:
	virtual void Draw() final
	{
		std::cout << "Mutex lock" << std::endl;
		DrawImp();
		std::cout << "Mutex unlock" << std::endl;
	}


//	virtual Shape* Clone() = 0; // 이렇게 하거나..
	// 아래 코드 의도는 
	// 재정의 안하고, 사용하지도 않으면 문제 없다.
	// 재정의 안하고, 사용하면 예외 발생한다.
	virtual Shape* Clone()
	{
		throw NotImplemented();
	}

	virtual ~Shape() {} // 기반 클래스는 반드시 가상소멸자 이어야 한다. (C++규칙)
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
// 1. C++기본문법, C# 기본문법
// 2. 디자인 패턴 을 먼저 전체를 이해해 보세요
// 3. C++중급, C# 중급
int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 도전 과제 1. 객체 생성과정을 OCP 를 만족하게 할수 없을까 ?
		//          => Factory 이야기!
		// 2. Undo/Redo 기능을 넣으려면 어떻게 코딩해야 할까 ?
		//     => Command 패턴
		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복사할까요 ? >>";

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



