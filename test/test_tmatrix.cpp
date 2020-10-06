#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);
  ASSERT_NO_THROW(TMatrix<int> m1(m));

}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
		m[i] = i + 3;
	TMatrix<int> m1(m);
	EXPECT_EQ(m1, m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
		m[i] = i + 3;
	TMatrix<int> m1(m);
	EXPECT_NE(&m[0][0], &m1[0][0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	EXPECT_EQ(0, m[0][0]);
	m[0][0] = 5;
	EXPECT_EQ(5, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(4);
	ASSERT_ANY_THROW(m[-2][-4] = 4);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(4);
	ASSERT_ANY_THROW(m[5][5] = 4);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(4);
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = i; j < 4; j++)
			m[i][j] = i * 10 + j;
	ASSERT_NO_THROW(m = m);
	EXPECT_EQ(m, m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5), m1(5);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
			m[i][j] = i * 10 + j;
	m1 = m;
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5), m1(10);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
			m[i][j] = i * 10 + j;
	m1 = m;
	EXPECT_EQ(5, m1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(5), m1(10);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
			m[i][j] = i * 10 + j;
	ASSERT_NO_THROW(m1 = m);
	EXPECT_EQ(m1, m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(5);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
			m[i][j] = i * 10 + j;
	TMatrix<int> m1 = m;
	EXPECT_EQ(1, m1 == m);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(5);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
			m[i][j] = i * 10 + j;
	EXPECT_EQ(1, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(5), m1(10);
	EXPECT_NE(m, m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(5), m1(5), exp(5);
	int i, j;

	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
		{
			m[i][j] = i * 10 + j;
			m1[i][j] = (i * 10 + j) * 100;
			exp[i] = (i * 10 + j) * 101;
		}
	EXPECT_NE(exp, m + m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(5), m1(10);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
			m[i][j] = (i * 10 + j) * 100;
	for ( i = 0; i < 10; i++)for (j = i; j < 5; j++)
		for (j = i; j < 10; j++)
			m1[i][j] = i * 10 + j;
	ASSERT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(5), m1(5), exp(5);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
		{
		    m[i][j] = (i * 10 + j) * 100;
			m1[i][j] = i * 10 + j;
			exp[i] = (i * 10 + j) * 99;
		}
	EXPECT_NE(exp, m + m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(5), m1(10);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
			m[i][j] = (i * 10 + j) * 100;
	for (i = 0; i < 10; i++)for (j = i; j < 5; j++)
		for (j = i; j < 10; j++)
			m1[i][j] = i * 10 + j;
	ASSERT_ANY_THROW(m - m1);
}

