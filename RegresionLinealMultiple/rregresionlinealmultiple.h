#ifndef RREGRESIONLINEALMULTIPLE_H
#define RREGRESIONLINEALMULTIPLE_H

#include <QMainWindow>

namespace Ui {
class RregresionLinealMultiple;
}

class RregresionLinealMultiple : public QMainWindow
{
    Q_OBJECT

public:
    explicit RregresionLinealMultiple(QWidget *parent = 0);
    ~RregresionLinealMultiple();
    double D[3][4];
    double A[8], B[8], C[8], E[8], F[8];

private:
    Ui::RregresionLinealMultiple *ui;
public slots:
    void metodo();
    void borrar();
};

#endif // RREGRESIONLINEALMULTIPLE_H
