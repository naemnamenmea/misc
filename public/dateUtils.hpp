#pragma once

#include "date.hpp"

class DateHelper
{
public:
  static Date ParseDate(std::istream& is);

  static int ComputeDiffInDays(const Date& date_from, const Date& date_to);

  static Date AddDaysToDate(const Date& date, const int daysToAdd);

private:
  static const time_t SECONDS_IN_DAY = 60 * 60 * 24;
};
