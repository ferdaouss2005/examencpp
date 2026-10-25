#include <iostream>
#include <string>
using namespace std;

class Vehicule {
protected:
    string immatriculation;
    string marque;
    double vitesseMax;

public:
    Vehicule(string immatriculation, string marque, double vitesseMax) {
        this->immatriculation = immatriculation;
        this->marque = marque;
        this->vitesseMax = vitesseMax;
    }

    virtual void afficherDetails() = 0;

    virtual ~Vehicule() {}
};

class Voiture : public Vehicule {
private:
    int nombrePortes;
    string typeCarburant;

public:
    Voiture(string immatriculation, string marque, double vitesseMax,
            int nombrePortes, string typeCarburant)
        : Vehicule(immatriculation, marque, vitesseMax) {
        this->nombrePortes = nombrePortes;
        this->typeCarburant = typeCarburant;
    }

    void afficherDetails() override {
        cout << "Immatriculation : " << immatriculation << endl;
        cout << "Marque : " << marque << endl;
        cout << "Vitesse maximale : " << vitesseMax << endl;
        cout << "Nombre de portes : " << nombrePortes << endl;
        cout << "Type de carburant : " << typeCarburant << endl;
    }
};

class Camion : public Vehicule {
private:
    double capaciteCharge;
    int nombreEssieux;

public:
    Camion(string immatriculation, string marque, double vitesseMax,
           double capaciteCharge, int nombreEssieux)
        : Vehicule(immatriculation, marque, vitesseMax) {
        this->capaciteCharge = capaciteCharge;
        this->nombreEssieux = nombreEssieux;
    }

    void afficherDetails() override {
        cout << "Immatriculation : " << immatriculation << endl;
        cout << "Marque : " << marque << endl;
        cout << "Vitesse maximale : " << vitesseMax << endl;
        cout << "Capacite de charge : " << capaciteCharge << endl;
        cout << "Nombre d'essieux : " << nombreEssieux << endl;
    }
};
int main() {
    Vehicule* tab[2];

    tab[0] = new Voiture("123-A-45", "Dacia", 180, 5, "Essence");
    tab[1] = new Camion("456-B-78", "Volvo", 120, 15.5, 4);

    for (int i = 0; i < 2; i++) {
        tab[i]->afficherDetails();
        cout << "------------------" << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete tab[i];
    }

    return 0;
}