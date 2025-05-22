//
// Created by ignac on 4/5/2025.
//

#ifndef EVENTO_HPP
#define EVENTO_HPP

#include <string>
#include <iostream>

class Evento {
private:
    std::string descripcion;

public:
    Evento() = default; // Constructor por defecto
    explicit Evento(const std::string& desc) : descripcion(desc) {}

    std::string getDescripcion() const {
        return descripcion;
    }

    bool operator == (const Evento& otro) const {
        return descripcion == otro.descripcion;
    }

    friend std::ostream& operator<<(std::ostream& os, const Evento& evento) {
        os << evento.descripcion;
        return os;
    }
};

#endif // EVENTO_HPP
