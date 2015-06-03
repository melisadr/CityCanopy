#ifndef URBANDATAMANAGER_H
#define URBANDATAMANAGER_H
#include "datamanager.h"

class UrbanDataManager : public DataManager
{
public:
    UrbanDataManager();
    ~UrbanDataManager();
    void load(const QString filename);

private:
    float xllcorner;
    float yllcorner;
};

#endif // URBANDATAMANAGER_H
