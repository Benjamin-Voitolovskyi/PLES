#ifndef HYBRIDRULE_H
#define HYBRIDRULE_H

#include "rule.h"

class HybridRule : public Rule
{
public:
    HybridRule();

    void run(std::map<std::string, Probability>& answers) override;
};

#endif // HYBRIDRULE_H
