#include "printlistview.h"
#include <QByteArray>

PrintListView::PrintListView(Veicolo* i, QWidget* p):
    veicolo(i),parent(p)
{
   update();

}

void PrintListView::update(){
   setText(QString::fromStdString(veicolo->getDetails()));


}

Veicolo* PrintListView::getItemAddress()const{
    return veicolo;
}
