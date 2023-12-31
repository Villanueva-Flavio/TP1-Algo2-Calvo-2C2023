#ifndef __NODO_H__
#define __NODO_H__

template <class T> class Nodo{
private:
    T data;
    Nodo<T>* sig;
    Nodo<T>* ant;

public:

    Nodo(T data);
    
    T getNData();
    
    void setNData(T data);
    
    Nodo<T>* next();

    Nodo<T>* prev();

    void setSig(Nodo<T>* sig);

    void setAnt(Nodo<T>* ant);
};

template <class T> Nodo<T>::Nodo(T data){
    this->data = data;
    this->sig = NULL;
    this->ant = NULL;
}

template <class T> T Nodo<T>::getNData(){
    return this->data;
}

template <class T> void Nodo<T>::setNData(T data){
    this->data = data;
}

template <class T> Nodo<T>* Nodo<T>::next(){
    return this->sig;
}

template <class T> Nodo<T>* Nodo<T>::prev(){
    return this->ant;
}

template <class T> void Nodo<T>::setSig(Nodo<T>* sig) {
    this->sig = sig;
}

template <class T> void Nodo<T>::setAnt(Nodo<T>* ant) {
    this->ant = ant;
}

#endif