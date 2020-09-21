#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QBitmap>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pixmap;
    pixmap.load("../fj");

    setAttribute(Qt::WA_TranslucentBackground);

    resize(pixmap.size());
    setMask(pixmap.mask());

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    this->hide();
    w.show();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0,0,QPixmap("../fj"));
}

void Widget::on_pushButton_2_clicked()
{
    this->close();
}
