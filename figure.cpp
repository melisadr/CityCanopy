#include "figure.h"

Figure::Figure() : m_count(0)
{

}

Figure::~Figure()
{

}

void Figure::add(const QVector3D &v, const QVector3D &n, const QVector3D &c)
{
    m_data.append(v.x());
    m_data.append(v.y());
    m_data.append(v.z());
    m_data.append(n.x());
    m_data.append(n.y());
    m_data.append(n.z());
    m_data.append(c.x());
    m_data.append(c.y());
    m_data.append(c.z());
    m_count += 9;
}

