#pragma once

#include <vector>
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

class Game {

public:
	Game(const vector<string>& tables, const vector<string>& names);
	~Game();
	//plays the game of blackjack
	void Play();

private:
	Deck m_Deck;
	Dealer m_Dealer;
	vector<Player> m_Players;
};