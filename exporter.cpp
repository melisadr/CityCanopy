#include "exporter.h"
#include "write_geogrid.c"
#include <QDebug>

Exporter::Exporter()
{

}

Exporter::~Exporter()
{

}

void Exporter::writeData(float *data, int ncols, int nrows){
    int nz = 1;
    int isigned = 0;
    int endian = 1;
    float scalefactor = 1.0;
    int wordsize = 1;

    m_data.resize(ncols * nrows);
    float* p = m_data.data();

    for (int i = nrows-1 ; i >= 0 ; i--){
        for (int j = 0; j < ncols ; j++){
            *p++ = data[i*ncols + j];
        }
    }
    write_geogrid(m_data.data(),&ncols,&nrows,&nz,&isigned,&endian,&scalefactor,&wordsize);

}
