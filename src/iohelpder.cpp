#include "iohelpder.hpp"

void SkipRestLine(std::istream& is)
{
  std::string dummy;
  std::getline(is, dummy);
}
