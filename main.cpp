#include <iostream>
#include <vector>
#include <string>
#include "tabr.hpp"

using namespace std;


bool is_file_exist(string file){
    std::ifstream infile(file.c_str());
    return infile.good();
}

int main(){
	Tabr tabr("anticonstitutionnellement_pas.txt");
	string nom, c;
	int val,p,q;
	int choix=1;
	// Pour générer un arbre // 
	int max,nbInter,nbNoeud;

	while (choix != 0){
		cout << endl << "Que souhaitez vous faire ?" << endl;
		cout << "1 - Afficher TABR en mode simple (parcours suffixe)" << endl;
		cout << "2 - Charger un TABR depuis un fichier" << endl;
		cout << "3 - Afficher TABR en mode graphique (parcours suffixe)" << endl;
		cout << "4 - Exporter TABR dans un fichier" << endl;
		cout << "5 - Générer TABR" << endl;
		cout << "0 - Quitter" << endl;
		cin >> choix;
		switch (choix) {
		case 1:
			tabr.afficher_tabr();
			break;
		case 2:
			cout << "Entrez le nom du fichier d'import: " << endl;
			cin >> nom; 
			nom +=  ".txt";
			if(is_file_exist(nom)){
				Tabr tabgenerate(nom);
				tabr = tabgenerate;
			}else{
				cout << "Ce fichier n'existe pas" << endl;
			}
			break;
		case 3:
			tabr.afficher_tabr_graphique();
			break;
		case 4:
			cout << "Entrez le nom du fichier d'export: " << endl;
			cin >> nom;
			nom += ".txt";
			if(is_file_exist(nom)){
				cout << "Attention ce fichier existe, voulez vous l'écraser? (o pour oui, n pour non) " << endl;
				cin >> c;
				if(c == "o"){
					tabr.export_tabr(nom);
				}else{
					cout << "Abandon sauvegarde" << endl;
					break;
				}
			}else{
				tabr.export_tabr(nom);
			}
			cout << "Création du fichier : " << nom  << endl;
			break;
		case 5:
			{ 
				cout << "Saisir la valeur maximum de l'intervalle max du TABR"<< endl;	 
				cin >> max; 

				cout << "Saisir le nombre d'intervalle"<< endl;	 
				cin >> nbInter; 

				cout << "Saisir le nombre de noeud à générer par arbre"<< endl;	 
				cin >> nbNoeud; 

				Tabr tabgenerate(max,nbInter,nbNoeud);
				tabr = tabgenerate;

				cout << "Tabr généré avec succés, félicitation"<< endl;
			}	
			break;
		default:
			// Code
			break;
		}
	}
	return 0;
}
