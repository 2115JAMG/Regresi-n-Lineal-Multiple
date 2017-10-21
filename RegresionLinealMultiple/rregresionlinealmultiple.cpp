#include "rregresionlinealmultiple.h"
#include "ui_rregresionlinealmultiple.h"
#include <Qstring>

RregresionLinealMultiple::RregresionLinealMultiple(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RregresionLinealMultiple)
{
    ui->setupUi(this);
    //Conexiones
      connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(metodo()));
      connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(borrar()));
      connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(close()));

}

RregresionLinealMultiple::~RregresionLinealMultiple()
{
    delete ui;
}
void RregresionLinealMultiple::metodo(){
QString temp, temp1, temp2, temp3, temp4;
    double X1=ui->x1->value(); //we take the value of spingbox and save them in double variables
    double X2=ui->x2->value();
    double X3=ui->x3->value();
    double X4=ui->x4->value();
    double X5=ui->x5->value();
    double X6=ui->x6->value();
    double X8=ui->x1_2->value();
    double X9=ui->x2_2->value();
    double X10=ui->x3_2->value();
    double X11=ui->x4_2->value();
    double X12=ui->x5_2->value();
    double X13=ui->x6_2->value();
    double F1=ui->x1_3->value();
    double F2=ui->x2_3->value();
    double F3=ui->x3_3->value();
    double F4=ui->x4_3->value();
    double F5=ui->x5_3->value();
    double F6=ui->x6_3->value();
    int i, n=6, x, j; //Variables that are dealt with in the program, such as the sum of the x and y
    double sumaX1=0,sumaX2=0, sumaY=0, productoXY=0, productoX1X2=0, productoX2Y=0, suma_cuadrado_X1=0, suma_cuadrado_X2=0, suma_cuadrado_y=0, mediaX=0, mediaY=0;
    int a2=0, a1=0, a0=0;
    double r=0, mul, Sr=0, St=0, m=0, l=0; //Variable to show the correlation between the line and the points

    A[0]=X1;
    A[1]=X2;
    A[2]=X3;
    A[3]=X4;
    A[4]=X5;
    A[5]=X6;   // store the value of x in a vector
    B[0]=F1;
    B[1]=F2;
    B[2]=F3;
    B[3]=F4;
    B[4]=F5;
    B[5]=F6;   // store the value of y in a vector
    C[0]=X8;
    C[1]=X9;
    C[2]=X10;
    C[3]=X11;
    C[4]=X12;
    C[5]=X13;

    for(i=0;i<6;i++){   //In this forum all sums required for formula
        sumaX1=sumaX1+A[i];
        sumaX2=sumaX2+C[i];
        sumaY=sumaY+B[i];
        productoXY=productoXY+(A[i]*B[i]);
        productoX1X2=productoX1X2+(A[i]*C[i]);
        productoX2Y=productoX2Y+(C[i]*B[i]);
        suma_cuadrado_X1=suma_cuadrado_X1+(A[i]*A[i]);
        suma_cuadrado_X2=suma_cuadrado_X2+(C[i]*C[i]);
        suma_cuadrado_y=suma_cuadrado_y+(B[i]*B[i]);
        E[i]=0;
        F[i]=0;
    }
    mediaY=sumaY/n; // obtain the median of y

    //Fill the matrix to obtain a0, a1 and a2
    D[0][0]=n;
    D[0][1]=sumaX1;
    D[0][2]=sumaX2;
    D[0][3]=sumaY;
    D[1][0]=sumaX1;
    D[1][1]=suma_cuadrado_X1;
    D[1][2]=productoX1X2;
    D[1][3]=productoXY;
    D[2][0]=sumaX2;
    D[2][1]=productoX1X2;
    D[2][2]=suma_cuadrado_X2;
    D[2][3]=productoX2Y;
    //In this part the matrix is ​​solved by the Gaussian elimination method

    for(i=1;i<3;i++){

    for (x=i;x<3;x++){

      mul=(D[x][i-1])/(D[i-1][i-1]);

    for(j=0;j<4;j++){

      D[x][j]=(D[x][j]-((D[i-1][j])*mul));
     }
    }
    mul=0;
      }

  a2=(D[2][3]/D[2][2]);
  a1=(((D[1][3])-(D[1][2]*a2))/(D[1][1]));
  a0=((D[0][3])-(a2*D[0][2])-(a1*D[0][1]))/(D[0][0]);
    //This is to compute (Yi-the median of Y) and (Yi-a0-a1X1-a2X2)
  for (x=0;x<6;x++){

     E[x]=(B[x]-mediaY)*(B[x]-mediaY);
     F[x]=((B[x])-(a0)-(a1*A[x])-(a2*C[x]))*(B[x]-a0-(a1*A[x])-(a2*C[x]));

  }//calculate St and Sr what is the estimated error of the operation
  for (i=0;i<6;i++){
      St=St+E[i];
      Sr=Sr+F[i];
  }
    //verify Sr equals zero since this form r would become infinite
    if(Sr==0){
    temp.append("\ny=").append(temp2.setNum(a0)).append("+(").append(temp3.setNum(a1)).append(")x1+(").append(temp4.setNum(a2)).append(")x2\nr=Infinito");
}
    //verify that Sr is different from 0 in this way we can express r
    if(Sr!=0){
    r=sqrt((St-Sr)/Sr);
    temp.append("\ny=").append(temp2.setNum(a0)).append("+").append(temp3.setNum(a1)).append("x1+").append(temp4.setNum(a2)).append("x2").append("\nr=").append(temp1.setNum(r));
}
 ui->textEdit->setText(temp);  //The text is presented in the window, showing the result of the operation

}
void RregresionLinealMultiple::borrar(){ //Delete function and all return to 0, and the text is clear.
    ui->x1->setValue(0.0);
    ui->x2->setValue(0.0);
    ui->x3->setValue(0.0);
    ui->x4->setValue(0.0);
    ui->x5->setValue(0.0);
    ui->x6->setValue(0.0);
    ui->x1_2->setValue(0.0);
    ui->x2_2->setValue(0.0);
    ui->x3_2->setValue(0.0);
    ui->x4_2->setValue(0.0);
    ui->x5_2->setValue(0.0);
    ui->x6_2->setValue(0.0);
    ui->x1_3->setValue(0.0);
    ui->x2_3->setValue(0.0);
    ui->x3_3->setValue(0.0);
    ui->x4_3->setValue(0.0);
    ui->x5_3->setValue(0.0);
    ui->x6_3->setValue(0.0);
    ui->textEdit->clear();
}
