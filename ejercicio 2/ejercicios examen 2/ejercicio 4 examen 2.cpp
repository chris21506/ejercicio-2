//Julio Christopher Beltran Solano
//youtube video https://youtu.be/wE0_F4LpGVc?si=wXtj7ZOdG326P3Gc
#include <iostream>
#include <cmath>     // Para funciones trigonométricas como tan()
#include <string>

using namespace std;

// Definimos M_PI si no está definido
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Clase base abstracta Figura
class Figura {
protected:
    string nombre; // Nombre de la figura

public:
    Figura(string name) : nombre(name) {}

    virtual ~Figura() {}

    // Funciones virtuales puras: obligan a redefinirlas en clases hijas
    virtual float CalcularArea() const = 0;
    virtual float CalcularPerimetro() const = 0;

    const string& ObtenerNombreDeFigura() const {
        return nombre;
    }
};

// Clase derivada: Círculo
class Circulo : public Figura {
private:
    float radio;

public:
    Circulo(float r) : Figura("Círculo"), radio(r) {}

    ~Circulo() override {}

    float CalcularArea() const override {
        return M_PI * radio * radio; // Área del círculo: πr^2
    }

    float CalcularPerimetro() const override {
        return 2 * M_PI * radio; // Perímetro del círculo: 2πr
    }
};

// Clase derivada: Cuadrado
class Cuadrado : public Figura {
protected:
    float lado;

public:
    Cuadrado(float l) : Figura("Cuadrado"), lado(l) {}

    ~Cuadrado() override {}

    float CalcularArea() const override {
        return lado * lado;
    }

    float CalcularPerimetro() const override {
        return 4 * lado;
    }

    float ObtenerLado() const {
        return lado;
    }
};

// Clase derivada: Figura regular con N lados
class FiguraNLados : public Figura {
private:
    int cantidadLados;
    float longitudLado;

public:
    FiguraNLados(int n, float l) : Figura("Figura de N Lados"), cantidadLados(n), longitudLado(l) {}

    ~FiguraNLados() override {}

    float CalcularArea() const override {
        float angulo = M_PI / cantidadLados;
        float apotema = longitudLado / (2 * tan(angulo));
        return (CalcularPerimetro() * apotema) / 2;
    }

    float CalcularPerimetro() const override {
        return cantidadLados * longitudLado;
    }
};

// Clase derivada de Cuadrado: Cubo
class Cubo : public Cuadrado {
public:
    Cubo(float l) : Cuadrado(l) {
        nombre = "Cubo";
    }

    ~Cubo() override {}

    float Volumen() const {
        return lado * lado * lado;
    }

    float Surface() const {
        return 6 * lado * lado;
    }

    float CalcularArea() const override {
        return Surface(); // Área superficial del cubo
    }

    float CalcularPerimetro() const override {
        return 12 * lado; // 12 aristas
    }
};

// Clase derivada: Línea con segmentos dinámicos
class Linea : public Figura {
private:
    float* segmentos;
    int cantidadSegmentos;

public:
    Linea(float* segs, int cantidad) : Figura("Línea"), cantidadSegmentos(cantidad) {
        segmentos = new float[cantidadSegmentos];
        for (int i = 0; i < cantidadSegmentos; ++i) {
            segmentos[i] = segs[i];
        }
    }

    ~Linea() override {
        delete[] segmentos;
    }

    float CalcularArea() const override {
        return 0.0f;
    }

    float CalcularPerimetro() const override {
        float total = 0.0f;
        for (int i = 0; i < cantidadSegmentos; ++i) {
            total += segmentos[i];
        }
        return total;
    }
};

// Función principal para probar todas las clases
int main() {
    Circulo c(5.0);
    cout << c.ObtenerNombreDeFigura() << " Área: " << c.CalcularArea() << ", Perímetro: " << c.CalcularPerimetro() << endl;

    Cuadrado q(4.0);
    cout << q.ObtenerNombreDeFigura() << " Área: " << q.CalcularArea() << ", Perímetro: " << q.CalcularPerimetro() << endl;

    Cubo cubo(3.0);
    cout << cubo.ObtenerNombreDeFigura() << " Volumen: " << cubo.Volumen() << ", Superficie: " << cubo.Surface() << endl;

    FiguraNLados hexagono(6, 2.0);
    cout << hexagono.ObtenerNombreDeFigura() << " Área: " << hexagono.CalcularArea() << ", Perímetro: " << hexagono.CalcularPerimetro() << endl;

    float segmentos[] = { 1.5, 2.0, 3.5 };
    Figura* linea = new Linea(segmentos, 3);
    cout << linea->ObtenerNombreDeFigura() << " Área: " << linea->CalcularArea() << ", Perímetro: " << linea->CalcularPerimetro() << endl;

    delete linea;

    return 0;
}
