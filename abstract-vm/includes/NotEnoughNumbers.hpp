/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotEnoughNumbers.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:15:59 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/06 21:16:14 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTENOUGHNUMBERS_HPP
# define NOTENOUGHNUMBERS_HPP

#include "AException.hpp"

class						NotEnoughNumbers : public AException
{
	private:
							NotEnoughNumbers(void);
		NotEnoughNumbers			&operator=(NotEnoughNumbers const & src);

	public:
							NotEnoughNumbers(std::string const & msg) throw();
							NotEnoughNumbers(NotEnoughNumbers const & src) throw();
		virtual				~NotEnoughNumbers(void) throw();
		virtual const char	*what() const throw();
};

#endif
