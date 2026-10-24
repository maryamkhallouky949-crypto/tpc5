
#include <iostream>
#include <string>
using namespace std;

class Produit {
private:
    string nom;
    double prixHT;

    // Taux de TVA partage entre tous les produits
    static float tauxTVA;

public:
    // Constructeur
    Produit(string n, double prix)
        : nom(n), prixHT(prix) {
    }

    // Calculer le prix toutes taxes comprises
    double getPrixTTC() const {
        return prixHT * (1 + tauxTVA / 100.0);
    }

    // Modifier le taux de TVA pour tous les produits
    static void modifierTVA(float nouveauTaux) {
        if (nouveauTaux >= 0) {
            tauxTVA = nouveauTaux;
        }
    }

    // Afficher le produit et son prix TTC
    void afficher() const {
        cout << "Produit : " << nom << endl;
        cout << "Prix HT : " << prixHT << " DH" << endl;
        cout << "Prix TTC : " << getPrixTTC() << " DH" << endl;
        cout << "" << endl;
    }
};

// Initialisation du taux a 20 %
float Produit::tauxTVA = 20.0f;

int main() {
    Produit p1("Ordinateur", 5000);
    Produit p2("Clavier", 200);
    Produit p3("Souris", 100);

    cout << "TVA initiale : 20 % " << endl;

    p1.afficher();
    p2.afficher();
    p3.afficher();

    // Modifier le taux commun
    Produit::modifierTVA(10.0f);

    cout << " TVA modifiee : 10 % " << endl;

    p1.afficher();
    p2.afficher();
    p3.afficher();

    return 0;
}
