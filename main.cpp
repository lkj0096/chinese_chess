#include "MainUserInterface.h"

int main(int argc, char *argv[]){
    //qDebug() << "123456";
    //QApplication* a = new QApplication(argc, argv);
    MainUserInterface inter(argc, argv);
    //QThread* t1 = new QThread();
    //t1->moveToThread(t1);
    //QObject::connect(t1, &QThread::started, [&] {  });
    
    inter.run();
    //inter.run();
    return 0;
}
