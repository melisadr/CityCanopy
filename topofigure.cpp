#include "topofigure.h"
#include <QVector3D>
#include <QDebug>

TopoFigure::TopoFigure()
{

}

TopoFigure::~TopoFigure()
{

}

void TopoFigure::load(DataManager &dataManager)
{
    int ncols = dataManager.getColsSize();
    int nrows = dataManager.getRowsSize();
    GLfloat xscale = 10.0;
    GLfloat yscale = 10.0;
    for(int i = 0; i < nrows-1; i++){
        for(int j = 0; j < ncols-1; j++){
            if(dataManager.getNoValue() != dataManager.getValue(i,j)){

                QVector3D v1((GLfloat)i*xscale,(GLfloat)j*yscale,(GLfloat)dataManager.getValue(i,j));
                QVector3D v2((GLfloat)(i+1)*xscale,(GLfloat)j*yscale,(GLfloat)dataManager.getValue((i+1),j));
                QVector3D v3((GLfloat)(i+1)*xscale,(GLfloat)(j+1)*yscale,(GLfloat)dataManager.getValue((i+1),(j+1)));
                QVector3D v4((GLfloat)i*xscale,(GLfloat)(j+1)*yscale,(GLfloat)dataManager.getValue(i,(j+1)));
                //qDebug() << v1 << v2 << v3 << v4;
                quad(v1,v2,v3,v4);
            }
        }
    }
}
