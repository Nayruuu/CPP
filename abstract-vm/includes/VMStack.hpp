/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VMStack.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:52:18 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/11 17:51:11 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VMSTACK_HPP
# define VMSTACK_HPP

#include <deque>
#include <map>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "OperandFactory.hpp"
#include "EmptyStack.hpp"
#include "NotEnoughNumbers.hpp"
#include "DivideByZero.hpp"
#include "WrongModulo.hpp"
#include "NotEqual.hpp"
#include "NotCharValue.hpp"
#include "NoExitCommand.hpp"

class									VMStack
{
	public:
											VMStack(void);
											~VMStack(void);

		void								setValid(void);
		void								unsetValid(void);
		bool								getExit(void) const;
		std::map<std::string, eOperandType>	getTypes(void) const;
		void								run_command(const char * cmd, ...);

	private:
		bool								_isValid;
		bool								_exit;
		std::deque<const IOperand *>		_stack;
		OperandFactory						_fact;

		typedef void (VMStack::*func)(eOperandType, std::string const &);
		std::map<std::string, func>			_functions;
		std::map<std::string, eOperandType>	_types;

		//Security
		bool								check_overflows(IOperand const *first, IOperand const *second,
											IOperand const *result);
		bool								check_underflows(IOperand const *first, IOperand const *second,
											IOperand const *result);

		//Command Functions
		void								push(eOperandType type, std::string const & value)
											throw (Overflow, Underflow);
		void								pop(void) throw(EmptyStack);
		void								dump(void) throw(NotEnoughNumbers);
		void								assert(eOperandType type, std::string const & value) throw(NotEqual);
		void								add(void) throw(NotEnoughNumbers, Overflow, Underflow);
		void								sub(void) throw(NotEnoughNumbers, Overflow, Underflow);
		void								mul(void) throw(NotEnoughNumbers, Overflow, Underflow);
		void								div(void) throw(NotEnoughNumbers, DivideByZero, Overflow, Underflow);
		void								mod(void) throw(NotEnoughNumbers, DivideByZero, WrongModulo, Overflow,
											Underflow);
		void								print(void) throw(NotCharValue, NotEnoughNumbers);
		void								swap(void) throw(NotEnoughNumbers);
		void								exit(void);

											VMStack(VMStack const & src);
		VMStack								&operator=(VMStack const & src);
};


#endif
