#pragma once
#include <string>
#include <vector>
#include <regex>
#include "Point.h"

class DataConverter {
public:
	static std::string Serialize(std::string name, std::vector<Point> points) {
		std::string str = name + ":[";
		for (Point p : points) {
			str += p.toString() + ",";
		}
		str += "]";
		return str;
	}

	static std::vector<Point> DeSerializePoints(std::string str) {
		std::smatch sm;
		std::regex_search(str, sm, std::regex("\\[([^\\[\\]]*)\\]"));
		str = sm[1];
		std::regex r("\\d+:\\d+");
		std::vector<Point> points;
		for (std::sregex_iterator i = std::sregex_iterator(str.begin(), str.end(), r);
			i != std::sregex_iterator();
			++i) {
			points.push_back(Point(std::smatch(*i).str()));
		}
		return points;
	}
};