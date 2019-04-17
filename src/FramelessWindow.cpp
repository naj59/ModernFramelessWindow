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

void FramelessWindow::drawShadow(QPainter &_painter, qint16 _margin, qreal _radius, QColor _start, QColor _end, qreal _startPos, qreal _endPos0, qreal _endPos1, qreal _width, qreal _height) {
    _painter.setPen(Qt::NoPen);

    QLinearGradient gradient;
    gradient.setColorAt(_startPos, _start);
    gradient.setColorAt(_endPos0, _end);

    QPointF right0(_width - _margin, _height / 2);
    QPointF right1(_width, _height / 2);
    gradient.setStart(right0);
    gradient.setFinalStop(right1);
    _painter.setBrush(QBrush(gradient));
    _painter.drawRoundRect(QRectF(QPointF(_width - _margin * _radius, _margin), QPointF(_width, _height - _margin)), 0.0, 0.0);

    QPointF left0(_margin, _height / 2);
    QPointF left1(0, _height / 2);
    gradient.setStart(left0);
    gradient.setFinalStop(left1);
    _painter.setBrush(QBrush(gradient));
    _painter.drawRoundRect(QRectF(QPointF(_margin * _radius, _margin), QPointF(0, _height - _margin)), 0.0, 0.0);

    QPointF top0(_width / 2, _margin);
    QPointF top1(_width / 2, 0);
    gradient.setStart(top0);
    gradient.setFinalStop(top1);
    _painter.setBrush(QBrush(gradient));
    _painter.drawRoundRect(QRectF(QPointF(_width - _margin, 0), QPointF(_margin, _margin)), 0.0, 0.0);

    QPointF bottom0(_width / 2, _height - _margin);
    QPointF bottom1(_width / 2, _height);
    gradient.setStart(bottom0);
    gradient.setFinalStop(bottom1);
    _painter.setBrush(QBrush(gradient));
    _painter.drawRoundRect(QRectF(QPointF(_margin, _height - _margin), QPointF(_width - _margin, _height)), 0.0, 0.0);

    QPointF bottomRight0(_width - _margin, _height - _margin);
    QPointF bottomRight1(_width, _height);
    gradient.setStart(bottomRight0);
    gradient.setFinalStop(bottomRight1);
    gradient.setColorAt(_endPos1, _end);
    _painter.setBrush(QBrush(gradient));
    _painter.drawRoundRect(QRectF(bottomRight0, bottomRight1), 0.0, 0.0);
    
    QPointF bottomLeft0(_margin, _height - _margin);
    QPointF bottomLeft1(0, _height);
    gradient.setStart(bottomLeft0);
    gradient.setFinalStop(bottomLeft1);
    gradient.setColorAt(_endPos1, _end);
    _painter.setBrush(QBrush(gradient));
    _painter.drawRoundRect(QRectF(bottomLeft0, bottomLeft1), 0.0, 0.0);
    
    QPointF topLeft0(_margin, _margin);
    QPointF topLeft1(0, 0);
    gradient.setStart(topLeft0);
    gradient.setFinalStop(topLeft1);
    gradient.setColorAt(_endPos1, _end);
    _painter.setBrush(QBrush(gradient));
    _painter.drawRoundRect(QRectF(topLeft0, topLeft1), 0.0, 0.0);
    
    QPointF topRight0(_width - _margin, _margin);
    QPointF topRight1(_width, 0);
    gradient.setStart(topRight0);
    gradient.setFinalStop(topRight1);
    gradient.setColorAt(_endPos1, _end);
    _painter.setBrush(QBrush(gradient));
    _painter.drawRoundRect(QRectF(topRight0, topRight1), 0.0, 0.0);
    
    _painter.setBrush(QBrush("#FFFFFF"));
    _painter.setRenderHint(QPainter::Antialiasing);
    _painter.drawRoundRect(QRectF(QPointF(_margin, _margin), QPointF(_width - _margin, _height - _margin)), _radius, _radius);
}