#include "gpsvalise.h"
#include <QString>
#include <QUrl>


GPS::GPS()
{

}
void GPS::search(const QString & Address )
{
    QUrl url = QString( "http://maps.google.fr/maps?f=q&hl=fr&q=%1" )
       .arg( Address );


    if ( !QDesktopServices::openUrl( url ) )
    {
        // echec
    }
}
