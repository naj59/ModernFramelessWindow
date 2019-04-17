#include "FramelessWindow.h"

FramelessWindow::FramelessWindow(QWidget *parent) : QMainWindow(parent) {
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
}

FramelessWindow::~FramelessWindow() {

}

void FramelessWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    drawShadow(painter, 10, 2.0, QColor(120, 120, 120, 32), QColor(255, 255, 255, 0), 0.0, 1.0, 0.6, width(), height());
}