#include "exporterwrf.h"

ExporterWRF::ExporterWRF()
{

}

ExporterWRF::~ExporterWRF()
{

}

void ExporterWRF::exportData(DataManager &dataManager){
    int ncols = dataManager.getColsSize();
    int nrows = dataManager.getRowsSize();

    writeData(dataManager.getData().data(),ncols,nrows);
}

