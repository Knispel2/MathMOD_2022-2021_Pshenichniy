#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "testmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addModelButton_clicked();

    void on_updateModelButton_clicked();

    void modelUpdatedSlot(int, QString);

private:
    Ui::MainWindow *ui;
    std::vector<testModel*> models;
    unsigned int counter = 0;
};
#endif // MAINWINDOW_H
