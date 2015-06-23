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
};

#endif // TOPOFIGURE_H
