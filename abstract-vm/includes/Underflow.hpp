/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Underflow.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:15:59 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/06 19:07:46 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNDERFLOW_HPP
# define UNDERFLOW_HPP

#include "AException.hpp"

class						Underflow : public AException
{
	private:
							Underflow(void);
		Underflow			&operator=(Underflow const & src);

	public:
							Underflow(std::string const & msg) throw();
							Underflow(Underflow const & src) throw();
		virtual				~Underflow(void) throw();
		virtual const char	*what() const throw();
};

#endif
