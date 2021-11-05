#include <iostream>
#include <vector>

// 8. template method 패턴
//    => 기반 클래스가 전체적인 틀을 가진 코드를 제공하고
//    => 변해야 하는 부분(protected, 가상함수)를 
//    => 서브클래스가 다시 변경할수 있는 기회를 주는 패턴.
//    => 아래 코드에서 DrawImp 가 "훅" 함수 입니다.

class Shape
{
public:
	int type;

	// 공통성과 가변성의 분리
	// 변하지 않은 전체 흐름(알고리즘)속에 있는 변하는 것은 분리 되어야 한다.
	// 변하는 것을 가상함수로 분리 한다.
protected:
	virtual void DrawImp()
	{
		std::cout << "Draw Shape" << std::endl; 
	}

public:
	// C++11 final : 파생클래스가 재정의 못하게 하는 문법
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



