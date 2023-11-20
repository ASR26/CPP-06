/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:51:33 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/20 09:34:18 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base *generate()
{
	srand(time(NULL));

	switch (rand() % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (nullptr);
	}	
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != nullptr)
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B *>(p) != nullptr)
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C *>(p) != nullptr)
		std::cout << "Type: C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Type: A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "Type: B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "Type: C" << std::endl;
			}
			catch(std::exception &e)
			{
			}
		}
	}
}

