#ifndef GROUPVIEW_H
#define GROUPVIEW_H

#include "listviewwidget.h"
#include "viewveicolo.h"

#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QObject>

class GroupView : public QWidget
{
    Q_OBJECT
private:
    QPushButton *btnElimina;
    QPushButton* btnModifica;
    ListViewWidget* list;
    ViewVeicolo* dialog;
    QWidget* parent;

public:
    GroupView(QWidget* = nullptr);
    ~GroupView();
    ListViewWidget* getList() const;
    QPushButton* getBtnElimina() const;
    QPushButton* getBtnModifica() const;

public slots:
    void slotElementoSelezionato(bool= true)const;
    void slotRowChanged()const;

signals:
    void signalElementoSelezionato(bool=true)const;

};

#endif // GROUPVIEW_H
