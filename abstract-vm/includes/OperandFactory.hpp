/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 20:00:00 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/07 23:10:41 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFACTORY_HPP
# define OPERANDFACTORY_HPP

#include <deque>
#include "IOperandFactory.hpp"

class							OperandFactory : public IOperandFactory
{
	private:
								OperandFactory(OperandFactory const & src);
		OperandFactory			&operator=(OperandFactory const & src);
		virtual IOperand const	*createInt8(std::string const & value) const;
		virtual IOperand const	*createInt16(std::string const & value) const;
		virtual IOperand const	*createInt32(std::string const & value) const;
		virtual IOperand const	*createFloat(std::string const & value) const;
		virtual IOperand const	*createDouble(std::string const & value) const;

	public:
								OperandFactory(void);
		virtual					~OperandFactory(void);
		virtual IOperand const	*createOperand(eOperandType type, std::string const & value) const;
};

#endif
