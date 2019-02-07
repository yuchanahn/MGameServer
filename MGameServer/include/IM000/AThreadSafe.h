#pragma once
#include <atomic>
#include <functional>

template <typename T>
class AThreadSafe
{

	std::atomic<int> guard_ = 1;

public:
	T data_;

	AThreadSafe(T data);
	~AThreadSafe();

	void Get(std::function<void()>);
};


template<typename T>
inline AThreadSafe<T>::AThreadSafe(T data)
	:data_(data)
{}


template<typename T>
inline AThreadSafe<T>::~AThreadSafe()
{
}

template<typename T>
inline void AThreadSafe<T>::Get(std::function<void()> func)
{
	while (1) {
		if (guard_.load(std::memory_order_acquire) != 0)
		{
			guard_.store(0, std::memory_order_release);
			func();
			guard_.store(1, std::memory_order_release);
			return;
		}
	}

}
