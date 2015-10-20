/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EmptyStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:15:59 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/06 21:16:23 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMPTYSTACK_HPP
# define EMPTYSTACK_HPP

#include "AException.hpp"

class						EmptyStack : public AException
{
	private:
							EmptyStack(void);
		EmptyStack			&operator=(EmptyStack const & src);

	public:
							EmptyStack(std::string const & msg) throw();
							EmptyStack(EmptyStack const & src) throw();
		virtual				~EmptyStack(void) throw();
		virtual const char	*what() const throw();
};

#endif
