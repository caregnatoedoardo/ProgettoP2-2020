#ifndef PRINTLISTVIEW_H
#define PRINTLISTVIEW_H
#include <QListWidgetItem>
#include "hierarchy/veicolo.h"
#include "hierarchy/carrozzeria.h"


class PrintListView : public QListWidgetItem{
private:
    Veicolo* veicolo;
    QWidget* parent;

public:
    PrintListView(Veicolo*,QWidget* =nullptr);
    Veicolo* getItemAddress() const;
    void update();
};

#endif // PRINTLISTVIEW_H
