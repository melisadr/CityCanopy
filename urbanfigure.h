#ifndef URBANFIGURE_H
#define URBANFIGURE_H
#include "figure.h"
#include "datamanager.h"
#include <QVector3D>

class UrbanFigure : public Figure
{
public:
    UrbanFigure();
    ~UrbanFigure();
    void load(DataManager &dataManager);

private:
    void finalNormals(DataManager &dataManager,float mScale);
    void addQuad(QVector3D v1, QVector3D v2, QVector3D v3,QVector3D v4);

};

#endif // URBANFIGURE_H
