/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongModulo.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:15:59 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/08 12:53:18 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGMODULO_HPP
# define WRONGMODULO_HPP

#include "AException.hpp"

class						WrongModulo : public AException
{
	private:
							WrongModulo(void);
		WrongModulo			&operator=(WrongModulo const & src);

	public:
							WrongModulo(std::string const & msg) throw();
							WrongModulo(WrongModulo const & src) throw();
		virtual				~WrongModulo(void) throw();
		virtual const char	*what() const throw();
};

#endif
