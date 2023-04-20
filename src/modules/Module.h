#ifndef MODULES_H
#define MODULE_H

#include <ArduinoJson.h>

class Module
{
public:
    virtual void begin(){};
    virtual void update(){};
    virtual String getData(){};
};

#endif
