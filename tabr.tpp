#include "tabr.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <time.h>  
#include "tabr.hpp"
#include "abrprinter.hpp"
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
			remplirCaseString(vinterval, vvalues);
		    vligne.clear();
		    vinterval.clear();
		    vvalues.clear();
		}
		fichier.close();
		cout << "Tabr généré avec succés, félicitation." << endl;
	}
	else{
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
}


Tabr::Tabr(int m,int n,int nbNoeud){
	vector<Interval> intervalles = generateInter(m,n);
	afficher_vector_intervalles(intervalles);
	for(int i=0;i<intervalles.size();i++)
	{
		vector<int> values;
		Case c;
		c.interval = intervalles.at(i);
		values = multiple_random(c.interval.valmin,c.interval.valmax,nbNoeud);
		afficher_vector_int(values);
		Abr abr(values);
		c.abr = abr;
		tabr.push_back(c);
	}
}



void Tabr::remplirCase(vector<Interval> intervals,vector<int> values){


}


void Tabr::remplirCaseString(vector<string> intervals,vector<string> values){

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
		cout << "Interval : " << tabr[i].interval.valmin << ";" << tabr[i].interval.valmax << ":";
		tabr[i].abr.afficher(tabr[i].abr.racine);
		cout << endl;
	}
}

bool Tabr::addToTabr(int my_val){
	bool res = false;
	bool foundInter = false;
	for (int i=0; i<tabr.size();i++){
		if(tabr[i].interval.valmin <= my_val &&  my_val <= tabr[i].interval.valmax){
			foundInter = true;
			res = tabr[i].abr.ajouter(tabr[i].abr.racine, my_val);
		}
	}
	if(!foundInter){
		cout << "La valeur" << my_val << " ne correspond à aucun interval" << endl;
	}
	return res;
}

string Tabr::to_String(){
	string res = "";
	for (int i=0; i<tabr.size();i++){
		res += to_string(tabr[i].interval.valmin) + ":" + to_string(tabr[i].interval.valmax) + ";" + tabr[i].abr.to_String(tabr[i].abr.racine) + "\n";
	}
	return res;
}

void Tabr::afficher_tabr_graphique(){
	AbrPrinter ap;
	for (int i=0; i<tabr.size();i++){
		cout << "Interval : " << to_string(tabr[i].interval.valmin) << ";" << to_string(tabr[i].interval.valmax) << endl;
		ap.printPretty(tabr[i].abr.racine, 1, 0, cout);
	}
}

//Exporte un Tabr dans un fichier texte dont le chemin est passé en paramètre
void Tabr::export_tabr(string path){
  	ofstream myfile;
  	myfile.open (path.c_str());
  	myfile << to_String();
  	myfile.close();	
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

vector<Interval> Tabr::generateInter(int m,int n){

	vector<Interval> intervalles; 

	Interval inter; 
	int borne_min=1;
	int borne_max=m;
	int i = 0;

	srand(time(NULL)); // initialisation de rand

	for(int i=0;i<n-1;i++){

	borne_max = random(borne_min,(borne_max/n)*(1+i));

	inter.valmin = borne_min; 
	inter.valmax = borne_max;

	if(borne_max < m-5){
		int a = borne_max + random(0,5);
		borne_max = a;
	}

	borne_min = borne_max;
	borne_max = m;
	
	intervalles.push_back(inter);// ajout intervalle dans le vector //

	}

	// POur le dernier intervalle // 

	inter.valmin = inter.valmax; 

	inter.valmax = m;

	intervalles.push_back(inter);

	return intervalles;
}

void Tabr::afficher_vector_string (const vector<string>& v){
  for (int i=0; i<v.size();i++){
    cout << v[i] << endl;
  }
}

void Tabr::afficher_vector_int(const vector<int>& v){
  for (int i=0; i<v.size();i++){
    cout << v[i] << endl;
  }
}


void Tabr::afficher_vector_intervalles(vector<Interval> inter){


for(int i=0;i<inter.size();i++)
{
	afficher_inter(inter.at(i));
}

}


void Tabr::afficher_inter(Interval inter){
	cout << "Interval : " << inter.valmin << ";" << inter.valmax << endl;
}


int Tabr::random(int min,int max){

	return rand()%(max-min) + min;
}

vector<int> Tabr::multiple_random(int min,int max,int nb){


	vector<int> values;

	for(int i=0;i<nb;i++){

		int val = random(min,max);
		values.push_back(val);

	}

	return values;
}