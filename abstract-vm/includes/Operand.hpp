/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 18:58:31 by sde-toda          #+#    #+#             */
/*   Updated: 2015/10/20 17:58:03 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

#include <cfloat>
#include <climits>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include "IOperand.hpp"
#include "Overflow.hpp"
#include "Underflow.hpp"
#include "OperandFactory.hpp"

# define FLOAT_MIN (-FLT_MAX)
# define DOUBLE_MIN (-DBL_MAX)

typedef struct			s_operand
{
	std::string			type;
	double				min;
	double				max;
	int					precision;
}						t_operand;

t_operand const			operands[5] =
{
	{"Int8", SCHAR_MIN, SCHAR_MAX, 0},
	{"Int16", SHRT_MIN, SHRT_MAX, 1},
	{"Int32", INT_MIN, INT_MAX, 2},
	{"Float", FLOAT_MIN, FLT_MAX, 3},
	{"Double", DOUBLE_MIN, DBL_MAX, 4}
};

template<typename T>
class							Operand: public IOperand
{
	private:			
		T						_value;
		std::string				_representation;
		eOperandType			_type;
		int						_precision;
		OperandFactory			fact;

	public:

		//Constructor, Destructor
									Operand(eOperandType type, std::string const & val)
									{
										double value = strtod(val.c_str(), NULL);
										
										_representation = val;
										if (type == INT8 || type == INT16 || type == INT32)
											_value = static_cast<int>(value);
										else if (type == FLOAT)
											_value = static_cast<float>(value);
										else
											_value = value;
										_precision = operands[type].precision;
										_type = type;
									};
									Operand(Operand const & src) { this = src; };
		Operand						&operator=(Operand const & src)
		{
			_value = src.getValue();
			_type = src.getType();
			_representation = src.toString();
			_precision = src.getPrecision();
			return (*this);
		}
		virtual 					~Operand(void){ };

		//Getters
		T							getValue(void) const { return _value; };
		virtual	eOperandType		getType(void) const { return _type; };
		virtual	int					getPrecision(void) const { return _precision; };
		virtual std::string const	&toString(void) const { return _representation; };

		//Operations
		double calc(std::string const & s1, std::string const & s2, int prec, char op) const
		{
			double					val1 = strtod(s1.c_str(), NULL);
			double					val2 = strtod(s2.c_str(), NULL);
			double					calc;

			if (op == '-')
				calc =  (val1 - val2);
			else if (op == '*')
				calc = (val1 * val2);
			else if (op == '/' && prec <= 2)
				calc =  static_cast<double>((static_cast<int>(val1) / static_cast<int>(val2)));
			else if (op == '/')
				calc = val1 / val2;
			else if (prec <= 2 && op == '%')
				calc =  static_cast<double>((static_cast<int>(val1) % static_cast<int>(val2)));
			else
				calc =  (val1 + val2);
			return (calc);
		};
		virtual IOperand const		*operator+(IOperand const & rhs) const
		{
			std::stringstream		result;
			
			if (this->getPrecision() > 2)
				result << std::fixed << std::setprecision(2)
				<< calc(this->toString(), rhs.toString(), this->getPrecision(), '+');
			else
				result << calc(this->toString(), rhs.toString(), this->getPrecision(), '+');
			return (fact.createOperand(this->getType(), result.str()));
		};
		virtual IOperand const		*operator-(IOperand const & rhs) const
		{
			std::stringstream		result;
			
			if (this->getPrecision() > 2)
				result << std::fixed << std::setprecision(2)
				<< calc(this->toString(), rhs.toString(), this->getPrecision(), '-');
			else
				result << calc(this->toString(), rhs.toString(), this->getPrecision(), '-');
			return (fact.createOperand(this->getType(), result.str()));			
		};
		virtual IOperand const		*operator*(IOperand const & rhs) const
		{
			std::stringstream		result;
			
			if (this->getPrecision() > 2)
				result << std::fixed << std::setprecision(2)
				<< calc(this->toString(), rhs.toString(), this->getPrecision(), '*');
			else
				result << calc(this->toString(), rhs.toString(), this->getPrecision(), '*');
			return (fact.createOperand(this->getType(), result.str()));		
		};
		virtual IOperand const		*operator/(IOperand const & rhs) const
		{
			std::stringstream		result;
			
			if (this->getPrecision() > 2)
				result << std::fixed << std::setprecision(2)
				<< calc(this->toString(), rhs.toString(), this->getPrecision(), '/');
			else
				result << calc(this->toString(), rhs.toString(), this->getPrecision(), '/');
			return (fact.createOperand(this->getType(), result.str()));			
		};
		virtual IOperand const		*operator%(IOperand const & rhs) const
		{
			std::stringstream		result;
			
			if (this->getPrecision() > 2)
				result << std::fixed << std::setprecision(2)
				<< calc(this->toString(), rhs.toString(), this->getPrecision(), '%');
			else
				result << calc(this->toString(), rhs.toString(), this->getPrecision(), '%');
			return (fact.createOperand(this->getType(), result.str()));			
		};
};

#endif
