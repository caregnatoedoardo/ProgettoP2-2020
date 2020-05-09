#ifndef VIEWVEICOLO_H
#define VIEWVEICOLO_H


#include "printlistview.h"
#include "listviewwidget.h"

#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QObject>



class ViewVeicolo : public QDialog
{
    Q_OBJECT

private:

    PrintListView *listVeicoli;
    QPushButton* btnClose;
    QPushButton* salvaMod;
    Veicolo* veicolo;
    QTextEdit* descrizione;

public:
    ViewVeicolo(PrintListView*, QWidget* = nullptr);


public slots:
    void slotSalvaModifica() const;

};


#endif // VIEWVEICOLO_H
