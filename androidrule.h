#ifndef ANDROIDRULE_H
#define ANDROIDRULE_H

#include "rule.h"

class AndroidRule : public Rule
{
public:
    AndroidRule();

    void run(std::map<std::string, Probability>& answers) override;
};

#endif // ANDROIDRULE_H
