#ifndef EXPORTER_H
#define EXPORTER_H
#include "datamanager.h"

class Exporter
{
public:

    Exporter();
    ~Exporter();
    void writeData(float *data, int ncols, int nrows);

private:
    QVector<float> m_data;

};

#endif // EXPORTER_H
