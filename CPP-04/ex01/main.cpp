/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:09:21 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/18 14:25:39 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"Animal.hpp"
# include	"Cat.hpp"
# include	"Dog.hpp"

int main()
{
Animal* j = new Dog();
Animal* i = new Cat();
Cat 	*cat = dynamic_cast<Cat *>(i);
Dog		*dog = dynamic_cast<Dog *>(j);

cat->getBrain()->setIdea(50, "Hello world");
dog->getBrain()->setIdea(50, "Woof");

std::cout << cat->getBrain()->getIdea(50) << std::endl;
std::cout << dog->getBrain()->getIdea(50) << std::endl;

delete j;
delete i;
return 0;
}