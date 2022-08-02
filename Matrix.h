#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>
#include <fstream>

class Col {
    public:
        int colIndex;
        int val;
};

class Row {
    public:
        Col row;
        int rowIndex;
};

class SMatrix {
    public:
        std::vector<Row> matrix;
        int horizontalSize;
        int verticalSize;

        SMatrix();
        SMatrix(int _horizontal_size, int _vertical_size);
        void setX(int _horizontalSize);
        void setY(int _verticalSize);
        int getX();
        int getY();
        bool insert(int value, int row, int col);
        bool remove(int row, int col);
        int getValueAt(int row, int col);
        bool searchValue(int value, int &row, int &col);
        bool fileMatrix(std::string fileName);
        void retrieveMatrix(std::string fileName);

    private:
        int searchInMatrix(int row, int col);
        void sort();
        void sortRow(int row);
        void split(const std::string &s, char c, std::vector<std::string> &v);
};

#endif