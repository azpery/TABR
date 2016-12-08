#include <iostream>
#include <vector>
#include <string>
#include "tabr.hpp"

using namespace std;

int main(){
	Tabr tabr("anticonstitutionnellement_pas.txt");
	string nom;
	int val,p,q;
	int choix=1;
	while (choix != 0){
		cout << endl << "Que souhaitez vous faire ?" << endl;
		cout << "1 - Afficher TABR en mode simple (parcours suffixe)" << endl;
		cout << "2 - Afficher TABR en mode graphique (parcours suffixe)" << endl;
		cout << "0 - Quitter" << endl;
		cin >> choix;
		switch (choix) {
		case 1:
			tabr.afficher_tabr();
			break;
		case 2:
			tabr.afficher_tabr_graphique();
		case 3:
			cout << "Entrez le nom du fichier d'export: " << endl;
			cin >> nom;
			tabr.export_tabr(nom+".txt");
			cout << "Création du fichier : " << nom << ".txt" << endl;
		default:
			// Code
			break;
		}
	}
	return 0;
}



