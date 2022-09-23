#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QObject>
#include "stdio.h"
#include "iostream"

class testModel : public QObject
{
    Q_OBJECT

public:
    QString type_model;
    testModel(int);
    void onUpdate();
    ~testModel();
    unsigned int ID;
signals:
    void modelUpdatedSignal(int, QString);
};

class testModel_X : public testModel
{
public:
    testModel_X(int data) : testModel(data) {type_model = QString("X");};
};

class testModel_Y : public testModel
{
public:
    testModel_Y(int data) : testModel(data) {type_model = QString("Y");};
};

#endif // TESTMODEL_H
