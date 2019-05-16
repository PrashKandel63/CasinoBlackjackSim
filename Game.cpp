#include "BlackJack.h"

Game::~Game()
{}

void Game::Play()
{
	//deal initial 2 cards to everyone
	vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; ++i)
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
			m_Deck.Deal(*pPlayer);
		m_Deck.Deal(m_Dealer);
	}

	//hide Dealer's first card
	m_Dealer.FlipFirstCard();

	//display everyone's hand
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		cout << *pPlayer << endl;
	cout << m_Dealer << endl;

	//deal additional cards to players
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		m_Deck.AdditionalCards(*pPlayer);

	//reveal Dealer's first card
	m_Dealer.FlipFirstCard();
	cout << endl << m_Dealer;

	//deal additional cards to Dealer
	m_Deck.AdditionalCards(m_Dealer);

	if (m_Dealer.IsBusted())
	{
		//everyone still playing wins
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
			if (!(pPlayer->IsBusted()))
				pPlayer->Win();
	}
	else
	{
		//compare each player still playing to Dealer
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
			if (!(pPlayer->IsBusted()))
			{
				if (pPlayer->GetTotal() > m_Dealer.GetTotal())
					pPlayer->Win();
				else if (pPlayer->GetTotal() < m_Dealer.GetTotal())
					pPlayer->Lose();
				else
					pPlayer->Push();
			}
	}

	//remove everyone's cards
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		pPlayer->Clear();
	m_Dealer.Clear();
}