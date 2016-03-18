TEMPLATE = app
HEADERS = mainwindow.hh SensorData.hh
SOURCES = temps.cc mainwindow.cc SensorData.cc

QT += webkit

QMAKE_CXXFLAGS += -std=c++11

RESOURCES = resources.xml

INCLUDEPATH += /usr/include/sensors/
LIBS += -lsensors
