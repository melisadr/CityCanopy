#include "exporterwrf.h"

ExporterWRF::ExporterWRF()
{

}

ExporterWRF::~ExporterWRF()
{

}

void ExporterWRF::exportData(DataManager* dataManager){
    int ncols = dataManager->getColsSize();
    int nrows = dataManager->getRowsSize();
    float lonMin = dataManager->getLonMin();
    float latMin = dataManager->getLatMin();
    float cellsize = dataManager->getCellSize();

    writeData(dataManager->getData().data(),ncols,nrows);
    writeIndexData(ncols,nrows,lonMin,latMin,cellsize);
}

void ExporterWRF::writeIndexData(int ncols,int nrows,float lonMin,float latMin,float cellsize){
    QFile file;
    file.setFileName("index");
    if( file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << "type=categorical" << endl;
        out << "category_min=31" << endl;
        out << "category_max=33" << endl;
        out << "projection=regular_ll" << endl;
        out << "dx=" << cellsize << endl;
        out << "dy=" << cellsize << endl;
        out << "known_x=1.0" << endl;
        out << "known_y=1.0" << endl;
        out << "known_lat=" << latMin << endl;
        out << "known_lon=" << lonMin << endl;
        out << "wordsize=1" << endl;
        out << "tile_x=" << ncols << endl;
        out << "tile_y=" << nrows << endl;
        out << "tile_z=1" << endl;
        out << "missing_value = 0" << endl;
        out << "units=\"category\"" << endl;
        out << "description=\"3-category urban LU\"" << endl;
        file.close();
    }
}

