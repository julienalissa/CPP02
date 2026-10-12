#include "Fixed.hpp"

// 4 Orthodox Canonical

Fixed::Fixed(void) : _rawBits(0)
{

}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		int	bitsAfterCopy;

		bitsAfterCopy = other.getRawBits();
		this->_rawBits = bitsAfterCopy;
	}
	return (*this);
}

Fixed::~Fixed(void)
{

}

//extra constructor

Fixed::Fixed(const int value)
{
	int	valueRawBits;

	valueRawBits = value << _fractionalBits;
	this->_rawBits = valueRawBits;
}

Fixed::Fixed(const float value)
{
	float	valeurMultipliee;
	float	valeurArrondie;

	valeurMultipliee = value * 256.0f;
	valeurArrondie = roundf(valeurMultipliee);
	this->_rawBits = (int)valeurArrondie;
}

// get set RawBits

int	Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits(const int raw)
{
	this->_rawBits = raw;
}

// convert

float	Fixed::toFloat(void) const
{
	float	rawInFloat;
	float	resultatFloat;

	rawInFloat = (float)this->_rawBits;
	resultatFloat = rawInFloat / 256.0f;
	return (resultatFloat);
}

int	Fixed::toInt(void) const
{
	int	resInt;

	resInt = this->_rawBits >> _fractionalBits;
	return (resInt);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	float	valueDisplay;

	valueDisplay = fixed.toFloat();
	out << valueDisplay;
	return (out);
}

// 4 arithmetic operators

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed x;
	long	multi = 0;

	multi = (long)this->_rawBits * (long)other.getRawBits();
	multi = multi >> _fractionalBits;
	x.setRawBits((int)multi);
	return (x);
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed x;
	long	multi = 0;

	multi = (long)this->_rawBits << _fractionalBits;
	multi = multi / (long)other.getRawBits();
	x.setRawBits((int)multi);
	return (x);
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed x;
	long	multi = 0;

	multi = (long)this->_rawBits + (long)other.getRawBits();
	x.setRawBits((int)multi);
	return (x);
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed x;
	long	multi = 0;

	multi = (long)this->_rawBits - (long)other.getRawBits();
	x.setRawBits((int)multi);
	return (x);
}

// The 6 comparison

bool	Fixed::operator>(const Fixed &other)const
{
	if (this->_rawBits > other._rawBits)
		return (1);
	else
		return (0);
}

bool	Fixed::operator<(const Fixed &other)const
{
	if (this->_rawBits < other._rawBits)
		return (1);
	else
		return (0);
}

bool	Fixed::operator>=(const Fixed &other)const
{
	if (this->_rawBits >= other._rawBits)
		return (1);
	else
		return (0);
}

bool	Fixed::operator<=(const Fixed &other)const
{
	if (this->_rawBits <= other._rawBits)
		return (1);
	else
		return (0);
}

bool	Fixed::operator==(const Fixed &other)const
{
	if (this->_rawBits == other._rawBits)
		return (1);
	else
		return (0);
}

bool	Fixed::operator!=(const Fixed &other)const
{
	if (this->_rawBits != other._rawBits)
		return (1);
	else
		return (0);
}

//The 4 increment/decrement

Fixed &Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_rawBits++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_rawBits--;
	return (tmp);
}

//4 min max

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return(a);
	else
		return (b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return(a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return(a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return(a);
	else
		return (b);
}
