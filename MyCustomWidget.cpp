#include "MyCustomWidget.h"

#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QTextStream>
#include <QtWidgets>
#include "ui_mainwindow.h"
#include "shapes.h"
#include "mylineshape.h"
#include "myrectangleshape.h"
#include "myellipseshape.h"
#include <memory.h>

using namespace std;

MyCustomWidget::MyCustomWidget(QWidget *parent) :
    QWidget(parent)//,
  //ui(new Ui::MyCustomWidget)
{
    //ui->setupUi(this);

    mPix = QPixmap(QWidget::size()); //400,400
    mPix.fill(Qt::white);
    //painter.begin(&mPix);

    //myShape = 0;

    //set everything to false as nothing has started yet
    mousePressed = false;
    drawStarted = false;

    //default is line
    selectedTool = 2;

    myPenColor = Qt::blue;
    myPenWidth = 1;

    //connect(ui.)
}

void MyCustomWidget::setDrawingObject(Shapes *b){

    //myShape is a Shapes class pointer which stores the passed pointer
    //for later use
    myShape = b;

}

void MyCustomWidget::setPenColor(const QColor &color)
{
    myPenColor = color;
}

void MyCustomWidget::setPenWidth(int w)
{
    myPenWidth = w;
}


void MyCustomWidget::mousePressEvent(QMouseEvent* event){
    //Mouse is pressed for the first time
    mousePressed = true;

    //depending on Object type setPoint methods of
    //Different object is called
    myShape->setPoint1(event->pos());
    myShape->setPoint2(event->pos());
}

void MyCustomWidget::mouseMoveEvent(QMouseEvent* event){

    //As mouse is moving set the second point again and again
    // and update continuously
    if(event->type() == QEvent::MouseMove){
        myShape->setPoint2(event->pos());
    }

    //it calls the paintEven() function continuously
    update();
}

void MyCustomWidget::mouseReleaseEvent(QMouseEvent *event){

    //When mouse is released update for the one last time
    mousePressed = false;
    update();
}

void MyCustomWidget::paintEvent(QPaintEvent *event){

    painter.begin(this);

    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    //When the mouse is pressed
    if(mousePressed){
        // we are taking QPixmap reference again and again
        //on mouse move and drawing a line again and again
        //hence the painter view has a feeling of dynamic drawing
        painter.drawPixmap(0,0,mPix);

        /*Depending on myShape type object from those shapes are called
            for painting on the painter using appropriate method,
            benefit is we don't need to know Shape type beforehand */
        if(dynamic_cast<MyLineShape*>(myShape)){
            painter.drawLine(dynamic_cast<MyLineShape*>(myShape)->qline);
        }
        else if(dynamic_cast<MyRectangleShape*>(myShape))
        {
            painter.drawRect(dynamic_cast<MyRectangleShape*>(myShape)->qRect);
        }
        else if(dynamic_cast<MyEllipseShape*>(myShape))
        {
            painter.drawEllipse(dynamic_cast<MyEllipseShape*>(myShape)->qEllipse);
        }

        drawStarted = true;
    }
    else if (drawStarted){
        // It created a QPainter object by taking  a reference
        // to the QPixmap object created earlier, then draws a line
        // using that object, then sets the earlier painter object
        // with the newly modified QPixmap object
        QPainter tempPainter(&mPix);
        tempPainter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                                Qt::RoundJoin));

        if(dynamic_cast<MyRectangleShape*>(myShape))
        {
            tempPainter.drawRect(dynamic_cast<MyRectangleShape*>(myShape)->qRect);
        }
        else if(dynamic_cast<MyLineShape*>(myShape))
        {
            tempPainter.drawLine(dynamic_cast<MyLineShape*>(myShape)->qline);

            dynamic_cast<MyLineShape*>(myShape)->print();
        }
        else if(dynamic_cast<MyEllipseShape*>(myShape)){
            tempPainter.drawEllipse(dynamic_cast<MyEllipseShape*>(myShape)->qEllipse);
        }

        painter.drawPixmap(0,0,mPix);
    }


    painter.end();
}

MyCustomWidget::~MyCustomWidget()
{
    //delete ui;
}

bool MyCustomWidget::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("MDI"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    mPix.load(fileName,0,Qt::AutoColor);

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    //setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);

    //    connect(document(), SIGNAL(contentsChanged()),
    //            this, SLOT(documentWasModified()));

    return true;
}

void MyCustomWidget::setCurrentFile(const QString &fileName)
{
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    //document()->setModified(false);
    setWindowModified(false);

    //setWindowTitle(userFriendlyCurrentFile() + "[*]");
}

QSize MyCustomWidget::sizeHint() const
{
    return QSize(72 * fontMetrics().width('x'),
                 25 * fontMetrics().lineSpacing());

}
