#pragma once

#include <iostream>
#include <vector>

template<class T, size_t N, size_t M>
class Matrix {
public:
  Matrix(const std::vector<std::vector<T>>& mtrx) {
    m_mtrx.resize(N);
    for (size_t i = 0; i < N; ++i)
    {
      m_mtrx[i].resize(M);
      for (size_t j = 0; j < M; ++j)
      {
        m_mtrx[i][j] = mtrx[i][j];
      }
    }
  }

  Matrix() {
    m_mtrx.resize(N);
    for (size_t i = 0; i < N; ++i)
    {
      m_mtrx[i].assign(M, T(0));
    }
  }

  std::vector<T>& operator[](size_t i)
  {
    return m_mtrx[i];
  }

  const std::vector<T>& operator[](size_t i) const
  {
    return m_mtrx[i];
  }

  template<size_t K>
  Matrix<T, N, K> operator*(const Matrix<T, M, K>& other) const
  {
    Matrix<T, N, K> res;

    for (size_t i = 0; i < N; ++i)
    {
      for (size_t j = 0; j < K; ++j)
      {
        T sum(0);
        for (size_t k = 0; k < M; ++k)
        {
          sum += (*this)[i][k] * other[k][j];
        }
        res[i][j] = sum;
      }
    }

    return res;
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

protected:
  std::vector<std::vector<T>> m_mtrx;
};

template<class T, size_t N>
class SquareMatrix : public Matrix<T, N, N>
{
public:
  SquareMatrix()
  {
    for (size_t i = 0; i < N; ++i) {
      (*this)[i][i] = 1;
    }
  }

  SquareMatrix(const Matrix<T, N, N>& other) : Matrix<T, N, N>(other) {}
};