#pragma once

#include <iostream>
#include <vector>
#include <limits>

namespace Ankor
{
  template<class T, size_t N, size_t M>
  class Matrix {
  public:
    Matrix(const std::initializer_list < std::initializer_list<T>> mtrx) {
      for (size_t i = 0; i < N; ++i)
      {
        for (size_t j = 0; j < M; ++j)
        {
          m_mtrx[i][j] = *((mtrx.begin() + i)->begin() + j);
        }
      }
    }

    Matrix(const T mtrx[N][M]) {
      for (size_t i = 0; i < N; ++i)
      {
        for (size_t j = 0; j < M; ++j)
        {
          m_mtrx[i][j] = mtrx[i][j];
        }
      }
    }

    Matrix() {
      for (size_t i = 0; i < N; ++i)
      {
        for (size_t j = 0; j < M; ++j)
        {
          m_mtrx[i][j] = T(0);
        }
      }
    }

    T* operator[](size_t i)
    {
      return m_mtrx[i];
    }

    const T* operator[](size_t i) const
    {
      return m_mtrx[i];
    }

    friend std::istream& operator>>(std::istream& is, Matrix& mtrx)
    {
      for (size_t i = 0; i < N; ++i)
      {
        for (size_t j = 0; j < M; ++j)
        {
          is >> mtrx[i][j];
        }
      }

      return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mtrx)
    {
      for (size_t i = 0; i < N; ++i)
      {
        for (size_t j = 0; j < M; ++j)
        {
          os << mtrx[i][j] << (j + 1 == M ? "\r\n" : " ");
        }
      }

      return os;
    }

    template<size_t K>
    Matrix<T, N, K> operator*(const Matrix<T, M, K>& rhs)
    {
      Matrix<T, N, K> res;
      T sum;

      for (size_t i = 0; i < N; ++i)
      {
        for (size_t j = 0; j < K; ++j)
        {
          sum = 0;
          for (size_t k = 0; k < M; ++k)
          {
            sum += (*this)[i][k] * rhs[k][j];
          }
          res[i][j] = sum;
        }
      }

      return res;
    }

    bool operator==(const Matrix<T, N, M>& other) const
    {
      for (size_t i = 0; i < N; ++i)
      {
        for (size_t j = 0; j < M; ++j)
        {
          if ((*this)[i][j] != other[i][j])
            return false;
        }
      }

      return true;
    }

  protected:
    T m_mtrx[N][M];
  };

  template<typename T, size_t N>
  using SquareMatrix = Matrix<T, N, N>;
}