#include "mainwindow.hh"
#include "SensorData.hh"

#include <QWebFrame>
#include <QStringList>

#include <QDebug>

/*
 * Default Constructor
 */
MainWin::MainWin(QWidget * parent) : QWebView(parent)
{
    // qrc:// URLs refer to resources. See imagenalayzer.qrc
    // Load web content now!
    setUrl(QUrl("qrc:/index.html"));
    
    sensorData = new SensorData();
    
QObject::connect(page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
                     this, SLOT(onPageInit()));    
}

void MainWin::onPageInit() 
{
    page()->mainFrame()->addToJavaScriptWindowObject(QString("sensorData"), sensorData);
    qDebug() << sensorData->getTemps();
}