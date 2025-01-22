#include "dateUtils.hpp"

Date DateHelper::ParseDate(std::istream& is)
{
  int day, month, year;
  is >> year;
  is.ignore(1);
  is >> month;
  is.ignore(1);
  is >> day;
  return Date(Day(day), Month(month), Year(year));
}

int DateHelper::ComputeDiffInDays(const Date& date_from, const Date& date_to) {
  const time_t timestamp_from = date_from.AsTimestamp();
  const time_t timestamp_to = date_to.AsTimestamp();
  return static_cast<int>((timestamp_to - timestamp_from) / SECONDS_IN_DAY);
}

Date DateHelper::AddDaysToDate(const Date& date, const int daysToAdd)
{
  time_t timeInSec = date.AsTimestamp() + daysToAdd * SECONDS_IN_DAY;
#ifdef _MSC_VER
#pragma warning(suppress: 4996)
#endif
  tm* t = localtime(&timeInSec);
  return Date::CreateDate(t);
}
