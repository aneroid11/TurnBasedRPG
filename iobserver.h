#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>

class IObserver
{
public:
    virtual ~IObserver() {}

    virtual void update(const std::wstring msgFromSubject) = 0;
};

#endif // IOBSERVER_H
