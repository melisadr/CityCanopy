#include "urbanfigure.h"
#include <QVector3D>
#include <QDebug>

UrbanFigure::UrbanFigure()
{

}

UrbanFigure::~UrbanFigure()
{

}

void UrbanFigure::load(DataManager &dataManager)
{
    int ncols = dataManager.getColsSize();
    int nrows = dataManager.getRowsSize();
    float mScale;

    if(ncols >= nrows){
        mScale = 1.0f/(ncols-1);
    }else{
        mScale = 1.0f/(nrows-1);
    }

    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){

            GLfloat xc = mScale*(j - (ncols-1)/2.0f);
            GLfloat yc = mScale*((nrows-1)/2.0f - i);
            GLfloat zc = dataManager.getValue(i,j);

            if(zc > 0.0f)
            {
                //draw a cube
                GLfloat x1 = xc - mScale/2.0f;
                GLfloat x2 = xc + mScale/2.0f;
                GLfloat y1 = yc - mScale/2.0f;
                GLfloat y2 = yc + mScale/2.0f;

                //vertices
                QVector3D v1(x1,y1,zc);
                QVector3D v2(x2,y1,zc);
                QVector3D v3(x2,y2,zc);
                QVector3D v4(x1,y2,zc);
                QVector3D v5(x1,y1,0.0f);
                QVector3D v6(x2,y1,0.0f);
                QVector3D v7(x2,y2,0.0f);
                QVector3D v8(x1,y2,0.0f);

                //top face
                addQuad(v1,v2,v3,v4);
                //lateral faces
                addQuad(v1,v5,v6,v2);
                addQuad(v2,v6,v7,v3);
                addQuad(v3,v7,v8,v4);
                addQuad(v4,v8,v5,v1);
            }
        }
    }
}

void UrbanFigure::addQuad(QVector3D v1, QVector3D v2, QVector3D v3,QVector3D v4)
{
    QVector3D n = QVector3D::normal(v2-v1,v3-v1);
    add(v1,n);
    add(v2,n);
    add(v3,n);
    n = QVector3D::normal(v3-v1,v4-v1);
    add(v1,n);
    add(v3,n);
    add(v4,n);
}
