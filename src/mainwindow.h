#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_ENUMS(Color)

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    enum Color {
        pushbutton1,
        pushbutton2,
    };

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
