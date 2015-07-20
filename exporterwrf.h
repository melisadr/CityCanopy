#ifndef EXPORTERWRF_H
#define EXPORTERWRF_H
#include "exporter.h"
#include "datamanager.h"

class ExporterWRF : public Exporter
{
public:
    ExporterWRF();
    ~ExporterWRF();
    void exportData(DataManager* dataManager);

private:
    void writeIndexData(int ncols,int nrows,float lonMin,float latMin,float cellsize);
};

#endif // EXPORTERWRF_H
