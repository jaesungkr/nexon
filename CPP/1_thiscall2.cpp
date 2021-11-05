// 1. 일반 함수 포인터에 멤버 함수의 주소를 담을수 없습니다.
// 2. 일반 함수 포인터에 static 멤버 함수의 주소를 담을수 있습니다.
class Dialog
{
public:
	void Close(int) {}
	static void Close2(int) {}
};

void foo(int) {}

int main()
{
	void(*f1)(int) = &foo;			 // ok
//	void(*f2)(int) = &Dialog::Close; // error. Dialog::CLose 는 this가 추가됩니다.
	void(*f3)(int) = &Dialog::Close2;// ok.. static 멤버 함수는 this가 추가 안됩니다.

	// 멤버 함수의 주소를 담은 멤버 함수 포인터... !
	void(Dialog::*f2)(int) = &Dialog::Close; 

	// 함수 포인터를 사용한 멤버 함수 호출..
//	f2(10); // 될까요 ?? error. 멤버 함수 인데.. 객체가 없습니다.

	Dialog dlg;
//	dlg.f2(10); // 될까요 ? error. dlg 안에는 f2라는 멤버가 없습니다.
	
	// 그래서, 이럴때 사용하는 "pointer to member 라는 연산자가 있습니다."
//	dlg.*f2(10);  // .* 가 한개의 연산자.
			     // 연산자 우선순위 문제로 에러..
	(dlg.*f2)(10); // ok.. 이렇게 해야 합니다.
					// 이 코드가 멤버 함수 포인터로 함수를 호출하는 코드 입니다.					
}
// 1. 함수 포인터 공부하세요(C# 의 델리게이트)
// 2. 왜 사용하는지 예제 학습해 보세요.
// 3. 그리고 위 코드 이해 해 보세요..






