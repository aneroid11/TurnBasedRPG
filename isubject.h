#ifndef ISUBJECT_H
#define ISUBJECT_H

#include <string>

#include "iobserver.h"

class ISubject
{
public:
    virtual ~ISubject() {}

    virtual void attachObserver(IObserver* o) = 0;
    virtual void detachObserver(IObserver* o) = 0;
    virtual void notifyObservers(const std::wstring msg) = 0;
};

#endif // ISUBJECT_H
