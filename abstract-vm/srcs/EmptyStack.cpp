/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EmptyStack.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:18:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/09 17:52:12 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EmptyStack.hpp"

EmptyStack::EmptyStack(std::string const & msg) throw() : AException(msg)
{
	return ;
}

EmptyStack::EmptyStack(EmptyStack const & src) throw() : AException(src)
{
	return ;
}

EmptyStack::~EmptyStack(void) throw()
{
	return ;
}

const char		*EmptyStack::what() const throw()
{
	return ("\033[31mThe stack is empty !\033[0m");
}
