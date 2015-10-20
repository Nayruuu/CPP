/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotEnoughNumbers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:18:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/10 15:34:24 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NotEnoughNumbers.hpp"

NotEnoughNumbers::NotEnoughNumbers(std::string const & msg) throw() : AException(msg)
{
	return ;
}

NotEnoughNumbers::NotEnoughNumbers(NotEnoughNumbers const & src) throw() : AException(src)
{
	return ;
}

NotEnoughNumbers::~NotEnoughNumbers(void) throw()
{
	return ;
}

const char		*NotEnoughNumbers::what() const throw()
{
	if (_msg == "calculation")
		return ("\033[31mNot enough numbers to do calculation !\033[0m");
	else
		return ("\033[31mNot enough number !\033[0m");
}
