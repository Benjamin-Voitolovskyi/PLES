#ifndef FRONTENDRULE_H
#define FRONTENDRULE_H

#include "rule.h"

class FrontendRule : public Rule
{
public:
    FrontendRule();

    void run(std::map<std::string, Probability>& answers) override;
};

#endif // FRONTENDRULE_H
