#ifndef GROUPVIEW_H
#define GROUPVIEW_H
#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QObject>
#include "listviewwidget.h"

class GroupView : public QWidget
{
    Q_OBJECT
private:
    QPushButton *btnElimina;
    QPushButton* btnModifica;
    QPushButton* btnVendi;
    ListViewWidget* list;
    ListViewWidget* listVenduti;

    QWidget* parent;
    bool status;

public:
    GroupView(bool,QWidget* = nullptr);
    ~GroupView();
    ListViewWidget* getList() const;
    ListViewWidget* getListVenduti() const;
    QPushButton* getBtnElimina() const;
    QPushButton* getBtnModifica() const;
    QPushButton* getBtnVendi() const;

public slots:
    void slotElementoSelezionato(bool= true)const;
    void slotRowChanged()const;
    void slotDisableElimina() const;
    void slotDisableVendi() const;
    void slotDisableLista(bool) const;


signals:
    void signalElementoSelezionato(bool=true)const;

};

#endif // GROUPVIEW_H
