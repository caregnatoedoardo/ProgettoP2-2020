#include "groupview.h"
#include "viewveicolo.h"


QPushButton* GroupView::getBtnElimina()const{
    return btnElimina;
}

QPushButton* GroupView::getBtnModifica()const{
    return btnModifica;
}

QPushButton* GroupView::getBtnVendi()const{
    return btnVendi;
}

GroupView::GroupView(bool venduti,QWidget* p):
    QWidget(p),
    btnElimina(new QPushButton("Elimina Record Selezionato",this)),
    btnModifica(new QPushButton("Modifica",this)),
    btnVendi(new QPushButton("Vendi Elemento",this)),
    list(new ListViewWidget(this)),
    listVenduti(new ListViewWidget(this)),
    dialog(nullptr),
    status(venduti)
{
    QVBoxLayout* vBox = new QVBoxLayout(this);
    btnElimina->setEnabled(false);
    btnModifica->setEnabled(false);
    btnVendi->setEnabled(false);
    if(venduti){
        vBox->addWidget(listVenduti);
    }
    else vBox->addWidget(list);

    list->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QHBoxLayout* l= new QHBoxLayout();

    l->addWidget(btnModifica);
    l->addWidget(btnVendi);
    l->addWidget(btnElimina);


    if(venduti){
        btnModifica->hide();
        btnVendi->hide();
    }

    vBox->addLayout(l);
    connect(list, SIGNAL(currentRowChanged(int)),this,SLOT(slotElementoSelezionato()));
    connect(listVenduti, SIGNAL(currentRowChanged(int)),this,SLOT(slotElementoSelezionato()));

    connect(this, SIGNAL(signalElementoSelezionato(bool)),this,SLOT(slotElementoSelezionato(bool)));
}

GroupView::~GroupView(){
    delete list;
    delete listVenduti;
    delete btnElimina;
}

ListViewWidget* GroupView::getList() const{
    if(status) return listVenduti;
    else  return list;
}

void GroupView::slotElementoSelezionato(bool t)const {

    btnElimina->setEnabled(t);
    btnModifica->setEnabled(t);
    btnVendi->setEnabled(t);
}

void GroupView::slotRowChanged()const{
    emit slotElementoSelezionato(true);
}

void GroupView::slotDisableElimina() const{
    btnElimina->setDisabled(true);

}

void GroupView::slotDisableVendi() const{
    btnVendi->setDisabled(true);
}

void GroupView::slotDisableLista(bool i) const{
    list->setDisabled(i);
}
