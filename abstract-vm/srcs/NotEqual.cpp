/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotEqual.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:18:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/09 17:53:33 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NotEqual.hpp"

NotEqual::NotEqual(std::string const & msg) throw() : AException(msg)
{
	return ;
}

NotEqual::NotEqual(NotEqual const & src) throw() : AException(src)
{
	return ;
}

NotEqual::~NotEqual(void) throw()
{
	return ;
}

const char		*NotEqual::what() const throw()
{
	return ("\033[31mValue on top of the stack and value passed are not equals\033[0m");
}
