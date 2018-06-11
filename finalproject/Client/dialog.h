#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>

namespace Ui {
class Dialog;
}

class Dialog1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
