/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:35:51 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/11 16:19:51 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN
# define TOKEN

#include <string>

enum eTokenType
{
	NONE,
	ERROR,
	COMM,
	INSTR,
	VALUE,
	CONST
};

class					Token
{
	private:
		eTokenType		_type;
		std::string		_token;
						Token(void);
	
	public:
						~Token(void);
						Token(Token const & src);
						Token(eTokenType type, std::string const & token);	
		Token			&operator=(Token const & src);
						
		eTokenType		getType(void) const;
		std::string		getToken(void) const;
};

#endif
