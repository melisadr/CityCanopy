#ifndef TOPODATAMANAGER_H
#define TOPODATAMANAGER_H
#include "datamanager.h"


class TopoDataManager : public DataManager
{
public:
    TopoDataManager();
    ~TopoDataManager();
    void load(const QString filename);

private:
    float xllcorner;
    float yllcorner;
};

#endif // TOPODATAMANAGER_H
