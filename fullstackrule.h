#ifndef FULLSTACKRULE_H
#define FULLSTACKRULE_H

#include "rule.h"

class FullstackRule : public Rule
{
public:
    FullstackRule();

    void run(std::map<std::string, Probability>& answers) override;
};

#endif // FULLSTACKRULE_H
