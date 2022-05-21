#include "MainUserInterface.h"
#include <thread>

MainUserInterface::MainUserInterface(int argc, char* argv[]) :user(this), QObject(nullptr) {
	this->argc = argc;
	this->argv = argv;
	//connect();
}

void MainUserInterface::run() {
	a = new QApplication(argc, argv);
	forms = new All_form();
	forms->set_interface(this);
	a->exec();
}