#ifndef CONTAINER_H
#define CONTAINER_H

#include "hierarchy/camion.h"
#include "hierarchy/auto.h"
#include "hierarchy/moto.h"
#include <iostream>
using namespace std;

template<class T>
class Iteratore;

template<class T>
class Container{
    friend class Iteratore<T>;
private:
    class Nodo{
    public:
        T info;
        Nodo* prev=nullptr, *next =nullptr ;
        Nodo(const T i=nullptr, Nodo*pr=nullptr, Nodo*ne=nullptr):info(i),prev(pr),next(ne){}
        ~Nodo(){if(next) delete next;}
        T& getInfo()const{return new T(info);}//RITORNA L'OGGETTO t (auto, moto, camion) CONTENUTO NEL NODO
        T* cloneInfo() const { return new T(info);}
    };
    Nodo* first=nullptr;
public:
    class Iteratore{
        friend class Container<T>;
    private:
        Nodo* punt;//è il puntatore che punta ad un nodo della doppialista;
    public:
        Iteratore(Nodo* p=nullptr):punt(p){}
        Iteratore& operator=(const Iteratore&);
        Iteratore& operator++();
        Iteratore& operator--();
        Iteratore(const Iteratore& it):punt(it.punt){}
        bool operator==(const Iteratore&)const;
        bool operator!=(const Iteratore&)const;
        T& operator*()const; //dereferenziazione, restituisce l'oggetto a cui punta l'iteratore
        ~Iteratore(){delete punt;}
    };
public:
    Iteratore begin()const;
    Iteratore end()const;
    Container(Nodo* p=nullptr):first(p){}
    Container(const Container& ct);
    Container<T>& operator=(const Container&);
    bool operator==(const Container&);
    bool operator!=(const Container&);
    ~Container(){if(first) delete first;}

    bool isEmpty()const;
    bool push_begin(const T&);
    bool push_end(const T&);
    bool push(const T&, unsigned int =0);//inserisce l'elemento t in posizione posiz (se la posizione è valida)
    bool remove(const T&);
    bool cancella(const T&);
    bool isDuplicate(const T&) const;//richiamata dalle push per vedere se il T passato è già presente nel container.
    int getPosiz(const T&)const; //ritorna la posizione (se presente) dell'elemento passato nel container
    void modify(const T&, const T&);//t1 è l'elemento dentro il container. Modifica l'elemento dentro il container eliminando quello vecchio(t1) ed inserendo nella stessa posizione quello nuovo (t2)
    bool search(const T&)const;
    T getVeicolo(unsigned int)const;
    bool checkDuplicatePlate(const T&)const;
    bool checkPlate(const T&)const;//sarà usata per controllare la stringa nella textbox dell'interfaccia grafica. Uguale a checkDuplicatePlate ma senza cast del parametro formale
    bool checkDuplicateChassis(const T&)const;
    bool checkDuplicateEngine(const T&)const;
    unsigned int getSize()const;
    Container<T>& copy(const Container&);//esegue una copia del container
    Container<T>& getNewContainerByType(const string type);//restituisce un nuovo container con tutti i veicoli di tipo type inserito
    string getTipoVeicolo()const;//restituisce una stringa che identifica la tipologia del veicolo dell'oggetto di invocazione
    void erase();
    Container<T>& ctcopy(const Container<T>& ct);
};

//METODI ITERATORE


template<class T>
typename Container<T>::Iteratore& Container<T>::Iteratore::operator=(const Iteratore& it){
    if(this != &it){
        delete punt;
        punt=it.punt;
    }
    return *this;
}

template<class T>
typename Container<T>::Iteratore& Container<T>::Iteratore::operator++(){
    punt=punt->next;
    return *this;
}

template<class T>
typename Container<T>::Iteratore& Container<T>::Iteratore::operator--(){
    punt=punt->prev;
    return *this;
}

template<class T>
bool Container<T>::Iteratore::operator==(const Iteratore& it)const{
    return punt==it.punt;
}

template<class T>
bool Container<T>::Iteratore::operator!=(const Iteratore& it)const{
    return punt!=it.punt;
}

template<class T>
T& Container<T>::Iteratore::operator*()const{
    return punt->info;
}

template<class T>
typename Container<T>::Iteratore Container<T>::begin()const{
    Iteratore nuovo;
    nuovo.punt=first;
    return nuovo;
}

template<class T>
typename Container<T>::Iteratore Container<T>::end()const{
    Iteratore nuovo=nullptr;
    return nuovo;
}

//METODI CONTAINER

template<class T>
Container<T>::Container(const Container& ct){
    delete first;
    first=ct.first;
}

template<class T>
Container<T>& Container<T>::operator=(const Container<T>& ct){
    if(ct.isEmpty()) return *this;
    if(this != &ct){
        delete first;
        first=ct.first;
    }
    return *this;
}

template<class T>
bool Container<T>::operator==(const Container<T>& ct){
    if(ct.isEmpty() && isEmpty()) return true;
    if(getSize() != ct.getSize()) return false;

    Nodo* scorri=first;
    Nodo* scorrict=ct.first;
    while(scorri->next){
        if(scorri->info!=scorrict->info) return false;
        scorri=scorri->next;
        scorrict=scorrict->next;
    }
    return(scorri->info == scorrict->info);
}

template<class T>
bool Container<T>::operator!=(const Container<T>& ct){
    if(ct.isEmpty() && isEmpty()) return false;
    if(getSize() != ct.getSize()) return true;

    Nodo* scorri=first;
    Nodo* scorrict=ct.first;
    while(scorri->next){
        if(scorri->info==scorrict->info) return false;
        scorri=scorri->next;
        scorrict=scorrict->next;
    }
    return !(scorri->info == scorrict->info);
}

template<class T>
bool Container<T>::isEmpty()const{
   return (!first);


}


template<class T>
bool Container<T>::push_begin(const T& t){
    if(isEmpty()){
        first=new Nodo(t,nullptr,nullptr);
        return true;
    }
    Nodo* newfirst=new Nodo(t,nullptr,first);
    first->prev=newfirst;
    first=newfirst;
    return true;
}



template<class T>
bool Container<T>::push_end(const T& t){
    if(isEmpty()){
        first=new Nodo(t,nullptr, nullptr);
        return true;
    }
    Nodo* scorri=first;
    while(scorri->next)
        scorri=scorri->next;
    scorri->next=new Nodo(t,scorri,nullptr);
    return true;
}

template<class T>
bool Container<T>::push(const T& t, unsigned int posiz){
    if(posiz>getSize()){
        push_end(t);
        return true;
    }
    if(isEmpty() || posiz==0){
        push_begin(t);
        return true;
    }
    Nodo* scorri=first;
    unsigned int pos=0;
    while(scorri->next){
        if(pos==posiz){
            scorri->prev->next=new Nodo(t,scorri->prev,scorri);
            scorri->prev=scorri->prev->next;
            return true;
        }
        pos++;
        scorri=scorri->next;
    }
    if(scorri && pos==posiz){
        scorri->prev->next=new Nodo(t,scorri->prev,scorri);
        scorri->prev=scorri->prev->next;
        return true;
    }
    return false;
}

template<class T>
bool Container<T>::remove(const T& t){
    try{
        if(isEmpty()) throw Exc();
    }
    catch(Exc){
        Exc(7);
        return false;
    }

    if(first->info==t){                 //rimozione in testa
        Nodo* elim=first;
        first=first->next;
        if(first)//se eliminiamo il solo ed unico nodo contenuto nel container
            first->prev=nullptr;
        elim->prev=elim->next=nullptr;
        delete elim;
        return true;
    }
    Nodo* scorri=first;                 //rimozione nel mezzo
    while(scorri->next){
        if(scorri->info==t){
            scorri->prev->next=scorri->next;
            scorri->next->prev=scorri->prev;
            scorri->next=scorri->prev=nullptr;
            delete scorri;
            return true;
        }
        scorri=scorri->next;
    }
    try{
        if(scorri->info==t){                //rimozione alla fine
            scorri->prev->next=nullptr;
            scorri->prev=nullptr;
            delete scorri;
            return true;
        }
        else
            throw Exc();
    }catch(Exc){
        Exc(12, "Veicolo non presente");
        return false;
    }
    return false;
}

template<class T>
bool Container<T>::cancella(const T& t){
    try{
        if(isEmpty()) throw Exc();
    }
    catch(Exc){
        Exc(7);
        return false;
    }

    if(first->info==t){                 //rimozione in testa
        Nodo* elim=first;
        first=first->next;
        if(first)//se eliminiamo il solo ed unico nodo contenuto nel container
            first->prev=nullptr;
        elim->prev=elim->next=nullptr;
        return true;
    }
    Nodo* scorri=first;                 //rimozione nel mezzo
    while(scorri->next){
        if(scorri->info==t){
            scorri->prev->next=scorri->next;
            scorri->next->prev=scorri->prev;
            scorri->next=scorri->prev=nullptr;
            return true;
        }
        scorri=scorri->next;
    }
    try{
        if(scorri->info==t){                //rimozione alla fine
            scorri->prev->next=nullptr;
            scorri->prev=nullptr;
            return true;
        }
        else
            throw Exc();
    }catch(Exc){
        Exc(12, "Veicolo non presente");
        return false;
    }
    return false;
}


template<class T>
int Container<T>::getPosiz(const T& t)const{
    try{
        if(isEmpty()) throw Exc();
    }
    catch(Exc){
        Exc(7);
        return -1;
    }

    int posiz=0;
    Nodo* scorri=first;
    while (scorri->next){
        if(scorri->info == t) return posiz;
        posiz++;
        scorri=scorri->next;
    }

    if(scorri->info==t) return posiz;

    return -1;

}//RITORNA LA POSIZIONE DELL'ELEMENTO t SE ESISTE, SENNO' RITORNA -1 (oppure solleva una eccezione???);

template<class T>
void Container<T>::modify(const T& t1, const T& t2){//remove del nodo t1 e una push con posizione del nodo t2
    try{
        if(isEmpty()) throw Exc();
    }
    catch(Exc){
        Exc(7);
        return;
    }
    push(t2,getPosiz(t1));
    remove(t1);
    return;
}

template<class T>
bool Container<T>::search(const T& t)const{
    try{
        if(isEmpty()) throw Exc();
    }
    catch(Exc){
        Exc(7);
        return false;
    }

    Nodo* scorri=first;
    while(scorri->next){
        if(scorri->info==t) return true;
        scorri=scorri->next;
    }
    return (scorri->info==t);

}//CERCA L'ELEMENTO t ALL'INTERNO DEL CONTAINER E RITORNA TRUE O FALSE

template<class T>
T Container<T>::getVeicolo(unsigned int i)const{
    if(i<0 || i>getSize()) return nullptr;
    unsigned int index=0;
    Nodo* scorri=first;
    while(scorri && index<i){
        scorri=scorri->next;
        index++;
    }
    return scorri->info;
}

template<class T>
unsigned int Container<T>::getSize()const{
    if(isEmpty()) return 0;

    unsigned int size=0;
    Nodo*scorri=first;
    while(scorri->next){
        size++;
        scorri=scorri->next;
    }
    return ++size;
}

template<class T>
Container<T>& Container<T>::copy(const Container<T>& ct){ //usata per fare dei file di backup dei container delle auto vendute e presenti
    delete first;
    first=ct.first;
    return *this;
}

template<class T>    // RICREATO NEL MODEL //
Container<T>& Container<T>::getNewContainerByType(const string type){
    Container<T>* nuovo=new Container<T>;
    for(auto it=begin(); it != end();++it)
        if((*it)->getTipo()==type)
            nuovo->push_end(*it);
    return *nuovo;
}//ritorna un container templatizzato con tutti gli elementi pari al tipo di typeveic

template<class T>
void Container<T>::erase(){
    while(!isEmpty())
        remove(first->info);
    return;
}

template<class T>
Container<T>& Container<T>::ctcopy(const Container<T>& ct){
    Container<T>* nuovo = new Container<T>;
    nuovo->first = new Nodo();

    Nodo* scorri=ct.first;
    while(scorri->next){
        T* copia = new T();
           copia= scorri->cloneInfo();
        nuovo->push_begin(*copia);
        scorri=scorri->next;
    }
    if(scorri){
        T* copia2 = new T();
           copia2=scorri->cloneInfo();
        nuovo->push_begin(*copia2);
    }
    return *nuovo;
}
#endif // CONTAINER_H
