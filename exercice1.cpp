
#include <iostream>
#include <string>
using namespace std;

class CompteBancaire {
    private :
    int numero;
    string titulaire;
    double solde;
    public : 
    CompteBancaire(int numero, string titulaire, double solde){
        this ->numero= numero;
        this -> titulaire=titulaire;
        this ->solde=solde;
    }
    void deposer(double montant){
        if (montant>0){
            solde += montant;
        }
    }
    void retirer(double montant){
        if (montant>0 && solde>=montant){
            solde-=montant;

        }
    }
    void afficher (){
        cout << "le numero est" << numero << " et le titulaire est "  << titulaire<< " et le solde est " << solde << endl;
    }

};
int main() {
    CompteBancaire c1(101, "ferdaouss", 500);
    CompteBancaire c2(102, "youssra", 800);
    c1.deposer(100);
    c1.retirer(50);
    c2.retirer(50);
    c1.afficher();
    c2.afficher();
    return 0;
}