#include "tabr.hpp"
#include <string>
#include <sstream>
#include <vector>

using namespace std;
//créer un abr vide


Tabr::Tabr(string file){
	ifstream fichier(file.c_str(), ios::in);
	vector<string> vligne;
	vector<string> vinterval;
	vector<string> vvalues;
	if(fichier)
	{
		string ligne;
		while(getline(fichier, ligne))  
		{
			vligne = splitVector(ligne, ';');
			vinterval = splitVector(vligne[0], ':');
			vvalues = splitVector(vligne[1], ':');
			remplirCase(vinterval, vvalues);
		    vligne.clear();
		    vinterval.clear();
		    vvalues.clear();
		}
		fichier.close();
	}
	else{
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
}


void Tabr::remplirCase(vector<string> intervals,vector<string> values){

	Case c ;
	Interval i;

	i.valmin = stoi(intervals[0]);
	i.valmax = stoi(intervals[1]);
	Abr abr(values);

	c.interval = i; 
	c.abr = abr;

	tabr.push_back(c);
}

void Tabr::afficher_tabr(){
	for (int i=0; i<tabr.size();i++){
		cout << "Interval : " << tabr[i].interval.valmin << ";" << tabr[i].interval.valmax << endl;
		tabr[i].abr.printPretty(tabr[i].abr.racine, 1, 0, cout);
	}
}


void Tabr::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

vector<string> Tabr::splitVector(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

void Tabr::afficher_vector (const vector<string>& v){
  for (int i=0; i<v.size();i++){
    cout << v[i] << endl;
  }
}