#include "groupview.h"
#include "viewveicolo.h"


QPushButton* GroupView::getBtnElimina()const
{
    return btnElimina;
}

QPushButton* GroupView::getBtnModifica()const
{
    return btnModifica;
}

GroupView::GroupView(QWidget* p):
    QWidget(p),
    btnElimina(new QPushButton("Elimina Record Selezionato",this)),
    btnModifica(new QPushButton("Modifica",this)),
    list(new ListViewWidget(this)),
    dialog(nullptr)
{
    QVBoxLayout* vBox = new QVBoxLayout(this);
    btnElimina->setEnabled(false);
    btnModifica->setEnabled(false);
    vBox->addWidget(list);
    list->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QHBoxLayout* l= new QHBoxLayout();


    l->addWidget(btnModifica);
    l->addWidget(btnElimina);

    vBox->addLayout(l);
    connect(list, SIGNAL(currentRowChanged(int)),this,SLOT(slotElementoSelezionato()));
    connect(this, SIGNAL(signalElementoSelezionato(bool)),this,SLOT(slotElementoSelezionato(bool)));


}

GroupView::~GroupView(){
    delete list;
    delete btnElimina;
}

ListViewWidget* GroupView::getList() const
{
    return list;
}

void GroupView::slotElementoSelezionato(bool t)const {
    btnElimina->setEnabled(t);
    btnModifica->setEnabled(t);
}

void GroupView::slotRowChanged()const{
    emit slotElementoSelezionato(true);
}
