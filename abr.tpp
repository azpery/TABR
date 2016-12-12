#include "abr.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <deque>
#include <iomanip>

using namespace std;
//créer un abr vide
Abr::Abr(){
	racine = NULL;
}

Abr::Abr(vector<string> v){
	racine = NULL;

  	for (int i = v.size() - 1; i >= 0 ;i--){
    	ajouter(racine, stoi(v[i]));
  	}
}

Abr::Abr(vector<int> v){
	racine = NULL;

  	for (int i = v.size() - 1; i >= 0 ;i--){
    	ajouter(racine, v[i]);
  	}
}

//Permet d'ajouter x dans l'arbre
void Abr::ajouter(Noeud* &node, int val){
	if(node == NULL){
		node = new Noeud;
		node->val = val;
		node->sad = NULL;
		node->sag = NULL;
	}
	else{
		//si la valeur à inserer est inférieur à celle du noeud acutel
		if(val <= node->val){
			ajouter(node->sag, val);
		}
		else {
			ajouter(node->sad, val);
		}
	}
}

void Abr::afficher(Noeud* c)
{
    if (c != NULL)
    {
        cout << to_String(c);
    }
}

bool Abr::isRoot(Noeud* c){
	bool res = false;
	if(c->val == racine->val){
		res = true;
	}
	return res;
}

string Abr::to_String(Noeud* c){
	string res = "";
    if (c != NULL)
    { 
        res = to_String(c->sag);
        res += to_String(c->sad);
        res += to_string(c->val) +( isRoot(c) == false ? ":" : "" );
    }
    return res;
}

