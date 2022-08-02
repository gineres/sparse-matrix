#include "Tests.h"

int main(){
    constructorEmpty();
    constructorRegular();
    std::cout << std::endl;
    insertOutOfBound();
    insertRegular();
    insertZero();
    std::cout << std::endl;
    removeEmptyPosition();
    removeOutOfBound();
    removeRegular();
    std::cout << std::endl;
    getValueAtOutOfBoundPosition();
    getValueAtRegularPosition();
    std::cout << std::endl;
    searchValueSucess();
    searchValueFail();
    std::cout << std::endl;
    filingAndRetrievingEmptyMatrix();
    filingAndRetrievingRegularMatrix();
    return 0;
}