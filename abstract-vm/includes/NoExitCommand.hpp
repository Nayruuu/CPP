/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NoExitCommand.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:15:59 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/06 21:22:27 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOEXITCOMMAND_HPP
# define NOEXITCOMMAND_HPP

#include "AException.hpp"

class						NoExitCommand : public AException
{
	private:
							NoExitCommand(void);
		NoExitCommand			&operator=(NoExitCommand const & src);

	public:
							NoExitCommand(std::string const & msg) throw();
							NoExitCommand(NoExitCommand const & src) throw();
		virtual				~NoExitCommand(void) throw();
		virtual const char	*what() const throw();
};

#endif
