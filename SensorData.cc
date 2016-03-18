#include <sensors/sensors.h>
#include "SensorData.hh"
#include <QRegExp>
#include <QDebug>

static QRegExp QREGEXP_NONWORD ("\\W+");

SensorData::SensorData()
{
   if (sensors_init(NULL)) return;
 
   versionId = libsensors_version;
}

SensorData::~SensorData()
{
    sensors_cleanup();
}

const QVariantMap SensorData::getTemps() const
{
    QVariantMap temps = QVariantMap();
    sensors_chip_name const * cn;
    char * str = new char[128];
    
    for (int c = 0; (cn = sensors_get_detected_chips(0, &c)) ; )
    {  

        if (sensors_snprintf_chip_name(str, 128, cn) <= 0)
        {
            continue;
        }
        
        sensors_feature const * feat;

        for (int f = 0 ; (feat = sensors_get_features(cn, &f)) ; ) 
        {
            if (feat->type != SENSORS_FEATURE_TEMP) continue;
        
            sensors_subfeature const * subfeat;
     
            for (int sf = 0 ; (subfeat = sensors_get_all_subfeatures(cn, feat, &sf)) ; ) 
            {
                if (subfeat->type != SENSORS_SUBFEATURE_TEMP_INPUT) continue;
            
                double val;
                QString id = QString("%1.%2.%3").arg(str).arg(feat->name).arg(subfeat->name);
            
                id.replace(QREGEXP_NONWORD, "_");

                if (subfeat->flags & SENSORS_MODE_R) 
                {
                    int rc = sensors_get_value(cn, subfeat->number, &val);
                
                    if (rc >= 0) 
                    {
                        //qDebug() << id << " = " << val;
                        temps.insert(id, QVariant(val));
                    }
                    else
                    {
                        qDebug() << id << " returned " << rc;                        
                    }
                }
            }
        }
        
    }
    
    delete str; 
    return temps;
}
