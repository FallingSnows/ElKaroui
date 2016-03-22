#include "Game.h"
#include <string>
#include <iostream>

void Game::SetNumberOfPacks()
{
	unsigned int			numberOfPacks;

	while (1)
	{
		std::cout << "Input the number of Packs: ";
		std::cin >> numberOfPacks;
		if (!std::cin.fail())
		{
			if (numberOfPacks > 0)
			{
				break;
			}
			else
			{
				std::cout << "The number your rntered isn't positive, Please give a positive integer!!" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		else
		{
			std::cout << "Please give a positive integer!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	m_numberOfPacks = numberOfPacks;
	return;
};

void Game::SetMatchMode()
{

	unsigned int			matchMode;

	while (1)
	{
		std::cout << "Please choose the match mode [1: Face Match 2: Suite match 3: Both match]: ";
		std::cin >> matchMode;
		if (!std::cin.fail())
		{
			if ((matchMode > 0) & (matchMode < 4))
			{
				break;
			}
			else
			{
				std::cout << "Please choose the match mode between [1: Face Match 2: Suite match 3: Both match] !" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		else
		{
			std::cout << "Your input is not accepted! Try again!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	m_matchMode = matchMode;
	return;
}

bool Game::CheckCardMatch(Card& A, Card& B) const
{
	if (m_matchMode == 1) // check face value
	{
		return A.GetFaceValue() == B.GetFaceValue();
	}
	else if (m_matchMode == 2)
	{
		return A.GetSuitValue() == B.GetSuitValue();
	}
	else if (m_matchMode == 3)
	{
		return A.GetFaceValue() == B.GetFaceValue() & A.GetSuitValue() == B.GetSuitValue();
	}
	else
	{
		std::cerr << "Please recheck the match mode, game error!" << std::endl;
		exit(0);
	}

}


std::string Game::ChoosePlayerWithSnap() const
{
	double a = rand() / (RAND_MAX + 1.0);
	if ((a - 0.5) * 2 < 0)
	{
	return m_players[0].GetPlayerName();
	}
	else
	{
	return m_players[1].GetPlayerName();
	}
};


//two stupid players, we could give them name also
void Game::InitializePlayers()
{
	Player A("Vincent");
	Player B("Vinci");

	std::vector<Player>	players;
	players.push_back(A);
	players.push_back(B);
	m_players = players;
	return;
};
void Game::ShufflingCards()
{
	std::vector<Card> shuffledCards;
	std::cout << "Cards shuffling ...." << std::endl;

	//shuffle the cards, total number 13 * 4 * N
	int size = 13 * 4 * m_numberOfPacks;
	std::vector<int> a(size);
	for (auto i = 0; i < size; ++i)
	{
		a[i] = i;
	}

	//shuffle randomly
	for (auto i = size - 1; i >= 1; --i)
	{
		int j = rand() % i;
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;

	}

	//change the vector<int> to vector<card>
	
	for (auto i = 0; i < size; ++i)
	{
		Card card;
		card.SetFaceValue(a[i] % 52 % 13 + 1);
		int temp = a[i] % 52;
		if (temp < 27)
		{
			if (temp < 14)
			{
				card.SetSuitValue(1);
			}
			else
			{
				card.SetSuitValue(2);
			}
		}
		else
		{
			if (temp < 40)
			{
				card.SetSuitValue(3);
			}
			else
			{
				card.SetSuitValue(4);
			}
		}
		shuffledCards.push_back(card);
	}

	m_cards = shuffledCards;
	std::cout << "Cards shuffled!" << std::endl;
	return;
};

void Game::CheckWinner() const
{
	std::cout << "Game over!" << std::endl;
	if (m_players[0].GetNumberOfCardsOwed() > m_players[1].GetNumberOfCardsOwed())
	{
		std::cout << "The winner is " << m_players[0].GetPlayerName() << ", and he has " << m_players[0].GetNumberOfCardsOwed() << " cards!"
			<< "And " << m_players[1].GetPlayerName() << " has " << m_players[1].GetNumberOfCardsOwed() << " cards."<< std::endl;
	}
	else if (m_players[0].GetNumberOfCardsOwed() == m_players[1].GetNumberOfCardsOwed()  )
	{
		std::cout << "The result is draw, each one has " << m_players[0].GetNumberOfCardsOwed() << " cards."<< std::endl;
	}
	else
	{
		std::cout << "The winner is " << m_players[1].GetPlayerName() << ", and he has " << m_players[1].GetNumberOfCardsOwed() << " cards!"
			<< "And " << m_players[0].GetPlayerName() << " has " << m_players[0].GetNumberOfCardsOwed() << " cards." << std::endl;
	}
}

void Game::GameSimulation()
{
	//begin the game by put one card
	Card temp = *(m_cards.end() - 1);
	m_cards.pop_back();
	unsigned int CardsFree = 1;

	while (!m_cards.empty())
	{
		//take a card
		Card temp_ = *(m_cards.end() - 1);
		m_cards.pop_back();
		//the card number in one run
		CardsFree++;

		//when two card match
		if (CheckCardMatch(temp, temp_))
		{
			//choose a snap player
			std::string snapPlayerName = ChoosePlayerWithSnap();
			//add to his amount of cards
			snapPlayerName == m_players[0].GetPlayerName()? m_players[0].AddToAccumulatedCards(CardsFree) : m_players[1].AddToAccumulatedCards(CardsFree);
			//reset the card number in one run
			CardsFree = 0;
		}
		else
		{
			temp = temp_;
		}
	}
	//give the free cards in the game if no sanp at the last run
	std::cerr << "There are " << CardsFree << " free cards at last." << std::endl;

	return;
};