#ifndef ARMBUTTONS_H
#define ARMBUTTONS_H

#include <QtGui/QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>

class ArmButtons : public QGroupBox
{
    Q_OBJECT

public:
    ArmButtons(QWidget *parent = 0);
    ~ArmButtons();
    void indicate(int ,int );
private:
    QPushButton *button;

private slots:
    void actionPerformed();
signals:
    void manipulatorAction(int , int );
};

#endif // ARMBUTTONS_H
