#pragma once

#include "matrix.hpp"

namespace MtrxUtils
{
  using namespace Ankor;

  template<class T, size_t N, size_t M, size_t K>
  Matrix<T, N, K> Mult(const Matrix<T, N, M>& lhs, const Matrix<T, M, K>& rhs, const T mod)
  {
    Matrix<T, N, K> res;
    T sum, tmp;

    for (size_t i = 0; i < N; ++i)
    {
      for (size_t j = 0; j < K; ++j)
      {
        sum = 0;
        for (size_t k = 0; k < M; ++k)
        {
          tmp = (lhs[i][k] * rhs[k][j]) % mod;
          sum = (sum + tmp) % mod;
        }
        res[i][j] = sum;
      }
    }

    return res;
  }
}