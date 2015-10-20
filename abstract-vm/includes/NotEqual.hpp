/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotEqual.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:15:59 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/06 21:15:38 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTEQUAL_HPP
# define NOTEQUAL_HPP

#include "AException.hpp"

class						NotEqual : public AException
{
	private:
							NotEqual(void);
		NotEqual			&operator=(NotEqual const & src);

	public:
							NotEqual(std::string const & msg) throw();
							NotEqual(NotEqual const & src) throw();
		virtual				~NotEqual(void) throw();
		virtual const char	*what() const throw();
};

#endif
