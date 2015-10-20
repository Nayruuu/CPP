/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AException.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:03:39 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/09 16:56:34 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AEXCEPTION_HPP
# define AEXCEPTION_HPP

#include <exception>
#include <string>

class						AException : public std::exception
{
	protected:
		std::string			_msg;
							AException(void);
		AException			&operator=(AException const & src);

	public:
							AException(std::string const & _msg) throw();
							AException(AException const & src) throw();
		virtual				~AException(void) throw();
		virtual const char	*what() const throw() = 0;
		std::string			getMsg(void) const;
};

#endif
