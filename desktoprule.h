#ifndef DESKTOPRULE_H
#define DESKTOPRULE_H

#include "rule.h"

class DesktopRule : public Rule
{
public:
    DesktopRule();

    void run(std::map<std::string, Probability>& answers) override;
};

#endif // DESKTOPRULE_H
