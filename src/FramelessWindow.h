#ifndef __FRAMELESS_WINDOW_H__
#define __FRAMELESS_WINDOW_H__

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QLinearGradient>
#include <QPointF>
#include <QMenuBar>
#include <QMenu>

class FramelessWindow : public QMainWindow {
    Q_OBJECT
public:
    FramelessWindow(QWidget *parent = nullptr);
    ~FramelessWindow();

    virtual void paintEvent(QPaintEvent *event);

    void drawShadow(QPainter &_painter, qint16 _margin, qreal _radius, QColor _start, QColor _end, qreal _startPosition, qreal _endPosition0, qreal _endPosition1, qreal _width, qreal _height);

protected:
    void mousePressEvent(QMouseEvent *event) {
        oldPos = event->globalPos();
    }

    void mouseMoveEvent(QMouseEvent *event) {
        const QPoint delta = event->globalPos() - oldPos;
        if (locked) move(x()+delta.x(), y());
        else move(x()+delta.x(),y()+delta.y());
        oldPos = event->globalPos();
    }

private:
    bool locked = false;
    QPoint oldPos;

    QMenuBar *mainMenuBar;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *windowMenu;
    QMenu *helpMenu;

};

#endif // __FRAMELESS_WINDOW_H__