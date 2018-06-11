#include "dialog.h"
#include "ui_dialog.h"

Dialog1::Dialog1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}
