#ifndef CONTAINER_H
#define CONTAINER_H
#include "exceptions/exceptions.h"
#include "hierarchy/mezzo.h"

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
 *
 * * */

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
        Nodo(const T& i=nullptr, Nodo*pr=nullptr, Nodo*ne=nullptr):info(i),prev(pr),next(ne){}
        ~Nodo(){delete info; delete prev; delete next;};
    };
    Nodo* first;
    class Iteratore{
        friend class Container<T>;
    private:
        Nodo* punt;//è il puntatore che punta ad un nodo della doppialista;
    public:
        Iteratore(Nodo* p=nullptr):punt(p){}
        Iteratore& operator=(const Iteratore&);
        Iteratore& operator++();
        Iteratore& operator--();
        bool operator==(const Iteratore&)const;
        bool operator!=(const Iteratore&)const;
        T& operator*()const; //dereferenziazione, restituisce l'oggetto a cui punta l'iteratore
    };
public:
    Iteratore begin()const;
    Iteratore end()const;
    Container(Nodo* p=nullptr):first(p){}
    ~Container(){if(first) delete first;}

    bool isEmpty()const;
    void push_begin(const T&);
    void push_end(const T&);
    void push(const T&, unsigned int =0);//inserisce l'elemento t in posizione posiz (se la posizione è valida)
    void remove(const T&);
    bool isDuplicate(const T&) const;//richiamata dalle push per vedere se la targa di un veicolo è doppia
    int getPosiz(const T&)const; //ritorna la posizione (se presente) dell'elemento passato nel container
    void modify(const T&, const T&);//t1 è l'elemento dentro il container. Modifica l'elemento dentro il container eliminando quello vecchio(t1) ed inserendo nella stessa posizione quello nuovo (t2)
    T& show(const Nodo* n)const;//restituisce una copia dell'oggetto a cui punta l'iteratore
    bool search(const T&)const;
    bool checkDuplicatePlate(string plate)const;
    unsigned int getSize()const;
    //unsigned int checkDuplicate()const;//verifica se nel container ci sono elementi doppi e li elimina (non dovrebbe servire per pre e post delle push)
    Container& copy();//esegue una copia del container
};

//METODI ITERATORE
//for(auto it=vec.begin();it!=vec.end();++it)

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
    return *punt;
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
bool Container<T>::isEmpty()const{
    return (!first);
}

template<class T>
void Container<T>::push_begin(const T& t){
    if(isEmpty()){
        first=new Nodo(t,nullptr,nullptr);
        return;
    }
    if(!isDuplicate(t)){
        //first=new Nodo(t,nullptr,first);
        Nodo* newfirst=new Nodo(t,nullptr,first);
        first->prev=newfirst;
        first=newfirst;
    }else
        throw Exc(6,"duplicato");
    return;
}

template<class T>
void Container<T>::push_end(const T& t){
    if(isEmpty()){
        first=new Nodo(t,nullptr, nullptr);
        return;
    }
    if(!isDuplicate(t)){
        Nodo* scorri=first;
        while(scorri->next)
            scorri=scorri->next;
        scorri->next=new Nodo(t,scorri,nullptr);
    }else
        throw Exc(6,"duplicato");
    return;
}

template<class T>
void Container<T>::push(const T& t, unsigned int posiz){
    if(posiz>getSize()) throw Exc(10,"posizione"); //check della posizione

    if(isDuplicate(t)){                                        //check se il veicolo è duplicato
        throw Exc(6,"duplicato");
        return;
    }

    if(isEmpty() || posiz==0){
        push_begin(t);
        return;
    }
    Nodo* scorri=first;
    int pos=0;
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
    if(isEmpty()) return;
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
    if(scorri->info==t){                //rimozione alla fine
        scorri->prev->next=nullptr;
        scorri->prev=nullptr;
        delete scorri;
    }
    return;
}

template<class T>
bool Container<T>::isDuplicate(const T& t)const{
    if(isEmpty()) return false;// se è vuota non è duplicato

    Nodo* scorri=first;
    while(scorri->next){
        if(scorri->info == t) return true;
        scorri=scorri->next;
    }
    return (scorri->info==t);
}

template<class T>
int Container<T>::getPosiz(const T& t)const{
    if(isEmpty()) return -1;

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
    if(isEmpty()) return;
    push(t2,getPosiz(t1));
    remove(t1);
    return;
}

template<class T>
T& Container<T>::show(const Nodo* n)const{
    return new T(n->info);
}//RITORNA L'OGGETTO t CONTENUTO NEL NODO

template<class T>
bool Container<T>::search(const T& t)const{
    if(isEmpty()) return false;

    Nodo* scorri=first;
    while(scorri->next){
        if(scorri->info==t) return true;
        scorri=scorri->next;
    }
    return (scorri->info==t);

}//CERCA L'ELEMENTO t ALL'INTERNO DEL CONTAINER E RITORNA TRUE O FALSE

template<class T>
bool Container<T>::checkDuplicatePlate(string plate)const{
    if(isEmpty()) return false;

    Nodo* scorri=first;
    while(scorri->next){
        Mezzo* mz=dynamic_cast<Mezzo*>(scorri->info);
        if(mz && mz->getTarga()==plate)
            return true;

        scorri=scorri->next;
    }
    //confronto ultimo nodo:
    Mezzo* mz=dynamic_cast<Mezzo*>(scorri->info);
    return(mz && mz->getTarga()==plate);
}

/*template<class T>
unsigned int Container<T>::checkDuplicate()const{
    if(isEmpty()) return false;
    unsigned int duplicate=0;
    Nodo* check=first;
    Nodo* scorri=first;//check è il nodo che scorrerà la mia lista per vedere se ci sono duplicati
    while(check->next){
        while(scorri->next){
            if(isDuplicate(scorri)){
                if(getPosiz(check) != getPosiz(scorri)){//evita di controllare due nodi che puntano allo stesso elemento
                        remove(scorri);
                        duplicate++;
                    }
                }
            scorri=scorri->next;
        }
        if(isDuplicate(scorri)) remove(scorri);

        scorri=first;
        check=check->next;
    }
    return duplicate;
}//FUNZIONE LANCIATA PER VERIFICARE LA CONSISTENZA DELL'ARCHIVIO*/



template<class T>
unsigned int Container<T>::getSize()const{
    if(isEmpty()) return 0;
    unsigned int size=0;
    Nodo*scorri=first;
    while(scorri->next){
        size++;
        scorri=scorri->next;
    }
    return size++;
}

template<class T>
Container<T>& Container<T>::copy(){ //usata per fare dei file di backup dei container delle auto vendute e presenti
    Container* nuovo = new Container(first);
    return *nuovo;
}
#endif // CONTAINER_H
