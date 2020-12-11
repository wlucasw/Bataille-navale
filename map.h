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

	void Change(pair<int, int> pos, int nb) {
		grid->at(pos.first)->at(pos.second) = nb;
	}

	void Init(string fichier) {
		ifstream grille(fichier);
		string line;
		int compt = 1;
		pair <int, int> pos;
		int i;
		while (getline(grille, line))
		{
			char a;
			boat->at(compt-1) = line.length() / 4;
			i = 0;
			while (i < line.length())
			{
				if (line.at(i) == '/') {
					Change(pos, compt);

				}
				if (int(line.at(i)) - int('0') < 10 && int(line.at(i)) - int('0') >= 0){
					pos.first = int(line.at(i)) - int('0');
				}
				if (line.at(i) == ';') {
					i += 1;
					pos.second = int(line.at(i)) - int('0');
				}
				i += 1;
			}
			cout << endl;
			compt += 1;
		}
	};

	pair<int, int> Random(void)
	{
		pair<int, int> pos;
		pos.first = rand() % 10;
		pos.second = rand() % 10;
		while( Get_pos(pos) == -1) {
			pos.first = rand() % 10;
			pos.second = rand() % 10;
		}
		return(pos);
	};

	string Touche(pair<int, int> pos)
	{
		if (Get_pos(pos) == 0) {
			Change(pos, -1);
			return("plouf");
		}
		else{
			boat->at(Get_pos(pos) - 1) -= 1 ;
			int b = boat->at(Get_pos(pos) - 1);
			Change(pos, -1);
			if (b == 0) { return("coule"); }
			else { return("touche"); }
		}
	};

	void Affichage() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << grid->at(i)->at(j);
				cout << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int k = 0; k < 5; k++) {
			cout << boat->at(k);
			cout << " ";
		}
		cout << endl<<endl;
	};
};