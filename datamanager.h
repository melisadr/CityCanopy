#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <QFile>
#include <QTextStream>
#include <QVector>

class DataManager
{
public:
    DataManager(){}
    ~DataManager(){}
    void load(const QString filename); //override this function
    QVector<float> getData() { return m_data; }
    float getValue(int i, int j){ return m_data[i*ncols + j]; }
    float getCellSize(){ return cellsize; }
    int getColsSize(){ return ncols;}
    int getRowsSize(){ return nrows;}
    int getNoValue(){ return NODATA_value;}

protected:
    QVector<float> m_data;
    int ncols;
    int nrows;
    int NODATA_value;
    float cellsize;
};

#endif // DATAMANAGER_H
