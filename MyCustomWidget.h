#pragma once

#include "shapes.h"
#include "mylineshape.h"
#include <QPainter>
#include <QWidget>

namespace Ui {
    class MyCustomWidget;
}

class MyCustomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyCustomWidget(QWidget *parent = 0);
    bool mousePressed;
    bool drawStarted;
    int selectedTool;
    bool undoVar;

    void setPenColor(const QColor &color);
    void setPenWidth(int w);

    QColor penColor() const {return myPenColor;}
    int penWidth() const {return myPenWidth;}

    //Creating a vector to store the shapes
    Shapes *myShape;
    vector<Shapes*> myShapeVector;

    bool loadFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void setDrawingObject(Shapes *b);

    QSize sizeHint() const;
    void printShapes();
    ~MyCustomWidget();

    bool saveAs();

    bool saveAsType(const QByteArray &fileFormat);
    bool saveFile(const QString &fileName, const QByteArray &fileFormat);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

public slots:

private:
    Ui::MyCustomWidget *ui;
    QPainter painter;
    QPixmap mPix;
    QString curFile;
    bool isUntitled;

    QColor myPenColor;
    int myPenWidth;

};
