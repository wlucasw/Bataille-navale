#include"map.h"

using namespace std;
/*
void map::Change(pair<int, int> pos, int nb) {
	grid[pos.first][pos.second] = nb;
}

void map::Init(string fichier) {
	ifstream grille(fichier);
	string line;
	int compt = 0;
	pair <int, int> pos;
	while (getline(grille, line))
	{
		char a;
		boat[compt] = line.length() / 4;
		for (int i = 0; i < line.length(); ++i)
		{
			if (line.at(i) == ';') {
				i += 1;
				pos.second = line.at(i);
			}
			if (line.at(i) == '/') {
				Change(pos, compt);
			}
			else {
				pos.first = line.at(i);
			}
		}
		compt += 1;
	}
};
/*
pair<int, int> map::Random(void) 
{ 
	pair<int, int> pos;
	pos.first = 1;
	pos.second = 1;
	return(pos); 
};

string map::Touche(pair<int, int>)
{
	return(" ");
};

void map::Affichage() {
	for (int i= 0; i < 10 ; i++) {
		for (int j = 0; j < 10; j++) {
			cout << grid[i][j];
			cout << " ";
		}
		cout << endl;
	}
};*/