
#ifndef abr_HPP
#define abr_HPP
#include <string>
// I/O de fichier
#include <deque>
#include "math.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

struct Noeud{
	int val;
	Noeud* sag;//plus grand
	Noeud* sad;//plus petit
};

class Abr{

	public:
		Abr();
		Abr(vector<string> values);
		Abr(vector<int> values);
		Noeud* racine; //noeud_arbre vide
		int nb_noeuds; //nb de noeud dans l'arbre
		void ajouter(Noeud*& node, int val);
		void afficher(Noeud* p);
		string to_String(Noeud* c);
};

#include "abr.tpp"
#endif // abr_HPP
