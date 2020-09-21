#include "fxq.h"
#include<QPaintEvent>
#include<QDebug>
#include<QPainter>
#include<QMovie>
#include<QMessageBox>
#include<QLabel>
#include <ctime>
#include <QTimer>
#include <QIcon>

fxq::fxq(QWidget *parent) : QWidget(parent)
{
    QIcon ico("../saizi.gif");
    QIcon i1("../s1");
    QIcon i2("../s2");
    QIcon i3("../s3");
    QIcon i4("../s4");
    QIcon i5("../s5");
    QIcon i6("../s6");
    tim=new QTimer(this);
    connect(tim, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    tim2=new QTimer(this);
    connect(tim2,SIGNAL(timeout()), this, SLOT(mysolt()));
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
              qp[i][j]=0;
          }
      }
      b.setParent(this);
      b.move(650,100);
      b.setIcon(ico);
      b.setIconSize(QSize(100,100));
      b.setFlat(true);
      connect(&b,&QPushButton::released,this,&fxq::mysolt);
      a1.setParent(this);
      a1.move(630,400);;
      a1.setIcon(i1);
      a1.setIconSize(QSize(50,50));
      a1.setFlat(true);
      connect(&a1,&QPushButton::released,this,&fxq::my1);
      a2.setParent(this);
      a2.move(680,400);;
      a2.setIcon(i2);
      a2.setIconSize(QSize(50,50));
      a2.setFlat(true);
      connect(&a2,&QPushButton::released,this,&fxq::my2);
      a3.setParent(this);
      a3.move(730,400);;
      a3.setIcon(i3);
      a3.setIconSize(QSize(50,50));
      a3.setFlat(true);
      connect(&a3,&QPushButton::released,this,&fxq::my3);
      a4.setParent(this);
      a4.move(630,500);;
      a4.setIcon(i4);
      a4.setIconSize(QSize(50,50));
      a4.setFlat(true);
      connect(&a4,&QPushButton::released,this,&fxq::my4);
      a5.setParent(this);
      a5.move(680,500);;
      a5.setIcon(i5);
      a5.setIconSize(QSize(50,50));
      a5.setFlat(true);
      connect(&a5,&QPushButton::released,this,&fxq::my5);
      a6.setParent(this);
      a6.move(730,500);;
      a6.setIcon(i6);
      a6.setIconSize(QSize(50,50));
      a6.setFlat(true);
      connect(&a6,&QPushButton::released,this,&fxq::my6);

}
void::fxq::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawPixmap(0,0,600,600,QPixmap("../fxqqp"));
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
            }
         }
    }
    for(i=0;i<52;i++){
                for(j=0;j<4;j++){
                    if(qp[i][j]){
                        if(i==0){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(400,20,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(400,20,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(400,20,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(400,20,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i>0&&i<3){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(408,60+(i-1)*37,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(408,60+(i-1)*37,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(408,60+(i-1)*37,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(408,60+(i-1)*37,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==3){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(393,60+(i-1)*37,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(393,60+(i-1)*37,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(393,60+(i-1)*37,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(393,60+(i-1)*37,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==4){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(425,166,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(425,166,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(425,166,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(425,166,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i>4&&i<7){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(425+(i-4)*37,156,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(425+(i-4)*37,156,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(425+(i-4)*37,156,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(425+(i-4)*37,156,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==7){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(425+(i-4)*37,171,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(425+(i-4)*37,171,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(425+(i-4)*37,171,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(425+(i-4)*37,171,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i>7&&i<=12){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(550,206+(i-8)*37,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(550,206+(i-8)*37,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(550,206+(i-8)*37,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(550,206+(i-8)*37,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==13){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(535-37*(i-13),400,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(535-37*(i-13),400,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(535-37*(i-13),400,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(535-37*(i-13),400,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i>13&&i<16){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(535-37*(i-13),405,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(535-37*(i-13),405,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(535-37*(i-13),405,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(535-37*(i-13),405,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==16){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(535-37*(i-13),395,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(535-37*(i-13),395,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(535-37*(i-13),395,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(535-37*(i-13),395,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==17){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(390,425+(i-17)*37,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(390,425+(i-17)*37,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(390,425+(i-17)*37,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(390,425+(i-17)*37,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i>17&&i<20){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(407,425+(i-17)*37,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(407,425+(i-17)*37,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(407,425+(i-17)*37,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(407,425+(i-17)*37,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==20){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(397,425+(i-17)*37,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(397,425+(i-17)*37,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(397,425+(i-17)*37,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(397,425+(i-17)*37,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i>20&&i<=25){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(355-(i-21)*36,550,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(355-(i-21)*36,550,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(355-(i-21)*36,550,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(355-(i-21)*36,550,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==26){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(171,545-(i-26)*37,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(171,545-(i-26)*37,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(171,545-(i-26)*37,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(171,545-(i-26)*37,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i>26&&i<29){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(161,535-(i-26)*37,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(161,535-(i-26)*37,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(161,535-(i-26)*37,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(161,535-(i-26)*37,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==29){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(171,535-(i-26)*37,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(171,535-(i-26)*37,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(171,535-(i-26)*37,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(171,535-(i-26)*37,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i>29&&i<=33){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(142-37*(i-30),400,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(142-37*(i-30),400,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(142-37*(i-30),400,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(142-37*(i-30),400,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i>33&&i<=38){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(15,350-37*(i-34),35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(15,350-37*(i-34),35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(15,350-37*(i-34),35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(15,350-37*(i-34),35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==39){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(32+37*(i-39),168,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(32+37*(i-39),168,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(32+37*(i-39),168,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(32+37*(i-39),168,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i>39&&i<42){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(32+37*(i-39),153,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(32+37*(i-39),153,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(32+37*(i-39),153,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(32+37*(i-39),153,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==42){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(32+37*(i-39),168,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(32+37*(i-39),168,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(32+37*(i-39),168,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(32+37*(i-39),168,35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==43){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(169,139-37*(i-43),35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(169,139-37*(i-43),35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(169,139-37*(i-43),35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(169,139-37*(i-43),35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i>43&&i<46){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(159,134-37*(i-43),35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(159,134-37*(i-43),35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(159,134-37*(i-43),35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(159,134-37*(i-43),35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i==46){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(169,134-37*(i-43),35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(169,134-37*(i-43),35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(169,134-37*(i-43),35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(169,134-37*(i-43),35,35,QPixmap("../green"));
                                break;
                            }
                        }
                        if(i>46&&i<=51){
                            switch(qp[i][j]){
                            case 1:
                                p.drawPixmap(211+36*(i-47),10,35,35,QPixmap("../red"));
                                break;
                            case 2:
                                p.drawPixmap(211+36*(i-47),10,35,35,QPixmap("../blue"));
                                break;
                            case 3:
                                p.drawPixmap(211+36*(i-47),10,35,35,QPixmap("../yellow"));
                                break;
                            case 4:
                                p.drawPixmap(211+36*(i-47),10,35,35,QPixmap("../green"));
                                break;
                            }}}}}
    for(i=0;i<4;i++){
        if(i==0){
            for(j=0;j<6;j++){
                switch(win[i][j]){
                    case 1:
                    p.drawPixmap(289,73+35*j,30,30,QPixmap("../red"));
                    break;
                    case 2:
                    p.drawPixmap(290,65+32*j,50,50,QPixmap("../blue"));
                    break;
                    case 3:
                    p.drawPixmap(290,65+32*j,50,50,QPixmap("../yellow"));
                    break;
                    case 4:
                    p.drawPixmap(290,65+32*j,50,50,QPixmap("../green"));
                    break;
                }
            }
        }
        if(i==1){
            for(j=0;j<6;j++){
                switch(win[i][j]){
                    case 1:
                    p.drawPixmap(500-35*j,285,30,30,QPixmap("../red"));
                    break;
                    case 2:
                    p.drawPixmap(500-35*j,285,30,30,QPixmap("../blue"));
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
                    p.drawPixmap(289,500-35*j,30,30,QPixmap("../red"));
                    break;
                    case 2:
                    p.drawPixmap(289,500-35*j,30,30,QPixmap("../blue"));
                    break;
                    case 3:
                    p.drawPixmap(289,500-35*j,30,30,QPixmap("../yellow"));
                    break;
                    case 4:
                    p.drawPixmap(289,480-32*j,50,50,QPixmap("../green"));
                    break;
                }
            }
        }
        if(i==3){
            for(j=0;j<6;j++){
                switch(win[i][j]){
                    case 1:
                    p.drawPixmap(70+35*j,280,30,30,QPixmap("../red"));
                    break;
                    case 2:
                    p.drawPixmap(70+35*j,280,30,30,QPixmap("../blue"));
                    break;
                    case 3:
                    p.drawPixmap(70+35*j,280,30,30,QPixmap("../yellow"));
                    break;
                    case 4:
                    p.drawPixmap(70+35*j,280,30,30,QPixmap("../green"));
                    break;
                }
            }
        }
    }
    switch(s%6){
       case 0:
        p.drawPixmap(650-a,100+v,100,100,QPixmap("../s1"));
        break;
       case 1:
        p.drawPixmap(650-a,100+v,100,100,QPixmap("../s2"));
        break;
       case 2:
        p.drawPixmap(650-a,100+v,100,100,QPixmap("../s3"));
        break;
       case 3:
        p.drawPixmap(650-a,100+v,100,100,QPixmap("../s4"));
        break;
       case 4:
        p.drawPixmap(650-a,100+v,100,100,QPixmap("../s5"));
        break;
       case 5:
        p.drawPixmap(650-a,100+v,100,100,QPixmap("../s6"));
        break;

    }
    if(ok){
        switch((s-1)%6){
           case 0:
            p.drawPixmap(250,250,130,130,QPixmap("../s1"));
            break;
           case 1:
            p.drawPixmap(250,250,130,130,QPixmap("../s2"));
            break;
           case 2:
            p.drawPixmap(250,250,130,130,QPixmap("../s3"));
            break;
           case 3:
            p.drawPixmap(250,250,130,130,QPixmap("../s4"));
            break;
           case 4:
            p.drawPixmap(250,250,130,130,QPixmap("../s5"));
            break;
           case 5:
            p.drawPixmap(250,250,130,130,QPixmap("../s6"));
            break;

        }
        ok=0;
    }
    switch(flag){
    case 0:
        p.drawPixmap(650,200,100,100,QPixmap("../red"));
        break;
    case 1:
        p.drawPixmap(650,200,100,100,QPixmap("../blue"));
        break;
    case 2:
        p.drawPixmap(650,200,100,100,QPixmap("../yellow"));
        break;
    case 3:
        p.drawPixmap(650,200,100,100,QPixmap("../green"));
        break;

    }
}
void fxq::mousePressEvent(QMouseEvent *e){
    int i,j;
    if(flag==0){
        //qp[13][0]=1;
        if(rc==1){
            if(r1<=49)
            qp[r1][0]=0;
            if(r1>49){
            win[0][r1-50]=0;}
            r1=r1+sjs;
            if(r1<=49){
                    if(r1==41){qp[r1][0]=0;r1=45;}
                    if(r1==37){qp[r1][0]=0;r1=41;}
                    if(r1==33){qp[r1][0]=0;r1=37;}
                    if(r1==29){qp[r1][0]=0;r1=33;}
                    if(r1==25){qp[r1][0]=0;r1=29;}
                    if(r1==21){qp[r1][0]=0;r1=25;}
                    if(r1==13){qp[r1][0]=0;r1=17;}
                    if(r1==9){qp[r1][0]=0;r1=13;}
                    if(r1==5){qp[r1][0]=0;r1=9;}
                    if(r1==1){qp[r1][0]=0;r1=5;}
                if(r1==17){
                    qp[r1][0]=0;
                    r1=r1+12;
                }
                    switch(qp[r1][0]){
                    case 2:
                        bc=0;
                        QMessageBox::information(this, "抱歉", "红队消灭了一架蓝队的飞机", QMessageBox::Ok);
                        home[1][bw]=1;
                        break;
                    case 3:
                        yc=0;
                        QMessageBox::information(this, "抱歉", "红队消灭了一架黄队的飞机", QMessageBox::Ok);
                        home[2][yw]=1;
                        break;
                    case 4:
                        gc=0;
                        QMessageBox::information(this, "抱歉", "红队消灭了一架绿队的飞机", QMessageBox::Ok);
                        home[3][gw]=1;
                        break;}
            qp[r1][0]=1;
            update();}
            if(r1>49){
                if(r1-49>6){
                    win[0][60-r1]=1;
                    r1=110-r1;
                    update();
                }
                else{if(r1-49<6){
                    win[0][r1-50]=1;
                    update();
                }
                if(r1-49==6){
                    win[0][5]=1;
                    QMessageBox::information(this, "恭喜", "红队有一架飞机到达终点", QMessageBox::Ok);
                    rw=rw+1;
                    if(rw==4){
                         QMessageBox::information(this, "恭喜", "红队获胜", QMessageBox::Ok);
                         tim2->stop();
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
                                 qp[i][j]=0;
                             }
                         }
                    }
                    rc=0;
                    update();
                }}
            }

        }
        if(rc==0){
            if(sjs==6){
                    rc=1;
                    home[0][rw]=0;
                    r1=0;
                    switch(qp[r1][0]){
                    case 2:
                        bc=0;
                        QMessageBox::information(this, "抱歉", "红队消灭了一架蓝队的飞机", QMessageBox::Ok);
                        home[1][bw]=1;
                        break;
                    case 3:
                        yc=0;
                        QMessageBox::information(this, "抱歉", "红队消灭了一架黄队的飞机", QMessageBox::Ok);
                        home[2][yw]=1;
                        break;
                    case 4:
                        gc=0;
                        QMessageBox::information(this, "抱歉", "红队消灭了一架绿队的飞机", QMessageBox::Ok);
                        home[3][gw]=1;
                        break;}
                    qp[0][0]=1;
                    update();
            }
        }
    }
    if(flag==1){
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
                        update();
                    }
                    if(b1-62==6){
                        win[1][5]=2;
                        QMessageBox::information(this, "恭喜", "蓝队有一架飞机到达终点", QMessageBox::Ok);
                        bc=0;
                        bw++;
                        if(bw==4){
                            QMessageBox::information(this, "恭喜", "蓝队获胜", QMessageBox::Ok);
                            tim2->stop();
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
                                    qp[i][j]=0;
                                }
                            }
                        }
                        update();
                    }
                    if(b1-62>6){

                        win[1][73-b1]=2;
                        b1=136-b1;
                        update();
                    }
                }
                else{
                    if(b1==58){qp[b1-52][0]=0;b1=62;}
                    if(b1==54){qp[b1-52][0]=0;b1=58;}
                    switch(qp[b1-52][0]){
                    case 1:
                        rc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架红队的飞机", QMessageBox::Ok);
                        home[0][rw]=1;
                        break;
                    case 3:
                        yc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架黄队的飞机", QMessageBox::Ok);
                        home[2][yw]=1;
                        break;
                    case 4:
                        gc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架绿队的飞机", QMessageBox::Ok);
                        home[3][gw]=1;
                        break;}
                qp[b1-52][0]=2;
                update();}
            }
            else {
            qp[b1][0]=0;
            b1=b1+sjs;
                if(b1>51||b1==50){
                    //if(b1==58){qp[b1-52][0]=0;b1=62;}
                    if(b1==54){qp[b1-52][0]=0;b1=58;}
                    if(b1==50){qp[b1][0]=0;b1=54;}
                switch(qp[b1-52][0]){
                    case 1:
                        rc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架红队的飞机", QMessageBox::Ok);
                        home[0][rw]=1;
                        break;
                    case 3:
                        yc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架黄队的飞机", QMessageBox::Ok);
                        home[2][yw]=1;
                        break;
                    case 4:
                        gc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架绿队的飞机", QMessageBox::Ok);
                        home[3][gw]=1;
                        break;}
                    qp[b1-52][0]=2;
                }
                else{
                    //if(b1==50){qp[b1][0]=0;b1=54;}
                    if(b1==46){qp[b1][0]=0;b1=50;}
                    if(b1==42){qp[b1][0]=0;b1=46;}
                    if(b1==38){qp[b1][0]=0;b1=42;}
                    if(b1==34){qp[b1][0]=0;b1=38;}
                    if(b1==26){qp[b1][0]=0;b1=30;}
                    if(b1==22){qp[b1][0]=0;b1=26;}
                    if(b1==18){qp[b1][0]=0;b1=22;}
                    if(b1==14){qp[b1][0]=0;b1=18;}
                    if(b1==30){
                        qp[b1][0]=0;
                        b1=b1+12;
                    }
                    switch(qp[b1][0]){
                    case 1:
                        rc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架红队的飞机", QMessageBox::Ok);
                        home[0][rw]=1;
                        break;
                    case 3:
                        yc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架黄队的飞机", QMessageBox::Ok);
                        home[2][rw]=1;
                        break;
                    case 4:
                        gc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架绿队的飞机", QMessageBox::Ok);
                        home[3][gw]=1;
                        break;}
                    qp[b1][0]=2;
                }

            update();}

        }
        if(bc==0){
            if(sjs==6){
                    home[1][bw]=0;

                    b1=13;
                    bc=1;
                    switch(qp[b1][0]){
                    case 1:
                        rc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架红队的飞机", QMessageBox::Ok);
                        home[0][rw]=1;
                        break;
                    case 3:
                        yc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架黄队的飞机", QMessageBox::Ok);
                        home[2][rw]=1;
                        break;
                    case 4:
                        gc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架绿队的飞机", QMessageBox::Ok);
                        home[3][gw]=1;
                        break;}
                    qp[13][0]=2;
                    update();

            }
        }
    }
    if(flag==2){
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
                        //qDebug()<<y1;
                        update();
                    }
                    if(y1-75==6){
                        win[2][5]=3;
                        yw++;
                        yc=0;
                        QMessageBox::information(this, "恭喜", "黄队有一架飞机到达终点", QMessageBox::Ok);
                        if(yw==4){
                            QMessageBox::information(this, "恭喜", "黄队获胜", QMessageBox::Ok);
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
                                    qp[i][j]=0;
                                }
                            }
                        }
                        update();
                    }
                    if(y1-75>6){
                        win[2][86-y1]=3;
                        y1=162-y1;
                        update();
                    }
                }
                else{
                        if(y1==71){qp[y1-52][0]=0;y1=75;}
                        if(y1==67){qp[y1-52][0]=0;y1=71;}
                        if(y1==63){qp[y1-52][0]=0;y1=67;}
                        if(y1==59){qp[y1-52][0]=0;y1=63;}
                        if(y1==55){qp[y1-52][0]=0;y1=59;}
                        switch(qp[y1-52][0]){
                        case 1:
                            rc=0;
                            QMessageBox::information(this, "抱歉", "黄对消灭了一架红队的飞机", QMessageBox::Ok);
                            home[0][rw]=1;
                            break;
                        case 2:
                            bc=0;
                            QMessageBox::information(this, "抱歉", "黄队消灭了一架蓝队的飞机", QMessageBox::Ok);
                            home[1][bw]=1;
                            break;
                        case 4:
                            gc=0;
                            QMessageBox::information(this, "抱歉", "黄队消灭了一架绿队的飞机", QMessageBox::Ok);
                            home[3][gw]=1;
                            break;}
                    qp[y1-52][0]=3;
                    update();}
            }
            else{
            qp[y1][0]=0;
            y1=y1+sjs;
            if(y1>=51||y1==43){
                if(y1==55){qp[y1-52][0]=0;y1=59;}
                if(y1==51){qp[y1][0]=0;y1=55;}
                if(y1==43){
                    qp[y1][0]=0;
                    y1=y1+12;
                }
                switch(qp[y1-52][0]){
                case 1:
                    rc=0;
                    QMessageBox::information(this, "抱歉", "黄对消灭了一架红队的飞机", QMessageBox::Ok);
                    home[0][rw]=1;
                    break;
                case 2:
                    bc=0;
                    home[1][bw]=1;
                    QMessageBox::information(this, "抱歉", "黄队消灭了一架蓝队的飞机", QMessageBox::Ok);
                    break;
                case 4:
                    gc=0;
                    QMessageBox::information(this, "抱歉", "黄队消灭了一架绿队的飞机", QMessageBox::Ok);
                    home[3][gw]=1;
                    break;}
                qp[y1-52][0]=3;}
            else{
                if(y1==47){qp[y1][0]=0;y1=51;}
                if(y1==39){qp[y1][0]=0;y1=43;}
                if(y1==35){qp[y1][0]=0;y1=39;}
                if(y1==31){qp[y1][0]=0;y1=35;}
                if(y1==27){qp[y1][0]=0;y1=31;}
                switch(qp[y1][0]){
                case 1:
                    rc=0;
                    home[0][rw]=1;
                    QMessageBox::information(this, "抱歉", "黄对消灭了一架红队的飞机", QMessageBox::Ok);
                    break;
                case 2:
                    bc=0;
                    home[1][bw]=1;
                    QMessageBox::information(this, "抱歉", "黄队消灭了一架蓝队的飞机", QMessageBox::Ok);
                    break;
                case 4:
                    gc=0;
                    home[3][gw]=1;
                    QMessageBox::information(this, "抱歉", "黄队消灭了一架绿队的飞机", QMessageBox::Ok);
                    break;}
                qp[y1][0]=3;}
            update();}

        }
        if(yc==0){
            if(sjs==6){
                    home[2][yw]=0;
                    qp[26][0]=3;
                    y1=26;
                    yc=1;
                    switch(qp[y1][0]){
                    case 1:
                        rc=0;
                        home[0][rw]=1;
                        QMessageBox::information(this, "抱歉", "黄对消灭了一架红队的飞机", QMessageBox::Ok);
                        break;
                    case 2:
                        bc=0;
                        home[1][bw]=1;
                        QMessageBox::information(this, "抱歉", "黄队消灭了一架蓝队的飞机", QMessageBox::Ok);
                        break;
                    case 4:
                        gc=0;
                        home[3][gw]=1;
                        QMessageBox::information(this, "抱歉", "黄队消灭了一架绿队的飞机", QMessageBox::Ok);
                        break;}
                    qp[y1][0]=3;}
                    update();

            }
        }
    if(flag==3){
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
                         update();
                     }
                     if(g1-88==6){
                         win[3][5]=4;
                         QMessageBox::information(this, "恭喜", "绿队有一架飞机到达终点", QMessageBox::Ok);
                         gc=0;
                         gw++;
                         if(gw==4){
                             QMessageBox::information(this, "恭喜", "绿队获胜", QMessageBox::Ok);
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
                                     qp[i][j]=0;
                                 }
                             }
                         }
                         update();
                     }
                     if(g1-88>6){
                         win[3][99-g1]=4;
                         g1=188-g1;
                         update();
                     }
                 }
                 else{
                     if(g1==84){qp[g1-52][0]=0;g1=88;}
                     if(g1==80){qp[g1-52][0]=0;g1=84;}
                     if(g1==76){qp[g1-52][0]=0;g1=80;}
                     if(g1==72){qp[g1-52][0]=0;g1=76;}
                     if(g1==68){qp[g1-52][0]=0;g1=72;}
                     if(g1==64){qp[g1-52][0]=0;g1=68;}
                     if(g1==60){qp[g1-52][0]=0;g1=64;}
                     if(g1==52){qp[g1-52][0]=0;g1=56;}
                     if(g1==56){
                         qp[g1-52][0]=0;
                         g1=g1+12;
                     }
                     switch(qp[g1-52][0]){
                     case 1:
                         rc=0;
                         QMessageBox::information(this, "抱歉", "绿对消灭了一架红队的飞机", QMessageBox::Ok);
                         home[0][rw]=1;
                         break;
                     case 2:
                         bc=0;
                         home[1][bw]=1;
                         QMessageBox::information(this, "抱歉", "绿队消灭了一架蓝队的飞机", QMessageBox::Ok);
                         break;
                     case 3:
                         yc=0;
                         home[3][yw]=1;
                         QMessageBox::information(this, "抱歉", "绿队消灭了一架黄队的飞机", QMessageBox::Ok);
                         break;}
                 qp[g1-52][0]=4;
                 update();}
             }
             else {
             qp[g1][0]=0;
             g1=g1+sjs;
                 if(g1>51||g1==48){
                     if(g1==52){qp[g1-52][0]=0;g1=56;}
                     if(g1==48){qp[g1][0]=0;g1=52;}
                     if(g1==56){
                         qp[g1-52][0]=0;
                         g1=g1+12;
                     }
                     switch(qp[g1-52][0]){
                     case 1:
                         rc=0;
                         home[0][rw]=1;
                         QMessageBox::information(this, "抱歉", "绿对消灭了一架红队的飞机", QMessageBox::Ok);
                         break;
                     case 2:
                         bc=0;
                         home[1][bw]=1;
                         QMessageBox::information(this, "抱歉", "绿队消灭了一架蓝队的飞机", QMessageBox::Ok);
                         break;
                     case 3:
                         yc=0;
                         home[2][yw]=1;
                         QMessageBox::information(this, "抱歉", "绿队消灭了一架黄队的飞机", QMessageBox::Ok);
                         break;}
                     qp[g1-52][0]=4;
                     //qDebug()<<g1;
                 }
                 else{
                     if(g1==44){qp[g1][0]=0;g1=48;}
                     if(g1==40){qp[g1][0]=0;g1=44;}
                     switch(qp[g1][0]){
                     case 1:
                         rc=0;
                         home[0][rw]=1;
                         QMessageBox::information(this, "抱歉", "绿对消灭了一架红队的飞机", QMessageBox::Ok);
                         break;
                     case 2:
                         bc=0;
                         home[1][bw]=1;
                         QMessageBox::information(this, "抱歉", "绿队消灭了一架蓝队的飞机", QMessageBox::Ok);
                         break;
                     case 3:
                         yc=0;
                         home[2][yw]=1;
                         QMessageBox::information(this, "抱歉", "绿队消灭了一架黄队的飞机", QMessageBox::Ok);
                         break;}
                     qp[g1][0]=4;
                 }

             update();}

         }
        if(gc==0){
            if(sjs==6){
                    home[3][gw]=0;
                    qp[39][0]=4;
                    g1=39;
                    gc=1;
                    switch(qp[g1][0]){
                    case 1:
                        rc=0;
                        home[0][rw]=1;
                        QMessageBox::information(this, "抱歉", "绿对消灭了一架红队的飞机", QMessageBox::Ok);
                        break;
                    case 2:
                        bc=0;
                        home[1][bw]=1;
                        QMessageBox::information(this, "抱歉", "绿队消灭了一架蓝队的飞机", QMessageBox::Ok);
                        break;
                    case 3:
                        yc=0;
                        home[2][yw]=1;
                        QMessageBox::information(this, "抱歉", "绿队消灭了一架黄队的飞机", QMessageBox::Ok);
                        break;}
                    update();

            }
        }
    }
    if(player%4==0||player%4==1||player%4==2){
        tim2->start(3000);
    }
}

void fxq::mysolt(){
    a=0;
    v=0;
    tim2->stop();
    tim->start(50);
    srand((int)time(0));
    sjs=rand()%6;
    player=player+1;
    flag=player%4;
    sjs=sjs+1;
    if(sjs==6){
        player=player-1;
    }
    s=sjs;
    if(sjs==1){
        if(flag==0)
        QMessageBox::information(this, "骰子", "红队的骰子数为1", QMessageBox::Ok);
        }
    if(sjs==2){
        if(flag==0)
        QMessageBox::information(this, "骰子", "红队的骰子数为2", QMessageBox::Ok);
        }
    if(sjs==3){
        if(flag==0)
        QMessageBox::information(this, "骰子", "红队的骰子数为3", QMessageBox::Ok);
        }
    if(sjs==4){
        if(flag==0)
        QMessageBox::information(this, "骰子", "红队的骰子数为4", QMessageBox::Ok);
        }
    if(sjs==5){
        if(flag==0)
        QMessageBox::information(this, "骰子", "红队的骰子数为5", QMessageBox::Ok);
        }
    if(sjs==6){
        if(flag==0)
        QMessageBox::information(this, "骰子", "红队的骰子数为6，再投一次", QMessageBox::Ok);
        }
    int i,j;
    if(flag==0){
        //qp[13][0]=1;
        if(rc==1){
            if(r1<=49)
            qp[r1][0]=0;
            if(r1>49){
            win[0][r1-50]=0;}
            r1=r1+sjs;
            if(r1<=49){
                    if(r1==41){qp[r1][0]=0;r1=45;}
                    if(r1==37){qp[r1][0]=0;r1=41;}
                    if(r1==33){qp[r1][0]=0;r1=37;}
                    if(r1==29){qp[r1][0]=0;r1=33;}
                    if(r1==25){qp[r1][0]=0;r1=29;}
                    if(r1==21){qp[r1][0]=0;r1=25;}
                    if(r1==13){qp[r1][0]=0;r1=17;}
                    if(r1==9){qp[r1][0]=0;r1=13;}
                    if(r1==5){qp[r1][0]=0;r1=9;}
                    if(r1==1){qp[r1][0]=0;r1=5;}
                if(r1==17){
                    qp[r1][0]=0;
                    r1=r1+12;
                }
                    switch(qp[r1][0]){
                    case 2:
                        bc=0;
                        QMessageBox::information(this, "抱歉", "红队消灭了一架蓝队的飞机", QMessageBox::Ok);
                        home[1][bw]=1;
                        break;
                    case 3:
                        yc=0;
                        QMessageBox::information(this, "抱歉", "红队消灭了一架黄队的飞机", QMessageBox::Ok);
                        home[2][yw]=1;
                        break;
                    case 4:
                        gc=0;
                        QMessageBox::information(this, "抱歉", "红队消灭了一架绿队的飞机", QMessageBox::Ok);
                        home[3][gw]=1;
                        break;}
            qp[r1][0]=1;
            update();}
            if(r1>49){
                if(r1-49>6){
                    win[0][60-r1]=1;
                    r1=110-r1;
                    update();
                }
                else{if(r1-49<6){
                    win[0][r1-50]=1;
                    update();
                }
                if(r1-49==6){
                    win[0][5]=1;
                    QMessageBox::information(this, "恭喜", "红队有一架飞机到达终点", QMessageBox::Ok);
                    rw=rw+1;
                    if(rw==4){
                         QMessageBox::information(this, "恭喜", "红队获胜", QMessageBox::Ok);
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
                                 qp[i][j]=0;
                             }
                         }
                    }
                    rc=0;
                    update();
                }}
            }

        }
        if(rc==0){
            if(sjs==6){
                    rc=1;
                    home[0][rw]=0;
                    r1=0;
                    switch(qp[r1][0]){
                    case 2:
                        bc=0;
                        QMessageBox::information(this, "抱歉", "红队消灭了一架蓝队的飞机", QMessageBox::Ok);
                        home[1][bw]=1;
                        break;
                    case 3:
                        yc=0;
                        QMessageBox::information(this, "抱歉", "红队消灭了一架黄队的飞机", QMessageBox::Ok);
                        home[2][yw]=1;
                        break;
                    case 4:
                        gc=0;
                        QMessageBox::information(this, "抱歉", "红队消灭了一架绿队的飞机", QMessageBox::Ok);
                        home[3][gw]=1;
                        break;}
                    qp[0][0]=1;
                    update();
            }
        }
    }
    if(flag==1){
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
                        update();
                    }
                    if(b1-62==6){
                        win[1][5]=2;
                        QMessageBox::information(this, "恭喜", "蓝队有一架飞机到达终点", QMessageBox::Ok);
                        bc=0;
                        bw++;
                        if(bw==4){
                            QMessageBox::information(this, "恭喜", "蓝队获胜", QMessageBox::Ok);
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
                                    qp[i][j]=0;
                                }
                            }
                        }
                        update();
                    }
                    if(b1-62>6){

                        win[1][73-b1]=2;
                        b1=136-b1;
                        update();
                    }
                }
                else{
                    if(b1==58){qp[b1-52][0]=0;b1=62;}
                    if(b1==54){qp[b1-52][0]=0;b1=58;}
                    switch(qp[b1-52][0]){
                    case 1:
                        rc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架红队的飞机", QMessageBox::Ok);
                        home[0][rw]=1;
                        break;
                    case 3:
                        yc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架黄队的飞机", QMessageBox::Ok);
                        home[2][yw]=1;
                        break;
                    case 4:
                        gc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架绿队的飞机", QMessageBox::Ok);
                        home[3][gw]=1;
                        break;}
                qp[b1-52][0]=2;
                update();}
            }
            else {
            qp[b1][0]=0;
            b1=b1+sjs;
                if(b1>51||b1==50){
                    //if(b1==58){qp[b1-52][0]=0;b1=62;}
                    if(b1==54){qp[b1-52][0]=0;b1=58;}
                    if(b1==50){qp[b1][0]=0;b1=54;}
                switch(qp[b1-52][0]){
                    case 1:
                        rc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架红队的飞机", QMessageBox::Ok);
                        home[0][rw]=1;
                        break;
                    case 3:
                        yc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架黄队的飞机", QMessageBox::Ok);
                        home[2][yw]=1;
                        break;
                    case 4:
                        gc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架绿队的飞机", QMessageBox::Ok);
                        home[3][gw]=1;
                        break;}
                    qp[b1-52][0]=2;
                }
                else{
                    //if(b1==50){qp[b1][0]=0;b1=54;}
                    if(b1==46){qp[b1][0]=0;b1=50;}
                    if(b1==42){qp[b1][0]=0;b1=46;}
                    if(b1==38){qp[b1][0]=0;b1=42;}
                    if(b1==34){qp[b1][0]=0;b1=38;}
                    if(b1==26){qp[b1][0]=0;b1=30;}
                    if(b1==22){qp[b1][0]=0;b1=26;}
                    if(b1==18){qp[b1][0]=0;b1=22;}
                    if(b1==14){qp[b1][0]=0;b1=18;}
                    if(b1==30){
                        qp[b1][0]=0;
                        b1=b1+12;
                    }
                    switch(qp[b1][0]){
                    case 1:
                        rc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架红队的飞机", QMessageBox::Ok);
                        home[0][rw]=1;
                        break;
                    case 3:
                        yc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架黄队的飞机", QMessageBox::Ok);
                        home[2][rw]=1;
                        break;
                    case 4:
                        gc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架绿队的飞机", QMessageBox::Ok);
                        home[3][gw]=1;
                        break;}
                    qp[b1][0]=2;
                }

            update();}

        }
        if(bc==0){
            if(sjs==6){
                    home[1][bw]=0;
                    b1=13;
                    bc=1;
                    switch(qp[b1][0]){
                    case 1:
                        rc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架红队的飞机", QMessageBox::Ok);
                        home[0][rw]=1;
                        break;
                    case 3:
                        yc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架黄队的飞机", QMessageBox::Ok);
                        home[2][rw]=1;
                        break;
                    case 4:
                        gc=0;
                        QMessageBox::information(this, "抱歉", "蓝队消灭了一架绿队的飞机", QMessageBox::Ok);
                        home[3][gw]=1;
                        break;}
                   qp[13][0]=2;
                    update();

            }
        }
    }
    if(flag==2){
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
                        //qDebug()<<y1;
                        update();
                    }
                    if(y1-75==6){
                        win[2][5]=3;
                        yw++;
                        yc=0;
                        QMessageBox::information(this, "恭喜", "黄队有一架飞机到达终点", QMessageBox::Ok);
                        if(yw==4){
                            QMessageBox::information(this, "恭喜", "黄队获胜", QMessageBox::Ok);
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
                                    qp[i][j]=0;
                                }
                            }
                        }
                        update();
                    }
                    if(y1-75>6){
                        win[2][86-y1]=3;
                        y1=162-y1;
                        update();
                    }
                }
                else{
                        if(y1==71){qp[y1-52][0]=0;y1=75;}
                        if(y1==67){qp[y1-52][0]=0;y1=71;}
                        if(y1==63){qp[y1-52][0]=0;y1=67;}
                        if(y1==59){qp[y1-52][0]=0;y1=63;}
                        if(y1==55){qp[y1-52][0]=0;y1=59;}
                        switch(qp[y1-52][0]){
                        case 1:
                            rc=0;
                            QMessageBox::information(this, "抱歉", "黄对消灭了一架红队的飞机", QMessageBox::Ok);
                            home[0][rw]=1;
                            break;
                        case 2:
                            bc=0;
                            QMessageBox::information(this, "抱歉", "黄队消灭了一架蓝队的飞机", QMessageBox::Ok);
                            home[1][bw]=1;
                            break;
                        case 4:
                            gc=0;
                            QMessageBox::information(this, "抱歉", "黄队消灭了一架绿队的飞机", QMessageBox::Ok);
                            home[3][gw]=1;
                            break;}
                    qp[y1-52][0]=3;
                    update();}
            }
            else{
            qp[y1][0]=0;
            y1=y1+sjs;
            if(y1>=51||y1==43){
                if(y1==55){qp[y1-52][0]=0;y1=59;}
                if(y1==51){qp[y1][0]=0;y1=55;}
                if(y1==43){
                    qp[y1][0]=0;
                    y1=y1+12;
                }
                switch(qp[y1-52][0]){
                case 1:
                    rc=0;
                    QMessageBox::information(this, "抱歉", "黄对消灭了一架红队的飞机", QMessageBox::Ok);
                    home[0][rw]=1;
                    break;
                case 2:
                    bc=0;
                    home[1][bw]=1;
                    QMessageBox::information(this, "抱歉", "黄队消灭了一架蓝队的飞机", QMessageBox::Ok);
                    break;
                case 4:
                    gc=0;
                    QMessageBox::information(this, "抱歉", "黄队消灭了一架绿队的飞机", QMessageBox::Ok);
                    home[3][gw]=1;
                    break;}
                qp[y1-52][0]=3;}
            else{
                if(y1==47){qp[y1][0]=0;y1=51;}
                if(y1==39){qp[y1][0]=0;y1=43;}
                if(y1==35){qp[y1][0]=0;y1=39;}
                if(y1==31){qp[y1][0]=0;y1=35;}
                if(y1==27){qp[y1][0]=0;y1=31;}
                switch(qp[y1][0]){
                case 1:
                    rc=0;
                    home[0][rw]=1;
                    QMessageBox::information(this, "抱歉", "黄对消灭了一架红队的飞机", QMessageBox::Ok);
                    break;
                case 2:
                    bc=0;
                    home[1][bw]=1;
                    QMessageBox::information(this, "抱歉", "黄队消灭了一架蓝队的飞机", QMessageBox::Ok);
                    break;
                case 4:
                    gc=0;
                    home[3][gw]=1;
                    QMessageBox::information(this, "抱歉", "黄队消灭了一架绿队的飞机", QMessageBox::Ok);
                    break;}
                qp[y1][0]=3;}
            update();}

        }
        if(yc==0){
            if(sjs==6){
                    home[2][yw]=0;
                    qp[26][0]=3;
                    y1=26;
                    yc=1;
                    switch(qp[y1][0]){
                    case 1:
                        rc=0;
                        home[0][rw]=1;
                        QMessageBox::information(this, "抱歉", "黄对消灭了一架红队的飞机", QMessageBox::Ok);
                        break;
                    case 2:
                        bc=0;
                        home[1][bw]=1;
                        QMessageBox::information(this, "抱歉", "黄队消灭了一架蓝队的飞机", QMessageBox::Ok);
                        break;
                    case 4:
                        gc=0;
                        home[3][gw]=1;
                        QMessageBox::information(this, "抱歉", "黄队消灭了一架绿队的飞机", QMessageBox::Ok);
                        break;}
                    qp[y1][0]=3;}
                    update();

            }
        }
    if(flag==3){
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
                         update();
                     }
                     if(g1-88==6){
                         win[3][5]=4;
                         QMessageBox::information(this, "恭喜", "绿队有一架飞机到达终点", QMessageBox::Ok);
                         gc=0;
                         gw++;
                         if(gw==4){
                             QMessageBox::information(this, "恭喜", "绿队获胜", QMessageBox::Ok);
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
                                     qp[i][j]=0;
                                 }
                             }
                         }
                         update();
                     }
                     if(g1-88>6){
                         win[3][99-g1]=4;
                         g1=188-g1;
                         update();
                     }
                 }
                 else{
                     if(g1==84){qp[g1-52][0]=0;g1=88;}
                     if(g1==80){qp[g1-52][0]=0;g1=84;}
                     if(g1==76){qp[g1-52][0]=0;g1=80;}
                     if(g1==72){qp[g1-52][0]=0;g1=76;}
                     if(g1==68){qp[g1-52][0]=0;g1=72;}
                     if(g1==64){qp[g1-52][0]=0;g1=68;}
                     if(g1==60){qp[g1-52][0]=0;g1=64;}
                     if(g1==52){qp[g1-52][0]=0;g1=56;}
                     if(g1==56){
                         qp[g1-52][0]=0;
                         g1=g1+12;
                     }
                     switch(qp[g1-52][0]){
                     case 1:
                         rc=0;
                         QMessageBox::information(this, "抱歉", "绿对消灭了一架红队的飞机", QMessageBox::Ok);
                         home[0][rw]=1;
                         break;
                     case 2:
                         bc=0;
                         home[1][bw]=1;
                         QMessageBox::information(this, "抱歉", "绿队消灭了一架蓝队的飞机", QMessageBox::Ok);
                         break;
                     case 3:
                         yc=0;
                         home[3][yw]=1;
                         QMessageBox::information(this, "抱歉", "绿队消灭了一架黄队的飞机", QMessageBox::Ok);
                         break;}
                 qp[g1-52][0]=4;
                 update();}
             }
             else {
             qp[g1][0]=0;
             g1=g1+sjs;
                 if(g1>51||g1==48){
                     if(g1==52){qp[g1-52][0]=0;g1=56;}
                     if(g1==48){qp[g1][0]=0;g1=52;}
                     if(g1==56){
                         qp[g1-52][0]=0;
                         g1=g1+12;
                     }
                     switch(qp[g1-52][0]){
                     case 1:
                         rc=0;
                         home[0][rw]=1;
                         QMessageBox::information(this, "抱歉", "绿对消灭了一架红队的飞机", QMessageBox::Ok);
                         break;
                     case 2:
                         bc=0;
                         home[1][bw]=1;
                         QMessageBox::information(this, "抱歉", "绿队消灭了一架蓝队的飞机", QMessageBox::Ok);
                         break;
                     case 3:
                         yc=0;
                         home[2][yw]=1;
                         QMessageBox::information(this, "抱歉", "绿队消灭了一架黄队的飞机", QMessageBox::Ok);
                         break;}
                     qp[g1-52][0]=4;
                     //qDebug()<<g1;
                 }
                 else{
                     if(g1==44){qp[g1][0]=0;g1=48;}
                     if(g1==40){qp[g1][0]=0;g1=44;}
                     switch(qp[g1][0]){
                     case 1:
                         rc=0;
                         home[0][rw]=1;
                         QMessageBox::information(this, "抱歉", "绿对消灭了一架红队的飞机", QMessageBox::Ok);
                         break;
                     case 2:
                         bc=0;
                         home[1][bw]=1;
                         QMessageBox::information(this, "抱歉", "绿队消灭了一架蓝队的飞机", QMessageBox::Ok);
                         break;
                     case 3:
                         yc=0;
                         home[2][yw]=1;
                         QMessageBox::information(this, "抱歉", "绿队消灭了一架黄队的飞机", QMessageBox::Ok);
                         break;}
                     qp[g1][0]=4;
                 }

             update();}

         }
        if(gc==0){
            if(sjs==6){
                    home[3][gw]=0;
                    qp[39][0]=4;
                    g1=39;
                    gc=1;
                    switch(qp[g1][0]){
                    case 1:
                        rc=0;
                        home[0][rw]=1;
                        QMessageBox::information(this, "抱歉", "绿对消灭了一架红队的飞机", QMessageBox::Ok);
                        break;
                    case 2:
                        bc=0;
                        home[1][bw]=1;
                        QMessageBox::information(this, "抱歉", "绿队消灭了一架蓝队的飞机", QMessageBox::Ok);
                        break;
                    case 3:
                        yc=0;
                        home[2][yw]=1;
                        QMessageBox::information(this, "抱歉", "绿队消灭了一架黄队的飞机", QMessageBox::Ok);
                        break;}
                    update();

            }
        }
    }
    if(player%4==0||player%4==1||player%4==2){
        tim2->start(3000);
    }
}
void fxq::handleTimeout(){
    s=s+1;
    if(a<400&&v<150){
        a=a+13;
        v=v+5;
    }
    if(a==390&&v==150){
       tim->stop();
        ok=1;
    }
    update();
}
void fxq::my1(){
    a=0;
    v=0;
    tim->start(50);
    tim2->start(3000);
    sjs=1;
    player=player+1;
    flag=player%4;
    s=sjs;
    if(sjs==1){
        if(flag==0)
        QMessageBox::information(this, "骰子", "红队的骰子数为1", QMessageBox::Ok);
        if(flag==1)
        QMessageBox::information(this, "骰子", "蓝队的骰子数为1", QMessageBox::Ok);
        if(flag==2)
        QMessageBox::information(this, "骰子", "黄队的骰子数为1", QMessageBox::Ok);
        if(flag==3)
        QMessageBox::information(this, "骰子", "绿队的骰子数为1", QMessageBox::Ok);
        }

}
void fxq::my2(){
    a=0;
    v=0;
    tim->start(50);
    tim2->start(3000);
    sjs=2;
    player=player+1;
    flag=player%4;
    s=sjs;
    if(sjs==2){
        if(flag==0)
        QMessageBox::information(this, "骰子", "红队的骰子数为2", QMessageBox::Ok);
        if(flag==1)
        QMessageBox::information(this, "骰子", "蓝队的骰子数为2", QMessageBox::Ok);
        if(flag==2)
        QMessageBox::information(this, "骰子", "黄队的骰子数为2", QMessageBox::Ok);
        if(flag==3)
        QMessageBox::information(this, "骰子", "绿队的骰子数为2", QMessageBox::Ok);
        }

}
void fxq::my3(){
    a=0;
    v=0;
    tim->start(50);
    tim2->start(3000);
    sjs=3;
    player=player+1;
    flag=player%4;
    s=sjs;
    if(sjs==3){
        if(flag==0)
        QMessageBox::information(this, "骰子", "红队的骰子数为3", QMessageBox::Ok);
        if(flag==1)
        QMessageBox::information(this, "骰子", "蓝队的骰子数为3", QMessageBox::Ok);
        if(flag==2)
        QMessageBox::information(this, "骰子", "黄队的骰子数为3", QMessageBox::Ok);
        if(flag==3)
        QMessageBox::information(this, "骰子", "绿队的骰子数为3", QMessageBox::Ok);
        }

}
void fxq::my4(){
    a=0;
    v=0;
    tim->start(50);
    tim2->start(3000);
    sjs=4;
    player=player+1;
    flag=player%4;
    s=sjs;
    if(sjs==4){
        if(flag==0)
        QMessageBox::information(this, "骰子", "红队的骰子数为4", QMessageBox::Ok);
        if(flag==1)
        QMessageBox::information(this, "骰子", "蓝队的骰子数为4", QMessageBox::Ok);
        if(flag==2)
        QMessageBox::information(this, "骰子", "黄队的骰子数为4", QMessageBox::Ok);
        if(flag==3)
        QMessageBox::information(this, "骰子", "绿队的骰子数为4", QMessageBox::Ok);
        }

}
void fxq::my5(){
    a=0;
    v=0;
    tim->start(50);
    tim2->start(3000);
    sjs=5;
    player=player+1;
    flag=player%4;
    s=sjs;
    if(sjs==5){
        if(flag==0)
        QMessageBox::information(this, "骰子", "红队的骰子数为5", QMessageBox::Ok);
        if(flag==1)
        QMessageBox::information(this, "骰子", "蓝队的骰子数为5", QMessageBox::Ok);
        if(flag==2)
        QMessageBox::information(this, "骰子", "黄队的骰子数为5", QMessageBox::Ok);
        if(flag==3)
        QMessageBox::information(this, "骰子", "绿队的骰子数为5", QMessageBox::Ok);
        }

}
void fxq::my6(){
    a=0;
    v=0;
    tim->start(50);
    tim2->start(3000);
    sjs=6;
    player=player+1;
    flag=player%4;
    s=sjs;
    if(sjs==6){
        if(flag==0)
        QMessageBox::information(this, "骰子", "红队的骰子数为6", QMessageBox::Ok);
        if(flag==1)
        QMessageBox::information(this, "骰子", "蓝队的骰子数为6", QMessageBox::Ok);
        if(flag==2)
        QMessageBox::information(this, "骰子", "黄队的骰子数为6", QMessageBox::Ok);
        if(flag==3)
        QMessageBox::information(this, "骰子", "绿队的骰子数为6", QMessageBox::Ok);
        }


}
