#include "Exception.h"

const char *Exception::what() const noexcept {
return "Invalid input. Expected an integer.";
}
