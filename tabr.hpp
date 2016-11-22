
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
		Tabr();
		Tabr(string file);
		void split(const string &s, char delim, vector<string> &elems);
		vector<string> splitVector(const string &s, char delim);
		void afficher_vector (const vector<string>& v);
		void remplirCase(vector<string> intervals,vector<string> values);
		void afficher_tabr();
};

#include "tabr.tpp"
#endif // abr_HPP
