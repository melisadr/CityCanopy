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
    float mScale;
    QVector3D color(0.5,0.5,0.5);

    if(ncols >= nrows){
        mScale = 1.0f/(ncols-1);
    }else{
        mScale = 1.0f/(nrows-1);
    }

    // vertex i,j normal := m_normals[i*ncols+j]
    finalNormals(dataManager,mScale);

    for(int i = 0; i < nrows-1; i++){
        for(int j = 0; j < ncols-1; j++){

            GLfloat x1 = mScale*(j - (ncols-1)/2.0f);
            GLfloat x2 = mScale*(j + 1 - (ncols-1)/2.0f);
            GLfloat y1 = mScale*((nrows-1)/2.0f - i);
            GLfloat y2 = mScale*((nrows-1)/2.0f - i - 1);

            GLfloat z11 = dataManager.getValue(i,j);
            GLfloat z12 = dataManager.getValue((i+1),j);
            GLfloat z22 = dataManager.getValue((i+1),(j+1));
            GLfloat z21 = dataManager.getValue(i,(j+1));

            QVector3D v1(x1,y1,z11);
            QVector3D v2(x1,y2,z12);
            QVector3D v3(x2,y2,z22);
            QVector3D v4(x2,y1,z21);

            add(v1,m_normals[i*ncols+j],color);
            add(v2,m_normals[(i+1)*ncols+j],color);
            add(v3,m_normals[(i+1)*ncols+j+1],color);

            add(v1,m_normals[i*ncols+j],color);
            add(v3,m_normals[(i+1)*ncols+j+1],color);
            add(v4,m_normals[i*ncols+j+1],color);
        }
    }
}

void TopoFigure::finalNormals(DataManager &dataManager,float mScale )
{
    int ncols = dataManager.getColsSize();
    int nrows = dataManager.getRowsSize();

    m_normals.resize(ncols*nrows);
    for( int k = 0; k < ncols*nrows ; ++k){
        m_normals[k] = QVector3D(0.0,0.0,0.0);
    }

    for(int i = 0; i < nrows-1; i++){
        for(int j = 0; j < ncols-1; j++){

            GLfloat x1 = mScale*(j - (ncols-1)/2.0f);
            GLfloat x2 = mScale*(j + 1 - (ncols-1)/2.0f);
            GLfloat y1 = mScale*((nrows-1)/2.0f - i);
            GLfloat y2 = mScale*((nrows-1)/2.0f - i - 1);

            GLfloat z11 = dataManager.getValue(i,j);
            GLfloat z12 = dataManager.getValue((i+1),j);
            GLfloat z22 = dataManager.getValue((i+1),(j+1));
            GLfloat z21 = dataManager.getValue(i,(j+1));

            QVector3D v1(x1,y1,z11);
            QVector3D v2(x1,y2,z12);
            QVector3D v3(x2,y2,z22);
            QVector3D v4(x2,y1,z21);

            QVector3D n1 = QVector3D::normal(v2-v1,v3-v1);
            QVector3D n2 = QVector3D::normal(v3-v1,v4-v1);

            m_normals[i*ncols + j] = (n1+m_normals[i*ncols+j]).normalized();
            m_normals[(i+1)*ncols+j] = (n1+m_normals[(i+1)*ncols+j]).normalized();
            m_normals[(i+1)*ncols+j+1] = (n1+m_normals[(i+1)*ncols+j+1]).normalized();

            m_normals[i*ncols+j] = (n2+m_normals[i*ncols+j]).normalized();
            m_normals[(i+1)*ncols+j+1] = (n2+m_normals[(i+1)*ncols+j+1]).normalized();
            m_normals[i*ncols+j+1] = (n2+m_normals[i*ncols+j+1]).normalized();
        }
    }
}
