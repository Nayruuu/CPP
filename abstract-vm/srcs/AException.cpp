/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AException.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:13:52 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/09 16:56:19 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AException.hpp"

AException::AException(std::string const & msg) throw()
{
	this->_msg = msg;
	return ;
}

AException::AException(AException const & src) throw()
{
	_msg = src.getMsg();
}

AException::~AException(void) throw()
{
	return ;
}

std::string		AException::getMsg(void) const
{
	return (_msg);
}
