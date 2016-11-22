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

  	for (int i=0; i<v.size();i++){
    	ajouter(racine, stoi(v[i]));
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
			ajouter(node->sad, val);
		}
		else {
			ajouter(node->sag, val);
		}
	}
}

void Abr::afficher(Noeud* c, int indent)
{
    if (c != NULL)
    {
        afficher(c->sag, indent + 4);
        if (indent > 0)
            cout << setw(indent) << " ";
        cout << c->val << endl;
        afficher(c->sad, indent + 4);
    }
}	
// Print the arm branches (eg, /    \ ) on a line
void Abr::printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Noeud*>& nodesQueue, ostream& out) {
  deque<Noeud*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {  
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}
 
// Print the branches and node (eg, ___10___ )
void Abr::printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Noeud*>& nodesQueue, ostream& out) {
  deque<Noeud*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->sag) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->val) : "");
    out << ((*iter && (*iter)->sad) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}
 
// Print the leaves only (just for the bottom row)
void Abr::printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<Noeud*>& nodesQueue, ostream& out) {
  deque<Noeud*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->val) : "");
  }
  out << endl;
}
 
// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
void Abr::printPretty(Noeud *root, int level, int indentSpace, ostream& out) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;
 
  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)
    
  deque<Noeud*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
 
    for (int i = 0; i < nodesInThisLevel; i++) {
      Noeud *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
       nodesQueue.push_back(currNode->sag);
       nodesQueue.push_back(currNode->sad);
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

