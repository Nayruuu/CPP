/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexerException.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:15:59 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/09 16:41:33 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXEREXCEPTION_HPP
# define LEXEREXCEPTION_HPP

#include "AException.hpp"

class						LexerException : public AException
{
	private:
							LexerException(void);
		LexerException			&operator=(LexerException const & src);

	public:
							LexerException(std::string const & msg) throw();
							LexerException(LexerException const & src) throw();
		virtual				~LexerException(void) throw();
		virtual const char	*what() const throw();
};

#endif
