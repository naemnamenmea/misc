#include "matrixUtils.hpp"
#include "my_testing_tools.hpp"

using namespace Ankor;

TEST(MatrixTest, SmokeTest)
{
  int mtrx[2][2] = { {1, 2},{3, 4} };
  auto mtrx1 = Matrix<int, 2, 2>(mtrx);
  auto mtrx2 = Matrix<int, 2, 2>({ {1, 2}, {3, 4} });

  auto expected = Matrix<int, 2, 2>({ {7, 10},{15, 22} });

  ASSERT_EQUAL(mtrx1 * mtrx2, expected);
}

TEST(MatrixTest, ModTest)
{
  int mod = 10;
  auto mtrx1 = SquareMatrix<int, 2>({ {1, 2},{3, 4} });
  auto mtrx2 = Matrix<int, 2, 2>({ {1, 2},{3, 4} });

  auto expected = Matrix<int, 2, 2>({ {7, 0},{5, 2} });

  ASSERT_EQUAL(MtrxUtils::Mult(mtrx1, mtrx2, mod), expected);
}