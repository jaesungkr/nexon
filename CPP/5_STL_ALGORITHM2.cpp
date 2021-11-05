#include <iostream>

// Step 2. �˻� ������ �Ϲ�ȭ ( �κ� ���ڿ� �˻��� �����ϰ�)
char* strchr(char* first, char* last, int c)
{
	while ( first != last && *first != c)
		++first;

	return *first == 0 ? nullptr : first;
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