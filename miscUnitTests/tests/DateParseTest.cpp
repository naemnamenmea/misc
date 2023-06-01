#include "dateUtils.hpp"
#include "my_testing_tools.hpp"

using namespace DateHelper;

TEST(Group1, DateParseTest)
{
  std::istringstream iss("2000-01-06");
  Date result = ParseDate(iss);
  Date expected = Date(Day(6), Month(1), Year(2000));

  ASSERT_EQUAL(result, expected);
}

TEST(Group1, ComputeDiffInDays1)
{
  Date dateFrom = Date(Day(13), Month(10), Year(2021));
  Date dateTo = Date(Day(14), Month(10), Year(2021));
  int result = ComputeDiffInDays(dateFrom, dateTo);
  int expected = 1;

  ASSERT_EQUAL(result, expected);
}

TEST(Group1, ComputeDiffInDays2)
{
  Date dateFrom = Date(Day(1), Month(11), Year(2021));
  Date dateTo = Date(Day(31), Month(10), Year(2021));
  int result = ComputeDiffInDays(dateFrom, dateTo);
  int expected = -1;

  ASSERT_EQUAL(result, expected);
}

TEST(Group1, ComputeDiffInDays3)
{
  Date dateFrom = Date(Day(31), Month(10), Year(2021));
  Date dateTo = Date(Day(1), Month(11), Year(2021));
  int result = ComputeDiffInDays(dateFrom, dateTo);
  int expected = 1;

  ASSERT_EQUAL(result, expected);
}