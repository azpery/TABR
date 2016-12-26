
#ifndef abr_HPP
#define abr_HPP
#include <string>
// I/O de fichier
#include <deque>
#include "math.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstddef>



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
		bool ajouter(Noeud*& node, int val);
		void afficher(Noeud* p);
		bool isRoot(Noeud* c);
		string to_String(Noeud* c);
		bool abrBienRempli(Noeud* c,vector<int> values,bool res,int min,int max);
};

#include "abr.tpp"
#endif // abr_HPP
