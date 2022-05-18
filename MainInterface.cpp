#include "MainInterface.h"
#include <thread>
void MainInterface::run() {
	std::thread t_ui([=] {
		
	});
	t_ui.join();
	a.exec();
}