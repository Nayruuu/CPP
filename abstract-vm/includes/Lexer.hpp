/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 18:29:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/09 16:55:47 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ########################################################################## */
/*																			  */
/* S := INSTR [SEP INSTR]* #												  */
/*																			  */
/* INSTR :=																	  */
/* 	  push VALUE															  */
/* 	| pop																	  */
/* 	| dump																	  */
/* 	| assert VALUE															  */
/* 	| add 																	  */
/*	| sub																	  */
/*	| mul																	  */
/*	| div																	  */
/*	| mod																	  */
/*	| print																	  */
/*	| exit																	  */
/*																			  */
/* VALUE :=																	  */
/*	  int8(N)																  */
/*	| int16(N)																  */
/*	| int32(N)																  */
/*	| float(Z)																  */
/*	| double(Z)																  */
/*																			  */
/* N := [-]?[0..9]+															  */
/*																		      */
/* Z := [-]?[0..9]+.[0..9]+													  */
/*																			  */
/* SEP := '\n'+																  */
/*																			  */
/* COM := ';'																  */
/*																			  */
/* ########################################################################## */

#ifndef LEXER_HPP
# define LEXER_HPP

#include <deque>
#include <string>
#include "Token.hpp"

typedef std::string::const_iterator lexer_iterator;

class Lexer
{
	private:
		std::deque<std::string>									instructions;
		std::deque<std::string>									values;
																Lexer(Lexer const & src);
		Lexer													&operator=(Lexer const & src);
	
	public:
																Lexer(void);
																~Lexer(void);
		void													getInstructions(void);
		void													getValues(void);

		bool inline												isZValue(lexer_iterator * s) const;
		bool inline												isNValue(lexer_iterator *s) const;
		bool inline												isValue(lexer_iterator *s) const;
		bool inline												isInstr(lexer_iterator *s) const;
		bool inline												isEndOfLine(lexer_iterator *s) const;
		bool inline												isChar(char const & c) const;
		bool inline												isSpace(char const & c) const;
		bool inline												isNum(char const & c) const;
		bool inline												isCommentary(char const & c) const;
		std::deque<Token>										tokenize(std::string const & s) const;
};

#endif
