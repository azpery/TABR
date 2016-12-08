
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
		Noeud* racine; //noeud_arbre vide
		int nb_noeuds; //nb de noeud dans l'arbre
		void ajouter(Noeud*& node, int val);
		void afficher(Noeud* p, int indent);
		void printPretty(Noeud *root, int level, int indentSpace, ostream& out);
		void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Noeud*>& nodesQueue, ostream& out);
		void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Noeud*>& nodesQueue, ostream& out);
		void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<Noeud*>& nodesQueue, ostream& out);
		int maxHeight(Noeud *p);
		string intToString(int val);
};

#include "abr.tpp"
#endif // abr_HPP
