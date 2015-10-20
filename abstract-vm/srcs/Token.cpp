/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:40:49 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/08 19:59:31 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Token.hpp"

Token::Token(void)
{
	return ;
}

Token::Token(Token const & src)
{
	*this = src;
}

Token::Token(eTokenType type, std::string const & token) : _type(type), _token(token)
{
	return ;
}

Token::~Token(void)
{
	return ;
}

Token				&Token::operator=(Token const & src)
{
	_type = src.getType();
	_token = src.getToken();
	return (*this);
}

eTokenType			Token::getType(void) const { return _type; }

std::string			Token::getToken(void) const { return _token;}
