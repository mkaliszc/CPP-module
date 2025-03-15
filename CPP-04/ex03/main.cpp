/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:43:33 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/15 16:23:41 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"
# include "Character.hpp"
# include "Cure.hpp"
# include "Ice.hpp"

void testMateriaLearning() {
  std::cout << "\n--- Testing MateriaSource Learning ---" << std::endl;
  MateriaSource src;
  src.learnMateria(new Ice());
  src.learnMateria(new Cure());
  src.learnMateria(new Ice());
  src.learnMateria(new Cure());
  src.learnMateria(new Ice()); // Should not add (inventory full)
}

void testCharacterEquip() {
  std::cout << "\n--- Testing Character Equip and Use ---" << std::endl;
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

void testInventoryManagement() {
  std::cout << "\n--- Testing Inventory Management ---" << std::endl;
  Character player("Player");
  AMateria *ice1 = new Ice();
  AMateria *ice2 = new Ice();
  AMateria *cure = new Cure();

  player.equip(ice1);
  player.equip(ice2);
  player.equip(cure);
  player.equip(new Cure());
  player.equip(new Ice()); // Should not equip (inventory full)

  player.use(0, player);
  player.use(1, player);

  std::cout << "Unequipping slot 1" << std::endl;
  AMateria *unequipped = ice2;
  player.unequip(1);
  delete unequipped;
  player.use(1, player); // Should not do anything
}

void testDeepCopy() {
  std::cout << "\n--- Testing Deep Copy ---" << std::endl;
  Character player("Player");
  AMateria *ice = new Ice();
  player.equip(ice);

  Character clone(player);
  clone.use(0, clone);

  player.use(0, player); // Ensure player still owns its own materia
}

int main() {
  testMateriaLearning();
  testCharacterEquip();
  testInventoryManagement();
  testDeepCopy();

  std::cout << "\n--- All tests completed successfully! ---" << std::endl;
  return 0;
}

/* int main()
{
	{
        Character    *Boss = new Character("Boss");
        Character    *Employ = new Character("Employ");
        Character    Healed("healed");

        for (int i = 0; i < 4; i++) {
            if (i % 2 == 0)
                Boss->equip(new Ice());
            else
                Boss->equip(new Cure());
        }
        for (int i = 0; i < 4; i++) {
            if (i % 2 != 0)
                Employ->equip(new Ice());
            else
                Employ->equip(new Cure());
        }
        *Boss = *Employ;

        Boss->unequip(3);
        Boss->use(2, Healed);
        delete (Boss);
        delete (Employ);
    }
	std::cout << "\ntest 2\n";
    {
        Ice        *ptrI = new Ice();
        Cure    *ptrC = new Cure();

        Character    Gros("gros");
        Character    Maigre("maigre");

        for (int i = 0; i < 4; i++) {
            if (i % 2 == 0)
                Gros.equip(new Ice());
            else
                Gros.equip(new Cure());
        }
        for (int i  = 0; i < 4; i++)
            Gros.unequip(i);
        for (int i = 0; i <= 4; i++) {
            if (i % 2 == 0)
                Maigre.equip(new Cure());
            else
                Maigre.equip(new Ice());
        }
        for (int i = 0; i < 18; i++)
            Maigre.equip(ptrI);
        delete ptrC;
        delete ptrI;
    }
} */






	/*
	* test sujet 
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

	return 0; */