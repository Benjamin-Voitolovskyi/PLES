#ifndef IOTRULE_H
#define IOTRULE_H

#include "rule.h"

class IoTRule : public Rule
{
public:
    IoTRule();

    void run(std::map<std::string, Probability>& answers) override;
};

#endif // IOTRULE_H
