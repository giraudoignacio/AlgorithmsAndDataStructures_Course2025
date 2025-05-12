#include "engine.hpp"
#include <iostream>
#include <fstream>

void Engine::start()
{
    m_randomGenerator = RandomEventGenerator();

    loadConfig();

    loadGame();

    initResources();
    initEntities();
    interactiveConsole();
}

void Engine::initResources()
{
    std::cout << GREEN << "Inicializando recursos..." << RESET << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Engine::initEntities()
{
    std::cout << GREEN << "Inicializando entidades..." << RESET << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Engine::onNewEvent(const Evento& evento) {
    m_eventosPendientes.enqueue(evento);
}

void Engine::processEvents() {
    m_eventosPendientes.processEvents();
}

void Engine::checkEvents() {
    m_eventosPendientes.checkEvents();
}

void Engine::registerDecision(const std::string& accion) {
    m_historialDecisiones.push(accion);
}

void Engine::undoDecision() {
    if (!m_historialDecisiones.isEmpty()) {
        m_historialDecisiones.pop();
    }
}

void Engine::showBanner()
{
    std::cout << GREEN
              << "         :---.  .---..---.   :--:..---..---..:------:.  . :-------.:-----:    .-+=.              "
              << RESET << std::endl;
    std::cout << GREEN
              << "          :@@@-  =@@%.*@@@+   *@@#.:%@@-.@@@-.%@@@@@@%. .  =@@@@@@@:*@@@@@+  =@@@@@*             "
              << RESET << std::endl;
    std::cout << GREEN
              << "           +@@%..@@@=:%@@@@.  *@@#.:%@@-.@@@-.::#@@%::.    .:=@@@::.*@@%::..*@@@+::: .           "
              << RESET << std::endl;
    std::cout << GREEN
              << "           :@@@==@@%.=@@@@@=  *@@#.:%@@-.@@@-   #@@#........ -@@@.  *@@%::.-@@@-               . "
              << RESET << std::endl;
    std::cout << GREEN
              << "           .*@@%%@@=.%@@+@@%. *@@#.:%@@-.@@@-   #@@#.-@@@@@* -@@@.  *@@@@@:=@@@.                 "
              << RESET << std::endl;
    std::cout << GREEN
              << "            .@@@@@%.-@@%.@@@- *@@#.:%@@-.@@@- . #@@#.:+++++- -@@@.  *@@%==.-@@@:                 "
              << RESET << std::endl;
    std::cout << GREEN
              << "             =@@@@-.#@@@@@@@* *@@%.:@@@-.@@@-...#@@#.        -@@@.  *@@%....#@@@-...             "
              << RESET << std::endl;
    std::cout << GREEN
              << "             .%@@%.:@@@:.-@@@:-@@@@@@@@..@@@@@@-#@@#.  .     -@@@.  *@@@@@* .*@@@@@*             "
              << RESET << std::endl;
    std::cout << GREEN
              << "             .=##=.=##+  .*##+..+%@@%=. .######:+##*.   .    :###.  =#####=  ..-#@%=        .    "
              << RESET << std::endl;
    std::cout << GREEN
              << "  .                                                             .      .                          "
              << RESET << std::endl;
    std::cout << GREEN
              << "           .           ..               ..-+%@@@@@@%+-..                       .                  "
              << RESET << std::endl;
    std::cout << GREEN
              << "  .                          .        .=@@@@@@@@@@@@@@@@=.     .           . .      .             "
              << RESET << std::endl;
    std::cout << GREEN
              << "           . .                    ...*@@@@%-:.   ..:-%@@@@*.                                      "
              << RESET << std::endl;
    std::cout << GREEN
              << "                .-*@@@@@@@@@@@@@@@@@@@@@=.       .    .=@@@@@@@@@@@@@@@@@@@@@*-..             .   "
              << RESET << std::endl;
    std::cout << GREEN
              << "                .-%@@@@@@@@@@@@@@@@@@@#.    .-*##*-.  . .#@@@@@@@@@@@@@@@@@@@%-.         ..       "
              << RESET << std::endl;
    std::cout << GREEN
              << "                   ..............:@@@+.   :%@@@@@@@@%:   .+@@@:..............                     "
              << RESET << std::endl;
    std::cout << GREEN
              << "        .          .          . .#@@%. ..=@@@@@@@@@@@@=.  .%@@*.      .              .     .      "
              << RESET << std::endl;
    std::cout << GREEN
              << "   .:+%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+   :@@@@@@@@@@@@@%: . *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+:..   ."
              << RESET << std::endl;
    std::cout << GREEN
              << "  .*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+   :@@@@@@@@@@@@@@: . +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*.    "
              << RESET << std::endl;
    std::cout << GREEN
              << "    ..:-+++++++++++++++++++++++++@@@*.  .%@@@@@@@@@@@@%.  .#@@@+++++++++++++++++++++++++-:..      "
              << RESET << std::endl;
    std::cout << GREEN
              << " .                              .+@@@:  ..%@@@@@@@@@@%..  :@@@+                                   "
              << RESET << std::endl;
    std::cout << GREEN
              << "      .          .:=*%@@@@@@@@@@@@@@@%.   .=%@@@@@@%-.   .@@@@@@@@@@@@@@@@%*-..                   "
              << RESET << std::endl;
    std::cout << GREEN
              << "       .        :%@@@@@@@@@@@@@@@@@@@@@-   .            -@@@@@@@@@@@@@@@@@@@@@%:                  "
              << RESET << std::endl;
    std::cout << GREEN
              << "                  .:=*###############@@@@=.          .=@@@@###############*-:.           .        "
              << RESET << std::endl;
    std::cout << GREEN
              << "      .            ..                :#@@@@@#+=--=+#@@@@@#.                  .                    "
              << RESET << std::endl;
    std::cout << GREEN
              << "            .                .         .=%@@@@@@@@@@@@%=.                                         "
              << RESET << std::endl;
    std::cout << GREEN
              << "                  . .               ..    ...-=++=:...                   .                        "
              << RESET << std::endl;
}

void Engine::showMenu()
{
    std::cout << GREEN << "========== CONSOLA DE OPERACIONES VAULT-TEC v" << CONSOLE_VERSION << " ==========" << RESET
              << std::endl;
    std::cout << GREEN << "<> [i] status   " << RESET << " - Mostrar estado del refugio" << std::endl;
    std::cout << GREEN << "<> [e] events   " << RESET << " - Ver historial de eventos" << std::endl;
    std::cout << GREEN << "<> [c] check    " << RESET << " - Verificar evento activo" << std::endl;
    std::cout << GREEN << "<> [x] explore  " << RESET << " - Realizar una exploración" << std::endl;
    std::cout << GREEN << "<> [f] fight    " << RESET << " - Enfrentar a un enemigo" << std::endl;
    std::cout << GREEN << "<> [s] save     " << RESET << " - Guardar el progreso" << std::endl;
    std::cout << GREEN << "<> [q] exit     " << RESET << " - Salir del sistema" << std::endl;
    std::cout << GREEN << "====================================" << RESET << std::endl;
}

void Engine::clearScreen()
{
    std::system(CLEAR_SCREEN);
}

void Engine::interactiveConsole()
{
    bool keepRunning = true;
    while (keepRunning)
    {
        showBanner();
        showMenu();
        std::string input;
        std::cout << GREEN << "> " << RESET;
        std::cin >> input;

        if (m_validOperations.find(input[0]) != m_validOperations.end())
        {
            switch (m_validOperations.at(input[0]))
            {
                case Operation::SHOW_STATUS:
                    std::cout << "Mostrando detalles..." << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    break;
                case Operation::EXIT:
                    std::cout << "Saliendo..." << std::endl;
                    keepRunning = false;
                    break;
                default: std::cout << "Operación desconocida" << std::endl; break;
            }
        }
        else
        {
            std::cout << "Operación desconocida" << std::endl;
        }
        clearScreen();
    }
}

void Engine::engineConfig(const EngineData::GameConfig& config)
{
    m_gameConfig = config;
}

const EngineData::GameConfig& Engine::engineConfig() const
{
    return m_gameConfig;
}

void Engine::playerShelter(const Refugio& refugio)
{
    m_shelter = std::make_unique<Refugio>(refugio);
}

const Refugio& Engine::playerShelter() const
{
    return *m_shelter;
}

void Engine::playerInfo(const EngineData::PlayerInfo& player)
{
    m_player = player;
}

const EngineData::PlayerInfo& Engine::playerInfo() const
{
    return m_player;
}

void Engine::loadGame()
{
    // Verifica sino existe un archivo de guardado
    if (std::filesystem::exists(SAVE_FILE))
    {
        std::cout << GREEN << "\n\n[INFO] Restableciendo información desde servidores centrales..." << RESET
                  << std::endl;
        if (!GameSerializer::load(*this, SAVE_FILE))
        {
            std::cout << RED << "[ERROR] Corte de luz detectado. EPEC no responde." << RESET << std::endl;
            std::cout << RED << "Por favor, reinicie el sistema y verifique que estén los cables conectados." << RESET
                      << std::endl;
            exit(1);
        }
    }
    else
    {
        std::cout << "\n\nNo se encontró información de guardado. Iniciando sistema después de masivo reinicio..."
                  << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "\n\nAlgunos datos no están disponibles. Por favor, ingreselos" << std::endl;
        std::cout << "Si no recuerda alguno, tome un descanso y vuelva a intentarlo." << std::endl;
        std::cout << "Si no recuerda nada, por favor, reinicie el sistema." << std::endl;
        std::cout << "Si no recuerda como reiniciar el sistema, por favor, largo de aqui." << std::endl;

        std::cout << "\n\nPresione ENTER para continuar...";

        std::cin.get();

        std::cout << "Ingrese su nombre: ";
        std::string playerName;
        std::getline(std::cin, playerName);
        std::cout << "Ingrese el identificador unico provisto por VAULT TEC del refugio: ";
        std::string vaultId;
        std::getline(std::cin, vaultId);

        m_player.level = "1"; // Nivel inicial
        m_player.name = playerName;

        // Crea el refugio
        m_shelter = std::make_unique<Refugio>(vaultId, playerName);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        if (m_randomGenerator.chance(0.5f))
        {
            std::cout << GREEN << "\n\n ===== SISTEMA VAULT CARGADO ====" << RESET << std::endl;
        }
        else
        {
            std::cout << RED << "\n\n ===== [ERROR] SISTEMA VAULT DAÑADO ====" << RESET << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << RED << "\n\n ===== [ERROR] SISTEMA VAULT DAÑADO ====" << RESET << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
            std::cout << RED << "\n\n ===== [ERROR] SISTEMA VAULT DAÑADO ====" << RESET << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << YELLOW << "\n\n ===== [INFO] PATEANDO SERVIDOR CENTRAL ====" << RESET << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            std::cout << GREEN << "\n\n ===== SISTEMA VAULT CARGADO ====" << RESET << std::endl;
        }

        // Guardar nueva información
        GameSerializer::save(*this, SAVE_FILE);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Engine::loadConfig()
{
    std::cout << GREEN << "\n\n[INFO] Cargando configuracion..." << RESET << std::endl;
    if (!std::filesystem::exists(CONFIG_FILE))
    {
        std::ofstream fileOut(CONFIG_FILE);
        if (!fileOut)
        {
            std::cerr << RED << "[ERROR] No se pudo crear el archivo de configuración. Hubo... un... corte de luz?"
                      << RESET << std::endl;
            return;
        }
        fileOut << R"(# === CONFIGURACIÓN DEL SISTEMA REFUGIO 33 ===
# Este archivo define los parámetros de eventos, exploración y combates
# ¡Modifique bajo su propia responsabilidad!

[exploration]
successRate=0.45
lootChance=0.30
dangerChance=0.25

[fight]
criticalHitChance=0.15
criticalHitMultiplier=2.0
enemyAttackMultiplier=1.5
enemyDefenseMultiplier=1.2
enemyHealthMultiplier=1.3
enemyLootMultiplier=1.5
enemyExperienceMultiplier=1.5
luckyFactor=1.2

[resources]
successRate=0.50
lootChance=0.40
badLuckChance=0.20
durationFactor=1.5

[shelter]
defenseFactor=1.5
attackFactor=1.2
visitantsRate=0.10

# === FIN DEL ARCHIVO ===
)";
        fileOut.close();
        std::cout << GREEN << "[SUCCESS] Se generó el archivo de configuración por defecto.\n" << RESET;
    }

    std::ifstream inFile(CONFIG_FILE);
    if (!inFile)
    {
        std::cerr << RED << "[ERROR] No se pudo abrir el archivo de configuración. Que rompió?" << RESET << std::endl;
        return;
    }

    std::string line, section;
    while (std::getline(inFile, line))
    {
        if (line.empty() || line[0] == '#' || line[0] == ';')
            continue;
        if (line.front() == '[')
        {
            section = line;
            continue;
        }

        size_t eq = line.find('=');
        if (eq == std::string::npos)
            continue;

        std::string key = line.substr(0, eq);
        std::string val = line.substr(eq + 1);

        double value = std::stod(val);

        if (section == "[exploration]")
        {
            if (key == "successRate")
                m_gameConfig.exploration.successRate = value;
            else if (key == "lootChance")
                m_gameConfig.exploration.lootChance = value;
            else if (key == "dangerChance")
                m_gameConfig.exploration.dangerChance = value;
        }
        else if (section == "[fight]")
        {
            if (key == "criticalHitChance")
                m_gameConfig.fight.criticalHitChance = value;
            else if (key == "criticalHitMultiplier")
                m_gameConfig.fight.criticalHitMultiplier = value;
            else if (key == "enemyAttackMultiplier")
                m_gameConfig.fight.enemyAttackMultiplier = value;
            else if (key == "enemyDefenseMultiplier")
                m_gameConfig.fight.enemyDefenseMultiplier = value;
            else if (key == "enemyHealthMultiplier")
                m_gameConfig.fight.enemyHealthMultiplier = value;
            else if (key == "enemyLootMultiplier")
                m_gameConfig.fight.enemyLootMultiplier = value;
            else if (key == "enemyExperienceMultiplier")
                m_gameConfig.fight.enemyExperienceMultiplier = value;
            else if (key == "luckyFactor")
                m_gameConfig.fight.luckyFactor = value;
        }
        else if (section == "[resources]")
        {
            if (key == "successRate")
                m_gameConfig.resources.successRate = value;
            else if (key == "lootChance")
                m_gameConfig.resources.lootChance = value;
            else if (key == "badLuckChance")
                m_gameConfig.resources.badLuckChance = value;
            else if (key == "durationFactor")
                m_gameConfig.resources.durationFactor = value;
        }
        else if (section == "[shelter]")
        {
            if (key == "defenseFactor")
                m_gameConfig.shelter.defenseFactor = value;
            else if (key == "attackFactor")
                m_gameConfig.shelter.attackFactor = value;
            else if (key == "visitantsRate")
                m_gameConfig.shelter.visitantsRate = value;
        }
    }

    std::cout << GREEN << "[SUCCESS] Configuración cargada correctamente desde el servidor de VAULT\n" << RESET;
}
