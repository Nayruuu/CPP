/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Underflow.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:18:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/11 13:27:46 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Underflow.hpp"

Underflow::Underflow(std::string const & msg) throw() : AException(msg)
{
	return ;
}

Underflow::Underflow(Underflow const & src) throw() : AException(src)
{
	return ;
}

Underflow::~Underflow(void) throw()
{
	return ;
}

const char		*Underflow::what() const throw()
{
	if (this->getMsg() == "Int8")
		return ("\033[31mInt8 : Underflow !\033[0m");
	else if (this->getMsg() == "Int16")
		return ("\033[31mInt16 : Underflow !\033[0m");
	else if (this->getMsg() == "Int32")
		return ("\033[31mInt32 : Underflow !\033[0m");
	else if (this->getMsg() == "Float")
		return ("\033[31mFloat : Underflow !\033[0m");
	else
		return ("\033[31mDouble : Underflow !\033[0m");
}
