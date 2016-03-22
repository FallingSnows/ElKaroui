#include "Card.h"

unsigned int Card::GetFaceValue() const
{
	return m_face;
};

unsigned int Card::SetFaceValue(unsigned int faceValue)
{
	return m_face = faceValue;
};

unsigned int Card::GetSuitValue() const
{
	return m_suit;
};

unsigned int Card::SetSuitValue(unsigned int suitValue)
{
	return m_suit = suitValue;
};
