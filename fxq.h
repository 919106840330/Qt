#ifndef FXQ_H
#define FXQ_H

#include <QWidget>
#include <QPaintEvent>
#include <QPushButton>
#include <QMouseEvent>
#include <QTimer>

class fxq : public QWidget
{
    Q_OBJECT
public:
    explicit fxq(QWidget *parent = nullptr);
   // void mysolt();
    void my1();
    void my2();
    void my3();
    void my4();
    void my5();
    void my6();
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
   // int r2,b2,y2,g2;
    int rw,bw,yw,gw;
    int rc,bc,yc,gc;
    int s=0;
    int a=0;
    int v=0;
    int ok=0;
    QPushButton b;
    QPushButton a1,a2,a3,a4,a5,a6;
    QTimer *tim;
    QTimer *tim2;


public slots:
     void handleTimeout();
         void mysolt();
};

#endif // FXQ_H
