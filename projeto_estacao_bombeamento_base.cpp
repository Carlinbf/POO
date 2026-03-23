#include <iostream>
#include <string>
using namespace std;

class AtivoCampo {
private:
    string tag;
    bool bloqueado;

protected:
    bool estaBloqueado() const {
        return bloqueado;
    }

public:
    AtivoCampo(string t, bool b) : tag(t), bloqueado(b) {}

    string getTag() const {
        return tag;
    }

    void setBloqueio(bool b) {
        bloqueado = b;
    }
};

class SensorNivel : public AtivoCampo {
private:
    double nivel;

public:
    SensorNivel(string tag, bool bloqueado, double nivelInicial)
        : AtivoCampo(tag, bloqueado), nivel(nivelInicial) {}

    bool setNivel(double novoNivel) {
        if (estaBloqueado()) {
            cout << "Sensor bloqueado!\n";
            return false;
        }
        if (novoNivel < 0 || novoNivel > 100) {
            cout << "Nivel invalido!\n";
            return false;
        }
        nivel = novoNivel;
        return true;
    }

    double getNivel() const {
        return nivel;
    }

    friend void inspecionarSensor(const SensorNivel& s);
};

void inspecionarSensor(const SensorNivel& s) {
    cout << "[INSPECAO TECNICA]\n";
    cout << "Tag: " << s.getTag() << "\n";
    cout << "Nivel interno: " << s.nivel << "\n";
}

class BombaDosadora : public AtivoCampo {
private:
    double vazao;

public:
    BombaDosadora(string tag, bool bloqueado, double vazaoInicial)
        : AtivoCampo(tag, bloqueado), vazao(vazaoInicial) {}

    bool setVazao(double novaVazao) {
        if (estaBloqueado()) {
            cout << "Bomba bloqueada!\n";
            return false;
        }
        if (novaVazao < 0 || novaVazao > 500) {
            cout << "Vazao invalida!\n";
            return false;
        }
        vazao = novaVazao;
        return true;
    }

    double getVazao() const {
        return vazao;
    }
};

int main() {
    SensorNivel sensor("SN-01", false, 50);
    BombaDosadora bomba("BD-01", false, 120);

    sensor.setNivel(80);
    bomba.setVazao(200);

    cout << "\n=== RESUMO DOS ATIVOS ===\n";
    cout << "Sensor: " << sensor.getTag() << ", Nivel: " << sensor.getNivel() << "\n";
    cout << "Bomba: " << bomba.getTag() << ", Vazao: " << bomba.getVazao() << "\n";

    cout << "\n";
    inspecionarSensor(sensor);

    return 0;
}
