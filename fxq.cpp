#include "fxq.h"
#include<QPaintEvent>
#include<QPainter>
#include<QDebug>
#include<QMovie>
#include<QLabel>
#include<QMessageBox>
#include <ctime>

fxq::fxq(QWidget *parent) : QWidget(parent)
{
      resize(800,600);
      int i,j;
      for(i=0;i<4;i++){
          for(j=0;j<4;j++){
              home[i][j]=1;
          }
      }
      for (i=0;i<52;i++){
          for(j=0;j<4;j++){
              qp[i][j]=0;
          }
      }
      b.setParent(this);
      b.setText("投骰子");
      b.move(650,100);
      b.resize(100,60);
      connect(&b,&QPushButton::released,this,&fxq::mysolt);
}

void::fxq::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawPixmap(0,0,600,600,QPixmap("../fxqqp"));
    QMovie * mov = new QMovie("../saizi");

    QLabel l;
        l.setMovie(mov);
        l.setFixedSize(50,50);
        l.setScaledContents(true);
        l.move(600,600);
        //ui->label_gif->adjustSize();//在这里没有效果
        mov->start(); //没有这一行，就不会显示任何内容
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(i==0){
                if(home[i][j]==1){
                    switch(j){
                    case 0:
                        p.drawPixmap(480,0,50,50,QPixmap("../red"));
                        break;
                    case 1:
                        p.drawPixmap(550,0,50,50,QPixmap("../red"));
                        break;
                    case 2:
                        p.drawPixmap(480,60,50,50,QPixmap("../red"));
                        break;
                    case 3:
                        p.drawPixmap(550,60,50,50,QPixmap("../red"));
                        break;
                    }
                }
            }
            if(i==1){
                if(home[i][j]==1){
                    switch(j){
                    case 0:
                        p.drawPixmap(480,480,50,50,QPixmap("../blue"));
                        break;
                    case 1:
                        p.drawPixmap(550,480,50,50,QPixmap("../blue"));
                        break;
                    case 2:
                        p.drawPixmap(480,550,50,50,QPixmap("../blue"));
                        break;
                    case 3:
                        p.drawPixmap(550,550,50,50,QPixmap("../blue"));
                        break;
                    }
                }
            }
            if(i==2){
                if(home[i][j]==1){
                    switch(j){
                    case 0:
                        p.drawPixmap(5,480,50,50,QPixmap("../yellow"));
                        break;
                    case 1:
                        p.drawPixmap(75,480,50,50,QPixmap("../yellow"));
                        break;
                    case 2:
                        p.drawPixmap(5,550,50,50,QPixmap("../yellow"));
                        break;
                    case 3:
                        p.drawPixmap(75,550,50,50,QPixmap("../yellow"));
                        break;
                    }
                }
            }
            if(i==3){
                if(home[i][j]==1){
                    switch(j){
                    case 0:
                        p.drawPixmap(5,5,50,50,QPixmap("../green"));
                        break;
                    case 1:
                        p.drawPixmap(75,5,50,50,QPixmap("../green"));
                        break;
                    case 2:
                        p.drawPixmap(5,75,50,50,QPixmap("../green"));
                        break;
                    case 3:
                        p.drawPixmap(75,75,50,50,QPixmap("../green"));
                        break;
                    }
                }
            }
        }
    }
    for(i=0;i<52;i++){
        for(j=0;j<4;j++){
            if(qp[i][j]){
                if(i==0){
                    switch(qp[i][j]){
                    case 1:
                        p.drawPixmap(420,0,50,50,QPixmap("../red"));
                        break;
                    case 2:
                        p.drawPixmap(420,0,50,50,QPixmap("../blue"));
                        break;
                    case 3:
                        p.drawPixmap(420,0,50,50,QPixmap("../yellow"));
                        break;
                    case 4:
                        p.drawPixmap(420,0,50,50,QPixmap("../green"));
                        break;
                    }
                }
                if(i>0&&i<=3){
                    switch(qp[i][j]){
                    case 1:
                        p.drawPixmap(420,30*i+10,50,50,QPixmap("../red"));
                        break;
                    case 2:
                        p.drawPixmap(420,30*i+10,50,50,QPixmap("../blue"));
                        break;
                    case 3:
                        p.drawPixmap(420,30*i+10,50,50,QPixmap("../yellow"));
                        break;
                    case 4:
                        p.drawPixmap(420,30*i+10,50,50,QPixmap("../green"));
                        break;
                    }
                }
                if(i>3&&i<=7){
                    switch(qp[i][j]){
                    case 1:
                        p.drawPixmap(420+(i-3)*30,160,50,50,QPixmap("../red"));
                        break;
                    case 2:
                        p.drawPixmap(420+(i-3)*30,160,50,50,QPixmap("../blue"));
                        break;
                    case 3:
                        p.drawPixmap(420+(i-3)*30,160,50,50,QPixmap("../yellow"));
                        break;
                    case 4:
                        p.drawPixmap(420+(i-3)*30,160,50,50,QPixmap("../green"));
                        break;
                    }
                }
                if(i>7&&i<=13){
                    switch(qp[i][j]){
                    case 1:
                        p.drawPixmap(640,160+(i-3)*30,50,50,QPixmap("../red"));
                        break;
                    case 2:
                        p.drawPixmap(640,160+(i-3)*30,50,50,QPixmap("../blue"));
                        break;
                    case 3:
                        p.drawPixmap(640,160+(i-3)*30,50,50,QPixmap("../yellow"));
                        break;
                    case 4:
                        p.drawPixmap(640,160+(i-3)*30,50,50,QPixmap("../green"));
                        break;
                    }
                }
            }
        }
    }

  }
void fxq::mousePressEvent(QMouseEvent *e){
    flag=player%4;
    player=player++;
    if(flag==0){
        if(home[0][0]&&home[0][1]&&home[0][2]&&home[0][3]){ //全部没出门
            if(sjs==6){
                if(e->x()>=480&&e->x()<=530&&e->y()>=0&&e->y()<=50){
                    home[0][0]=0;
                    qp[0][0]=1;
                    update();
                }
                if(e->x()>=550&&e->x()<=600&&e->y()>=0&&e->y()<=50){
                    home[0][1]=0;
                    qp[0][0]=1;
                    update();
                }
                if(e->x()>=480&&e->x()<=530&&e->y()>=60&&e->y()<=110){
                    home[0][2]=0;
                    qp[0][0]=1;
                    update();
                }
                if(e->x()>=550&&e->x()<=600&&e->y()>=60&&e->y()<=110){
                    home[0][0]=0;
                    qp[0][0]=1;
                    update();
                }
            }
        }
    }
}
void fxq::mysolt(){
    srand((int)time(0));
    sjs=rand()%6;
    qDebug()<<sjs;
    sjs=sjs+1;
    if(sjs==1){
        QMessageBox::information(this, "骰子", "您的骰子数为1", QMessageBox::Ok);
        }
    if(sjs==2){
        QMessageBox::information(this, "骰子", "您的骰子数为2", QMessageBox::Ok);
        }
    if(sjs==3){
        QMessageBox::information(this, "骰子", "您的骰子数为3", QMessageBox::Ok);
        }
    if(sjs==4){
        QMessageBox::information(this, "骰子", "您的骰子数为4", QMessageBox::Ok);
        }
    if(sjs==5){
        QMessageBox::information(this, "骰子", "您的骰子数为5", QMessageBox::Ok);
        }
    if(sjs==6){
        QMessageBox::information(this, "骰子", "您的骰子数为6", QMessageBox::Ok);
        }
}
