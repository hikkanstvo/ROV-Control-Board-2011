#include "autopilotbuttons.h"

AutoPilotButtons::AutoPilotButtons(QWidget *parent)
    : QGroupBox(parent)
{
    this->setTitle("AutoPilot");
    button=new QCheckBox[3];

    button[0].setText("AutoPitch");
    button[1].setText("AutoDepth");
    button[2].setText("AutoHead");

    button[0].setMinimumSize(250,75);//pitch
    button[1].setMinimumSize(250,75);//depth
    button[2].setMinimumSize(250,75);//head

    QVBoxLayout *lay=new QVBoxLayout;
    lay->addWidget(&button[0]);
    lay->addWidget(&button[1]);
    lay->addWidget(&button[2]);
    this->setLayout(lay);

    connect(&button[0], SIGNAL(toggled(bool)),this, SIGNAL(autoPitchToggled(bool)));
    connect(&button[1], SIGNAL(toggled(bool)),this, SIGNAL(autoDepthToggled(bool)));
    connect(&button[2], SIGNAL(toggled(bool)),this, SIGNAL(autoHeadToggled(bool)));

}

AutoPilotButtons::~AutoPilotButtons()
{
    delete [] button;
}

////public/////////////////////////////////////////////////////
void AutoPilotButtons::indicatePDH(bool APitch,bool ADepth,bool AHead)
{
    button[0].setChecked(APitch);
    button[1].setChecked(ADepth);
    button[2].setChecked(AHead);
}

bool AutoPilotButtons::isAutoPitch()
{
    return button[0].isChecked();
}
bool AutoPilotButtons::isAutoDepth()
{
    return button[1].isChecked();
}
bool AutoPilotButtons::isAutoHead()
{
    return button[2].isChecked();
}


