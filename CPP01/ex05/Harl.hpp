/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/09 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
class Harl
{
  private:
    typedef void (Harl::*funcPtr)(void);

    static const std::string _debugLevelText;
    static const std::string _infoLevelText;
    static const std::string _warningLevelText;
    static const std::string _errorLevelText;
    static const std::string _unknownLevelText;

    static const funcPtr     functions[4];
    static const std::string levels[4];

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

  public:
    Harl();
    ~Harl();
    Harl(const Harl& other);
    Harl& operator=(const Harl& other);
    void  complain(std::string level);
};

#endif
