#ifndef AIRULE_H
#define AIRULE_H

#include "rule.h"

class AIRule : public Rule
{
public:
    AIRule();

    void run(std::map<std::string, Probability>& answers) override;
};

#endif // AIRULE_H
