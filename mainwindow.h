#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include "MyCustomWidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    MyCustomWidget *customWidget;
    QMdiSubWindow *findMdiChild(const QString &fileName);
    bool openFile(const QString &fileName);

    ~MainWindow();

    MyCustomWidget *createMyCustomWidgetChild();
private slots:
    void on_actionPlace_a_window_triggered();

    void on_actionRect_triggered();

    void on_actionTile_triggered();

    void on_actionCascade_triggered();

    void on_OpenFile_triggered();

    void on_actionPen_Color_triggered();

    void on_actionPen_Width_triggered();

    void on_actionClose_triggered();

    void on_actionLine_triggered();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
