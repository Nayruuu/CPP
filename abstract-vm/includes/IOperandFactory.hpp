/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperandFactory.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 19:52:40 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/08 11:36:01 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERANDFACTORY_HPP
# define IOPERANDFACTORY_HPP

#include "IOperand.hpp"

class							IOperandFactory
{
	public:
		virtual					~IOperandFactory() {};
		virtual IOperand const	*createOperand(eOperandType type, std::string const & value) const = 0;
	
	private:
		virtual IOperand const	*createInt8(std::string const & value) const = 0;
		virtual	IOperand const	*createInt16(std::string const & value) const = 0;
		virtual IOperand const	*createInt32(std::string const & value) const = 0;
		virtual IOperand const	*createFloat(std::string const & value) const = 0;
		virtual IOperand const	*createDouble(std::string const & value) const = 0;
};

#endif
