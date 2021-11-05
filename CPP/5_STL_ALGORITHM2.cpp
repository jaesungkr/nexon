#include <iostream>

// Step 2. 검색 구간의 일반화 ( 부분 문자열 검색이 가능하게)
char* strchr(char* first, char* last, int c)
{
	while ( first != last && *first != c)
		++first;

	return first == last ? nullptr : first;
}

int main()
{
	char s[] = "abcdefgh";

	char* p = strchr(s, s+4, 'e');

	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}
