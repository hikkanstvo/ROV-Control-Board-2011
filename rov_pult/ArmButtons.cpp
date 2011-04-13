#include "ArmButtons.h"


ArmButtons::ArmButtons(QWidget *parent)
    : QGroupBox(parent)
{
        this->setTitle("Arm");
        button=new QPushButton[4];

        button[0].setText("UP");
        button[1].setText("RELEASE");
        button[2].setText("CATCH");
        button[3].setText("DOWN");
        button[0].setMinimumSize(250,75);
        button[1].setMinimumSize(250,75);
        button[2].setMinimumSize(250,75);
        button[3].setMinimumSize(250,75);

        QVBoxLayout *lay=new QVBoxLayout;
        lay->addWidget(&button[0]);
        lay->addWidget(&button[1]);
        lay->addWidget(&button[2]);
        lay->addWidget(&button[3]);
        this->setLayout(lay);

        connect(&button[0], SIGNAL(pressed()), this, SLOT(actionPerformed()));
        connect(&button[1], SIGNAL(pressed()), this, SLOT(actionPerformed()));
        connect(&button[2], SIGNAL(pressed()), this, SLOT(actionPerformed()));
        connect(&button[3], SIGNAL(pressed()), this, SLOT(actionPerformed()));
 }

ArmButtons::~ArmButtons()
{
    delete [] button;
}

void ArmButtons::actionPerformed()
{
     int s=qobject_cast<QPushButton*>(sender())-button;
     if(s==0)//up
     {  emit manipulatorAction(1,0);}
     else if(s==1)//release
     {  emit manipulatorAction(0,-1);}
     else if(s==2)//catch
     {  emit manipulatorAction(0,1);}
     else if(s==3)//down
     {  emit manipulatorAction(-1,0);}
}
////public/////////////////////////////////////////////////////

void ArmButtons::indicate(int UD,int RC)
{
    button[0].setCheckable(true);
    button[0].setChecked(true);
    button[0].setEnabled(false);
    if(UD==0)
    {
        button[0].setCheckable(false);
        button[3].setCheckable(false);
        button[0].setEnabled(true);
        button[3].setEnabled(true);
    }
    else if(UD==1)//up
    {
        button[0].setCheckable(true);
        button[0].setChecked(true);
        button[0].setEnabled(false);
        button[3].setEnabled(false);
    }
    else if(UD==-1)//down
    {
        button[3].setCheckable(true);
        button[3].setChecked(true);
        button[3].setEnabled(false);
        button[0].setEnabled(false);
    }

    if(RC==0)
    {
        button[1].setCheckable(false);
        button[2].setCheckable(false);
        button[1].setEnabled(true);
        button[2].setEnabled(true);
    }
    else if(RC==1)//catch
    {
        button[2].setCheckable(true);
        button[2].setChecked(true);
        button[2].setEnabled(false);
        button[1].setEnabled(false);
    }
    else if(RC==-1)//release
    {
        button[1].setCheckable(true);
        button[1].setChecked(true);
        button[1].setEnabled(false);
        button[2].setEnabled(false);
    }
}


