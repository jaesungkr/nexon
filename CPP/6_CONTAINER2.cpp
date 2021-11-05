#include <iostream>

// �̱۸���Ʈ�� ����� ���ô�.
template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

// slist �ȿ� Node�� ����Ű�� ������ ��Ȱ�� ��ü
template<typename T> 
class slist_iterator
{
	Node<T>* current;

public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	// find �� �������� 4���� ������ �����ؾ� �Ѵ�.(==, !=, ++, *)
	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	inline T& operator*() { return current->data ;}

	inline bool operator==(const slist_iterator& it)
	{
		return current == it.current;
	}
	inline bool operator!=(const slist_iterator& it)
	{
		return current != it.current;
	}
};

//slist_iterator<int> p(500����);
//++p; // p.operator++()
//*p;  // p.operator*()



template<typename T> class slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}
	// ��� �����̳� �����ڴ� �ڽ��� ����/������ ���� �� ����Ű�� 
	// �ݺ��ڸ� ��ȯ�ϴ� �Լ��� �־�� �Ѵٰ� ��� �մϴ�.
	slist_iterator<T> begin() { return slist_iterator<T>(head); }
	slist_iterator<T> end()   { return slist_iterator<T>(nullptr); }
};

int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

	slist_iterator<int> p = s.begin();
	
	// ���� p�� ������ ó�� �����ϰ� ����ϸ� �˴ϴ�.
	while (p != s.end())
	{
		std::cout << *p << std::endl;
		++p;
	}

	for (auto e : s)
	{
		std::cout << e << std::endl;
	}
}