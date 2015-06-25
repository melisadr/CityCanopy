#ifndef EXPORTERWRF_H
#define EXPORTERWRF_H
#include "exporter.h"
#include "datamanager.h"

class ExporterWRF : public Exporter
{
public:
    ExporterWRF();
    ~ExporterWRF();
    void exportData(DataManager &dataManager);
};

#endif // EXPORTERWRF_H
