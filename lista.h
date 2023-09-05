#include <iostream>
#include "nodo.h"

#ifndef __LISTA_H__
#define __LISTA_H__

enum Iteracion {
    SIGUIENTE, 
    FINAL, 
    ANTERIOR
};

template <class T> class Lista {
private:
	Nodo<T>* primero;
	Nodo<T>* iterador;
	int size;
	int iteracion;
	
public: 

	Lista();

	~Lista();

	void irANodo(int x);	
	
	void iterar(Iteracion iteracion);

	void resetIter();

	void assign(T data);

	Nodo<T>* getNodo();

	T getLData(int x);

	void add(T data);

	void remove(int x);

	int getIter();

	int getSize();

};


template <class T> Lista<T>::Lista() {
	this->primero = NULL;
	this->iterador = this->primero;
	this->iteracion = 0;
	this->size = 0;
}

template <class T> Lista<T>::~Lista() {
	Nodo<T>* destructor = this->primero;
	while(this->getSize()>0){
		this->primero = this->primero->next();
		delete destructor;
		destructor = this->primero;
		this->size --;
	}
} 

template <class T> void Lista<T>::assign(T data){
	this->iterador->setNData(data);
}

template <class T> void Lista<T>::iterar(Iteracion iteracion){
	if(this->getSize() > 0){
        if(iteracion == ANTERIOR){
            this->iterador = this->iterador->prev();
            this->iteracion --;
        } else {
            do{
                this->iterador = this->iterador->next();
                this->iteracion++;
            } while(this->iteracion < this->getsize() -1);
        }
	}
}

template <class T> void Lista<T>::resetIter() {
	this->iterador = this->primero;
	this->iteracion = 0;
}

template <class T> Nodo<T>* Lista<T>::getNodo() {
	return this->iterador;
}

template <class T> T Lista<T>::getLData(int x) {
	irANodo(x);
	return this->iterador->getNData();
}

template <class T> void Lista<T>::add(T data) {
	Nodo<T>* nuevo = new Nodo<T>(data);
	iterar(FINAL);
	if(this->getSize() == 0){
		this->primero = nuevo;
		this->iterador = this->primero;
	}else{
		nuevo->setAnt(this->iterador);
		this->iterador->setSig(nuevo);
	}
	this->size++;
}

template <class T> int Lista<T>::getIter() {
	return this->iteracion;
}

template <class T> int Lista<T>::getSize() {
	return this->size;
}

template <class T> void Lista<T>::irANodo(int x){
	bool inicioMasCerca = (this->getIter() / 2 < x);

    if(x >= this->getIter()){
        for(int i = this->getIter(); i > x; i--){
            this->iterar(ANTERIOR);
        }
    } else {
        if(inicioMasCerca){
        	this->resetIter();
        }
        for(int i = this->getIter(); i < x; i++){
            this->iterar(SIGUIENTE);
        }
    }
}

template <class T> void Lista<T>::remove(int x){
	irANodo(x);
	if(this->getSize() == 1){
		this->primero = NULL;
		this->iterador = this->primero;
	}else{
		if(this->iterador == this->primero){
			this->primero = this->primero->next();
			this->primero->setAnt(NULL);
			this->iterador = this->primero;
		}else{
			this->iterador->prev()->setSig(this->iterador->next());
			this->iterador->next()->setAnt(this->iterador->prev());
			this->iterador = this->primero;
		}
	}
	this->size--;
}

#endif