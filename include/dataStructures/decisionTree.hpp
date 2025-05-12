//
// Created by ignac on 5/8/2025.
//

#ifndef DECISIONTREE_HPP
#define DECISIONTREE_HPP

#include <string>
#include <stdexcept>
#include <iostream>

class DecisionTree {

private:
    struct Nodo {
        std::string decision;
        Nodo* izquierda;
        Nodo* derecha;

        Nodo(const std::string& d)
            : decision(d), izquierda(nullptr), derecha(nullptr) {}
    };

public:
    DecisionTree() : raiz(nullptr) {}

    ~DecisionTree() {
        destruir(raiz);
    }

    void insertar(const std::string& decision) {
        insertar(raiz, decision);
    }

    bool buscar(const std::string& decision) const {
        return buscar(raiz, decision);
    }

    void eliminar(const std::string& decision) {
        eliminarNodo(raiz, decision);
    }

    bool estaVacio() const {
        return raiz == nullptr;
    }

    void recorrerPreorden() const {
        recorrerPreorden(raiz);
    }

private:
    Nodo* raiz;
    void insertar(Nodo*& nodo, const std::string& decision) {
        if (nodo == nullptr) {
            nodo = new Nodo(decision);
        }
        else if (decision < nodo->decision) {
            insertar(nodo->izquierda, decision);
        }
        else if (decision > nodo->decision) {
            insertar(nodo->derecha, decision);
        }
    }

    bool buscar(Nodo* nodo, const std::string& decision) const {
        if (nodo == nullptr) {
            return false;
        }
        if (decision == nodo->decision) {
            return true;
        }
        if (decision < nodo->decision) {
            return buscar(nodo->izquierda, decision);
        }
        else {
            return buscar(nodo->derecha, decision);
        }
    }

    void eliminarNodo(Nodo*& nodo, const std::string& decision) {
        if (nodo == nullptr) {
            return;
        }
        if (decision < nodo->decision) {
            eliminarNodo(nodo->izquierda, decision);
        }
        else if (decision > nodo->decision) {
            eliminarNodo(nodo->derecha, decision);
        }
        else {
            if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
                delete nodo;
                nodo = nullptr;
            } else if (nodo->izquierda == nullptr) {
                Nodo* temp = nodo;
                nodo = nodo->derecha;
                delete temp;
            } else if (nodo->derecha == nullptr) {
                Nodo* temp = nodo;
                nodo = nodo->izquierda;
                delete temp;
            } else {
                Nodo* reemplazo = nodo->derecha;
                while (reemplazo->izquierda != nullptr) {
                    reemplazo = reemplazo->izquierda;
                }
                nodo->decision = reemplazo->decision;
                eliminarNodo(nodo->derecha, reemplazo->decision);
            }
        }
    }

    void recorrerPreorden(Nodo* nodo) const {
        if (nodo == nullptr) return;
        std::cout << nodo->decision << std::endl;
        recorrerPreorden(nodo->izquierda);
        recorrerPreorden(nodo->derecha);
    }

    void destruir(Nodo* nodo) {
        if (nodo == nullptr) return;
        destruir(nodo->izquierda);
        destruir(nodo->derecha);
        delete nodo;
    }
};

#endif // DECISIONTREE_HPP

