/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 18:25:14 by sde-toda          #+#    #+#             */
/*   Updated: 2015/10/20 18:01:22 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "AException.hpp"
#include "VMStack.hpp"
#include "Lexer.hpp"
#include "LexerException.hpp"

void							read_from_input(bool option, const char *file)
{
	Lexer						lexer;
	VMStack						stack;
	std::string 				line;
	std::deque<Token>			tokens;
	std::ofstream				ofs;

	if (option == true)
	{
		ofs.open(file, std::ofstream::in | std::ofstream::out | std::ofstream::trunc);
		if (!ofs.is_open())
		{
			std::cerr << "./avm : can.t open file \"" << file << "\"" << std::endl;
			return ;
		}
	}
	while (!stack.getExit() && std::getline(std::cin, line))
	{
		try
		{
			tokens = lexer.tokenize(line);
			if (tokens[0].getType() == ERROR)
				throw LexerException(tokens[0].getToken());
			else if (tokens[0].getType() == NONE)
				throw LexerException(tokens[0].getToken());
			else if (tokens[0].getType() == INSTR)
			{
				stack.unsetValid();
				if (option == false)
					stack.run_command(tokens[0].getToken().c_str(), tokens[1].getToken().c_str(),
					tokens[2].getToken().c_str());
				else
				{
					ofs << tokens[0].getToken().c_str();
					if (tokens[1].getType() == VALUE)
					{
						ofs << " " << tokens[1].getToken() << "(" << tokens[2].getToken() << ")";
					}
					ofs << std::endl;
					if (tokens[0].getToken() == "exit")
						return ;
				}
			}
			tokens.clear();
			tokens.erase(tokens.begin(), tokens.end());
		}
		catch (AException & e)
		{
			std::cerr << e.what() << std::endl;
		}
		line.erase();
	}
	if (option == true)
		ofs.close();
}

bool								read_file(char * file, std::deque< std::deque<Token> > *instructions, bool *exit, bool *error)
{
	char							c;
	Lexer							lexer;
	std::string						line;
	std::deque<std::string>			lines;
	std::deque<Token>				tokens;
	std::ifstream					ifs(file, std::ifstream::binary);
	
	try
	{
		if (ifs.good())
		{
			while (ifs.get(c))
			{
				if (c == '\n' || c == '\0')
				{
					lines.push_back(line);
					tokens = lexer.tokenize(line);
					if (tokens[0].getType() == INSTR && tokens[0].getToken() == "exit")
						*exit = true;
					if (tokens[0].getType() == ERROR)
						*error = true;
					instructions->push_back(tokens);
					tokens.erase(tokens.begin(), tokens.end());
					line.erase();
				}
				else
					line.push_back(c);
			}
			if (line.size())
			{
				lines.push_back(line);
				tokens = lexer.tokenize(line);
				instructions->push_back(tokens);
			}
			ifs.close();
		}
		else
		{
			throw LexerException("\033[31mFile is not valid\033[0m");
		}
	}
	catch (AException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (false);
}


void								read_from_file(char *file)
{
	size_t							i = 0;
	VMStack							stack;
	std::deque<Token>				tokens;
	bool							exit = false;
	bool							error = false;
	std::deque< std::deque<Token> >	instructions;

	if (!read_file(file, &instructions, &exit, &error))
	{
		try
		{
			if (!exit || error)
				stack.setValid();
			while (i < instructions.size())
			{
				tokens = instructions[i];
				try
				{	
					if (instructions[i][0].getType() == INSTR)
					{
						stack.run_command(tokens[0].getToken().c_str(), tokens[1].getToken().c_str(),
						tokens[2].getToken().c_str());
						if (stack.getExit())
							return ;
					}
				}
				catch (AException & e)
				{
					std::stringstream line;
					line << (i + 1);
					std::cerr << "\033[31mline " + line.str() + " : " + e.what() << std::endl;
				}
				try
				{
					if (instructions[i][0].getType() == ERROR)
					{
						std::stringstream line;
						line << (i + 1);
						throw (LexerException("\033[31mline " + line.str() + " : " +
						instructions[i][0].getToken()));
					}
				}
				catch (AException & e)
				{
					std::cerr << e.what() << std::endl;
				}
				i++;
			}
			if (!exit)
			{
				std::stringstream line;
				line << (instructions.size() + 1);
				throw (LexerException("\033[31mline " + line.str() + " : missing exit command"));
			}
		}
		catch (AException & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
		
	
int							main(int argc, char **argv)
{
	if (argc < 2)
		read_from_input(false, "none");
	else if (argc == 2)
		read_from_file(argv[1]);
	else if (argc == 3)
	{
		if (static_cast<std::string>(argv[1]) == "-s")
			read_from_input(true, argv[2]);
		else
			std::cerr << "./avm \"" << argv[1] << "\" : Unknown option" << std::endl;
	}
	else
	{
		std::cerr << "./avm [-t] [file]" << std::endl;
	}
	return (0);
}
