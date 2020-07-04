#ifndef LISTVIEWWIDGET_H
#define LISTVIEWWIDGET_H

#include <QListWidget>
#include <QPushButton>
#include <QObject>
#include "printlistview.h"


class ListViewWidget : public QListWidget
{
    Q_OBJECT
    QWidget* parent;
    QAction* onClickAction, *onRightClickAction;

public:
    ListViewWidget(QWidget* =nullptr);
    void addVeicolo(Veicolo*);
    PrintListView* takeItem(int);
    PrintListView* currentItem()const;
    PrintListView* takeItem(Veicolo*);

signals:
    void signalEliminaElementoDaList(Veicolo*);
};

#endif // LISTVIEWWIDGET_H
