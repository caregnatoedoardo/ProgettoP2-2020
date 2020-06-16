#include "printlistview.h"
#include <QByteArray>
#include "model.h"


PrintListView::PrintListView(Veicolo* i, QWidget* p):
    veicolo(i),parent(p)
{
   update();

}

void PrintListView::update(){
    QPixmap a = Model::getImage(veicolo->getPathImg());


   setIcon(a);
   setText(QString::fromStdString(veicolo->getDetails()));


}

Veicolo* PrintListView::getItemAddress()const{
    return veicolo;
}
