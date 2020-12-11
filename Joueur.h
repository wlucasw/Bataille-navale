#pragma once
#include "map.cpp"


class joueur {

private :
	map grid;
	int* boat;
	bool winner;

public :

	//Constructeurs
	joueur(){
		int* boats = new int();
		*boats = 5;
		bool win = false;
		grid = map();
		winner = win;
		boat = boats;
	}

	joueur(string bateaux) {
		int* boats = new int();
		*boats = 5;
		bool win = false;
		grid = map();
		winner = win;
		boat = boats;
		grid.Init(bateaux);
	}

	//Accesseurs
	map Get_grid() { return(grid); };
	int Get_boat() { return(*boat); };
	bool Get_winner() { return(winner); };

	//Seteurs
	void Set_grid(map map) { this->grid = map; };
	void Set_boat(int n) { this->boat = &n; };
	void Set_winner(bool win) { this->winner = win; };

	//Fonction de jeu
	void Play_bot(joueur adv) {
		pair<int, int> pos = adv.Get_grid().Random();
		string result = adv.Get_grid().Touche(pos);
		if (result == "coule") { 
			*adv.boat= *adv.boat - 1; 
			if (adv.Get_boat() == 0) { winner = true; }
		}

	};

}; 