/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotCharValue.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:18:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/09 17:53:01 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NotCharValue.hpp"

NotCharValue::NotCharValue(std::string const & msg) throw() : AException(msg)
{
	return ;
}

NotCharValue::NotCharValue(NotCharValue const & src) throw() : AException(src)
{
	return ;
}

NotCharValue::~NotCharValue(void) throw()
{
	return ;
}

const char		*NotCharValue::what() const throw()
{
	return ("\033[31mValue on top of the stack is not printable ! Not a 8-bit integer\033[0m");
}
