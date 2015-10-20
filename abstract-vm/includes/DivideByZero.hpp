/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DivideByZero.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:15:59 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/06 21:15:57 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIVIDEBYZERO_HPP
# define DIVIDEBYZERO_HPP

#include "AException.hpp"

class						DivideByZero : public AException
{
	private:
							DivideByZero(void);
		DivideByZero		&operator=(DivideByZero const & src);

	public:
							DivideByZero(std::string const & msg) throw();
							DivideByZero(DivideByZero const & src) throw();
		virtual				~DivideByZero(void) throw();
		virtual const char	*what() const throw();
};

#endif
