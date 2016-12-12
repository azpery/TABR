
#ifndef tabr_HPP
#define tabr_HPP
#include "abr.hpp"
// I/O de fichier
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

struct Interval{
	int valmin;
	int valmax;
};

struct Case{
	Interval interval;
	Abr abr;
};

class Tabr{

	public:
		vector<Case> tabr;

		// Constructors // 
		Tabr();
		Tabr(string file);
		Tabr(int m,int n,int nbNoeud);
		void split(const string &s, char delim, vector<string> &elems);
		vector<string> splitVector(const string &s, char delim);
		void export_tabr(string path);


		void remplirCaseString(vector<string> intervals,vector<string> values);
		void remplirCase(vector<Interval> intervals,vector<int> values);


		// Genérations // 

		vector<Interval> generateInter(int m,int n);
		int random(int min,int max);
		vector<int> multiple_random(int min,int max,int nb);



		// Affichages // 
		void afficher_vector_string (const vector<string>& v);
		void afficher_vector_int(const vector<int>& v);
		void afficher_vector_intervalles(vector<Interval> inter);
		void afficher_tabr();
		void afficher_tabr_graphique();
		void afficher_inter(Interval inter);
		string to_String();


};

#include "tabr.tpp"
#endif // abr_HPP
