#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QObject>

class testmodel : public QObject
{
    Q_OBJECT
public:
    explicit testmodel(QObject *parent = nullptr);

signals:

};

#endif // TESTMODEL_H
