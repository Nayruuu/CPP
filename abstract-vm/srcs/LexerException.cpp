/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexerException.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:18:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/09 16:57:06 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LexerException.hpp"

LexerException::LexerException(std::string const & msg) throw() : AException(msg)
{
	return ;
}

LexerException::LexerException(LexerException const & src) throw() : AException(src)
{
	return ;
}

LexerException::~LexerException(void) throw()
{
	return ;
}

const char		*LexerException::what() const throw()
{
	return (_msg.c_str());
}
