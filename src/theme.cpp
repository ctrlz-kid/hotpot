#include "theme.h"
#include "theme_p.h"
#include <QFileInfo>
#include <QMetaEnum>
#include <QPalette>
#include <QSettings>

namespace Extras {
    static Theme *m_creatorTheme = 0;

    Theme *creatorTheme()
    {
        return m_creatorTheme;
    }

    void setCreatorTheme(Theme *theme)
    {
        if (m_creatorTheme == theme)
            return;
        delete m_creatorTheme;
        m_creatorTheme = theme;
    }

    static QColor readColor(const QString &color)
    {
        bool ok = true;
        const QRgb rgba = color.toLongLong(&ok, 16);
        return QColor::fromRgba(rgba);
    }
}


using namespace Extras;


Theme::Theme(QObject *parent)
    : QObject(parent)
    , d(new ThemePrivate)
{

}

Theme::~Theme()
{
    delete d;
}

QColor Theme::color(int role) const
{
    return d->colors[role].first;
}

QColor Theme::palette(QString role)
{
    return d->palette[role];
}

void Theme::readSettings(QSettings &settings)
{
    {
        settings.beginGroup(QLatin1String("Palette"));
        foreach (const QString &key, settings.allKeys()) {
            QColor c = readColor(settings.value(key).toString());
            d->palette[key] = c;
        }
        settings.endGroup();
    }
}

void Theme::setSomething(QSettings &settings, const QMetaEnum &e)
{
    settings.beginGroup(QLatin1String("Colors"));
    d->colors.resize        (e.keyCount());

    for (int i = 0, total = e.keyCount(); i < total; ++i) {
        const QString key = QLatin1String(e.key(i));
        if (!settings.contains(key)) {
            qWarning("Theme \"%s\" misses color setting for key \"%s\".",
                     qPrintable(d->fileName), qPrintable(key));
            continue;
        }
        d->colors[i] = readNamedColor(settings.value(key).toString());
    }
    settings.endGroup();
}

QPair<QColor, QString> Theme::readNamedColor(const QString &color) const
{
    if (d->palette.contains(color))
        return qMakePair(d->palette[color], color);
    if (color == QLatin1String("style"))
        return qMakePair(QColor(), QString());

    bool ok = true;
    const QRgb rgba = color.toLongLong(&ok, 16);
    if (!ok) {
        qWarning("Color \"%s\" is neither a named color nor a valid color", qPrintable(color));
        return qMakePair(Qt::black, QString());
    }
    return qMakePair(QColor::fromRgba(rgba), QString());
}
