#include <iostream>
#include <vector>

// 5. OCP 원칙
// 기능 확장에는 열려 있고(Open, 클래스/모듈이 나중에 추가 되어도)
// 코드 수정에는 닫혀 있어야(Close, 기존 코드는 변경되지 않게 해라)
// 는 이론(Principle)

// Open Close Principle ( OCP )
// 개방 폐쇄의 법칙
// 5대 원칙 : SRP, OCP, LSP, ISP, DIP ( SOLID )

// 6. 자주 사용되는 코딩 기술에 이름을 붙이자...
//    객체지향에서 널리 사용되는 코딩 스타일이 "이름"을 부여한것

// 디자인 패턴 "23가지의 이름" ..

// 7. prototype 패턴
//   => 견본 객체를 만들고 복사해서 객체를 만드는 기술
//     clone()가상함수
// C# 의 IClonable 인터페이스, java 의 clonable() 메소드가 
// swift 의 copy 메소드가 

// 모두 이 패턴의 응용 기술입니다.





class Shape
{
public:
	int type;
	virtual void Draw() { std::cout << "Draw Shape" << std::endl; }

	// 자신의 복제본을 만드는 가상함수는 항상 유용하게 활용됩니다.
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
			std::cout << "몇번째 도형을 복사할까요 ? >>";
			
			int k;
			std::cin >> k;

			// k 번째 도형의 복사본을 만들어서 v에 추가 합니다.
			// 그런데 k번째 도형은 뭘까요 ??
			// 어떻게 해야 할까요 ?

			// 아래 코드는 OCP를 만족하지 못하는 전형적인 코드 입니다.
			/*
			switch (v[k]->type)
			{
			case 1: v.push_back(new Rect(*v[k])); break;
			case 2: v.push_back(new Circle(*v[k])); break;
			}
			*/

			// 리팩토링 용어
			// Replace Conditional With Polymorphism
			// 조건문을 다형성(가상함수)으로 변경해라!!

			v.push_back(v[k]->Clone()); // 다형성. OCP를 만족하는 아주 좋은 코드. 


		}


		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();  // 다형성(Polymorphism)
						// 동일한 함수 호출 코드가 상황(객체)에 따라
						// 다르게 동작하는 것.
		}
	}
}





