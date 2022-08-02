#include "Matrix.h"

//Constructors

SMatrix::SMatrix(){
    horizontalSize = 0;
    verticalSize = 0;
}

SMatrix::SMatrix(int _horizontalSize, int _verticalSize){
    horizontalSize = _horizontalSize;
    verticalSize = _verticalSize;
}

//Public methods

void SMatrix::setX(int _horizontalSize){
    horizontalSize = _horizontalSize;
}

void SMatrix::setY(int _verticalSize){
    verticalSize = _verticalSize;
}

int SMatrix::getX(){
    return horizontalSize;
}

int SMatrix::getY(){
    return verticalSize;
}

bool SMatrix::insert (int value, int row, int col){
    if (value == 0 || row >= verticalSize || col >= horizontalSize){
        return false;
    }

    int findCol = searchInMatrix(row, col);
    
    if(findCol != -1){
        matrix[findCol].row.val = value;
        return true;
    }
  
    Col element{};
    element.colIndex = col;
    element.val = value;

    Row tempRow{};
    tempRow.rowIndex = row;
    tempRow.row = element;
    matrix.push_back(tempRow);

    sort();
    sortRow(row);
    
    return true;
}

bool SMatrix::remove (int row, int col){
    if (row >= verticalSize || col >= horizontalSize){
        return false;
    }
    int colIndex = searchInMatrix(row, col);
    if (colIndex != -1){
        matrix.erase(matrix.begin() + colIndex);
        return true;
    }
    return false;
}

int SMatrix::getValueAt(int row, int col){
    if (row >= verticalSize || col >= horizontalSize)
        return -1;
    int getPos = searchInMatrix(row, col);
    if (getPos != -1)
        return matrix[getPos].row.val;
    else
        return 0;
}

bool SMatrix::searchValue(int value, int &row, int &col){
    for (int i = 0; i < matrix.size(); i++){
        if (matrix[i].row.val == value){
            row = matrix[i].rowIndex;
            col = matrix[i].row.colIndex;
            return true;
        }
    }
    row=-1;
    col=-1;
    return false;
}

bool SMatrix::fileMatrix(std::string fileName){
    std::ofstream newFile(fileName);
    if (newFile.is_open())
    {
        newFile << verticalSize << "x" << horizontalSize << "\n";
        for (int i = 0; i < matrix.size(); i++)
        {
            newFile << matrix[i].row.val << "," << matrix[i].rowIndex << ","<< matrix[i].row.colIndex << "\n";
        }
        newFile.close();
        return true;
    }
    return false;
}

void SMatrix::retrieveMatrix(std::string fileName){
    std::ifstream readFile(fileName);
    std::string line;
    std::vector<std::string> values;
    std::vector<std::string> sizeInfo;
    int i = 0;
    int val, row, col;
    if (readFile.is_open()){
        matrix.clear();
        while (getline(readFile, line))
        {
            if (i == 0)
            {
                split(line, 'x', sizeInfo);
                verticalSize = std::stoi(sizeInfo[0]);
                horizontalSize = std::stoi(sizeInfo[1]);
                i++;
            }
            else{
                values.clear();
                split(line, ',', values);
                val = std::stoi(values[0]);
                row = std::stoi(values[1]);
                col = std::stoi(values[2]);
                insert(val,row,col);         
            }
        }
        readFile.close();
    }
}

//Utility methods.

//Returns the position in the main array where the row and column is located.
int SMatrix::searchInMatrix(int row, int col){
    int start = 0;
    int end = matrix.size() - 1;
    int mid;

    while(start <= end){
        mid = (start+end)/2;
        if(col < matrix[mid].row.colIndex){
            if (row < matrix[mid].rowIndex){
                end = mid-1;
                continue;
            }
            else if (row > matrix[mid].rowIndex){
                start = mid+1;
                continue;
            }
            else{
                end = mid-1;
            }
        }

        else if (col > matrix[mid].row.colIndex){
            if (row < matrix[mid].rowIndex){
                end = mid-1;
                continue;
            }
            else if (row > matrix[mid].rowIndex){
                start = mid+1;
                continue;
            }
            else{
                start = mid + 1;
            }
        }

        else if (col == matrix[mid].row.colIndex){
            if(row == matrix[mid].rowIndex){return mid;}
            else{
                if (row < matrix[mid].rowIndex){
                    end = mid-1;
                    continue;
                }
                else if (row > matrix[mid].rowIndex){
                    start = mid+1;
                    continue;
                }
            }
        }
        else{
            return -1;
        }
    }
    return -1;
}

//Sorts the array.
void SMatrix::sort()
{
    int i, key, j;
    Row tempRow;
    for (i = 1; i < matrix.size(); i++)
    {
        key = matrix[i].rowIndex;
        tempRow = matrix[i];
        
        j = i - 1;

        while (j >= 0 && matrix[j].rowIndex > key)
        {
            matrix[j + 1].rowIndex = matrix[j].rowIndex;
            matrix[j + 1] = matrix[j];
            j = j - 1;
        }
        matrix[j + 1].rowIndex = key;
        matrix[j + 1] = tempRow;
    }
}

//Sorts a single row in the array.
void SMatrix::sortRow(int row)
{
    int i, key, j;
    Row tempRow;
    for (i = 1; i < matrix.size(); i++)
    {
        key = matrix[i].row.colIndex;
        tempRow = matrix[i];
        
        j = i - 1;

        while (j >= 0 && matrix[j].row.colIndex > key && matrix[j].rowIndex == row)
        {
            matrix[j + 1] = matrix[j];
            j = j - 1;
        }
        matrix[j + 1] = tempRow;
    }
}

//Support function for splitting strings
void SMatrix::split(const std::string &s, char c, std::vector<std::string> &v){
  std::string::size_type i = 0;
  std::string::size_type j = s.find(c);
  while (j != std::string::npos){
    v.push_back(s.substr(i, j-i));
    i = ++j;
    j = s.find(c, j);
    if (j == std::string::npos)
      v.push_back(s.substr(i, s.length( )));
  }
}