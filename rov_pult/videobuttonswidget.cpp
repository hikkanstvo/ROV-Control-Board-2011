#include "videobuttonswidget.h"

VideoButtonsWidget::VideoButtonsWidget(QWidget *parent)
    : QGroupBox(parent)
{   this->setTitle("Video");
    button=new QRadioButton[3];
    button[0].setText("1");
    button[1].setText("2");
    button[2].setText("3");

    button[0].setMinimumSize(250,75);
    button[1].setMinimumSize(250,75);
    button[2].setMinimumSize(250,75);

    QVBoxLayout* lay=new QVBoxLayout;
    lay->addWidget(&button[0]);
    lay->addWidget(&button[1]);
    lay->addWidget(&button[2]);
    this->setLayout(lay);

    connect(&button[0], SIGNAL(clicked()),this, SLOT(setActiveCamera()));
    connect(&button[1], SIGNAL(clicked()),this, SLOT(setActiveCamera()));
    connect(&button[2], SIGNAL(clicked()),this, SLOT(setActiveCamera()));

    indicate(1);
}

void VideoButtonsWidget::setActiveCamera()//если кликнули по кнопке
{
  activeCamera=qobject_cast<QRadioButton*>(sender())-button+1;
  emit cameraChanged(activeCamera);
}

VideoButtonsWidget::~VideoButtonsWidget()
{
    delete [] button;
}

////public/////////////////////////////////////////////////////
void VideoButtonsWidget::indicate(int n)
{
  activeCamera=n;
  button[n-1].setChecked(true);
}

int VideoButtonsWidget::getActiveCamera()
{
    return activeCamera;
}

