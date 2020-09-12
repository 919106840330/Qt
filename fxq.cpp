#include "fxq.h"
#include<QPaintEvent>
#include<QDebug>
#include<QPainter>
#include<QMovie>
#include<QMessageBox>
#include<QLabel>
#include <ctime>

fxq::fxq(QWidget *parent) : QWidget(parent)
{
      player=-1;
      resize(800,600);
      rw=0;
      bw=0;
      yw=0;
      gw=0;
      rc=0;
      bc=0;
      yc=0;
      gc=0;
      int i,j;
      for(i=0;i<4;i++){
          for(j=0;j<6;j++){
              win[i][j]=0;
          }
      }
      for(i=0;i<4;i++){
          for(j=0;j<4;j++){
              home[i][j]=1;
          }
      }
      for (i=0;i<52;i++){
          for(j=0;j<4;j++){
              qp[i][j]=1;
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
    for(i=0;i<4;i++){    //出生点
        if(i==0){
            for(j=0+rw;j<4;j++){
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
            }}
            if(i==1){
                for(j=0+bw;j<4;j++){
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
        }
            if(i==2){
                for(j=0+yw;j<4;j++){
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
         }
            if(i==3){
                for(j=0+gw;j<4;j++){
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
            }}
    }

    for(i=0;i<52;i++){
            for(j=0;j<4;j++){
                if(qp[i][j]){
                    if(i==0){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(400,10,50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(400,10,50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(400,10,50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(400,10,50,50,QPixmap("../green"));
                            break;
                        }
                    }
                    if(i>0&&i<=3){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(400,30*i+40,50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(400,30*i+40,50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(400,30*i+40,50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(400,30*i+40,50,50,QPixmap("../green"));
                            break;
                        }
                    }
                    if(i>3&&i<=7){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(420+(i-3)*25,150,50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(420+(i-3)*25,150,50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(420+(i-3)*25,150,50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(420+(i-3)*25,150,50,50,QPixmap("../green"));
                            break;
                        }
                    }
                    if(i>7&&i<=12){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(535,160+(i-6)*30,50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(535,160+(i-6)*30,50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(535,160+(i-6)*30,50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(535,160+(i-6)*30,50,50,QPixmap("../green"));
                            break;
                        }
                    }
                    if(i>12&&i<=16){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(540-25*(i-12),400,50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(540-25*(i-12),400,50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(540-25*(i-12),400,50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(540-25*(i-12),400,50,50,QPixmap("../green"));
                            break;
                        }
                    }
                    if(i>=17&&i<=20){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(400,400+(i-16)*30,50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(400,400+(i-16)*30,50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(400,400+(i-16)*30,50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(400,400+(i-16)*30,50,50,QPixmap("../green"));
                            break;
                        }
                    }
                    if(i>20&&i<=25){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(400-(i-19)*30,540,50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(400-(i-19)*30,540,50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(400-(i-19)*30,540,50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(400-(i-19)*30,540,50,50,QPixmap("../green"));
                            break;
                        }
                    }
                    if(i>25&&i<=29){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(150,540-(i-25)*25,50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(150,540-(i-25)*25,50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(150,540-(i-25)*25,50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(150,540-(i-25)*25,50,50,QPixmap("../green"));
                            break;
                        }
                    }
                    if(i>29&&i<=33){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(150-30*(i-29),400,50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(150-30*(i-29),430,50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(150-30*(i-29),430,50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(150-30*(i-29),430,50,50,QPixmap("../green"));
                            break;
                        }
                    }
                    if(i>33&&i<=38){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(16,370-30*(i-33),50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(16,370-30*(i-33),50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(16,370-30*(i-33),50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(16,370-30*(i-33),50,50,QPixmap("../green"));
                            break;
                        }
                    }
                    if(i>38&&i<=42){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(10+25*(i-38),150,50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(10+25*(i-38),150,50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(10+25*(i-38),150,50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(10+25*(i-38),150,50,50,QPixmap("../green"));
                            break;
                        }
                    }
                    if(i>42&&i<=46){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(155,150-30*(i-42),50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(155,150-30*(i-42),50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(155,150-30*(i-42),50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(155,150-30*(i-42),50,50,QPixmap("../green"));
                            break;
                        }
                    }
                    if(i>46&&i<=51){
                        switch(qp[i][j]){
                        case 1:
                            p.drawPixmap(170+28*(i-45),10,50,50,QPixmap("../red"));
                            break;
                        case 2:
                            p.drawPixmap(170+28*(i-45),10,50,50,QPixmap("../blue"));
                            break;
                        case 3:
                            p.drawPixmap(170+28*(i-45),10,50,50,QPixmap("../yellow"));
                            break;
                        case 4:
                            p.drawPixmap(170+28*(i-45),10,50,50,QPixmap("../green"));
                            break;
                        }}}}}
    for(i=0;i<4;i++){
        if(i==0){
            for(j=0;j<6;j++){
                switch(win[i][j]){
                    case 1:
                    p.drawPixmap(275,65+32*j,50,50,QPixmap("../red"));
                    break;
                    case 2:
                    p.drawPixmap(275,65+32*j,50,50,QPixmap("../blue"));
                    break;
                    case 3:
                    p.drawPixmap(275,65+32*j,50,50,QPixmap("../yellow"));
                    break;
                    case 4:
                    p.drawPixmap(275,65+32*j,50,50,QPixmap("../green"));
                    break;
                }
            }
        }
        if(i==1){
            for(j=0;j<6;j++){
                switch(win[i][j]){
                    case 1:
                    p.drawPixmap(480-32*j,285,50,50,QPixmap("../red"));
                    break;
                    case 2:
                    p.drawPixmap(480-32*j,285,50,50,QPixmap("../blue"));
                    break;
                    case 3:
                    p.drawPixmap(480-32*j,285,50,50,QPixmap("../yellow"));
                    break;
                    case 4:
                    p.drawPixmap(480-32*j,285,50,50,QPixmap("../green"));
                    break;
        }
    }
  }
        if(i==2){
            for(j=0;j<6;j++){
                switch(win[i][j]){
                    case 1:
                    p.drawPixmap(275,480-32*j,50,50,QPixmap("../red"));
                    break;
                    case 2:
                    p.drawPixmap(275,480-32*j,50,50,QPixmap("../blue"));
                    break;
                    case 3:
                    p.drawPixmap(275,480-32*j,50,50,QPixmap("../yellow"));
                    break;
                    case 4:
                    p.drawPixmap(275,480-32*j,50,50,QPixmap("../green"));
                    break;
                }
            }
        }
        if(i==3){
            for(j=0;j<6;j++){
                switch(win[i][j]){
                    case 1:
                    p.drawPixmap(70+32*j,280,50,50,QPixmap("../red"));
                    break;
                    case 2:
                    p.drawPixmap(70+32*j,280,50,50,QPixmap("../blue"));
                    break;
                    case 3:
                    p.drawPixmap(70+32*j,280,50,50,QPixmap("../yellow"));
                    break;
                    case 4:
                    p.drawPixmap(70+32*j,280,50,50,QPixmap("../green"));
                    break;
                }
            }
        }
    }
}
void fxq::mousePressEvent(QMouseEvent *e){
    flag=player%4;
    if(flag==0){
        //qp[13][0]=1;
        qDebug()<<"red";
        if(rc==1){
            if(r1<=49)
            qp[r1][0]=0;
            if(r1>49){
            win[0][r1-50]=0;
            qDebug()<<r1;
            qDebug()<<"ok";}
            r1=r1+sjs;
            if(r1<=49){
            qp[r1][0]=1;
            update();}
            if(r1>49){
                if(r1-49>6){
                    win[0][60-r1]=1;
                    r1=110-r1;
                    qDebug()<<r1;
                    update();
                }
                else{if(r1-49<6){
                    win[0][r1-50]=1;
                    update();
                }
                if(r1-49==6){
                    win[0][5]=1;
                    QMessageBox::information(this, "恭喜", "红队有一架飞机到达终点", QMessageBox::Ok);
                    bw=bw+1;
                    rc=0;
                    update();
                }}
            }

        }
        if(rc==0){ //全部没出门
            if(sjs==6){
                    rc=1;
                    home[rw][0]=0;
                    qp[0][0]=1;
                    r1=0;
                    update();
            }
        }
    }
    qDebug()<<player;
    if(flag==1){
        qDebug()<<"blue";
        if(bc==1){
            if(b1>51){
                if(b1<=62){
                qp[b1-52][0]=0;
                update();}
                if(b1>62){
                    win[1][b1-63]=0;
                    update();
                }
                b1=b1+sjs;
                if(b1>62){
                    if(b1-62<6){
                        win[1][b1-63]=2;
                        qDebug()<<b1;
                        update();
                    }
                    if(b1-62==6){
                        win[1][5]=2;
                        QMessageBox::information(this, "恭喜", "蓝队有一架飞机到达终点", QMessageBox::Ok);
                        bc=0;
                        bw++;
                        update();
                    }
                    if(b1-62>6){

                        win[1][73-b1]=2;
                        b1=136-b1;
                        qDebug()<<b1;
                        update();
                    }
                }
                else{
                qp[b1-52][0]=2;
                update();}
            }else {
            qp[b1][0]=0;
            b1=b1+sjs;
                if(b1>51){
                    qp[b1-52][0]=2;
                    qDebug()<<b1;
                }
                else{
                    qp[b1][0]=2;
                }

            update();}

        }
        if(bc==0){ //全部没出门
            if(sjs==6){
                    home[1][bw]=0;
                    qp[13][0]=2;
                    b1=13;
                    bc=1;
                    update();

            }
        }
    }
    if(flag==2){
        qDebug()<<"yellow";
        if(yc==1){
            if(y1>51){
               if(y1<=75){
                   qp[y1-52][0]=0;
                   update();}
                if(y1>75){
                    win[2][y1-76]=0;
                    update();
                }
                    y1=y1+sjs;
                    if(y1>75){
                    if(y1-75<6){
                        win[2][y1-76]=3;
                        qDebug()<<y1;
                        update();
                    }
                    if(y1-75==6){
                        win[2][5]=3;
                        yw++;
                        yc=0;
                        QMessageBox::information(this, "恭喜", "黄队有一架飞机到达终点", QMessageBox::Ok);
                        update();
                    }
                    if(y1-75>6){
                        win[2][86-y1]=3;
                        y1=162-y1;
                        update();
                    }
                }
                else{
                    qp[y1-52][0]=3;
                    update();}
            }
            else{
            qp[y1][0]=0;
            y1=y1+sjs;
            if(y1>51){
                qp[y1-52][0]=3;}
            else{
                qp[y1][0]=3;}
            update();}

        }
        if(yc==0){ //全部没出门
            if(sjs==6){
                    home[2][yw]=0;
                    qp[26][0]=3;
                    y1=26;
                    yc=1;
                    update();

            }
        }
    }
    if(flag==3){
         qDebug()<<"green";
         if(gc==1){
             if(g1>51){
                 if(g1<=88){
                 qp[g1-52][0]=0;
                 update();}
                 if(g1>88){
                     win[3][g1-89]=0;
                     update();
                 }
                 g1=g1+sjs;
                 if(g1>88){
                     if(g1-88<6){
                         win[3][g1-89]=4;
                         qDebug()<<g1;
                         update();
                     }
                     if(g1-88==6){
                         win[3][5]=4;
                         QMessageBox::information(this, "恭喜", "绿队有一架飞机到达终点", QMessageBox::Ok);
                         gc=0;
                         gw++;
                         update();
                     }
                     if(g1-88>6){

                         win[3][99-g1]=4;
                         g1=188-g1;
                         qDebug()<<g1;
                         update();
                     }
                 }
                 else{
                 qp[g1-52][0]=4;
                 update();}
             }else {
             qp[g1][0]=0;
             g1=g1+sjs;
                 if(g1>51){
                     qp[g1-52][0]=4;
                     qDebug()<<g1;
                 }
                 else{
                     qp[g1][0]=4;
                 }

             update();}

         }
        if(gc==0){ //全部没出门
            if(sjs==6){
                    home[3][gw]=0;
                    qp[39][0]=4;
                    g1=39;
                    gc=1;
                    update();

            }
        }
    }
}
void fxq::mysolt(){
    srand((int)time(0));
    sjs=rand()%6;
    player=player+1;
    sjs=5;
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
