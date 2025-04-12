#include <fstream>
#include <iostream>
#include <thread>

#include "engine.hpp"
#include "evento.hpp"

auto constexpr HELP_FILE {"assets/help.txt"}; //< Nombre del archivo de ayuda

int main()
{
    std::cout << GREEN << "Cargando:" << RESET;

    for (int i = 0; i <= 100; i += 10)
    {
        std::cout << "[" << i << "%]" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (i < 100)
        {
            std::cout << GREEN << "\b\b\b\b\b" << RESET << std::flush;
        }
    }

    // Preguntar por tutorial
    std::cout << WHITE << "\n\n¿Desea ver el manual del ingeniero de sistemas? (s/n): " << RESET;
    char answer;
    std::cin >> answer;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (answer == 's' || answer == 'S')
    {
        std::ifstream helpFile(HELP_FILE);
        if (helpFile)
        {
            std::string line;
            while (std::getline(helpFile, line))
            {
                std::cout << line << std::endl;
            }
        }
        else
        {
            std::cout << RED << "[ERROR] La humedad ha dañado el archivo de ayuda." << RESET << std::endl;
            std::cout << RED << "Por favor, contacte a su ingeniero de sistemas (Si es que sigue vivo)." << RESET
                      << std::endl;
            std::cout << std::endl << "Presione ENTER para continuar...";
            std::cin.get();
        }
    }

    // Inicializa el motor del juego
    auto engine = std::make_unique<Engine>();

    engine->start();

    std::cout << GREEN << "Revolucionando la seguridad para un futuro incierto :)" << RESET;

    return 0;
}


