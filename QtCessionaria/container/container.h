#ifndef CONTAINER_H
#define CONTAINER_H

#include "hierarchy/camion.h"
#include "hierarchy/auto.h"
#include "hierarchy/moto.h"


/* 1) Lista concatenata o lista doppiamente concatenata?
 * 2) Obbligatorio un iteratore per scorrere gli elementi della lista (cuscino tra la lista e l'interfaccia)
 * 3) Funzionalità della lista:
 *      3.1) Inserimento - Inizio e Fine con verifica se duplicati
 *      3.2) Rimozione  -   eventuale rimozione anche dei duplicati
 *      3.3) Modifica
 *      3.4) Estrazione (come visualizzazione e non come anche rimozione) elemento del container in tempo lineare - Inizio - nella lista - Fine
 *      3.5) Ricerca elemento del container
 *      3.6) Verifica elementi doppi (stessa targa) nel container
 *      3.7) COPIA DI CONTAINER (?) nel caso in cui nel progetto sia implementata la vendita di veicoli
 *      3.8) Flush del container (elimina tutti gli elementi)
 * * * */

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
        ~Nodo(){delete info;}
        T& getInfo()const{return new T(info);}//RITORNA L'OGGETTO t (auto, moto, camion) CONTENUTO NEL NODO
    };
    Nodo* first;
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
    void push_begin(const T&);
    void push_end(const T&);
    void push(const T&, unsigned int =0);//inserisce l'elemento t in posizione posiz (se la posizione è valida)
    void remove(const T&);
    bool isDuplicate(const T&) const;//richiamata dalle push per vedere se il T passato è già presente nel container.
    int getPosiz(const T&)const; //ritorna la posizione (se presente) dell'elemento passato nel container
    void modify(const T&, const T&);//t1 è l'elemento dentro il container. Modifica l'elemento dentro il container eliminando quello vecchio(t1) ed inserendo nella stessa posizione quello nuovo (t2)
    //T& getVeicolo(const Nodo* n)const;//restituisce una copia dell'oggetto a cui punta l'iteratore
    bool search(const T&)const;
    bool checkDuplicatePlate(const T&)const;
    bool checkPlate(const T&)const;//sarà usata per controllare la stringa nella textbox dell'interfaccia grafica. Uguale a checkDuplicatePlate ma senza cast del parametro formale
    bool checkDuplicateChassis(const T&)const;
    bool checkDuplicateEngine(const T&)const;
    unsigned int getSize()const;
    Container<T>& copy(const Container&);//esegue una copia del container
    Container<T>* getVehicleByType(const string type);//restituisce un nuovo container con tutti i veicoli di tipo type inserito
    string getTipoVeicolo()const;//restituisce una stringa che identifica la tipologia del veicolo dell'oggetto di invocazione
    void erase();
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
void Container<T>::push_begin(const T& t){
    if(isEmpty()){
        first=new Nodo(t,nullptr,nullptr);
        return;
    }
    try{
        if(!isDuplicate(t) && !checkDuplicatePlate(t) && !checkDuplicateEngine(t) && !checkDuplicateChassis(t) && !checkPlate(t)){
            Nodo* newfirst=new Nodo(t,nullptr,first);
            first->prev=newfirst;
            first=newfirst;
            return;
        }
        throw Exc();
    }
    catch (Exc){
        Exc(6,"duplicato");
    }
}

template<class T>
void Container<T>::push_end(const T& t){
    if(isEmpty()){
        first=new Nodo(t,nullptr, nullptr);
        return;
    }
    try{
        if(!isDuplicate(t) && !checkDuplicatePlate(t) && !checkDuplicateEngine(t) && !checkDuplicateChassis(t) && !checkPlate(t)){
            Nodo* scorri=first;
            while(scorri->next)
                scorri=scorri->next;
            scorri->next=new Nodo(t,scorri,nullptr);
            return;
        }
        throw Exc();
    }
    catch(Exc){
        Exc(6,"duplicato");
    }
}

template<class T>
void Container<T>::push(const T& t, unsigned int posiz){
    try{
        if(!isDuplicate(t) && !checkDuplicatePlate(t) && !checkDuplicateEngine(t) && !checkDuplicateChassis(t) && !checkPlate(t))  //check se il veicolo è duplicato
            throw Exc();
    }
    catch(Exc){
        Exc(6,"duplicato");
        return;
    }

    if(posiz>getSize()){
        push_end(t);
        return;
    }
    if(isEmpty() || posiz==0){
        push_begin(t);
        return;
    }
    Nodo* scorri=first;
    unsigned int pos=0;
    while(scorri->next){
        if(pos==posiz){
            scorri->prev->next=new Nodo(t,scorri->prev,scorri);
            scorri->prev=scorri->prev->next;
            return;
        }
        pos++;
        scorri=scorri->next;
    }
    if(scorri && pos==posiz){
        scorri->prev->next=new Nodo(t,scorri->prev,scorri);
        scorri->prev=scorri->prev->next;
    }

    return;
}

template<class T>
void Container<T>::remove(const T& t){
    try{
        if(isEmpty()) throw Exc();
    }
    catch(Exc){
        Exc(7);
        return;
    }

    if(first->info==t){                 //rimozione in testa
        Nodo* elim=first;
        first=first->next;
        if(first)//se eliminiamo il solo ed unico nodo contenuto nel container
            first->prev=nullptr;
        elim->prev=elim->next=nullptr;
        delete elim;
        return;
    }
    Nodo* scorri=first;                 //rimozione nel mezzo
    while(scorri->next){
        if(scorri->info==t){
            scorri->prev->next=scorri->next;
            scorri->next->prev=scorri->prev;
            scorri->next=scorri->prev=nullptr;
            delete scorri;
            return;
        }
        scorri=scorri->next;
    }
    try{
        if(scorri->info==t){                //rimozione alla fine
            scorri->prev->next=nullptr;
            scorri->prev=nullptr;
            delete scorri;
        }
        else
            throw Exc();
    }catch(Exc){
        Exc(12, "Veicolo non presente");
    }
    return;
}

template<class T>
bool Container<T>::isDuplicate(const T& t)const{
    if(isEmpty()) return false;

    Nodo* scorri=first;
    while(scorri && scorri->next){
        if(scorri->info == t) return true;
        scorri=scorri->next;
    }
    return (scorri->info==t);
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

    if(scorri->info==t) return posiz++;

    return -1;
    //throw Exc(...);

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

/*template<class T>
T& Container<T>::getVeicolo(const Nodo* n)const{
    return new T(n->info);
}//RITORNA L'OGGETTO t CONTENUTO NEL NODO*/

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
bool Container<T>::checkDuplicatePlate(const T& t)const{
    if(isEmpty()) return false;

    Mezzo* me=dynamic_cast<Mezzo*>(t);
    Nodo* scorri=first;
    while(me && scorri->next){
       Mezzo* mz=dynamic_cast<Mezzo*>(scorri->info);
        if(me && mz && (mz->getTarga()==me->getTarga()))
            return true;

        scorri=scorri->next;
    }
    //confronto ultimo nodo:
    Mezzo* mz=dynamic_cast<Mezzo*>(scorri->info);
    return(me && mz && (mz->getTarga()==me->getTarga()));
}

template<class T>
bool Container<T>::checkPlate(const T& t)const{
    Mezzo* mz=dynamic_cast<Mezzo*>(t);
    if(mz)
        return mz->checkTarga();
    return false;
    /*try{
        if(isEmpty()) throw Exc();
    }
    catch(Exc){
        Exc(7);
        return false;
    }
     Nodo* scorri=first;
     while(scorri->next){
         Mezzo* mz=dynamic_cast<Mezzo*>(scorri->info);
         if(mz && mz->getTarga()==plate)
             return true;
         scorri=scorri->next;
     }
     //confronto ultimo nodo:
     Mezzo* mz=dynamic_cast<Mezzo*>(scorri->info);
     return(mz && mz->getTarga()==plate);*/
}

template<class T>
bool Container<T>::checkDuplicateEngine(const T& t)const{
    if(isEmpty()) return false;

    Nodo* scorri=first;
    Motore* mt=dynamic_cast<Motore*>(t);
    while(mt && scorri->next){
        Motore* mttemp=dynamic_cast<Mezzo*>(scorri->info);
        if(mttemp && mt->getNMotore()==mttemp->getNMotore())
            return true;
        scorri=scorri->next;
    }
    //confronto ultimo nodo:
    Mezzo* mttemp=dynamic_cast<Mezzo*>(scorri->info);
    return(mt && (mttemp && mt->getNMotore()==mttemp->getNMotore()));
}

template<class T>
bool Container<T>::checkDuplicateChassis(const T& t)const{
    if(isEmpty()) return false;

    Nodo* scorri=first;
    Carrozzeria* cr=dynamic_cast<Carrozzeria*>(t);
    while(cr && scorri->next){
        Carrozzeria* crtemp=dynamic_cast<Carrozzeria*>(scorri->info);
        if(crtemp && cr->getNTelaio()==crtemp->getNTelaio())
            return true;
        scorri=scorri->next;
    }
    //confronto ultimo nodo:
    Carrozzeria* crtemp=dynamic_cast<Carrozzeria*>(scorri->info);
    return(cr && (crtemp && cr->getNTelaio()==crtemp->getNTelaio()));
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

template<class T>
Container<T>* Container<T>::getVehicleByType(const string type){
    Container<T>* nuovo=new Container<T>;
    for(auto it=begin(); it != end();++it)
        if((*it)->getTipo()==type)
            nuovo->push_end(*it);
    return nuovo;
}//ritorna un container templatizzato con tutti gli elementi pari al tipo di typeveic

template<class T>
string Container<T>::getTipoVeicolo()const{
    try{
        Carrozzeria*cr=dynamic_cast<Carrozzeria*>(*this);
        if(cr) return "carrozzeria";

        Motore* mt=dynamic_cast<Motore*>(*this);
        if(mt) return "motore";

        Auto* au=dynamic_cast<Auto*>(*this);
        if(au) return "auto";

        Camion* cm=dynamic_cast<Camion*>(*this);
        if(cm) return "camion";

        Moto* mto=dynamic_cast<Moto*>(*this);
        if(mto) return "moto";
        throw Exc();
    }catch(Exc){
         Exc(4,"non valido");
    }
}

template<class T>
void Container<T>::erase(){
    while(!isEmpty())
        remove(first->info);
    return;
}

#endif // CONTAINER_H
