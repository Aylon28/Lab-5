#include <iostream>
#include <string>
using namespace std;

class Casino {
protected:
	int victoryMoney;
	int quantityOfPlayers;

public:
	Casino(int victoryMoney = 0, int quantityOfPlayers = 1) {
		//cout << "Constructor Casino" << endl;
		this->victoryMoney = victoryMoney;
		this->quantityOfPlayers = quantityOfPlayers;
	}
	virtual ~Casino() {
		//cout << "Destructor Casino" << endl;
	}
	virtual void Show() = 0;
	virtual void Name() = 0;
};

class Poker : public Casino {
	int quantityOfCards;
	int bet;

public:
	Poker(int quantityOfCards = 54, int bet = 0, int victoryMoney = 0, int quantityOfPlayers = 2) : Casino(victoryMoney, quantityOfPlayers) {
		//cout << "Constructor Poker" << endl;
		this->quantityOfCards = quantityOfCards;
		this->bet = bet;
	}
	~Poker() {
		//cout << "Destructor Poker" << endl;
	}
	void Show();
	void Name(){
		cout << "\nPoker\n";
	}
};

void Poker::Show() {
	cout << "Amount of players in Poker - " << quantityOfPlayers << ", won money - " << victoryMoney << "$, used quantity of cards - " <<
		quantityOfCards << ", bet of player - " << bet << "." << endl;
}

class Slots : public Casino {
	int amountOfRollers;
	bool isWinCombination;
	int paidMoney;

public:
	Slots(int amountOfRollers = 3, string isWin = "n", int paidMoney = 0, int victoryMoney = 0, int quantityOfPlayers = 1) : Casino(victoryMoney, quantityOfPlayers) {
		//cout << "Constructor Slots" << endl;
		if(isWin == "y" || isWin == "Y" ){
			this->isWinCombination = true;
		}else{
			this->isWinCombination = false;
		}
		this->amountOfRollers = amountOfRollers;
		this->paidMoney = paidMoney;
	}
	~Slots() {
		//cout << "Destructor Slots" << endl;
	}
	void Show();
	void Name(){
		cout << "\nSlots\n";
	}
};

void Slots::Show() {
	string combination = "no";

	if (isWinCombination) {
		combination = "yes";
	}
	cout << "Amount of players in Slots - " << quantityOfPlayers << ", won money - " << victoryMoney << "$, used quantity of rollers - " <<
		amountOfRollers << ", paid money by player - " << paidMoney << ", is it currently a win combination - " << combination << "." << endl;
}

class Dice : public Casino {
	int quantityOfDices;
	int score;

public:
	Dice(int quantityOfDices = 2, int score = 0, int victoryMoney = 0, int quantityOfPlayers = 2) : Casino(victoryMoney, quantityOfPlayers) {
		//cout << "Constructor Dice" << endl;
		this->quantityOfDices = quantityOfDices;
		this->score = score;
	}
	~Dice() {
		//cout << "Destructor Dice" << endl;
	}
	void Show();
	void Name(){
		cout << "\nDice\n";
	}
};

void Dice::Show() {
	cout << "Amount of players in Dice - " << quantityOfPlayers << ", won money - " << victoryMoney << "$, used amount of dices - " <<
		quantityOfDices << ", score - " << score << "." << endl;
}

bool IsNumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

string IsCorrect(string request){
	string item;
	do{
		cout << request;
		getline(cin, item);
		while(IsNumber(item) == false){
				cout << "\nINCORRECT" << endl;
				cout << request;
				getline(cin, item);
		}
	}while(stoi(item) < 1);
	return item;
}

int main() {
	Casino *objects[3];
	string players, money, quantity, paid, score;

	//POKER
	cout << "POKER OBJECT";
	cout << "\nEnter the correct data: " << endl;
	players = IsCorrect("Amount of players = ");
	quantity = IsCorrect("Amount of cards = ");
	paid = IsCorrect("Bet money = ");
	money = IsCorrect("Amount of won money = ");
	Poker poker(stoi(quantity), stoi(paid), stoi(money), stoi(players));
	objects[0] = &poker;

	//SLOTS
	cout << "\nSLOTS OBJECT";
	cout << "\nEnter the correct data: " << endl;
	players = IsCorrect("Amount of players = ");
	quantity = IsCorrect("Amount of rollers = ");
	paid = IsCorrect("Paid money = ");
	money = IsCorrect("Amount of won money = ");
	do{
		cout << "Is it a win combinaton (y/n) = ";
		getline(cin, score);
	}while(score != "y" && score != "Y" && score != "n" && score != "N");
	Slots slots(stoi(quantity), score, stoi(paid), stoi(money), stoi(players));
	objects[1] = &slots;

	//Dices
	cout << "\nDICE OBJECT";
	cout << "\nEnter the correct data: " << endl;
	players = IsCorrect("Amount of players = ");
	quantity = IsCorrect("Amount of dices = ");
	score = IsCorrect("Score = ");
	money = IsCorrect("Amount of won money = ");
	Dice dice(stoi(quantity), stoi(score), stoi(money), stoi(players));
	objects[2] = &dice;

	for(int i = 0; i < 3; i++){
		objects[i]->Name();
		objects[i]->Show();
	}
	return 0;
}
