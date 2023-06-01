#pragma once
#include <string>
#include <sstream>
#include <tuple>
#include <ctime>

struct Day
{
  explicit Day(const int value) : value_(value) {}
  operator int() const { return value_; }

  int value_;
};

struct Month
{
  explicit Month(const int value) : value_(value) {}
  operator int() const { return value_; }

  int value_;
};

struct Year
{
  explicit Year(const int value) : value_(value) {}
  operator int() const { return value_; }

  int value_;
};

class Date
{
public:
  explicit Date(Day day, Month month, Year year)
    :day_(day), month_(month), year_(year) {}

  static Date CreateDate(const tm* const t)
  {
    return Date(Day(t->tm_mday), Month(t->tm_mon + 1), Year(t->tm_year + 1900));
  }

  time_t AsTimestamp() const
  {
    tm t = {};
    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 0;
    t.tm_mday = day_;
    t.tm_mon = month_ - 1;
    t.tm_year = year_ - 1900;
    t.tm_isdst = 0;
    return mktime(&t);
  }

  std::string ToString(const char d = '/') const
  {
    std::ostringstream oss;
    oss << day_ << d << month_ << d << year_;
    return oss.str();
  }

  bool operator<(const Date& other) const
  {
    return std::tie(year_, month_, day_)
      < std::tie(other.year_, other.month_, other.day_);
  }

  bool operator<=(const Date& other) const
  {
    return std::tie(year_, month_, day_)
      <= std::tie(other.year_, other.month_, other.day_);
  }

  bool operator==(const Date& other) const
  {
    return std::tie(this->year_, this->month_, this->day_)
      == std::tie(other.year_, other.month_, other.day_);
  }

private:
  Day day_;
  Month month_;
  Year year_;
};

class DateRange
{
public:
  DateRange(Date fromInc, Date toExc) : m_fromInc(std::move(fromInc)), m_toExc(std::move(toExc)) {
    Validate();
  }

  const Date& GetBegin() const 
  {
    return m_fromInc;
  }

  const Date& GetEnd() const 
  {
    return m_toExc;
  }

  void SetBegin(Date fromInc)
  {
    m_fromInc = std::move(fromInc);
    Validate();
  }

  void SetEnd(Date toExc)
  {
    m_toExc = std::move(toExc);
    Validate();
  }
private:
  void Validate() const
  {
    if (m_toExc < m_fromInc)
      throw std::range_error("inverse range provided");
  }

  Date m_fromInc;
  Date m_toExc;
};

std::ostream& operator<<(std::ostream& os, const Date& date);
