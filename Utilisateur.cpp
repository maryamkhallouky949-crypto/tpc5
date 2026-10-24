
#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
private:
    string nom;
    string role;

    // Nombre d'utilisateurs actuellement connectes
    static int nbUtilisateursConnectes;

public:
    // Constructeur : connexion
    Utilisateur(string n, string r)
        : nom(n), role(r) {
        nbUtilisateursConnectes++;
        cout << nom << " est connecte." << endl;
    }

    
    }

    // Methode statique pour obtenir le nombre de connexions
    static int getNbUtilisateursConnectes() {
        return nbUtilisateursConnectes;
    }

    // Afficher les informations de l'utilisateur
    void afficher() const {
        cout << "Nom : " << nom << endl;
        cout << "Role : " << role << endl;
    }
};

// Initialisation du compteur
int Utilisateur::nbUtilisateursConnectes = 0;

int main() {
    cout << "Utilisateurs connectes : "
         << Utilisateur::getNbUtilisateursConnectes()
         << endl;

    Utilisateur u1("Amine", "admin");

    cout << "Nombre connecte : "
         << Utilisateur::getNbUtilisateursConnectes()
         << endl;

    {
        Utilisateur u2("Sara", "visiteur");

        cout << "Nombre connecte : "
             << Utilisateur::getNbUtilisateursConnectes()
             << endl;

        Utilisateur u3("Youssef", "visiteur");

        cout << "Nombre connecte : "
             << Utilisateur::getNbUtilisateursConnectes()
             << endl;

        u2.afficher();
    } // u2 et u3 sont detruits ici

    cout << "Apres deconnexion de Sara et Youssef : "
         << Utilisateur::getNbUtilisateursConnectes()
         << endl;

    return 0;
}
