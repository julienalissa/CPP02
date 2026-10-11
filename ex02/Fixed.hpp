# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed(void);

	Fixed(const int value);
	Fixed(const float value);

// 4 arithmetic operators
	Fixed	operator*(const Fixed &other);
	Fixed	operator/(const Fixed &other);
	Fixed	operator+(const Fixed &other);
	Fixed	operator-(const Fixed &other);

	// The 6 comparison
	bool	operator>(const Fixed &other)const;
	bool	Fixed::operator<(const Fixed &other)const;
	bool	Fixed::operator>=(const Fixed &other)const;
	bool	Fixed::operator<=(const Fixed &other)const;
	bool	Fixed::operator==(const Fixed &other)const;
	bool	Fixed::operator!=(const Fixed &other)const;

	//The 4 increment/decrement

	

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);



#endif
