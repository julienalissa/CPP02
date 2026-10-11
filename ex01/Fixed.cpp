#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		int	bitsApresCopie;

		bitsApresCopie = other.getRawBits();
		this->_rawBits = bitsApresCopie;
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;

	int	valeurDecalee;

	valeurDecalee = value << _fractionalBits;
	this->_rawBits = valeurDecalee;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;

	float	valeurMultipliee;
	float	valeurArrondie;

	valeurMultipliee = value * 256.0f;
	valeurArrondie = roundf(valeurMultipliee);
	this->_rawBits = (int)valeurArrondie;
}

int	Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits(const int raw)
{
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	float	rawEnFloat;
	float	resultatFloat;

	rawEnFloat = (float)this->_rawBits;
	resultatFloat = rawEnFloat / 256.0f;
	return (resultatFloat);
}

int	Fixed::toInt(void) const
{
	int	resultatInt;

	resultatInt = this->_rawBits >> _fractionalBits;
	return (resultatInt);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	float	valeurAffichable;

	valeurAffichable = fixed.toFloat();
	out << valeurAffichable;
	return (out);
}
