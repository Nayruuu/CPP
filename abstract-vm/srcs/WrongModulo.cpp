/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongModulo.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:18:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/09 17:55:41 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongModulo.hpp"

WrongModulo::WrongModulo(std::string const & msg) throw() : AException(msg)
{
	return ;
}

WrongModulo::WrongModulo(WrongModulo const & src) throw() : AException(src)
{
	return ;
}

WrongModulo::~WrongModulo(void) throw()
{
	return ;
}

const char		*WrongModulo::what() const throw()
{
	return ("\033[31mCan't do modulo with floating values !\033[0m");
}
