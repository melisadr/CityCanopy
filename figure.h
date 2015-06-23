#ifndef FIGURE_H
#define FIGURE_H
#include <qopengl.h>
#include <QVector>
#include <QVector3D>
#include "datamanager.h"
class Figure
{
public:
    Figure();
    ~Figure();
    const GLfloat *constData() const { return m_data.constData(); }
    int count() const { return m_count; }
    int vertexCount() const { return m_count / 6; }
    void load(DataManager &dataManager);

protected:
    void add(const QVector3D &v, const QVector3D &n);
    void quad(QVector3D &v1, QVector3D &v2, QVector3D &v3, QVector3D &v4);
    QVector<GLfloat> m_data;
    int m_count;
};

#endif // FIGURE_H
