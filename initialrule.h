#ifndef INITIALRULE_H
#define INITIALRULE_H

#include "rule.h"

class InitialRule : public Rule
{
public:
    InitialRule();

    std::unique_ptr<Rule> getChildRule(const std::string& input) const override;
};

#endif // INITIALRULE_H
