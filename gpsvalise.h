#ifndef GPSVALISE_H
#define GPSVALISE_H
#include <QString>
#include <QDesktopServices>
#include "gestion_activite.h"
#include "ui_gestion_etablissement.h"



using namespace  std ;

class GPS
{
public:
    GPS();
     void search(const QString &Address);

};
#endif // GPSVALISE_H
