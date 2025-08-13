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

        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }

    {

        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    {

        Weapon sword = Weapon("longsword");
        HumanA arthur("Arthur", sword);
        arthur.attack();
    }

    {

        HumanB lancelot("Lancelot");
        lancelot.attack();
    }

    {

        Weapon axe = Weapon("battle axe");
        HumanB guinevere("Guinevere");
        guinevere.setWeapon(axe);
        guinevere.attack();
    }

    {

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

        Weapon hammer = Weapon("warhammer");
        HumanA thorin("Thorin", hammer);
        thorin.attack();
        hammer.setType("dwarven warhammer");
        thorin.attack();
    }

    {

        Weapon mace = Weapon("steel mace");
        Weapon flail = Weapon("chain flail");
        HumanB boromir("Boromir");
        boromir.setWeapon(mace);
        boromir.attack();
        boromir.setWeapon(flail);
        boromir.attack();
    }

    {

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

    {

        Weapon glaive = Weapon("glaive");
        HumanA aragorn("Aragorn", glaive);
        aragorn.attack();
        glaive.setType("elven glaive");
        aragorn.attack();
        HumanB legolas("Legolas");
        legolas.setWeapon(glaive);
        legolas.attack();
        glaive.setType("mithril glaive");
        legolas.attack();
        aragorn.attack();
    }

    return 0;
}
