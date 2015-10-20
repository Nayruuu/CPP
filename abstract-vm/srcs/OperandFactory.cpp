/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:10:51 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/11 16:02:29 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.hpp"
#include "Operand.hpp"

//Constructor, Destructor

OperandFactory::OperandFactory(void)
{
	return ;
}

OperandFactory::~OperandFactory(void)
{
	return ;
}

//Creating Operands

IOperand const	*OperandFactory::createInt8(std::string const & value) const
{
	return(new Operand<char>(INT8, value));
}

IOperand const	*OperandFactory::createInt16(std::string const & value) const
{
	return (new Operand<short>(INT16, value));
}

IOperand const	*OperandFactory::createInt32(std::string const & value) const
{
	return (new Operand<int>(INT32, value));
}

IOperand const	*OperandFactory::createFloat(std::string const & value) const
{
	return (new Operand<float>(FLOAT, value));
}

IOperand const	*OperandFactory::createDouble(std::string const & value) const
{
	return (new Operand<double>(DOUBLE, value));
}

IOperand const	*OperandFactory::createOperand(eOperandType type, std::string const & value) const
{
	IOperand const *(OperandFactory::*ptr[5])(std::string const & value) const =
	{
		&OperandFactory::createInt8,
		&OperandFactory::createInt16,
		&OperandFactory::createInt32,
		&OperandFactory::createFloat,
		&OperandFactory::createDouble
	};
	return ((this->*(ptr[type]))(value));
}
