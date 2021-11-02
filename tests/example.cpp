// Copyright 2021 <geraldy12319@gamil.com>

#include <gtest/gtest.h>

#include <dir_analyze.hpp>
#include <stdexcept>

TEST(Example, EmptyTest) {
    EXPECT_THROW(example(), std::runtime_error);
}
