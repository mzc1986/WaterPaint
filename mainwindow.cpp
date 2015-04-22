#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QFileDialog>
#include <QtWidgets>
#include "MyCustomWidget.h"
#include "mylineshape.h"
#include "shapes.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPlace_a_window_triggered()
{
    customWidget = new MyCustomWidget();
    customWidget->setWindowFlags(Qt::Window);
    ui->myMDI->addSubWindow(customWidget);
    ui->myMDI->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->myMDI->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    customWidget->show();

    connect(ui->btnLine,SIGNAL(clicked()),this, SLOT(on_actionLine_triggered()));
    connect(ui->btnRectangle,SIGNAL(clicked()),this, SLOT(on_actionRect_triggered()));
    connect(ui->btnEllipse,SIGNAL(clicked()),this, SLOT(on_actionEllipse_triggered()));
}


void MainWindow::on_actionTile_triggered()
{
    ui->myMDI->tileSubWindows();

}

void MainWindow::on_actionCascade_triggered()
{
    ui->myMDI->cascadeSubWindows();
}

void MainWindow::on_OpenFile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) {
        //        QMdiSubWindow *existing = findMdiChild(fileName);
        //        if (existing) {
        //            ui->myMDI->setActiveSubWindow(existing);
        //            return;
        //        }

        if (openFile(fileName))
            statusBar()->showMessage(tr("File loaded"), 2000);
    }
}

bool MainWindow::openFile(const QString &fileName)
{
    MyCustomWidget *child = createMyCustomWidgetChild();
    const bool succeeded = child->loadFile(fileName);
    if (succeeded)
        child->show();
    else
        child->close();
    return succeeded;
}

MyCustomWidget *MainWindow::createMyCustomWidgetChild(){

    MyCustomWidget *child = new MyCustomWidget;
    ui->myMDI->addSubWindow(child);

    return child;
}


//QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName)
//{
//    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

//    foreach (QMdiSubWindow *window, myMDI->subWindowList()) {
//        myMDI *mdiChild = qobject_cast<MdiChild *>(window->widget());
//        if (mdiChild->currentFile() == canonicalFilePath)
//            return window;
//    }
//    return 0;
//}

void MainWindow::on_actionPen_Color_triggered()
{
    QColor newColor = QColorDialog::getColor(customWidget->penColor());
    if (newColor.isValid())
        customWidget->setPenColor(newColor);
}

void MainWindow::on_actionPen_Width_triggered()
{
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Scribble"),
                                        tr("Select pen width:"),
                                        customWidget->penWidth(),
                                        1, 50, 1, &ok);
    if (ok)
        customWidget->setPenWidth(newWidth);
}

void MainWindow::on_actionClose_triggered()
{
    ui->myMDI->closeAllSubWindows();
}

void MainWindow::on_actionLine_triggered()
{
    if(!activeMdiChild()) return;
    MyCustomWidget *actCustomWidget = activeMdiChild();
//    actCustomWidget->setSelectedTool(2);

    //Shapes myLine;
    MyLineShape b;
    //Polymorphic usage through reference
    //Shapes& myLine = b;
    //qDebug()<<b;
    actCustomWidget->setDrawingObject(b);

    //myLine.setPoint1();
    //myLine.setPoint2();

    //MyLineShape myLine = new MyLineShape();
}

void MainWindow::on_actionRect_triggered()
{
    if(!activeMdiChild()) return;
    MyCustomWidget *actCustomWidget = activeMdiChild();

    actCustomWidget->setSelectedTool(1);
}

MyCustomWidget *MainWindow::activeMdiChild()
{
    if (QMdiSubWindow *activeSubWindow = ui->myMDI->activeSubWindow())
        return qobject_cast<MyCustomWidget *>(activeSubWindow->widget());   //returns 0 if no casting possible
    return 0;
}

void MainWindow::on_actionEllipse_triggered()
{
    if(!activeMdiChild()) return;
    MyCustomWidget *actCustomWidget = activeMdiChild();

    actCustomWidget->setSelectedTool(3);
}
