#pragma once
#include <sstream>
#include <iomanip>
#include <string>
//Just x, y
class Point {
public:
	int x;
	int y;
	Point() {
		x = y = 0;
	}
	Point(std::string str) {
		x = stoi(str.substr(0, 2));
		y = stoi(str.substr(3, 2));
	}
	/// <summary>
	/// Just Constructor Ok?
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	/// <summary>
	///  If position out of Board
	/// </summary>
	/// <returns></returns>
	bool NotVaild() {
		return x < 2 || y < 2 || x > 10 || y > 11;
	}

	std::string toString() {
		std::stringstream ss;
		ss << std::setw(2) << std::setfill('0') << x << ":" << std::setw(2) << std::setfill('0') << y;
		std::string s = ss.str();
		return s;
	}
};