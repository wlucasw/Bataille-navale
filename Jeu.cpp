#include "joueur.cpp"

class jeu {
private: 

	joueur bot, j1, winner;

public: 

	//Constructeur
	jeu() {
		//fin = false;
		bot = joueur();
		j1 = joueur();
		winner = joueur();
	}

	//Accesseurs
	joueur Get_j1() { return(j1); };
	joueur Get_bot() { return(bot); };
	joueur Get_winner() { return(winner); };

	//Seteurs
	void Set_j1(joueur j) { this->j1 = j; };
	void Set_bot(joueur j) { this->bot = j; };
	void Set_winner(joueur j) { this->winner = j; };

	//Fonction de déroulement du jeu
	void start() {

		joueur bot = joueur("Grille.txt");
		joueur j1 = joueur("Grille.txt");

		int compt = 0;
		while (!bot.Get_winner() && !j1.Get_winner()) {
			compt += 1;
			cout << compt << endl;
			bot.Play_bot(j1);
			cout << "bot" << endl;
			bot.Get_grid().Affichage();
			j1.Play_bot(bot);
			cout << "j1" << endl;
			j1.Get_grid().Affichage();
		}
		bot.Get_grid().Affichage();
		j1.Get_grid().Affichage();
		if (bot.Get_winner()) { winner = bot; }
		else { winner = j1; }
		
	};
};