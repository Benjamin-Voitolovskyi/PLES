#ifndef BACKENDRULE_H
#define BACKENDRULE_H

#include "rule.h"

class BackendRule : public Rule
{
public:
    BackendRule();

    void run(std::map<std::string, Probability>& answers) override;
};

#endif // BACKENDRULE_H
