#include <iostream>
#include <string>

class SensorNivel {
private:
    std::string id;
    double leitura;
    std::string unidade;

public:
    // Justificativa: Identidade basica para sensores recem-instalados.
    SensorNivel(std::string nome) 
        : id(nome), leitura(0.0), unidade("cm") {}

    // Justificativa: Permite iniciar o sensor ja com valores conhecidos.
    SensorNivel(std::string nome, double valor, std::string tipo) 
        : id(nome), leitura(valor), unidade(tipo) {}

    void exibirResumo() {
        std::cout << "[Sensor] " << id << " | Leitura: " << leitura << " " << unidade << std::endl;
    }
};

class Bomba {
private:
    std::string modelo;
    bool ligada;
    double forca;

public:
    // Justificativa: Cria uma bomba padrao com configuracao minima.
    Bomba(std::string tipo) 
        : modelo(tipo), ligada(false), forca(10.0) {}

    // Justificativa: Permite definir a potencia da bomba na criacao.
    Bomba(std::string tipo, double potencia) 
        : modelo(tipo), ligada(false), forca(potencia) {}

    void exibirResumo() {
        std::string status = ligada ? "Ligada" : "Desligada";
        std::cout << "[Bomba] Modelo: " << modelo << " | Forca: " << forca << " | Status: " << status << std::endl;
    }
};

class ControladorTanque {
private:
    std::string nome;
    double alvo;

public:
    // Justificativa: Registro do controlador no sistema sem meta definida.
    ControladorTanque(std::string identificador) 
        : nome(identificador), alvo(0.0) {}

    // Justificativa: Define o controlador ja com uma meta de nivel.
    ControladorTanque(std::string identificador, double meta) 
        : nome(identificador), alvo(meta) {}

    void exibirResumo() {
        std::cout << "[Controlador] " << nome << " | Meta: " << alvo << "%" << std::endl;
    }
};

int main() {
    SensorNivel s1("Sensor_A");
    SensorNivel s2("Sensor_B", 50.0, "m");

    Bomba b1("Bomba_Pequena");
    Bomba b2("Bomba_Grande", 500.0);

    ControladorTanque c1("Painel_01");
    ControladorTanque c2("Painel_02", 75.0);

    s1.exibirResumo();
    s2.exibirResumo();
    std::cout << "---" << std::endl;
    b1.exibirResumo();
    b2.exibirResumo();
    std::cout << "---" << std::endl;
    c1.exibirResumo();
    c2.exibirResumo();

    return 0;
}