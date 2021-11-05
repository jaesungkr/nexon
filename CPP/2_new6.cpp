/*
#include <vector>
#include <iostream>

// ����� ���� allocator �����.
// 
int main()
{
	std::vector<int, MyAlloc<int> > v;

	v.push_back(10); // �̼��� �޸� �Ҵ� �۾��� �մϴ�.
}
*/

// visual studio ���� C++17 �̻� ����Ϸ���
// /std:c++latest �ɼ��ʿ� �մϴ�.
// ������Ʈ�޴�=> �Ӽ� �޴� => C/C++ => ����� => �Ʒ�Edit ���� "/std:c++latest" ��������

#include <cstdlib>
#include <new>
#include <limits>
#include <iostream>
#include <vector>

template <class T>
struct Mallocator
{
	typedef T value_type;

	Mallocator() = default;
	template <class U> constexpr Mallocator(const Mallocator <U>&) noexcept {}

	[[nodiscard]] T* allocate(std::size_t n) {
		if (n > std::numeric_limits<std::size_t>::max() / sizeof(T))
			throw std::bad_array_new_length();

		if (auto p = static_cast<T*>(std::malloc(n * sizeof(T)))) {
			report(p, n);
			return p;
		}

		throw std::bad_alloc();
	}

	void deallocate(T* p, std::size_t n) noexcept {
		report(p, n, 0);
		std::free(p);
	}

private:
	void report(T* p, std::size_t n, bool alloc = true) const {
		std::cout << (alloc ? "Alloc: " : "Dealloc: ") << sizeof(T)*n
			<< " bytes at " << std::hex << std::showbase
			<< reinterpret_cast<void*>(p) << std::dec << '\n';
	}
};

template <class T, class U>
bool operator==(const Mallocator <T>&, const Mallocator <U>&) { return true; }
template <class T, class U>
bool operator!=(const Mallocator <T>&, const Mallocator <U>&) { return false; }

int main()
{
	std::vector<int, Mallocator<int>> v(8);
	v.push_back(42);
}