#include <QtGui/QApplication>
#include "ArmButtons.h"
#include <QFile>
#include <QMessageBox>
#include <QPalette>
#include <QColor>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    w.setGeometry(20,20,600,600);


    ArmButtons v;
    v.setParent(&w);
    v.move(20,20);

    QFile styleFile("trueStyle.qss");
    if(!styleFile.open(QFile::ReadOnly))
    {//if style file does not exists
        QMessageBox::critical(0,"Achtung!","Style file was not found!",QMessageBox::Close);
        return 1;
    }
    a.setStyleSheet(QString(styleFile.readAll()));

    w.show();

    return a.exec();
}
