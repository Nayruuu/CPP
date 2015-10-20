/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Overflow.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:15:59 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/06 19:04:42 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OVERFLOW_HPP
# define OVERFLOW_HPP

#include "AException.hpp"

class						Overflow : public AException
{
	private:
							Overflow(void);
		Overflow			&operator=(Overflow const & src);

	public:
							Overflow(std::string const & msg) throw();
							Overflow(Overflow const & src) throw();
		virtual				~Overflow(void) throw();
		virtual const char	*what() const throw();
};

#endif
