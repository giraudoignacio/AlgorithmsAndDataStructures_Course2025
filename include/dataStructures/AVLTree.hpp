//
// Created by ignac on 5/15/2025.
//

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>
#include <queue>
#include <algorithm>

class AVLTree {
private:
    struct Nodo {
        int outpostId;
        int priority;
        int height;
        Nodo* left;
        Nodo* right;
        Nodo(int id, int p) : outpostId(id), priority(p), height(0), left(nullptr), right(nullptr) {}
    };

    Nodo* raiz = nullptr;

public:
    AVLTree() {}

    void insert(int outpostId, int priority) {
        raiz = insertRec(raiz, outpostId, priority);
    }

    void remove(int outpostId) {
        raiz = removeRec(raiz, outpostId);
    }

    bool contains(int outpostId) {
        if (raiz == nullptr) {
            return false;
        }
        std::queue<Nodo*> cola;
        cola.push(raiz);

        while (!cola.empty()) {
            Nodo* actual = cola.front();
            cola.pop();

            if (actual->outpostId == outpostId)
                return true;
            if (actual->left)
                cola.push(actual->left);
            if (actual->right)
                cola.push(actual->right);
        }
        return false;
    }

    int findMin() {
        Nodo* min = findMinNode(raiz);
        if (min)
            return min->outpostId;
        else
            return -1;
    }

    int findMax() {
        Nodo* actual = raiz;
        if (actual == nullptr) {
            return -1;
        }
        while (actual->right) {
            actual = actual->right;
        }
        return actual->outpostId;
    }

    void printInOrder() {
        printInOrderRec(raiz);
        std::cout << "\n";
    }

    void printStats() {
        std::cout << "Cantidad de nodos: " << countNodes(raiz) << "\n";
        std::cout << "Altura del árbol: " << getHeight(raiz) << "\n";
    }

private:
    int getHeight(Nodo* n) {
        if (n != nullptr) {
            return n->height;
        } else {
            return -1;
        }
    }

    int getBalance(Nodo* n) {
        if (n != nullptr) {
            return (getHeight(n->left) - getHeight(n->right));
        }
        else {
            return 0;
        }
    }

    void updateHeight(Nodo* n) {
        n->height = 1 + std::max(getHeight(n->left), getHeight(n->right));
    }

    Nodo* rotateRight(Nodo* y) {
        Nodo* x = y->left;
        Nodo* aux = x->right;

        x->right = y;
        y->left = aux;

        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Nodo* rotateLeft(Nodo* x) {
        Nodo* y = x->right;
        Nodo* aux = y->left;

        y->left = x;
        x->right = aux;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Nodo* insertRec(Nodo* nodo, int id, int priority) {
        if (nodo == nullptr) {
            return new Nodo(id, priority);
        }
        if (priority < nodo->priority) {
            nodo->left = insertRec(nodo->left, id, priority);
        }
        else if (priority > nodo->priority) {
            nodo->right = insertRec(nodo->right, id, priority);
        }
        updateHeight(nodo);
        int balance = getBalance(nodo);

        if (balance > 1 && priority < nodo->left->priority) {
            return rotateRight(nodo);
        }
        if (balance < -1 && priority > nodo->right->priority) {
            return rotateLeft(nodo);
        }
        if (balance > 1 && priority > nodo->left->priority) {
            nodo->left = rotateLeft(nodo->left);
            return rotateRight(nodo);
        }
        if (balance < -1 && priority < nodo->right->priority) {
            nodo->right = rotateRight(nodo->right);
            return rotateLeft(nodo);
        }
        return nodo;
    }

    Nodo* findMinNode(Nodo* nodo) {
        if (nodo == nullptr) {
            return nullptr;
        }
        while (nodo->left) {
            nodo = nodo->left;
        }
        return nodo;
    }

    Nodo* removeRec(Nodo* nodo, int outpostId) {
        if (nodo == nullptr) {
            return nullptr;
        }
        if (outpostId < nodo->outpostId) {
            nodo->left = removeRec(nodo->left, outpostId);
        }
        else if (outpostId > nodo->outpostId) {
            nodo->right = removeRec(nodo->right, outpostId);
        }
        else {
            if (nodo->left == nullptr || nodo->right == nullptr) {
                Nodo* temp;
                if (nodo->left != nullptr)
                    temp = nodo->left;
                else
                    temp = nodo->right;
                delete nodo;
                return temp;
            }
            else {
                Nodo* temp = findMinNode(nodo->right);
                nodo->outpostId = temp->outpostId;
                nodo->priority = temp->priority;
                nodo->right = removeRec(nodo->right, temp->outpostId);
            }
        }

        updateHeight(nodo);

        int balance = getBalance(nodo);

        if (balance > 1 && getBalance(nodo->left) >= 0) {
            return rotateRight(nodo);
        }

        if (balance > 1 && getBalance(nodo->left) < 0) {
            nodo->left = rotateLeft(nodo->left);
            return rotateRight(nodo);
        }

        if (balance < -1 && getBalance(nodo->right) <= 0) {
            return rotateLeft(nodo);
        }

        if (balance < -1 && getBalance(nodo->right) > 0) {
            nodo->right = rotateRight(nodo->right);
            return rotateLeft(nodo);
        }
        return nodo;
    }

    void printInOrderRec(Nodo* nodo) {
        if (!nodo) return;
        printInOrderRec(nodo->left);
        std::cout << nodo->outpostId << " ";
        printInOrderRec(nodo->right);
    }

    int countNodes(Nodo* nodo) {
        if (!nodo) return 0;
        return 1 + countNodes(nodo->left) + countNodes(nodo->right);
    }
};

#endif // AVLTREE_HPP
