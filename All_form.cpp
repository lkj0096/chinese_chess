#include "All_form.h"
#include <string>
#include <QFileDialog>
#include <QMessageBox>
using std::string;

All_form::All_form(QWidget* parent)
	: QObject(parent) {
	
	showform(&form_main);

	connect(&form_main, &MainWindow::maintointe, [=](string str) {
		if (str == "single") {
			//call 4j
			showform(&form_sing);
		}
		else if (str == "multi") {
			//call 4j
			showform(&form_multi);
		}
	});

	connect(&form_sing, &Single::singtointe, [=](string str) {
		if (str == "back") {
			//call 4j
			showform(&form_main);
		}
		else if (str == "self") {
			//call 4j
			showform(&form_board);
			form_board.game_start();
		}
		else if (str == "AI") {
			//call 4j
			showform(&form_board);
			form_board.game_start();
		}
		else if (str == "load") {
			QString Filename = QFileDialog::getOpenFileName(&form_sing,
					"Open File", __FILE__, "Text Files (*.txt)");
			qDebug() << Filename;
			if (!Filename.isEmpty() && Filename.endsWith(".txt")) {
				//call 4j
				showform(&form_board);
				form_board.game_start();
			}
			else {
				QMessageBox msgBox;
				msgBox.setText("Something Error.");
				msgBox.exec();
			}
		}
	});
	
	connect(&form_multi, &Multiplayer::multitointe, [=](string str) {
		if (str == "back") {
			showform(&form_main);
			//call 4j
		}
		else if (str == "create") {
			// ???
			showform(&form_lobb);
			//call 4j
		}
		else if (str == "join") {
			// ???
			showform(&form_lobb);
			//call 4j
		}
	});

	connect(&form_lobb, &Lobby::lobtointe, [=](string str) {
		if (str == "back") {
			showform(&form_multi);
			//call 4j
		}
		else if (str == "start") {
			// ???
			//call 4j
			showform(&form_board);
			form_board.game_start();
		}
		else if (str == "kickp2") {
			// ???
			//call 4j
		}
	});
}
