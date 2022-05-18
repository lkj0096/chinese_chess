#pragma once
#include <QtWidgets/QApplication>
#include <string>
#include <vector>
#include "All_form.h"
using std::string, std::vector;

class MainInterface {
	QApplication a;
	All_form forms;
public:
	MainInterface(int argc, char* argv[]) : forms(), a(argc, argv){};
	void run();
};