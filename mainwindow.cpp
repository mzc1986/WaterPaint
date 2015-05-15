#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QFileDialog>
#include <QtWidgets>
#include "MyCustomWidget.h"
#include "mylineshape.h"
#include "myrectangleshape.h"
#include "myellipseshape.h"
#include "shapes.h"
#include "mypenshape.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("~WATER PAINT~"));
}


void MainWindow::on_actionPlace_a_window_triggered()
{
    customWidget = new MyCustomWidget();
    customWidget->setWindowFlags(Qt::Window);
    ui->myMDI->addSubWindow(customWidget);
    ui->myMDI->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->myMDI->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    customWidget->show();

    createActions();

    newColor = Qt::blue;
    newWidth = 1;

    connect(ui->btnPen,SIGNAL(clicked()),this, SLOT(on_actionPencil_triggered()));
    connect(ui->btnLine,SIGNAL(clicked()),this, SLOT(on_actionLine_triggered()));
    connect(ui->btnRectangle,SIGNAL(clicked()),this, SLOT(on_actionRect_triggered()));
    connect(ui->btnEllipse,SIGNAL(clicked()),this, SLOT(on_actionEllipse_triggered()));
}


void MainWindow::createActions()
{

    //for each supported image type create an ACTION and add
    //SIGNAL and SLOT with those Actions

    //Finally add those Actions to saveAsActs Menu
    foreach (QByteArray format, QImageWriter::supportedImageFormats()) {
        QString text = tr("%1...").arg(QString(format).toUpper());

        QAction *action = new QAction(text, this);
        action->setData(format);
        connect(action, SIGNAL(triggered()), this, SLOT(saveUsingType()));
        saveAsActs.append(action);
    }

    //Create a new QMenu
    saveAsMenu = new QMenu(tr("&Save As"), this);
    foreach (QAction *action, saveAsActs)
        saveAsMenu->addAction(action);

    //get a reference to the GUI defined MenuItem and add our Menu with it
    ui->menuAdd_somethig->addMenu(saveAsMenu);
}


void MainWindow::saveUsingType()
{
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    //saveFile(fileFormat);

    if(!activeMdiChild()) return;
    MyCustomWidget *actCustomWidget = activeMdiChild();

    actCustomWidget->saveAsType(fileFormat);
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
    QString fileName = QFileDialog::getOpenFileName(this,"","",tr("Images (*.png *.xpm *.jpg)"));


//    if (!fileName.isEmpty()) {
//                QMdiSubWindow *existing = findMdiChild(fileName);
//                if (existing) {
//                    ui->myMDI->setActiveSubWindow(existing);
//                    return;
//                }

        if (openFile(fileName))
            statusBar()->showMessage(tr("File loaded"), 2000);
    //}
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



void MainWindow::on_actionPen_Color_triggered()
{
    newColor = QColorDialog::getColor(customWidget->penColor());
    if (newColor.isValid())
        customWidget->setPenColor(newColor);
}

void MainWindow::on_actionPen_Width_triggered()
{
    bool ok;
    newWidth = QInputDialog::getInt(this, tr("Scribble"),
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

    //Creating a MyLineShape pointer for later use
    MyLineShape *b = new MyLineShape(newColor, newWidth);

    //Polymorphic usage through reference
    actCustomWidget->setDrawingObject(b);
}

void MainWindow::on_actionRect_triggered()
{
    if(!activeMdiChild()) return;
    MyCustomWidget *actCustomWidget = activeMdiChild();

    MyRectangleShape *r = new MyRectangleShape(newColor, newWidth);

    actCustomWidget->setDrawingObject(r);

}

void MainWindow::on_actionEllipse_triggered()
{
    if(!activeMdiChild()) return;

    MyCustomWidget *actCustomWidget = activeMdiChild();
    MyEllipseShape *el = new MyEllipseShape(newColor, newWidth);

    actCustomWidget->setDrawingObject(el);

}

MyCustomWidget *MainWindow::activeMdiChild()
{
    if (QMdiSubWindow *activeSubWindow = ui->myMDI->activeSubWindow())
        return qobject_cast<MyCustomWidget *>(activeSubWindow->widget());   //returns 0 if no casting possible
    return 0;
}


void MainWindow::on_actionUndo_triggered()
{
    if(!activeMdiChild()) return;
    MyCustomWidget *actCustomWidget = activeMdiChild();

    //Polymorphic usage through reference
    actCustomWidget->printShapes();
}

QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName)
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

//    foreach (QMdiSubWindow *window, ui->myMDI->subWindowList()) {
//        ui->myMDI *mdiChild = qobject_cast<MyCustomWidget *>(window->widget());
//        if (mdiChild->currentFile() == canonicalFilePath)
//            return window;
//    }
//    return 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_triggered()
{
    if(!activeMdiChild()) return;
    MyCustomWidget *actCustomWidget = activeMdiChild();

    if (actCustomWidget->saveAs())
        statusBar()->showMessage(tr("File saved"), 2000);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About Water Paint"),
            tr("<p>Computer Science Project:</p><p><b>A Paint Program using Qt/C++ & OOP</b></p>"));
}

void MainWindow::on_actionSource_triggered()
{
    QDesktopServices::openUrl(
                QUrl("http://mangoprojects.info/category/c/", QUrl::TolerantMode));
}

void MainWindow::on_actionPencil_triggered()
{
    if(!activeMdiChild()) return;
    MyCustomWidget *actCustomWidget = activeMdiChild();

    //Creating a MyLineShape pointer for later use
    MyPenShape *b = new MyPenShape(newColor, newWidth);

    //Polymorphic usage through reference
    actCustomWidget->setDrawingObject(b);
}
