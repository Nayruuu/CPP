/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:01:03 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/12 11:34:17 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include <stdlib.h>
#include <iostream>

//Constructor, Destructor

Lexer::Lexer(void)
{
	getInstructions();
	getValues();
}

Lexer::~Lexer(void)
{
	return ;
}

//Initializing lexer

void				Lexer::getInstructions(void)
{
	instructions.push_front("push");
	instructions.push_front("pop");
	instructions.push_front("dump");
	instructions.push_front("assert");
	instructions.push_front("add");
	instructions.push_front("sub");
	instructions.push_front("mul");
	instructions.push_front("div");
	instructions.push_front("mod");
	instructions.push_front("print");
	instructions.push_front("exit");
	instructions.push_front("swap");
}

void				Lexer::getValues(void)
{
	values.push_front("int8(");
	values.push_front("int16(");
	values.push_front("int32(");
	values.push_front("float(");
	values.push_front("double(");
}

//Verification

bool inline						Lexer::isEndOfLine(lexer_iterator *it) const
{
	while (isSpace((*it[0])))
		(*it)++;
	if (!(*it[0]) || (*it[0] == ';'))
		return (true);
	else
		return (false);
}

bool inline						Lexer::isChar(char const & c) const
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (true);
	else
		return (false);
}

bool inline						Lexer::isSpace(char const & c) const
{
	if (c == ' ' || c == '\t')
		return (true);
	else
		return (false);
}

bool inline						Lexer::isNum(char const & c) const
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

bool inline						Lexer::isCommentary(char const & c) const
{
	if (c == ';')
		return (true);
	else
		return (false);
}

bool inline						Lexer::isInstr(lexer_iterator *it) const
{
	size_t						i = 0;
	std::string					string;

	while (isChar((*it[0])))
	{
		string.push_back((*it[0]));
		(*it)++;
	}
	while (i < instructions.size())
	{
		if (string == (instructions[i]))
			return (true);
		i++;
	}
	return (false);
}

bool inline						Lexer::isNValue(lexer_iterator *it) const
{
	bool						Num = false;

	while (isSpace((*it[0])))
		(*it)++;
	if ((*it[0]) == '-')
		(*it)++;
	while (isNum((*it[0])))
	{
		Num = true;
		(*it)++;
	}
	if (!Num)
		return (false);
	while (isSpace((*it[0])))
		(*it)++;
	if ((*it)[0] != ')')
		return (false);
	return (true);
}

bool inline						Lexer::isZValue(lexer_iterator *it) const
{
	bool						Num = false;

	while (isSpace((*it[0])))
		(*it)++;
	if ((*it[0]) == '-')
		(*it)++;
	while (isNum((*it[0])))
	{
		Num = true;
		(*it)++;
	}
	if (!Num)
		return (false);
	if ((*it[0]) == '.')
		(*it)++;
	else
		return (false);
	Num = false;
	while (isNum((*it[0])))
	{
		Num = true;
		(*it)++;
	}
	if (!Num)
		return (false);
	while (isSpace((*it[0])))
		(*it)++;
	if ((*it)[0] != ')')
		return (false);
	return (true);
}

bool inline						Lexer::isValue(lexer_iterator *it) const
{
	size_t						i = 0;
	std::string					string;

	while (isChar((*it[0])) || isNum((*it[0])))
	{
		string.push_back((*it[0]));
		(*it)++;
	}
	if ((*it)[0] == '(')
		string.push_back((*it[0]));
	else
		return (false);
	while (i < values.size())
	{
		if (string == values[i])
			return (true);
		i++;
	}
	return (false);
}

std::deque<Token> 				Lexer::tokenize(std::string const & s) const
{
	size_t						start;
	size_t						start2;
	int							start3;
	std::deque<Token>			tokens;
	lexer_iterator				it = s.cbegin();
	lexer_iterator				it2 = s.begin();
	lexer_iterator				it3 = s.begin();
	lexer_iterator				it4 = s.begin();
	
	while (isSpace(*it))
		it++;
	if (!(*it))
	{
		tokens.clear();
		tokens.push_front(Token(NONE, "\033[31mNo instructions\033[0m"));
	}
	else if (isCommentary(*it))
	{
		it++;
		if (isCommentary(*it))
		{
			it2 = it;
			start = std::distance(s.begin(), it) - 1;
			it++;
			while (isSpace(*it))
				it++;
			if (!(*it))
			{
				tokens.push_front(Token(INSTR, "exit"));
				return (tokens);
			}
			else
			{
				tokens.push_front(Token(ERROR, "\033[31mBad end of program \"" +
				s.substr(start, std::distance(it2, s.end()) + 1) + "\" : end of program must be \";;\"\033[0m"));
			}
			return (tokens);
		}
		tokens.push_front(Token(COMM, s));
		return (tokens);
	}
	while (isSpace(*it))
		it++;
	if (isChar(*it))
	{
		it2 = it;
		start = std::distance(s.begin(), it2);	
		if (isInstr(&it))
		{
			tokens.push_front(Token(INSTR, s.substr(start, std::distance(it2, it))));
			if (tokens[0].getToken() == "assert" || tokens[0].getToken() == "push")
			{
				while (isSpace(*it))
					it++;
				if (isChar(*it))
				{
					it3 = it;
					start2 = std::distance(s.begin(), it3);
					if (isValue(&it))
					{
						tokens.push_back(Token(VALUE, s.substr(start2, std::distance(it3, it))));
						it++;
						it4 = it;
						start3 = std::distance(s.begin(), it4);
						if (tokens[1].getToken() == "int8" || tokens[1].getToken() == "int16" || 
							tokens[1].getToken() == "int32")
						{
							if (isNValue(&it))
								tokens.push_back(Token(CONST, s.substr(start3, std::distance(it4, it))));
							else
							{
								tokens.clear();
								tokens.push_front(Token(ERROR, "\033[31mSomething wrong with value \"" +
								s.substr(start, s.size()) + "\" : invalid value or missing end bracket\033[0m"));
							}
						}
						else
						{
							if (isZValue(&it))
								tokens.push_back(Token(CONST, s.substr(start3, std::distance(it4, it))));
							else
							{
								tokens.clear();
								tokens.push_front(Token(ERROR, "\033[31mSomething wront with value \"" +
								s.substr(start, s.size()) + "\" : invalid value or missing end bracket\033[0m"));
							}
						}
						it++;
						if (isEndOfLine(&it))
							return (tokens);
						else
						{
							tokens.clear();
							tokens.push_front(Token(ERROR, "\033[31mCommand line \"" +
							s.substr(start, s.size()) + "\" : invalid\033[0m"));
						}

					}
					else
					{
						tokens.clear();
						tokens.push_front(Token(ERROR, "\033[31mSomething wrong with value \"" + 
						s.substr(start, s.size()) + "\" : missing open bracket or invalid value\033[0m")); 
					}
				}
				else
				{
					tokens.clear();
					tokens.push_front(Token(ERROR, "\033[31mSomething wrong with instruction \"" + 
					s.substr(start, s.size()) + "\" : invalid value : [int8, int16, int32, float, double]\033[0m")); 
				}
			}
			if (isEndOfLine(&it))
				return (tokens);
			else
			{
				tokens.clear();
				tokens.push_front(Token(ERROR, "\033[31mCommand line \"" +
				s.substr(start, s.size()) + "\" : invalid\033[0m"));
			}
		}
		else
		{
			tokens.push_front(Token(ERROR, "\033[31mUnknown instruction : \"" +
			s.substr(start, std::distance(it2, s.end())) + "\"\033[0m"));
		}	
	}
	if (isEndOfLine(&it))
		return (tokens);
	else
	{
		tokens.clear();
		tokens.push_front(Token(ERROR, "\033[31mCommand line \"" +
		s.substr(start, s.size()) + "\" : invalid\033[0m"));
	}
	return (tokens);
}
