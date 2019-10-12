#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QMetaEnum>
#include "theme.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings *config = NULL;
    config = new QSettings("test.ini" , QSettings::IniFormat);
    QString v =  config->value("Colors/outline").toString();


    Extras::Theme themeHandle;
    Extras::setCreatorTheme(&themeHandle);

    Extras::creatorTheme()->readSettings(*config);
    QColor color = Extras::creatorTheme()->palette("text");


    const QMetaObject &m = *metaObject();
    //QMetaEnum tenum = QMetaEnum::fromType<MainWindow::Color>();
    //int y = tenum.keyCount();
    {
        QMetaEnum e = m.enumerator(m.indexOfEnumerator("Color"));
        int x  = m.indexOfEnumerator("Color");
        Extras::creatorTheme()->setSomething(*config, e);
    }


    color = Extras::creatorTheme()->color(Color::pushbutton1);
    QString s;
    s = QString("color: rgb(%1,%2,%3);").arg(color.red()).arg(color.green()).arg(color.blue());

    ui->pushButton->setStyleSheet(s);

    color = Extras::creatorTheme()->color(Color::pushbutton2);
    s = QString("color: rgb(%1,%2,%3);").arg(color.red()).arg(color.green()).arg(color.blue());
    ui->pushButton_2->setStyleSheet(s);
}

MainWindow::~MainWindow()
{
    delete ui;
}
