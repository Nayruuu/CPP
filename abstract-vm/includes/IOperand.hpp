/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 18:39:22 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/10 17:56:14 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

#include <iostream>

enum	eOperandType
{
		INT8=0,
		INT16,
		INT32,
		FLOAT,
		DOUBLE,
		NONEE
};

class								IOperand
{
	public:

		virtual int					getPrecision(void) const = 0;
		virtual eOperandType		getType(void) const = 0;
		virtual IOperand const		*operator+(IOperand const & rhs) const = 0;	//Sum
		virtual IOperand const		*operator-(IOperand const & rhs) const = 0;	//Difference
		virtual IOperand const		*operator*(IOperand const & rhs) const = 0;	//Product
		virtual IOperand const		*operator/(IOperand const & rhs) const = 0;	//Quotient
		virtual IOperand const		*operator%(IOperand const & rhs) const = 0;	//Modulo

		virtual std::string const	&toString(void) const = 0;
		virtual						~IOperand(void) {};
};

#endif
