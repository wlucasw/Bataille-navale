#pragma once
#include "joueur.h"

//Constructeur par défaut
joueur::joueur() {
	int* boats = new int();
	*boats = 5;
	bool win = false;
	grid = map();
	winner = win;
	boat = boats;
};

//Constructeur à partir de bateaux
joueur::joueur(string bateaux) {
	int* boats = new int();
	*boats = 5;
	bool win = false;
	grid = map();
	winner = win;
	boat = boats;
	grid.Init(bateaux);
};

//fonction de jeu
void joueur::Play_bot(joueur adv) {
	pair<int, int> pos = adv.Get_grid().Random();
	string result = adv.Get_grid().Touche(pos);
	if (result == "coule") {
		*adv.boat = *adv.boat - 1;
		if (adv.Get_boat() == 0) { winner = true; }
	}
}