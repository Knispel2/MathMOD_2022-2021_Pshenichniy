#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addModelButton_clicked()
{
    auto logStr = QString("Button clicked");
    ui->textBrowser->append(logStr);
    testModel * newModel;
    if (ui->radioButton_X->isChecked())
        newModel = new testModel_X(counter++);
    else
        newModel = new testModel_Y(counter++);
    this->models.push_back(newModel);
    connect(newModel, SIGNAL(modelUpdatedSignal(int,QString)),
            this, SLOT(modelUpdatedSlot(int,QString)));
    logStr = QString("Model added");
        ui->textBrowser->append(logStr);

}

void MainWindow::on_updateModelButton_clicked()
{
    for(auto m : this->models)
    {
        m->onUpdate();
        auto logStr = QString("Update method called for model of <span style=\"color: red;\"> type %1 </span> with <span style=\"color: green;\"> ID %2 </span>").arg(m->type_model).arg(m->ID);
            ui->textBrowser->append(logStr);
    }
}

void MainWindow::modelUpdatedSlot(int ID, QString name_data)
{
    std::cout << QString("model with <span style=\"color: red;\"> ID %1 </span> update signal receive").arg(ID).toStdString() << std::endl;

    auto logStr = QString("Slot activated: received signal from updated model of <span style=\"color: red;\"> type %1 </span> with <span style=\"color: green;\"> ID %2 </span>").arg(name_data).arg(ID);
        ui->textBrowser->append(logStr);
}
