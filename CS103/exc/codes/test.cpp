#include <gtest/gtest.h>

bool IsPrime(long long inp)
{
    if (inp < 2)
        return false;
    
    long long checkPnt = 0;
    checkPnt = inp/2;

    for(int i = 2; i <= checkPnt; i++)
    {  
        if(inp % i == 0)
        {  
            return false;
        }
    }

    return true;
}


TEST(Function, Target)
{
  EXPECT_EQ(IsPrime(2), true);
  EXPECT_EQ(IsPrime(3), false);
  EXPECT_EQ(IsPrime(4), false);
  EXPECT_EQ(IsPrime(5), true);
  EXPECT_EQ(IsPrime(6), false);
}