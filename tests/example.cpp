// Copyright 2021 <geraldy12319@gamil.com>

#include <gtest/gtest.h>

#include <dir_analyze.hpp>
#include <stdexcept>

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Analyze_dir, For_misc){
  std::ostringstream output;
  Analyzer A(CUR_DIR"/misc/ftp");
  A.Accounts_Stats(output);
  EXPECT_EQ(
      output.str(),
      R"(broker: ib       | account: 00100001 | files: 48  | lastdate: 20181018
broker: ib       | account: 00100002 | files: 48  | lastdate: 20181018
broker: ib       | account: 00100003 | files: 47  | lastdate: 20181017
broker: bcs      | account: 00122223 | files: 51  | lastdate: 20181016
broker: bcs      | account: 00123456 | files: 44  | lastdate: 20181014
broker: bcs      | account: 00123458 | files: 48  | lastdate: 20181018
broker: bcs      | account: 00143456 | files: 46  | lastdate: 20181016
broker: otkritie | account: 03934520 | files: 48  | lastdate: 20181018
broker: otkritie | account: 03934523 | files: 47  | lastdate: 20181017
)");
}
