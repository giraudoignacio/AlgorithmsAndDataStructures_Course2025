#ifndef HERMANO_ACERO_HPP
#define HERMANO_ACERO_HPP

#include "entidadGenerica.hpp"
#include <iostream>

/**
 * @class HermanoAcero
 * @brief Representa a un miembro de la Hermandad del Acero.
 *
 * Poseen entrenamiento militar avanzado y pueden usar artefactos únicos.
 * Requieren muchos recursos y son estrictos con su permanencia en un refugio.
 */
class HermanoAcero : public EntidadGenerica
{
private:
    int m_entrenamiento; ///< Nivel de entrenamiento (impacta en defensa del refugio)
    double m_suministros;   ///< Recursos necesarios para mantenerlo
    bool m_enRefugio;    ///< Si actualmente vive en un refugio
    int m_consumoMinimo; ///< Cuántos recursos necesita por turno

public:
    /**
     * @brief Constructor
     * @param nombre Nombre del miembro
     * @param entrenamiento Nivel de habilidad (100 por defecto)
     */
    HermanoAcero(const std::string& nombre, int entrenamiento = 100)
        : EntidadGenerica(nombre)
        , m_entrenamiento(entrenamiento)
        , m_suministros(0.20f) // 20% de los suministros del refugio
        , m_enRefugio(false)
        , m_consumoMinimo(20) // el doble de lo estándar
    {
    }

    /**
     * @brief Muestra información del hermano del acero
     */
    void showInfo() const override
    {
        std::cout << "⚙️ Hermano del Acero: " << m_name << "\n"
                  << " - Nivel de entrenamiento: " << m_entrenamiento << "\n"
                  << " - Suministros actuales: " << m_suministros << "\n"
                  << " - En refugio: " << (m_enRefugio ? "Sí" : "No") << "\n";
    }

    /**
     * @brief Intenta ingresar al refugio
     * @param recursosDisponibles Recursos disponibles del refugio
     * @return Recursos consumidos, o 0 si no fue aceptado
     */
    int solicitarIngreso(int recursosDisponibles)
    {
        if (recursosDisponibles >= m_consumoMinimo)
        {
            m_enRefugio = true;
            std::cout << "💬" << m_name << " >>> Por la tecnología, serviré a este refugio." << std::endl;
            return m_consumoMinimo;
        }
        else
        {
            std::cout << "💬" << m_name << " >>> Sus recursos no están a la altura de la Hermandad." << std::endl;
            return 0;
        }
    }

    /**
     * @brief Consume recursos cada ciclo, si no hay suficientes abandona el refugio
     */
    void consumir()
    {
        if (m_suministros >= m_consumoMinimo)
        {
            m_suministros -= m_consumoMinimo;
            std::cout << "💬" << m_name << " >>> Reabastecido. Listo para defender." << std::endl;
        }
        else
        {
            m_enRefugio = false;
            std::cout << "💬" << m_name << " >>> Sin suministros. Este refugio no merece protección." << std::endl;
        }
    }

    /**
     * @brief Saber si está aún en el refugio
     */
    bool estaEnRefugio() const
    {
        return m_enRefugio;
    }
};

#endif // HERMANO_ACERO_HPP
