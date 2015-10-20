/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NoExitCommand.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:18:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/09 17:52:45 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NoExitCommand.hpp"

NoExitCommand::NoExitCommand(std::string const & msg) throw() : AException(msg)
{
	return ;
}

NoExitCommand::NoExitCommand(NoExitCommand const & src) throw() : AException(src)
{
	return ;
}

NoExitCommand::~NoExitCommand(void) throw()
{
	return ;
}

const char		*NoExitCommand::what() const throw()
{
	return ("\033[31mExit command not found\033[0m");
}
