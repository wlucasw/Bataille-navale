#include "joueur.h"

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

		//création des joueurs
		joueur bot = joueur("Grille.txt");
		joueur j1 = joueur("Grille.txt");

		//nombre de tour
		int compt = 0;

		//le jeu commence et continue tant qu'aucun des joueurs n'a gagné
		while (!bot.Get_winner() && !j1.Get_winner()) {

			compt += 1;
			cout << compt << endl;

			//tour du bot
			bot.Play_bot(j1);
			cout << "bot" << endl;
			bot.Get_grid().Affichage();

			//tour du j1
			j1.Play_bot(bot);
			cout << "j1" << endl;
			j1.Get_grid().Affichage();
		}


		//fin du jeu
		bot.Get_grid().Affichage();
		j1.Get_grid().Affichage();


		//affichage du gagnant
		if (bot.Get_winner()) { 
			winner = bot; 
			cout << "le gagnant est le bot";
		}
		else { 
			winner = j1; 
			cout << "le gagnant est le j1"<<endl; 
		}
		
	};
};