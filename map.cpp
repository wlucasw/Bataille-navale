#include"map.h"

using namespace std;

//Modifie la case à la position pos en nb
void map::Change(pair<int, int> pos, int nb) {
	grid->at(pos.first)->at(pos.second) = nb;
}

//Crée la grille du joueur à l'aide d'un fichier passé en argument
void map::Init(string fichier) {
	ifstream grille(fichier);
	string line;
	int compt = 1;
	pair <int, int> pos;
	int i;
	while (getline(grille, line))
	{
		char a;
		boat->at(compt - 1) = line.length() / 4;
		i = 0;
		while (i < line.length())
		{
			if (line.at(i) == '/') {
				Change(pos, compt);

			}
			if (int(line.at(i)) - int('0') < 10 && int(line.at(i)) - int('0') >= 0) {
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

//Renvoie une position non déjà touché aléatoire de la grille du joueur
pair<int, int> map::Random() 
{ 
	pair<int, int> pos;
	pos.first = rand() % 10;
	pos.second = rand() % 10;
	while (Get_pos(pos) == -1) {
		pos.first = rand() % 10;
		pos.second = rand() % 10;
	}
	return(pos);
};

//Renvoie touche, coule ou plouf en fonction de case interrogée, modifie aussi les cases du bateau touché pour qu'elles correspondent à sa nouvelle longueur
string map::Touche(pair<int, int> pos)
{
	if (Get_pos(pos) == 0) {
		Change(pos, -1);
		return("plouf");
	}
	else {
		boat->at(Get_pos(pos) - 1) -= 1;
		int b = boat->at(Get_pos(pos) - 1);
		Change(pos, -1);
		if (b == 0) { return("coule"); }
		else { return("touche"); }
	}
};

//fonction d'affichage dans le terminal
void map::Affichage() {
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
	cout << endl << endl;
};