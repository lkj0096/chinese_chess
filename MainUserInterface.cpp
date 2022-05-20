#include "MainUserInterface.h"
#include <thread>

MainUserInterface::MainUserInterface(int argc, char* argv[]) {
	this->argc = argc;
	this->argv = argv;
	a = nullptr;
	forms = nullptr;
}

void MainUserInterface::run() {
	std::thread t_ui([&] {
		a = new QApplication(argc, argv);
		forms = new All_form();
		forms->set_interface(this);
		a->exec();
	});
	t_ui.join();
}

void MainUserInterface::LoadGame() {
	//void (MainUserInterface::* func)() = &MainUserInterface::setX;
	//(this->*func)();
	user.LoadGame(this, &MainUserInterface::setX);
}