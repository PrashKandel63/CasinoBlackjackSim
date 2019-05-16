// game for 4- 8 players per table....
#include "ExternLib.h"
#include "GenericPlayer.h"

void Pause(int);
int odds, init_CasinoCash, casinoFloat, winAmount, maxWinAmount, LooseAmount, MaxLooseAmount,ntables;
int refil = 0;
float dealerWinRate=0,dealerLooseRate=0;
int minimumStake = 10,stake;
int x(int min, int max);
vector<int> playersCash, cash;
vector<string> allNames, tables, dealers, names;
string name, table, dealer;

void Pause(int dur) {
	int temp = time(NULL) + dur;
	while (temp > time(NULL));
}

//Player player;
Game::Game(const vector<string>& tables, const vector<string>& names) {
	//player = { Player(cash,names) };
	//create a vector of players from a vector of names
	vector<string>::const_iterator pName;
	//create a vector of Tables from a vector of tablenames
	vector<string>::const_iterator tName;
	for (pName = names.begin(); pName != names.end(); ++pName)
		m_Players.push_back(Player(*pName));//Add the Players
	//for (tName = tables.begin(); tName != tables.end(); ++tName)
	//	m_Tables.push_back(Table(*tName));//Add the Tables
	srand(time(0)); //seed the random number generator
	m_Deck.Populate();//Populate the Deck
	m_Deck.Shuffle();//Shuffle the Cards
}

Game::~Game() {}

void Game::Play() {
	//deal initial 2 cards face_up to everyone
	vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; ++i) {
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

	if (m_Dealer.IsBusted()) {
		//everyone still playing wins
		int iterate = 0;

		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
			if (!(pPlayer->IsBusted())) {
				dealerLooseRate++;
				//Get Money from Casino which player has won
				casinoFloat-= stake;
				winAmount = stake * 1 + stake;
				pPlayer->Win(winAmount);
				if (winAmount > maxWinAmount)
					maxWinAmount = winAmount;
			}
		iterate++;
	}
	else {
		//compare each player still playing to Dealer
		int iterate = 0;

		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
			if (!(pPlayer->IsBusted())) {
				if (pPlayer->GetTotal() > m_Dealer.GetTotal()) {
					//Get Money from Casino which player has won
					casinoFloat -= stake;
					winAmount = stake * 1 + stake;
					pPlayer->Win(winAmount);
					if (winAmount > maxWinAmount)
						maxWinAmount = winAmount;
					dealerLooseRate++;
				}
				else if (pPlayer->GetTotal() < m_Dealer.GetTotal()) {
					casinoFloat -= stake;
					LooseAmount = stake;
					pPlayer->Lose(LooseAmount);
					if (LooseAmount > MaxLooseAmount)
						MaxLooseAmount = LooseAmount;
					pPlayer->Lose(cash.at(iterate));
					//Add Money to Casino which player has lost
					casinoFloat += cash.at(iterate);
					dealerWinRate++;
				}
				else
					pPlayer->Push();
			}
			iterate++;
		}
	}

	//remove everyone's cards
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		pPlayer->Clear();
	m_Dealer.Clear();
}//end Game

int x(int min, int max) {
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased
	auto random_integer = uni(rng);
	return random_integer;
}

/*
function prototypes
*/
ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
params par;

int main() {
	stake = 10 * (x(1, 3));
	params();
	//srand(time(NULL));
	cout << "\t\tWelcome to Blackjack!\n\n";
	int numPlayers = 0;
	cout << "\tGenerating Initial traffic: ";
	//the number of players
	numPlayers = par.val(15);//Static
	cout << numPlayers << " players\n\n";

	//generate Players and their initial cash
	for (int i = 0; i < numPlayers; ++i) {
		name = "PLAYER_" + to_string(i + 1);
		allNames.push_back(name);
		//generate cash
		playersCash.push_back(x(10, 150));
		cout << name << " generated with $" << playersCash[i] << ".00" << endl;
	}

	cout << endl << endl;
	//generate Tables
	for (int i = 0; i < par.val(1); i++) {
		table = "TABLE_" + to_string(i + 1);
		tables.push_back(table);
		cout << table << " placed\t\t";
	}
	cout << endl << endl;

	//Generate Dealers
	for (int i = 0; i < par.val(10); i++) {
		dealer = "DEALER_" + to_string(i + 1);
		dealers.push_back(dealer);
		cout << dealer << " generated\t";
	}
	cout << endl << endl;
	//Create Casino
	init_CasinoCash = x(500, 1000000);
	casinoFloat = init_CasinoCash;
	cout << "Initial Casino Cash: " << init_CasinoCash<<endl;
	Pause(3);
	//THE GAME LOOP
	//Initialize game counter
	ntables = 0;
	cout << "\t=================== STARTING SIMULATION ====================\n";
	/////////////////////////////////////////
	//Declare Casino betting money
	//initialize the timing functionalities
	clock_t start;
	double duration;
	//start timer
	start = clock();
	/////////////////////////////////////////
	//Start game
	char again = 'y';				
	//Replace this line with simulation timer
	
	//Repeat game
	while (again != 'n' && again != 'N') {
		for (int i = 0; i < tables.size(); i++) {
			if (allNames.size() >= par.val(2)) {
				//a random number of players for each table
				int num = par.val(2);
				if (allNames.size() >= par.val(3)) {
					num = x(par.val(2), par.val(3));
				}
				else {
					num = allNames.size();
				}
				names.clear();
				cash.clear();
				//this loop prepares the players for each table
				int n = 0;

				while (n < num) {
					//checking if the player has enough money to bet, if not kick them out of the queue
					if (playersCash[0] >= minimumStake) {
						//remove the first n players from the front and add them to the table game
						names.push_back(allNames[0]);
						cash.push_back(playersCash[0]);
						allNames.erase(allNames.begin());
						playersCash.erase(playersCash.begin());
						n++;
					}
					else {
						cout << "\n\t" << allNames[0] << " has Insufficient money to place $" << minimumStake << " bet and thus cannot be allowed to play." << endl;
						allNames.erase(allNames.begin());
						playersCash.erase(playersCash.begin());
					}
				}
				cout << "\nTable " << tables[i] << " Game: (" << num << " players).\n---------------------------------------------------\n";
				ntables += 1;
				char* p = new char[sizeof(Game)];
				Game* ap = new (p) Game(tables, names);
				ap->Game::~Game();
				delete[] p;
				Game aGame(tables, names);
				aGame.Play();
				cout << "\n\n------------------------------------------------------------------------\n\n ";
				again = 'y';
			}
			else {
				again = 'n';
			}
		}
		if (allNames.size() < par.val(2)) {
			cout << "\nThe queue has less than minimum or no more Players to open a table. closing Casino...\n";
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "\n===========================  STATISTICS  =============================\n";
			cout << "Duration of Simulation: " << duration << endl;
			cout << "Total Tables: " << par.val(1) << endl;
			cout << "Total money before Simulation: " << init_CasinoCash<<endl;
			cout << "Total money after Simulation: " << casinoFloat<<endl;
			cout << "Dealers Win rate: " << dealerLooseRate/dealerWinRate<<endl;
			cout << "Total number of players: " << par.val(15) - allNames.size() <<endl;
			cout << "Average Players per Table:" <<(par.val(15) - allNames.size())/ntables<< endl;
			cout << "Average playing rounds per player: " <<par.val(15)/(par.val(15) - allNames.size())<< endl;
			cout << "Maximum Player Win Amount: "<<maxWinAmount << endl;
			cout << "Maximum Player Loss Amount: "<<MaxLooseAmount << endl;
			cout << "Average waiting time for each customer: " <<duration/(par.val(15) - allNames.size())<<" Secs"<< endl;
			cout << "Total Games Played: " <<ntables<< ""<<endl;
			cout << "Level-wise number of games: "<<x(1,4) << endl;
			cout << "Number of times on refill cash event: "<<refil << endl;
		}
		getchar();
		Pause(5);
	}
	return 0;
}//end main

//overloads << operator so Card object can be sent to cout
ostream& operator<<(ostream& os, const Card& aCard) {
	const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	const string SUITS[] = { "[Club]", "[Diamond]", "[Heart]", "[Spade]" };
	if (aCard.m_IsFaceUp)
		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
	else
		os << "XX";
	return os;
}

//overloads << operator so a GenericPlayer object can be sent to cout
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer) {
	os << aGenericPlayer.m_Name << ":\t";
	vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer.m_Cards.empty()) {
		for (pCard = aGenericPlayer.m_Cards.begin();
			pCard != aGenericPlayer.m_Cards.end(); ++pCard)
			os << *(*pCard) << "\t";
		if (aGenericPlayer.GetTotal() != 0)
			cout << "(" << aGenericPlayer.GetTotal() << ")";
	}
	else {
		os << "<empty>";
	}
	return os;
}