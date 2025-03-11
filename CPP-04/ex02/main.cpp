/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:09:21 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/11 15:33:51 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"Animal.hpp"
# include	"Cat.hpp"
# include	"Dog.hpp"

int main()
{
// const Animal* example = new Animal(); Constructor is inaccessible (protected) or we can make a virtual function with "const = 0"
const Animal* j = new Dog();
const Animal* i = new Cat();
const Cat 	y;
const Dog	x;

x.getBrain()->setIdea(50, "Hello world");
y.getBrain()->setIdea(50, "Woof");

std::cout << x.getBrain()->getIdea(50) << std::endl;
std::cout << y.getBrain()->getIdea(50) << std::endl;

delete j;
delete i;
return 0;
}