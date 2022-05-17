#pragma once
#include <vector>
#include <iostream>

using namespace std;

class DebugLogger {
public:
	template <class T>
	static void Print(int code, long line, std::vector<T> items);
};

template<class T>
inline void DebugLogger::Print(int code, long line, std::vector<T> items) {
	switch (code) {
		//Network
	case 0:
		return;
	default:
		return;
	}

	cout << "Line : " << line << " || ";
	for (T item : items) {
		cout << item << " ";
	}
	cout << endl;

}
