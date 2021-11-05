#include <iostream>

// Step 4. ���� �Ϲ�ȭ �ǵ���!!

// �Ʒ�ó�� ����� 2���� ������ �ֽ��ϴ�.
// 1. ������ Ÿ�԰� �˻���� Ÿ���� �����˴ϴ�.
//    double �迭���� int �˻��� �ȵ˴ϴ�.

// 2. T* ��� �ϸ� �ݵ�� ������ raw pointer�� ����ؾ� �մϴ�.
//    ����Ʈ �����͵��� ������ ���� ��ü�� ����Ҽ� �����ϴ�

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