#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <cmath>
#include <QDebug>

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    for(int i=0; i<30;i++){
        tempo.push_back(i);
        dados.push_back(i);
    }
}
void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;
    double x1,x2, y1,y2;

    painter.setRenderHint(QPainter::Antialiasing);


    brush.setColor(QColor(220, 220, 220));
    brush.setStyle(Qt::CrossPattern);


    painter.setBrush(brush);

    pen.setColor(QColor(0,0,0));
    pen.setWidth(1);

    painter.setPen(pen);

    painter.drawRect(0,0,width(),height());

    pen.setColor(QColor(0,0,255));
    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);

    painter.setPen(pen);

    x1 = tempo[0]*width();
    y1 = dados[0]*(height()-dados[0]);

    for(int i=1; i<30; i++){
        x2 = tempo[i]*width();
        y2 = dados[i]*(height()-dados[i]);
        painter.drawLine(x1,y1,x2,y2);

        x1 = x2;
        y1 = y2;
    }

}

void Plotter::loadData(std::vector<double> t,std::vector<double> d)
{
    tempo = t;
    dados = d;
    repaint();
}
