#include "listviewwidget.h"
#include <QScrollBar>

ListViewWidget::ListViewWidget(QWidget* p): parent(p)
{
    addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical,parent),Qt::AlignRight);

}

void ListViewWidget::addVeicolo(Veicolo *a)
{
    PrintListView* ve = new PrintListView(a,parent);
    addItem(ve);
}

PrintListView* ListViewWidget::takeItem(int i){
    PrintListView* p = static_cast<PrintListView*>(QListWidget::takeItem(i));
    return p;
}

PrintListView*  ListViewWidget::takeItem(Veicolo* iad){

    bool find = false;
    PrintListView* ritornato = nullptr;
    for(int i=0; i<count()&& !find; i++){
        PrintListView* t = static_cast<PrintListView*>(item(i));
        if(t->getItemAddress()== iad){
            ritornato = static_cast<PrintListView*>(takeItem(i));
            find = true;
        }
    }
    return ritornato;
}


PrintListView* ListViewWidget::currentItem() const {
    return static_cast<PrintListView*>(QListWidget::currentItem());
}




