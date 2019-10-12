#ifndef THEME_H
#define THEME_H

#include <QObject>
#include <QSettings>

namespace Extras {

class ThemePrivate;

class Theme : public QObject
{
    Q_OBJECT
public:
    explicit Theme(QObject *parent = 0);
    ~Theme();

    QColor color(int role) const;
    QColor palette(QString role);

    void readSettings(QSettings &settings);
    void setSomething(QSettings &settings, const QMetaEnum &e);

    ThemePrivate *d;
private:
    QPair<QColor, QString> readNamedColor(const QString &color) const;
};


Theme *creatorTheme();

void setCreatorTheme(Theme *theme);

}



#endif // THEME_H
