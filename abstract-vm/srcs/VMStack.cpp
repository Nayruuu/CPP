/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VMStack.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 21:24:16 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/12 11:30:02 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VMStack.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstdarg>

//Constructor, Destructor

VMStack::VMStack(void)
{
	_exit = false;
	_isValid = false;
	_types["none"] = NONEE;
	_types["int8"] = INT8;
	_types["int16"] = INT16;
	_types["int32"] = INT32;
	_types["float"] = FLOAT;
	_types["double"] = DOUBLE;
	_functions["push"] = reinterpret_cast<func>(&VMStack::push);
	_functions["dump"] = reinterpret_cast<func>(&VMStack::dump);
	_functions["print"] = reinterpret_cast<func>(&VMStack::print);
	_functions["pop"] = reinterpret_cast<func>(&VMStack::pop);
	_functions["mod"] = reinterpret_cast<func>(&VMStack::mod);
	_functions["add"] = reinterpret_cast<func>(&VMStack::add);
	_functions["sub"] = reinterpret_cast<func>(&VMStack::sub);
	_functions["mul"] = reinterpret_cast<func>(&VMStack::mul);
	_functions["assert"] = reinterpret_cast<func>(&VMStack::assert);
	_functions["exit"] = reinterpret_cast<func>(&VMStack::exit);
	_functions["div"] = reinterpret_cast<func>(&VMStack::div);
	_functions["swap"] = reinterpret_cast<func>(&VMStack::swap);
	return ;
}

VMStack::~VMStack(void)
{
	return ;
}

//Getters/Setters

void		VMStack::setValid(void)
{
	this->_isValid = true;
}

void		VMStack::unsetValid(void)
{
	_isValid = false;
}

std::map<std::string, eOperandType>		VMStack::getTypes(void) const
{
	return (_types);
}

bool		VMStack::getExit(void) const
{
	return (_exit);
}

//Instructions

void		VMStack::run_command(const char * cmd, ...)
{
	if (strcmp(cmd, "assert") || strcmp(cmd, "push"))
	{
		va_list	ap;
		va_start(ap, cmd);
		const char * type;
		std::string value;

		type = va_arg(ap, const char *);
		value.assign(va_arg(ap, const char *));
		(*this.*(_functions.find(cmd)->second))(_types[type], value);
		va_end(ap);
	}
	else
		(*this.*(_functions.find(cmd)->second))(_types["none"], "none");
}

bool		VMStack::check_overflows(IOperand const *first, IOperand const *second, IOperand const *result)
{
	if (strtod(result->toString().c_str(), NULL) > operands[result->getType()].max)
	{
		_stack.push_front(second);
		_stack.push_front(first);
		delete result;
		setValid();
		return (true);
	}
	else
		return (false);
}

bool		VMStack::check_underflows(IOperand const *first, IOperand const *second, IOperand const *result)
{
	if (strtod(result->toString().c_str(), NULL) < operands[result->getType()].min)
	{
		_stack.push_front(second);
		_stack.push_front(first);
		delete result;
		setValid();
		return (true);
	}
	else
		return (false);
}

void		VMStack::swap(void) throw(NotEnoughNumbers)
{
	if (_stack.size() == 0)
		throw (NotEnoughNumbers("swap"));
	else
	{
		IOperand const *first;
		IOperand const *second;

		first = _stack.front();
		_stack.pop_front();
		second = _stack.front();
		_stack.pop_front();
		_stack.push_front(first);
		_stack.push_front(second);
	}
}

void		VMStack::push(eOperandType type, std::string const & value) throw (Overflow, Underflow)
{
	if (strtod(value.c_str(), NULL) > operands[type].max)
	{
		setValid();
		throw (Overflow(operands[type].type));
	}
	else if (strtod(value.c_str(), NULL) < operands[type].min)
	{
		setValid();
		throw (Underflow(operands[type].type));
	}
	_stack.push_front(_fact.createOperand(type, value));
}

void		VMStack::pop(void) throw(EmptyStack)
{
	if (_stack.size() == 0)
	{
		setValid();
		throw (EmptyStack("pop"));
	}
	else
		_stack.pop_front();
}

void		VMStack::dump(void) throw(NotEnoughNumbers)
{
	size_t	i = 0;

	if (_stack.size())
	{
		if (!_isValid)
		{
			while (i < _stack.size())
			{
				std::cout << _stack[i]->toString() << std::endl;
				i++;
			}
		}
	}
	else
	{
		setValid();
		throw (NotEnoughNumbers("print"));
	}
}

void		VMStack::add(void) throw(NotEnoughNumbers, Overflow, Underflow)
{
	if (_stack.size() < 2)
	{
		setValid();
		throw (NotEnoughNumbers("calculation"));
	}
	else
	{
		IOperand const	*_new;
		IOperand const 	*first;
		IOperand const	*second;
		IOperand const	*result;

		first = _stack.front();
		_stack.pop_front();
		second = _stack.front();
		_stack.pop_front();
		if (first->getPrecision() > second->getPrecision())
		{
			_new = _fact.createOperand(first->getType(), second->toString());
			result = *_new + *first;
			delete _new;
		}
		else
		{
			_new = _fact.createOperand(second->getType(), first->toString());
			result = *second + *_new;
			delete _new;
		}
		if (check_overflows(first, second, result))
			throw (Overflow(operands[result->getType()].type));
		else if (check_underflows(first, second,result))
			throw (Underflow(operands[result->getType()].type));
		delete first;
		delete second;
		_stack.push_front(result);
	}
}

void		VMStack::sub(void) throw(NotEnoughNumbers, Overflow, Underflow)
{
	if (_stack.size() < 2)
	{
		setValid();
		throw (NotEnoughNumbers("calculation"));
	}
	else
	{
		IOperand const	*_new;
		IOperand const 	*first;
		IOperand const	*second;
		IOperand const	*result;

		first = _stack.front();
		_stack.pop_front();
		second = _stack.front();
		_stack.pop_front();
		if (first->getPrecision() > second->getPrecision())
		{
			_new = _fact.createOperand(first->getType(), second->toString());
			result = *_new - *first;
			delete _new;
		}
		else
		{
			_new = _fact.createOperand(second->getType(), first->toString());
			result = *second - *_new;
			delete _new;
		}
		if (check_overflows(first, second, result))
			throw (Overflow(operands[result->getType()].type));
		else if (check_underflows(first, second,result))
			throw (Underflow(operands[result->getType()].type));
		delete first;
		delete second;
		_stack.push_front(result);
	}
}

void		VMStack::mul(void) throw(NotEnoughNumbers, Overflow, Underflow)
{
	if (_stack.size() < 2)
	{
		setValid();
		throw (NotEnoughNumbers("calculation"));
	}
	else
	{
		IOperand const	*_new;
		IOperand const 	*first;
		IOperand const	*second;
		IOperand const	*result;

		first = _stack.front();
		_stack.pop_front();
		second = _stack.front();
		_stack.pop_front();
		if (first->getPrecision() > second->getPrecision())
		{
			_new = _fact.createOperand(first->getType(), second->toString());
			result = *_new * *first;
			delete _new;
		}
		else
		{
			_new = _fact.createOperand(second->getType(), first->toString());
			result = *_new * *second;
			delete _new;
		}
		if (check_overflows(first, second, result))
			throw (Overflow(operands[result->getType()].type));
		else if (check_underflows(first, second,result))
			throw (Underflow(operands[result->getType()].type));
		delete first;
		delete second;
		_stack.push_front(result);
	}
}

void		VMStack::div(void) throw(NotEnoughNumbers, DivideByZero, Overflow, Underflow)
{
	if (_stack.size() < 2)
	{
		setValid();
		throw (NotEnoughNumbers("calculation"));
	}
	else
	{
		if (strtod(_stack[0]->toString().c_str(), NULL) == 0)
		{
			setValid();
			throw (DivideByZero("Division"));
		}
		else
		{
			IOperand const	*_new;
			IOperand const 	*first;
			IOperand const	*second;
			IOperand const	*result;

			first = _stack.front();
			_stack.pop_front();
			second = _stack.front();
			_stack.pop_front();
			if (first->getPrecision() > second->getPrecision())
			{
				_new = _fact.createOperand(first->getType(), second->toString());
				result = *_new / *first;
				delete _new;
			}
			else
			{
				_new = _fact.createOperand(second->getType(), first->toString());
				result = *second / *_new;
				delete _new;
			}
			if (check_overflows(first, second, result))
				throw (Overflow(operands[result->getType()].type));
			else if (check_underflows(first, second,result))
				throw (Underflow(operands[result->getType()].type));
			delete first;
			delete second;
			_stack.push_front(result);
		}
	}
}

void		VMStack::mod(void) throw(NotEnoughNumbers, DivideByZero, WrongModulo, Overflow, Underflow)
{
	if (_stack.size() < 2)
	{
		setValid();
		throw (NotEnoughNumbers("calculation"));
	}
	else
	{
		if (strtod(_stack[0]->toString().c_str(), NULL) == 0)
		{
			setValid();
			throw (DivideByZero("Modulo"));
		}
		else if (_stack[0]->getPrecision() > 2 || _stack[1]->getPrecision() > 2)
		{
			setValid();
			throw (WrongModulo("Modulo"));
		}
		else
		{
			IOperand const	*_new;
			IOperand const 	*first;
			IOperand const	*second;
			IOperand const	*result;

			first = _stack.front();
			_stack.pop_front();
			second = _stack.front();
			_stack.pop_front();
			if (first->getPrecision() > second->getPrecision())
			{
				_new = _fact.createOperand(first->getType(), second->toString());
				result = *_new % *first;
				delete _new;
			}
			else
			{
				_new = _fact.createOperand(second->getType(), first->toString());
				result = *second % *_new;
				delete _new;
			}
			if (check_overflows(first, second, result))
				throw (Overflow(operands[result->getType()].type));
			else if (check_underflows(first, second,result))
				throw (Underflow(operands[result->getType()].type));
			delete first;
			delete second;
			_stack.push_front(result);
		}
	}
}

void		VMStack::assert(eOperandType type, std::string const & value) throw(NotEqual)
{
	if (_stack[0]->getType() != type ||
			strtod(_stack[0]->toString().c_str(), NULL) != strtod(value.c_str(), NULL))
	{
		setValid();
		throw (NotEqual("assert"));
	}
}

void		VMStack::print(void) throw(NotCharValue, NotEnoughNumbers)
{
	if (_stack.size())
	{
		if (_stack[0]->getType() != INT8)
		{
			setValid();
			throw (NotCharValue("print"));
		}
		else if (!_isValid)
			std::cout << (static_cast<const Operand<char> *>(_stack[0]))->getValue() << std::endl;
	}
	else
	{
		setValid();
		throw (NotEnoughNumbers("printing"));
	}
}

void		VMStack::exit(void)
{
	_exit = true;
}
