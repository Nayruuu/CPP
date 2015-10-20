/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Overflow.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:18:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/11 13:27:43 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Overflow.hpp"

Overflow::Overflow(std::string const & msg) throw() : AException(msg)
{
	return ;
}

Overflow::Overflow(Overflow const & src) throw() : AException(src)
{
	return ;
}

Overflow::~Overflow(void) throw()
{
	return ;
}

const char		*Overflow::what() const throw()
{
	if (this->getMsg() == "Int8")
		return ("\033[31mInt8 : Overflow !\033[0m");
	else if (this->getMsg() == "Int16")
		return ("\033[31mInt16 : Overflow !\033[0m");
	else if (this->getMsg() == "Int32")
		return ("\033[31mInt32 : Overflow !\033[0m");
	else if (this->getMsg() == "Float")
		return ("\033[31mFloat : Overflow !\033[0m");
	else
		return ("\033[31mDouble : Overflow !\033[0m");
}
