#ifndef TOPOFIGURE_H
#define TOPOFIGURE_H
#include "figure.h"
#include "datamanager.h"
class TopoFigure : public Figure
{
public:
    TopoFigure();
    ~TopoFigure();
    void load(DataManager &dataManager);

private:
    void finalNormals(DataManager &dataManager,float mScale,float hScale);
};

#endif // TOPOFIGURE_H
