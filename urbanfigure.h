#ifndef URBANFIGURE_H
#define URBANFIGURE_H
#include "figure.h"
#include "datamanager.h"
#include "topofigure.h"
#include <QVector3D>

class UrbanFigure : public Figure
{
public:
    UrbanFigure();
    ~UrbanFigure();
    void load(DataManager* dataManager, float width, float height) ;
    void load(DataManager *dataManager, float width, float height, TopoFigure *figure);

private:
    void addQuad(QVector3D v1, QVector3D v2, QVector3D v3,QVector3D v4,QVector3D color);

};

#endif // URBANFIGURE_H
