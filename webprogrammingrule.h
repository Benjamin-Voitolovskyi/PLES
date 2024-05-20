#ifndef WEBPROGRAMMINGRULE_H
#define WEBPROGRAMMINGRULE_H

#include "rule.h"

class WebProgrammingRule : public Rule
{
public:
    WebProgrammingRule();

    std::unique_ptr<Rule> getChildRule(const std::string& input) const override;
    void run(std::map<std::string, Probability>& answers) override;
};

#endif // WEBPROGRAMMINGRULE_H
