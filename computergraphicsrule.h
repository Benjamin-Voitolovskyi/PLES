#ifndef COMPUTERGRAPHICSRULE_H
#define COMPUTERGRAPHICSRULE_H

#include "rule.h"

class ComputerGraphicsRule : public Rule
{
public:
    ComputerGraphicsRule();

    void run(std::map<std::string, Probability>& answers) override;
};

#endif // COMPUTERGRAPHICSRULE_H
