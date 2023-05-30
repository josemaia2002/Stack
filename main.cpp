#include <algorithm>
#include <cstddef>
#include <iostream>

template <typename T>
class Stack{
private:
	T*m_storage;
	size_t m_top;
	size_t m_capacity;

public:
	Stack(size_t cap = 0) : m_capacity{cap}, m_storage{ new T[m_capacity] }, m_top{0} 
	{}

	~Stack(){
		delete [] m_storage;
	}

	// Copy Constructor
	Stack(const Stack& other) : m_capacity{other.m_capacity}, m_storage{ new T[m_capacity]}, m_top{other.m_top}{
		std::copy(&other.m_storage[0], &other.m_storage[other.m_top], m_storage);
	}

	// Assignment
	Stack& operator=(const Stack& other){
		if(this != &other){
			delete [] m_storage;
			m_storage = new T[other.m_capacity];
			std::copy(&other.m_storage[0], &other.m_storage[other.m_top], m_storage)
		}
		return  *this;
	}

	[[nodiscard]] bool full() const {return m_top == m_capacity;}
	[[nodiscard]] bool empty() const {return m_top == m_capacity;}
	[[nodiscard]] size_t size() const {return m_top == m_capacity;}
	[[nodiscard]] size_t capacity() const {return m_top == m_capacity;}


	bool push(const T& value){
		if(full()){
			return false;
		}
		m_storage[m_top++] = value;
		return true;
	}

	bool pop(){
		if(empty()){
			return false;
		}
		--m_top;
		return true;
	}

	const T& top(T& value){
		if(empty()){
			return false;
		}
		value = m_storage[m_top-1];
		return true;
	}
};

constexpr size_t size{20};

int main(){
	Stack<int> s(size);

	for(int i = 0; i < size; ++i){
		s.push(i+1);
	}



/*
	if(not s.empty()){
		std::cout << s.top()
	}

*/

}