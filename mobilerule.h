#ifndef MOBILERULE_H
#define MOBILERULE_H

#include "rule.h"

class MobileRule : public Rule
{
public:
    MobileRule();

    void run(std::map<std::string, Probability>& answers) override;
    std::unique_ptr<Rule> getChildRule(const std::string& input) const override;
};

#endif // MOBILERULE_H
