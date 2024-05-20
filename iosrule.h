#ifndef IOSRULE_H
#define IOSRULE_H

#include "rule.h"

class IOSRule : public Rule
{
public:
    IOSRule();

    void run(std::map<std::string, Probability>& answers) override;
};

#endif // IOSRULE_H
