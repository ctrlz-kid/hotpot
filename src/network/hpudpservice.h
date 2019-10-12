#ifndef HPUDPSERVICE_H
#define HPUDPSERVICE_H

#include <QObject>

class HPUdpService : public QObject
{
    Q_OBJECT
public:
    explicit HPUdpService(QObject *parent = 0);

signals:

public slots:
};

#endif // HPUDPSERVICE_H