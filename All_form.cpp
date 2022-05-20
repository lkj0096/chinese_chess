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
	form_lobb_host = new Lobby();
	form_lobb_client = new Lobby();
    form_multi = new Multiplayer();
    form_set = new Settings();
	showform(form_main);

	connect(form_main, &MainWindow::maintointe, [=](string str) {
		if (str == "single") {
			showform(form_sing);
		}
		else if (str == "multi") {
			showform(form_multi);
		}
		else if (str == "endapp") {
			main_in->QuitAPP();
		}
	});

	connect(form_sing, &Single::singtointe, [=](string str) {
		if (str == "back") {
			//call 4j
			
			showform(form_main);
		}
		else if (str == "self") {
			//call 
			showform(form_board);
			form_board->game_start(1);
		}
		else if (str == "AI") {
			//call 4j
			showform(form_board);
			form_board->game_start(1);
		}
		else if (str == "load") {
			QString Filename = QFileDialog::getOpenFileName(form_sing,
					"Open File", __FILE__, "Text Files (*.txt)");
			qDebug() << Filename;
			if (!Filename.isEmpty() && Filename.endsWith(".txt")) {
				//call 4j
				main_in->LoadGame();
				showform(form_board);
				form_board->game_start(1);
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
			
			showform(form_main);
			//call 4j
		}
		else if (str == "create") {
			// ???
			main_in->CreateRoom();
			showform(form_lobb_host);
			//call 4j
		}
		else if (str == "join") {
			// ???
			// kick2p vis
			try {
				main_in->JoinRoom(form_multi->get_addr().toStdString());
				showform(form_lobb_client);
			}
			catch (const char* str) {

			}
			//call 4j
		}
	});

	connect(form_lobb_host, &Lobby::lobtointe, [=](string str) {
		if (str == "back") {
			
			main_in->CloseHost();
			showform(form_multi);
			//call 4j
		}
		else if (str == "start") {
			// ???
			//call 4j
			main_in->StartOnlineGame();
			showform(form_board);
			form_board->game_start(1);
		}
		else if (str == "kickp2") {
			// ???
			//call 4j
		}
	});

	connect(form_lobb_client, &Lobby::lobtointe, [=](string str) {
		if (str == "back") {
			
			main_in->CloseClient();
			showform(form_multi);
			//call 4j
		}
		//else if (str == "start") {
		//	// ???
		//	//call 4j
		//	main_in->StartOnlineGame();
		//	showform(form_board);
		//	form_board->game_start(1);
		//}
		else if (str == "kickp2") {
			// ???
			//call 4j
		}
	});

	connect(form_board, &qtui_ChessBoard::chesstointe, [=] (string str){
		if (str == "RDsurr") {
			//call 4j
			main_in->Surr("RDsurr");
			showform(form_main);
		}
		else if (str == "BLsurr") {
			// ???
			//call 4j
			main_in->Surr("BLsurr");
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
	form_lobb_host->hide();
	form_lobb_client->hide();
	form_sing->hide();
	form_multi->hide();
	form_set->hide();
	w->show();
}
