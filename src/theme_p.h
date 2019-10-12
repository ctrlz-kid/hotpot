#ifndef THEMEPRIVATE_H
#define THEMEPRIVATE_H

#include <QVector>
#include <QPair>
#include <QColor>
#include <QMap>

namespace Extras {

class  ThemePrivate
{
public:
    ThemePrivate();

    QString id;
    QString fileName;
    QString displayName;
    QVector<QPair<QColor, QString> > colors;
    QMap<QString, QColor> palette;
};

}
#endif // THEMEPRIVATE_H
