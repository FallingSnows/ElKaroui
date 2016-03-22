#pragma once
#ifndef CARD_H
#define CARD_H


class Card
{
	unsigned int m_face;
	unsigned int m_suit;
public:

	//getter and setter
	unsigned int GetFaceValue() const;
	unsigned int SetFaceValue(unsigned int);

	unsigned int GetSuitValue() const;
	unsigned int SetSuitValue(unsigned int);
};


#endif // !CARD_H

