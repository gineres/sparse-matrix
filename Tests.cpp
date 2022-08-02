#include <iostream>
#include "Tests.h"

void EXPECT_TRUE(bool data){
    if (data){
        std::cout<< " PASSED!" << std::endl;
        return;
    }
    std::cout<< " FAILED: expected 1, got " << data << std::endl;
}

void EXPECT_FALSE(bool data){
    if (!data){
        std::cout<< " PASSED!" << std::endl;
        return;
    }
    std::cout<< " FAILED: expected 0, got " << data << std::endl;
}

void EXPECT_EQ(int int1, int int2){
    if (int1 == int2){
        std::cout<< " PASSED!" << std::endl;
        return;
    }
    std::cout<< " FAILED: expected "<<int1<<", got " << int2 << std::endl;
}

void constructorEmpty(){
    SMatrix m{};
    std::cout << "TEST CONSTRUCTOR_EMPTY (X): ";
    EXPECT_EQ(0, m.getX());
    std::cout << "TEST CONSTRUCTOR_EMPTY (Y): ";
    EXPECT_EQ(0, m.getY());
}

void constructorRegular(){
    SMatrix m{1,2};
    std::cout << "TEST CONSTRUCTOR_REGULAR (X): ";
    EXPECT_EQ(1, m.getX());
    std::cout << "TEST CONSTRUCTOR_REGULAR (Y): ";
    EXPECT_EQ(2, m.getY());
}

void insertOutOfBound(){
    SMatrix m{500,500};
    std::cout << "TEST INSERT_OUT_OF_BOUND: ";
    EXPECT_FALSE(m.insert(1,500,499));
}

void insertZero(){
    SMatrix m{500,500};
    std::cout << "TEST INSERT_ZERO: ";
    EXPECT_FALSE(m.insert(0,499,499));
}

void insertRegular(){
    SMatrix m{500,500};
    std::cout << "TEST INSERT_REGULAR: ";
    EXPECT_TRUE(m.insert(1,499,499));
}

void removeOutOfBound(){
    SMatrix m{500,500};
    std::cout << "TEST REMOVE_OUT_OF_BOUND: ";
    EXPECT_FALSE(m.remove(500,500));
}

void removeEmptyPosition(){
    SMatrix m{500,500};
    std::cout << "TEST EMPTY_POSITION: ";
    EXPECT_FALSE(m.remove(499,499));
}

void removeRegular(){
    SMatrix m{500,500};
    m.insert(1,499,499);
    std::cout << "TEST REMOVE_REGULAR: ";
    EXPECT_TRUE(m.remove(499,499));
}

void getValueAtOutOfBoundPosition(){
    SMatrix m{500,500};
    m.insert(1,499,499);
    std::cout << "TEST GET_VALUE_AT_OUT_OF_BOUND_POSITION: ";
    EXPECT_EQ(-1,m.getValueAt(500,500));
}

void getValueAtRegularPosition(){
    SMatrix m{500,500};
    m.insert(1,499,499);
    std::cout << "TEST GET_VALUE_AT_REGULAR_POSITION: ";
    EXPECT_EQ(1,m.getValueAt(499,499));
}

void searchValueSucess(){
    SMatrix m{500,500};
    int row, col;
    m.insert(1,499,498);
    std::cout << "TEST SEARCH_VALUE_SUCESS (BOOLEAN): ";
    EXPECT_TRUE(m.searchValue(1, row, col));
    std::cout << "TEST SEARCH_VALUE_SUCESS (ROW): ";
    EXPECT_EQ(499,row);
    std::cout << "TEST SEARCH_VALUE_SUCESS (COL): ";
    EXPECT_EQ(498,col);
}

void searchValueFail(){
    SMatrix m{500,500};
    int row, col;
    m.insert(1,499,498);
    std::cout << "TEST SEARCH_VALUE_FAIL (BOOLEAN): ";
    EXPECT_FALSE(m.searchValue(2, row, col));
    std::cout << "TEST SEARCH_VALUE_FAIL (ROW): ";
    EXPECT_EQ(-1,row);
    std::cout << "TEST SEARCH_VALUE_FAIL (COL): ";
    EXPECT_EQ(-1,col);
}

void filingAndRetrievingEmptyMatrix(){
    SMatrix test{5, 5};
    SMatrix test2{};
    test.fileMatrix("matrix.txt");
    test2.retrieveMatrix("matrix.txt");
    std::cout << "TEST FILING_AND_RETRIEVING_EMPTY_MATRIX (SIZE): ";
    EXPECT_TRUE(test.getY() == test2.getY() && test.getX() == test2.getX());
    std::cout << "TEST FILING_AND_RETRIEVING_EMPTY_MATRIX (ELEMENTS): ";
    bool eqTest = true;
    for (int i = 0; i < test.getY(); i++){
        for (int j = 0; j < test.getX(); j++){
            eqTest = test.getValueAt(i,j) == test2.getValueAt(i,j);
            if (!eqTest){
                EXPECT_TRUE(eqTest);
                return;
            }
        }
    }
    EXPECT_TRUE(eqTest);
}

void filingAndRetrievingRegularMatrix(){
    SMatrix test{5, 5};
    test.insert(1,0,1);
    test.insert(2,0,2);
    test.insert(3,0,3);
    test.insert(4,0,4);
    test.insert(5,1,0);
    test.insert(6,1,1);
    test.insert(7,1,2);
    test.insert(8,1,3);
    test.insert(9,1,4);
    SMatrix test2{};
    test.fileMatrix("matrix.txt");
    test2.retrieveMatrix("matrix.txt");
    std::cout << "TEST FILING_AND_RETRIEVING_REGULAR_MATRIX (SIZE): ";
    EXPECT_TRUE(test.getY() == test2.getY() && test.getX() == test2.getX());
    std::cout << "TEST FILING_AND_RETRIEVING_REGULAR_MATRIX (ELEMENTS): ";
    bool eqTest = true;
    for (int i = 0; i < test.getY(); i++){
        for (int j = 0; j < test.getX(); j++){
            eqTest = test.getValueAt(i,j) == test2.getValueAt(i,j);
            if (!eqTest){
                EXPECT_TRUE(eqTest);
                return;
            }
        }
    }
    EXPECT_TRUE(eqTest);
}