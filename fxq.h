#ifndef FXQ_H
#define FXQ_H

#include <QWidget>
#include <QPaintEvent>
#include <QPushButton>
#include <QMouseEvent>

class fxq : public QWidget
{
    Q_OBJECT
public:
    explicit fxq(QWidget *parent = nullptr);
    void mysolt();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
signals:
private:
    int red[4];
    int blue[4];
    int yellow[4];
    int green[4];
    int qp[52][4];
    int redwin[6];
    int bluewin[6];
    int yellowwin[6];
    int greenwin[6];
    int home[4][4];
    int player=0;
    int sjs;
    int flag;
    QPushButton b;


public slots:
};

#endif // FXQ_H
