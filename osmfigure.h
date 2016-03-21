#ifndef OSMFIGURE_H
#define OSMFIGURE_H
#include "figure.h"
#include "datamanager.h"
#include "topofigure.h"
#include <QVector3D>

class OSMFigure : public Figure
{
public:
    OSMFigure();
    ~OSMFigure();
    void load(DataManager* dataManager, float width, float height) ;
    void load(DataManager *dataManager, float width, float height, TopoFigure *topoFigure);

private:
    void addQuad(QVector3D v1, QVector3D v2, QVector3D v3,QVector3D v4,QVector3D color);
};

#endif // OSMFIGURE_H
