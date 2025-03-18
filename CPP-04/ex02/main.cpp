/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:09:21 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/18 14:32:09 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"Animal.hpp"
# include	"Cat.hpp"
# include	"Dog.hpp"

int main()
{
// const Animal* example = new Animal(); // Constructor is inaccessible (protected) and there is a virtual function with "const = 0" so class is "pure virtual"
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