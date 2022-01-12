#pragma once
#include "map.h"


class joueur {

private :
	map grid;
	int* boat;
	bool winner;

public :

	//Constructeur par défaut
	joueur();

	//Constructeur à partir de bateaux
	joueur(string bateaux);

	//Accesseurs
	map Get_grid() { return(grid); };
	int Get_boat() { return(*boat); };
	bool Get_winner() { return(winner); };

	//Seteurs
	void Set_grid(map map) { this->grid = map; };
	void Set_boat(int n) { this->boat = &n; };
	void Set_winner(bool win) { this->winner = win; };

	//Fonction de jeu
	void Play_bot(joueur adv);

}; 