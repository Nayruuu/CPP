/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DivideByZero.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:18:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/09 17:52:00 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DivideByZero.hpp"

DivideByZero::DivideByZero(std::string const & msg) throw() : AException(msg)
{
	return ;
}

DivideByZero::DivideByZero(DivideByZero const & src) throw() : AException(src)
{
	return ;
}

DivideByZero::~DivideByZero(void) throw()
{
	return ;
}

const char		*DivideByZero::what() const throw()
{
	if (this->getMsg() == "Division")
		return ("\033[31mCan't divide by zero !\033[0m");
	else
		return ("\033[31mCan't do modulo with zero !\033[0m");
}
