#include "date.hpp"

std::ostream& operator<<(std::ostream& os, const Date& date)
{
  return os << date.ToString();
}
