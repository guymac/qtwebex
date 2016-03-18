#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWebView>

#include "SensorData.hh"

class MainWin : public QWebView
{
    Q_OBJECT

public:
    explicit MainWin(QWidget * parent = 0);

private:
    SensorData* sensorData;
    
private slots:
    void onPageInit();

};
#endif