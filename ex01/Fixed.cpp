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
		int	bitsAfterCopy;

		bitsAfterCopy = other.getRawBits();
		this->_rawBits = bitsAfterCopy;
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

	int	valueRawBits;

	valueRawBits = value << _fractionalBits; 
	this->_rawBits = valueRawBits;
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
