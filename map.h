#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <istream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include <time.h>
using namespace std;

class map {
private :
	vector<int>* boat;
	vector< vector<int>*>* grid;

public :

	//Constructeurs
	map() {
		vector<int>* boats;
		vector<int>* ligne;
		vector< vector<int>*>* grid;
		boats = new vector<int>();
		grid = new vector<vector<int>*>();
		for (int i=0; i <10; i++) {
			ligne = new vector<int>();
			for (int j=0;j <10; j++){ 
				ligne->push_back(0); 
			}
			grid->push_back(ligne);
		}
		for (int j = 0; j < 5; j++) {
			boats->push_back(0);
		}
		this->grid = grid;
		this->boat = boats;
	};
	
	//Accesseurs
	vector<int>* Get_boat() { return(boat); };
	vector< vector<int>*>* Get_grid() { return(grid); };
	int Get_pos(pair<int, int> pos) { return(grid->at(pos.first)->at(pos.second)); };

	//Seteurs
	void Set_boat(vector<int>* boats) { boat = boats; };
	void Set_grid(vector< vector<int>*>* map) { grid = map; };

	//Modifie la case � la position pos en nb
	void Change(pair<int, int> pos, int nb);

	//Cr�e la grille du joueur � l'aide d'un fichier pass� en argument
	void Init(string fichier);

	//Renvoie une position non d�j� touch� al�atoire de la grille du joueur
	pair<int, int> Random();

	//Renvoie touche, coule ou plouf en fonction de case interrog�e, modifie aussi les cases du bateau touch� pour qu'elles correspondent � sa nouvelle longueur
	string Touche(pair<int, int> pos);

	//fonction d'affichage dans le terminal
	void Affichage();
};