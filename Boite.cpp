
#include <iostream>
using namespace std;

class Boite {
private:
    double longueur;
    double largeur;
    double hauteur;

    // Compteur partage entre toutes les boites
    static int nbBoites;

public:
    // Constructeur
    Boite(double l, double lar, double h)
        : longueur(l), largeur(lar), hauteur(h) {
        nbBoites++;
        cout << "Creation d'une boite" << endl;
    }

    // Destructeur
    ~Boite() {
        nbBoites--;
        cout << "Destruction d'une boite" << endl;
    }

    // Methode statique pour obtenir le nombre de boites
    static int getNombreBoites() {
        return nbBoites;
    }

    // Afficher les dimensions
    void afficher() const {
        cout << "Longueur : " << longueur << endl;
        cout << "Largeur : " << largeur << endl;
        cout << "Hauteur : " << hauteur << endl;
    }
};

// Initialisation du compteur
int Boite::nbBoites = 0;

int main() {
    cout << "Nombre initial : "
         << Boite::getNombreBoites() << endl;

    Boite b1(10, 5, 3);
    cout << "Nombre de boites : "
         << Boite::getNombreBoites() << endl;

    Boite b2(8, 4, 2);
    cout << "Nombre de boites : "
         << Boite::getNombreBoites() << endl;

    {
        Boite b3(6, 3, 2);
        cout << "Nombre de boites : "
             << Boite::getNombreBoites() << endl;
    } // b3 est detruite ici

    cout << "Apres destruction de b3 : "
         << Boite::getNombreBoites() << endl;

    return 0;
}
