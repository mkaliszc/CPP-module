/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:43:33 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/18 14:30:22 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"
# include "Character.hpp"
# include "Cure.hpp"
# include "Ice.hpp"

/* void testMateriaLearning()
{
    std::cout << "\n|| Testing MateriaSource Learning ||\n";
    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    src.learnMateria(new Ice()); // Should not add (inventory full)
}

void testCharacterEquip()
{
    std::cout << "\n|| Testing Character Equip and Use ||\n";
    MateriaSource src;
    
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    
    Character player("Player");
    Character enemy("Enemy");
    
    AMateria *ice = src.createMateria("ice");
    AMateria *cure = src.createMateria("cure");
     
    player.equip(ice);
    player.equip(cure); 
    player.use(0, enemy);
    player.use(1, enemy);
}

void testInventoryManagement()
{
    std::cout << "\n|| Testing Inventory Management ||\n";
    Character player("Player");
    AMateria *ice1 = new Ice();
    AMateria *ice2 = new Ice();
    AMateria *cure = new Cure();

    player.equip(ice1);
    player.equip(ice2);
    player.equip(cure);
    player.equip(new Cure());
    player.equip(new Ice());

    player.use(0, player);
    player.use(1, player);

    std::cout << "Unequipping slot 1\n";
    AMateria *unequipped = ice2;
    player.unequip(1);
    delete unequipped;
    player.use(1, player);
}

void testDeepCopy()
{
    std::cout << "\n|| Testing Deep Copy ||\n";
    Character player("Player");
    AMateria *ice = new Ice();
    player.equip(ice);

    Character clone(player);
    clone.use(0, clone);

    player.use(0, player);
}

int main()
{
    testMateriaLearning();
    testCharacterEquip();
    testInventoryManagement();
    testDeepCopy();

    std::cout << "\n|| All tests completed successfully! ||\n";
    return 0;
} */


int main()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}