/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/09 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
    {
        // Test 1: HumanA with weapon (original)
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }

    {
        // Test 2: HumanB with weapon (original)
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    {
        // Test 3: HumanA with different weapon
        Weapon sword = Weapon("longsword");
        HumanA arthur("Arthur", sword);
        arthur.attack();
    }

    {
        // Test 4: HumanB with no weapon set
        HumanB lancelot("Lancelot");
        lancelot.attack(); // Should handle missing weapon gracefully
    }

    {
        // Test 5: HumanB gets weapon after being created
        Weapon axe = Weapon("battle axe");
        HumanB guinevere("Guinevere");
        guinevere.setWeapon(axe);
        guinevere.attack();
    }

    {
        // Test 6: HumanA shared weapon change
        Weapon dagger = Weapon("dagger");
        HumanA robin("Robin", dagger);
        HumanA will("Will", dagger);
        robin.attack();
        will.attack();
        dagger.setType("enchanted dagger");
        robin.attack();
        will.attack();
    }

    {
        // Test 7: HumanB shared weapon reassignment
        Weapon spear = Weapon("wooden spear");
        HumanB galahad("Galahad");
        HumanB percival("Percival");
        galahad.setWeapon(spear);
        percival.setWeapon(spear);
        galahad.attack();
        percival.attack();
        spear.setType("iron-tipped spear");
        galahad.attack();
        percival.attack();
    }

    {
        // Test 8: HumanA reuses weapon after another changes it
        Weapon hammer = Weapon("warhammer");
        HumanA thorin("Thorin", hammer);
        thorin.attack();
        hammer.setType("dwarven warhammer");
        thorin.attack();
    }

    {
        // Test 9: HumanB changes to a different weapon
        Weapon mace = Weapon("steel mace");
        Weapon flail = Weapon("chain flail");
        HumanB boromir("Boromir");
        boromir.setWeapon(mace);
        boromir.attack();
        boromir.setWeapon(flail);
        boromir.attack();
    }

    {
        // Test 10: HumanA and HumanB sharing weapon
        Weapon katana = Weapon("katana");
        HumanA ryu("Ryu", katana);
        HumanB ken("Ken");
        ken.setWeapon(katana);
        ryu.attack();
        ken.attack();
        katana.setType("legendary katana");
        ryu.attack();
        ken.attack();
    }

    return 0;
}
