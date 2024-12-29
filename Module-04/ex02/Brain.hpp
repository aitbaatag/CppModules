#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#define SEARCH "SEARCH"
#define ADD "ADD"
#define EXIT "EXIT"
#define CTRLD "CTRL+D"
#define GREEN "\e[1;32m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
#define RED "\e[1;31m"
#define RESET "\e[0m"
class Brain{
    public:
        std::string ideas[100];
        Brain();
        Brain(const Brain &brain);
        ~Brain();
        Brain &operator=(const Brain &brain);
        std::string getIdea(int index) const;
        void setIdea(int index,const std::string& idea);
};
#endif