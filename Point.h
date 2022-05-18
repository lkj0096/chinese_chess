#pragma once

//Just x, y
class Point {
public:
	int x;
	int y;
	Point() {
		x = y = 0;
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
		return x < 2 || y < 2 || x > 7 || y > 8;
	}
};