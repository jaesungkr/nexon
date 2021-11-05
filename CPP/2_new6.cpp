/*
#include <vector>
#include <iostream>

// 사용자 정의 allocator 만들기.
// 
int main()
{
	std::vector<int, MyAlloc<int> > v;

	v.push_back(10); // 이순간 메모리 할당 작업을 합니다.
}
*/

// visual studio 에서 C++17 이상 사용하려면
// /std:c++latest 옵션필요 합니다.
// 프로젝트메뉴=> 속성 메뉴 => C/C++ => 명령줄 => 아래Edit 에서 "/std:c++latest" 넣으세요

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