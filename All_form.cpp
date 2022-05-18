#include "MainUserInterface.h"
#include "All_form.h"
#include <string>
#include <QFileDialog>
#include <QMessageBox>
using std::string;

All_form::All_form(QWidget* parent)
	: QObject(parent) {
	form_main = new MainWindow();
	form_sing = new Single();
	form_board = new qtui_ChessBoard();
	form_lobb = new Lobby();
    form_multi = new Multiplayer();
    form_set = new Settings();
	showform(form_main);

	connect(form_main, &MainWindow::maintointe, [=](string str) {
		if (str == "single") {
			main_in->SingleGame();
			showform(form_sing);
		}
		else if (str == "multi") {
			main_in->MultiGame();
			showform(form_multi);
		}
		else if (str == "endapp") {
			main_in->QuitAPP();
		}
	});

	connect(form_sing, &Single::singtointe, [=](string str) {
		if (str == "back") {
			//call 4j
			main_in->Back();
			showform(form_main);
		}
		else if (str == "self") {
			//call 4j
			main_in->PlaySelf();
			showform(form_board);
			form_board->game_start();
		}
		else if (str == "AI") {
			//call 4j
			main_in->PlayAI();
			showform(form_board);
			form_board->game_start();
		}
		else if (str == "load") {
			QString Filename = QFileDialog::getOpenFileName(form_sing,
					"Open File", __FILE__, "Text Files (*.txt)");
			qDebug() << Filename;
			if (!Filename.isEmpty() && Filename.endsWith(".txt")) {
				//call 4j
				main_in->LoadGame();
				showform(form_board);
				form_board->game_start();
			}
			else {
				QMessageBox msgBox;
				msgBox.setText("Something Error.");
				msgBox.exec();
			}
		}
	});
	
	connect(form_multi, &Multiplayer::multitointe, [=](string str) {
		if (str == "back") {
			main_in->Back();
			showform(form_main);
			//call 4j
		}
		else if (str == "create") {
			// ???
			main_in->CreateRoom();
			showform(form_lobb);
			//call 4j
		}
		else if (str == "join") {
			// ???
			main_in->JoinRoom("");
			showform(form_lobb);
			//call 4j
		}
	});

	connect(form_lobb, &Lobby::lobtointe, [=](string str) {
		if (str == "back") {
			main_in->Back();
			showform(form_multi);
			//call 4j
		}
		else if (str == "start") {
			// ???
			//call 4j
			main_in->StartOnlineGame();
			showform(form_board);
			form_board->game_start();
		}
		else if (str == "kickp2") {
			// ???
			//call 4j
		}
	});

	connect(form_board, &qtui_ChessBoard::chesstointe, [=] (string str){
		if (str == "RDsurr") {
			//call 4j
			main_in->LeaveGame();
			showform(form_main);
		}
		else if (str == "BLsurr") {
			// ???
			//call 4j
			main_in->LeaveGame();
			showform(form_main);
		}
		else if (str == "Savelog") {
			// ???
			//call 4j
		}
	});

	connect(form_board, &qtui_ChessBoard::chess_pressed, [=](Point pt) {
		main_in->ChessPressed(pt);
	});

	connect(form_board, &qtui_ChessBoard::hint_pressed, [=](Point pt1, Point pt2) {
		main_in->HintPressed(pt1, pt2);
	});
}

void All_form::showform(QMainWindow* w) {
	form_main->hide();
	form_board->hide();
	form_lobb->hide();
	form_sing->hide();
	form_multi->hide();
	form_set->hide();
	w->show();
}
