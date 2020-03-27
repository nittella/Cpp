#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <sstream>

using namespace std;



class Matrix {
public:
    Matrix() {
      rows = 0;
      cols = 0;
      matrix = {};
    }

    Matrix(int num_rows, int num_cols) {
      Reset(num_rows, num_cols);
    }

    void Reset(int num_rows, int num_cols) {
      Check_Negativity_and_Throw_Exeption(num_rows,num_cols);
      if (num_rows == 0 || num_cols == 0) {
        num_rows = num_cols = 0;
      }
      vector<vector<int>> tmp_matrix;
      vector<int> tmp;
      rows = num_rows;
      cols = num_cols;
      tmp.assign(num_cols, 0);
      tmp_matrix.assign(num_rows, tmp);
      matrix = tmp_matrix;
    }

    int At(const int &row, const int &col) const {
        Check_Size_and_Throw_Exeption(row,col);
        Check_Negativity_and_Throw_Exeption(row, col);
      return matrix.at(row).at(col);
    }

    int &At(const int &row, const int &col) {
        Check_Size_and_Throw_Exeption(row,col);
        Check_Negativity_and_Throw_Exeption(row, col);
      return matrix.at(row).at(col);
    }

    int GetNumRows() const {
      return rows;
}

    int GetNumColumns() const {
      return cols;
    }

private:
    int rows, cols;
    vector<vector<int>> matrix;

    void Check_Negativity_and_Throw_Exeption(const int& num_rows, const int& num_cols) const {
      if (num_rows < 0 || num_cols < 0) {
        throw out_of_range("out_of_range");
      }
    }
    void Check_Size_and_Throw_Exeption  (const int& row, const int& col)const{
      if (row > rows || col > cols) {
        throw out_of_range("out_of_range");
      }
    }

};

Matrix operator+ (const Matrix& matrix_a, const Matrix& matrix_b){
 if (matrix_a.GetNumRows() != matrix_b.GetNumRows() || matrix_a.GetNumColumns() != matrix_b.GetNumColumns()){
    throw invalid_argument ("invalid_argument");
  }

  Matrix result (matrix_a.GetNumRows(), matrix_a.GetNumColumns());
  for (int i = 0; i < result.GetNumRows(); i++) {
    for (int k = 0; k < result.GetNumColumns(); k++) {
      result.At(i, k) = matrix_a.At(i, k) + matrix_b.At(i, k);
    }
  }
  return result;
}
istream& operator>>(istream& in, Matrix& matrix) {
  int num_rows, num_columns;
  in >> num_rows >> num_columns;

  matrix.Reset(num_rows, num_columns);
  for (int row = 0; row < num_rows; ++row) {
    for (int column = 0; column < num_columns; ++column) {
      in >> matrix.At(row, column);
    }
  }
  return in;
}


//istream& operator>> (istream& stream, Matrix& matrix){
//  string s;
//  getline(stream, s);
//  stringstream ss;
//  ss << s;
//  int num_rows, num_cols;
//  ss >> num_rows >> num_cols;
//  matrix.Reset(num_rows,num_cols);
//  for (int i = 0; i < matrix.GetNumRows(); i++){
//    stringstream ss_1;
//    getline(stream, s);
//    ss_1 << s;
//    for (int k = 0; k < matrix.GetNumColumns(); k++){
//      int tmp;
//      ss_1 >> tmp;
//      matrix.At(i,k) = tmp;
//    }
//  }
//  stream.ignore(1);
//  return stream;
//}
ostream& operator<< (ostream& stream, const Matrix& matrix){
  stream << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
  for (int i = 0; i < matrix.GetNumRows(); i++){
    for (int k = 0; k < matrix.GetNumColumns(); k++){
      int tmp = matrix.At(i, k);
      stream << tmp;
      if (k != matrix.GetNumColumns() - 1){
        stream << " ";
      }
    }
    if (i != matrix.GetNumRows() - 1){
      stream << endl;
    }
  }
  return stream;
}

bool operator== (const Matrix& lhs, const Matrix& rhs){
  if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()){
    return false;
  }
  for (int i = 0; i < lhs.GetNumRows(); i++) {
    for (int k = 0; k < lhs.GetNumColumns(); k++) {
      if (lhs.At(i, k) != rhs.At(i, k)){
        return false;
      }
    }
  }
  return true;
}

int main() {
  Matrix one, two;
  cin >> one;
  cout << one << endl;
//  cout << two << endl;
//  cout << one + two << endl;
  return 0;
}