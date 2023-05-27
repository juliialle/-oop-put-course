#ifndef PROJECT_EXCEPTION_H
#define PROJECT_EXCEPTION_H

#include <stdexcept>

class Exception : public std::exception {
public:
    const char *what() const noexcept override;
};

#endif //PROJECT_EXCEPTION_H
