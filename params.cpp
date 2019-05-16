#include "population.h"

params::params() {
	parameters();
}

int params::parameters() {
	inData.open("params.txt");
	if (!inData) {
		//print to console if error occurs while opening and exit
		cout << "can't open file" << endl;
		cin.get();
		return 1;
	}

	//While not EOF (!End of File)
	int line = 1;
	while (!inData.eof()) {
		switch (line) {
		case 1:
			inData >> n_tables;
			break;
		case 2:
			inData >> min_Players >> max_Players >> min_cards >> max_cards;
			break;
		case 3:
			inData >> transitionTable1 >> transitionTable2 >> transitionTable3 >> transitionTable4;
			break;
		case 4:
			inData >> n_Dealers >> salary >> winPercentage;
			break;
		case 5:
			inData >> startCash >> refillCash;
			break;
		case 6:
			inData >> n_Initiallayers;
			break;
		case 7:
			inData >> rPlayer >> mdPlayer >> sPlayer >> cPlayer;
			break;
		case 8:
			inData >> buf >> rLevel1 >> rLevel2 >> rLevel3 >> rLevel4;
			break;
		case 9:
			inData >> buf >> mdLevel1 >> mdLevel2 >> mdLevel3 >> mdLevel4;
			break;
		case 10:
			inData >> buf >> sLevel1 >> sLevel2 >> sLevel3 >> sLevel4;
			break;
		case 11:
			inData >> buf >> cLevel1 >> cLevel2 >> cLevel3 >> cLevel4;
			break;
		case 12:
			inData >> playerArrival;
			break;
		default:
			break;
		}
		line++;
	}
	inData.close();
	return 0;
}

float params::arrival(int v) {
	if (v == 36)
		return playerArrival;
}

int params::val(int v) {
	switch (v) {
	case 1:
		return n_tables;
		break;
	case 2:
		return min_Players;
		break;
	case 3:
		return max_Players;
		break;
	case 4:
		return min_cards;
		break;
	case 5:
		return max_cards;
		break;
	case 6:
		return transitionTable1; 
		break;
	case 7:
		return transitionTable2; 
		break;
	case 8:
		return transitionTable3; 
		break;
	case 9:
		return transitionTable4; 
		break;
	case 10:
		return n_Dealers; 
		break;
	case 11:
		return salary; 
		break;
	case 12:
		return winPercentage; 
		break;
	case 13:
		return startCash; 
		break;
	case 14:
		return refillCash; 
		break;
	case 15:
		return n_Initiallayers; 
		break;
	case 16:
		return rPlayer;
		break;
	case 17:
		return mdPlayer;
		break;
	case 18:
		return sPlayer;
		break;
	case 19:
		return cPlayer;
		break;
	case 20:
		return rLevel1;
		break;
	case 21:
		return rLevel2;
		break;
	case 22:
		return rLevel3;
		break;
	case 23:
		return rLevel4;
		break;
	case 24:
		return mdLevel1;
		break;
	case 25:
		return mdLevel2;
		break;
	case 26:
		return mdLevel3;
		break;
	case 27:
		return mdLevel4;
		break;
	case 28:
		return sLevel1;
		break;
	case 29:
		return sLevel2;
		break;
	case 30:
		return sLevel3;
		break;
	case 31:
		return sLevel4;
		break;
	case 32:
		return cLevel1;
		break;
	case 33:
		return cLevel2;
		break;
	case 34:
		return cLevel3;
		break;
	case 35:
		return cLevel4;
		break;
	default:
		return 0;
		break;
	}
}