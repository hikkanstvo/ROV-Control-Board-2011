#ifndef AUTOPILOTBUTTONS_H
#define AUTOPILOTBUTTONS_H

#include <QtGui/QWidget>
#include <QCheckBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFlags>

class AutoPilotButtons : public QGroupBox
{
    Q_OBJECT
private:
    QCheckBox * button;

public:
    void indicatePDH(bool APitch,bool ADepth, bool AHead);
    AutoPilotButtons(QWidget *parent = 0);
    ~AutoPilotButtons();
    bool isAutoPitch();
    bool isAutoDepth();
    bool isAutoHead();
signals:
    void autoPitchToggled(bool);
    void autoHeadToggled(bool);
    void autoDepthToggled(bool);
};

#endif // AUTOPILOTBUTTONS_H
