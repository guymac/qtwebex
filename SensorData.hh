#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <QString>
#include <QStringList>
#include <QVariant>

class SensorData : public QObject
{
    
    Q_OBJECT
    
public:
    SensorData();
    ~SensorData();

    Q_PROPERTY(QString versionId READ getVersionId);


    const QString& getVersionId() const { return versionId; }

    Q_INVOKABLE const QVariantMap getTemps() const;

private:
    QString versionId;
};
#endif