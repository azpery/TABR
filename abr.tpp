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
bool Abr::ajouter(Noeud* &node, int val){
	bool res = true;
	if(node == NULL){
		node = new Noeud;
		node->val = val;
		node->sad = NULL;
		node->sag = NULL;
	}
	else{
		//si la valeur à inserer est inférieur à celle du noeud acutel
		if(val < node->val){
			res = ajouter(node->sag, val);
		}
		else if(val > node->val){
			res = ajouter(node->sad, val);
		}else{
			res = false;
			cout << "La valeur : " << val << " existe déjà, skipping.." << endl;
		}
	}
	return res;
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

bool Abr::abrBienRempli(Noeud* c,vector<int> values,bool res,int min,int max){


	if(res && c!=NULL){

		int val = c->val;

		if(find(values.begin(), values.end(), val) != values.end()){
			cout << "Element déjà présent dans l'ABR";
			res = false; 
		} else {

			if(val>= min && val<= max){

				values.push_back(val);

				return abrBienRempli(c->sad,values,res,min,max);
				return abrBienRempli(c->sag,values,res,min,max);
			} else {
				cout << "Element " << val <<" sort des bornes [" << min <<";"<< max <<"]";

				res =false; 
			}
		}

		return res; 
	} else {
		return res; 
	}
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

