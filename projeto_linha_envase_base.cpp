#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AtuadorLinha {
protected:
    string nome;
    double referenciaPercentual;

public:
    AtuadorLinha(string nome) : nome(nome), referenciaPercentual(0) {}

    virtual void aplicarReferenciaPercentual(double percentual) = 0;
    virtual void exibirResumo() const = 0;

    virtual ~AtuadorLinha() {}
};

class MotorEsteira : public AtuadorLinha {
private:
    double velocidadeRPM;

public:
    MotorEsteira(string nome) : AtuadorLinha(nome), velocidadeRPM(0) {}

    void aplicarReferenciaPercentual(double percentual) override {
        referenciaPercentual = percentual;
        velocidadeRPM = percentual * 30;
    }

    void exibirResumo() const override {
        cout << "MotorEsteira [" << nome << "] - "
             << referenciaPercentual << "% -> "
             << velocidadeRPM << " RPM" << endl;
    }
};

class ValvulaDosagem : public AtuadorLinha {
private:
    double vazao;

public:
    ValvulaDosagem(string nome) : AtuadorLinha(nome), vazao(0) {}

    void aplicarReferenciaPercentual(double percentual) override {
        referenciaPercentual = percentual;
        vazao = percentual * 0.5;
    }

    void exibirResumo() const override {
        cout << "ValvulaDosagem [" << nome << "] - "
             << referenciaPercentual << "% -> "
             << vazao << " L/min" << endl;
    }
};

int main() {
    vector<AtuadorLinha*> atuadores;

    atuadores.push_back(new MotorEsteira("Esteira 1"));
    atuadores.push_back(new ValvulaDosagem("Valvula A"));

    for (auto a : atuadores) {
        a->aplicarReferenciaPercentual(50);
    }

    cout << "\nResumo dos equipamentos:\n";
    for (auto a : atuadores) {
        a->exibirResumo();
    }

    for (auto a : atuadores) {
        delete a;
    }

    return 0;
}