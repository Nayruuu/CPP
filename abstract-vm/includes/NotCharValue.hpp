/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotCharValue.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:15:59 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/06 21:19:12 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTCHARVALUE_HPP
# define NOTCHARVALUE_HPP

#include "AException.hpp"

class						NotCharValue : public AException
{
	private:
							NotCharValue(void);
		NotCharValue		&operator=(NotCharValue const & src);

	public:
							NotCharValue(std::string const & msg) throw();
							NotCharValue(NotCharValue const & src) throw();
		virtual				~NotCharValue(void) throw();
		virtual const char	*what() const throw();
};

#endif
