#include <iostream>

// Step 3. 검색 대상 타입의 일반화 .. 템플릿 도입
// 함수 이름 변경 : strchr => find
template<typename T>
T* find(T* first, T* last, T c)
{
	while (first != last && *first != c)
		++first;

	return first == last ? nullptr : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = find(x, x + 10, 5.0);


	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}