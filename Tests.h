#include "Matrix.h"
#include <iostream>

void EXPECT_TRUE(bool data);
void EXPECT_FALSE(bool data);
void EXPECT_EQ(int int1, int int2);
void constructorEmpty();
void constructorRegular();
void insertOutOfBound();
void insertZero();
void insertRegular();
void removeOutOfBound();
void removeEmptyPosition();
void removeRegular();
void getValueAtOutOfBoundPosition();
void getValueAtRegularPosition();
void searchValueSucess();
void searchValueFail();
void filingAndRetrievingEmptyMatrix();
void filingAndRetrievingRegularMatrix();