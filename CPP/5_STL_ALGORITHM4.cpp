#include <iostream>

// Step 4. 보다 일반화 되도록!!

// 아래처럼 만들면 2개의 문제가 있습니다.
// 1. 구간의 타입과 검색대상 타입이 연관됩니다.
//    double 배열에서 int 검색이 안됩니다.

// 2. T* 라고 하면 반드시 구간은 raw pointer만 사용해야 합니다.
//    스마트 포인터등이 포인터 유사 객체를 사용할수 없습니다

//template<typename T> T* find(T* first, T* last, T c)

template<typename T1, typename T2> 
T1 find(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;

	return first == last ? nullptr : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };



	double* p = find(x, x + 10, 5);



	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}