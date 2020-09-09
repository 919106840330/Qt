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
    int win[4][6];
    int home[4][4];
    int player;
    int sjs;
    int flag;
    int r1,b1,y1,g1;
    int r2,b2,y2,g2;
    int rw,bw,yw,gw;
    int rc,bc,yc,gc;
    QPushButton b;


public slots:
};

#endif // FXQ_H
