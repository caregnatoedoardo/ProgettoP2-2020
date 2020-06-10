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
    QLabel* immagine;
    QLineEdit* pathFoto;
    QPushButton* bottoneScegliFoto;
    void setFoto(const QPixmap&);

public:

    ViewVeicolo(PrintListView* = nullptr, QWidget* = nullptr);


public slots:
    void slotSalvaModifica() const;
    //void slotFotoModifica();

};


#endif // VIEWVEICOLO_H
