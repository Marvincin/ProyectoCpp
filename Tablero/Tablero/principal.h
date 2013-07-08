#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "nivel.h"
#include <QDialog>

namespace Ui {
class principal;
}

class principal : public QDialog
{
    Q_OBJECT
    
public:
    explicit principal(QWidget *parent = 0);
    nivel *w;
    ~principal();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::principal *ui;
};

#endif // PRINCIPAL_H
