/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:30:43 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/02 18:44:56 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base*	generate()
{
	int	random = rand() % 3;

	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "obj is type A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "obj is type B\n";
	else
		std::cout << "obj is type C\n";
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "obj is type A\n";
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "obj is type B\n";
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "obj is type C\n";
	}
	catch(const std::exception& e) {}
}

int main()
{
	Base *obj;
	srand(time(NULL));

	obj = generate();
	identify(*obj);
	delete (obj);
}