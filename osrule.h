#ifndef OSRULE_H
#define OSRULE_H

#include "rule.h"

class OSRule : public Rule
{
public:
    OSRule();

    void run(std::map<std::string, Probability>& answers) override;
    std::unique_ptr<Rule> getChildRule(const std::string& input) const override;
};

#endif // OSRULE_H
