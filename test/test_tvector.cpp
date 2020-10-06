#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  TVector<int> v(10, 2);
  for (int i = 2; i < 10; i++)
	  v[i] = i * 3;
  TVector<int> v1(v);
  EXPECT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v(10);
  for (int i = 0; i < 10; i++)
	  v[i] = i * 3;
  TVector<int> v1(v);
  EXPECT_NE(&v[0], &v1[0]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);
  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);
  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  EXPECT_EQ(0, v[0]);
  v[0] = 4;
  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
  TVector<int> v(4);
  ASSERT_ANY_THROW(v[-2] = 4);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<int> v(4);
  ASSERT_ANY_THROW(v[6] = 4);
}

TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> v(4);
  for (int i = 0; i < 4; i++)
	  v[i] = i * 4;
  ASSERT_NO_THROW(v = v);
  EXPECT_EQ(v, v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  int size = 10;
  TVector<int> v(size);
  TVector<int> v1(size);
  for (int i = 0; i < size; i++)
  {
	  v[i] = i * 4;
	  v1[i] = i * 6;
  }
  v1 = v;
  EXPECT_EQ(v, v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	int size1 = 10;
	int  size2 = 5;
	TVector<int> v(size1);
	TVector<int> v1(size2);
	for (int i = 0; i < size1; i++)
		v[i] = i * 4;
	v1 = v;
	EXPECT_EQ(size1, v1.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	int size1 = 10;
	int  size2 = 5;
	TVector<int> v(size1);
	TVector<int> v1(size2);
	for (int i = 0; i < size1; i++)
		v[i] = i * 4;
	ASSERT_NO_THROW(v1 = v);
	EXPECT_EQ(v, v1);
  
}

TEST(TVector, compare_equal_vectors_return_true)
{
  TVector<int> v(4);
  for (int i = 0; i < 4; i++)
	  v[i] = i * 4;
  TVector<int> v1 = v;
  EXPECT_EQ(1, v == v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(4);
	for (int i = 0; i < 4; i++)
		v[i] = i * 4;
	EXPECT_EQ(1, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(4);
	TVector<int> v1(10);
	EXPECT_NE(v, v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(4), exp(4);
	int a = 6;
	for (int i = 0; i < 4; i++)
	{
		v[i] = i * 4;
		exp[i] = i * 4 + a;
	}
	ASSERT_NO_THROW(v + a);
	EXPECT_EQ(exp, v + a);  
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(4), exp(4);
	int a = 6;
	for (int i = 0; i < 4; i++)
	{
		v[i] = i * 4;
		exp[i] = i * 4 - a;
	}
	ASSERT_NO_THROW(v - a);
	EXPECT_EQ(exp, v - a);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(4), exp(4);
	int a = 6;
	for (int i = 0; i < 4; i++)
	{
		v[i] = i * 4;
		exp[i] = i * 24;
	}
	ASSERT_NO_THROW(v * a);
	EXPECT_EQ(exp, v * a);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(5), v1(5), exp(5);
	for (int i = 0; i < 5; i++)
	{
		v[i] = i * 2;
		v1[i] = i  * 3;
		exp[i] = i * 5;
	}
	EXPECT_EQ(exp, v + v1);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(5), v1(10);
	for (int i = 0; i < 5; i++)
	{
		v[i] = i * 2;
		v1[i * 2] = i * 3;
	}
	ASSERT_ANY_THROW( v + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(5), v1(5), exp(5);
	for (int i = 0; i < 5; i++)
	{
		v[i] = i * 3;
		v1[i] = i * 2;
		exp[i] = i;
	}
	EXPECT_EQ(exp, v - v1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(5), v1(10);
	for (int i = 0; i < 5; i++)
	{
		v[i] = i * 2;
		v1[i * 2] = i * 3;
	}
	ASSERT_ANY_THROW(v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(5), v1(5);
	int exp = 0;
	for (int i = 0; i < 5; i++)
	{
		v[i] = i * 2;
		v1[i] = i * 3;
		exp += (i * 2) * (i * 3);
	}
	EXPECT_EQ(exp, v * v1);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(5), v1(10);
	for (int i = 0; i < 5; i++)
	{
		v[i] = i * 2;
		v1[i * 2] = i * 3;
	}
	ASSERT_ANY_THROW(v * v1);
}

