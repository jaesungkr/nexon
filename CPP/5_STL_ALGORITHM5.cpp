#include <iostream>

// Step 5. 실패시 반환값의 변경. 
// nullptr 대신 last 를 반환하면
// 활용도가 높아지고, find 구현도 간결해고 빨라집니다.
template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;

	return first;// == last ? nullptr : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = find(x, x + 3, 5);

	if (p == x+3)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}