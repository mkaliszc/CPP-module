/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:09:21 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/08 16:55:15 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"Animal.hpp"
# include	"Cat.hpp"
# include	"Dog.hpp"
# include	"WrongCat.hpp"

int	main()
{
	Animal* meta = new Animal();
	WrongAnimal* wrong = new WrongAnimal();
	WrongAnimal* Wrongcat = new WrongCat();
	Animal* j = new Dog();
	Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << Wrongcat->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	Wrongcat->makeSound();
	wrong->makeSound();

	delete(Wrongcat);
	delete(wrong);
	delete(meta);
	delete(j);
	delete(i);
}