#include <iostream>

// 싱글리스트를 만들어 봅시다.
template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

// slist 안에 Node를 가리키는 포인터 역활의 객체
template<typename T> 
class slist_iterator
{
	Node<T>* current;

public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	// find 에 보내려면 4개의 연산이 가능해야 한다.(==, !=, ++, *)
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

//slist_iterator<int> p(500번지);
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
	// 모든 컨테이너 설계자는 자신의 시작/마지막 다음 을 가리키는 
	// 반복자를 반환하는 함수가 있어야 한다고 약속 합니다.
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
	
	// 이제 p는 포인터 처럼 생각하고 사용하면 됩니다.
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