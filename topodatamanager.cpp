#include "topodatamanager.h"
#include <QDebug>
#include <QMessageBox>

TopoDataManager::TopoDataManager()
{

}

TopoDataManager::~TopoDataManager()
{

}

void TopoDataManager::load(const QString fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QTextStream fileStream(&file);

    //get ncols and nrows

    QString line = fileStream.readLine();
    QStringList auxLine =  line.split(" ", QString::SkipEmptyParts);
    ncols = auxLine[1].toInt();
    qDebug() << "Cols" << ncols;

    line = fileStream.readLine();
    auxLine =  line.split(" ", QString::SkipEmptyParts);
    nrows = auxLine[1].toInt();
    qDebug() << "Rows" << nrows;

    //get maps attributes

    line = fileStream.readLine();
    auxLine =  line.split(" ", QString::SkipEmptyParts);
    xllcorner = auxLine[1].toFloat();

    line = fileStream.readLine();
    auxLine =  line.split(" ", QString::SkipEmptyParts);
    yllcorner = auxLine[1].toFloat();

    line = fileStream.readLine();
    auxLine =  line.split(" ", QString::SkipEmptyParts);
    cellsize = auxLine[1].toFloat();

    line = fileStream.readLine();
    auxLine =  line.split(" ", QString::SkipEmptyParts);
    NODATA_value = auxLine[1].toInt();

    m_data.resize(nrows * ncols);
    float *p_aux = m_data.data();

    int i, j;
    i = j = 0;

    while(i < nrows) {
        line = fileStream.readLine();
        auxLine = line.split(" ",QString::SkipEmptyParts);
        for(j = 0; j < ncols; ++j){
            *p_aux++ = auxLine[j].toFloat() / 1000.0;
        }
        ++i;
    }

    file.close();

}

