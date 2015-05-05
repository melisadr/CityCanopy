#include "figure.h"

Figure::Figure() : m_count(0)
{

}

Figure::~Figure()
{

}

void Figure::add(const QVector3D &v, const QVector3D &n)
{
    m_data.append(v.x());
    m_data.append(v.y());
    m_data.append(v.z());
    m_data.append(n.x());
    m_data.append(n.y());
    m_data.append(n.z());
    m_count += 6;
}

void Figure::quad(QVector3D &v1, QVector3D &v2, QVector3D &v3, QVector3D &v4)
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

