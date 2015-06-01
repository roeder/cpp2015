#include "Matrix.hpp"

// Copy constructor
Matrix::Matrix(const Matrix& otherMatrix)
{
    // Copy attributes from other matrix
    mNumRows = otherMatrix.mNumRows;
    mNumCols = otherMatrix.mNumCols;

    // Allocate memory for matrix
    mData = new double* [mNumRows];
    for (int i = 0; i<mNumRows; i++)
    {
        mData[i] = new double [mNumCols];
    }

    // Populate matrix with values from other matrix
    for (int i = 0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
}

// Custom constructor
Matrix::Matrix(int numRows, int numCols)
{
    // Assert correct dimensions
    assert(numRows > 0);
    assert(numCols > 0);

    // Set attributes based on input
    mNumRows = numRows;
    mNumCols = numCols;

    // Allocate memory for matrix
    mData = new double* [mNumRows];
    for (int i = 0; i<mNumRows; i++)
    {
        mData[i] = new double [mNumCols];
    }

    // Populate matrix with zeroes
    for (int i = 0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            mData[i][j] = 0.0;
        }
    }
}

// Custom destructor
Matrix::~Matrix()
{
    for (int i = 0; i < mNumRows; i++)
    {
        delete[] mData[i];
    }
    delete[] mData;
}

// Get number of rows
int Matrix::GetNumberOfRows() const
{
    return mNumRows;
}

// Get number of columns
int Matrix::GetNumberOfColumns() const
{
    return mNumCols;
}

// Round brackets overload with 1-based indexing
double& Matrix::operator()(int i, int j)
{
    assert(i > 0);
    assert(j > 0);

    assert(i < mNumRows + 1);
    assert(j < mNumCols + 1);

    return mData[i - 1][j - 1];
}

// Overload assignment operator
Matrix& Matrix::operator=(const Matrix& otherMatrix)
{
    assert(mNumRows = otherMatrix.mNumRows);
    assert(mNumCols = otherMatrix.mNumCols);

    for (int i = 0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }

    return *this;
}

// Overload unary +
Matrix Matrix::operator+() const
{
    Matrix m(mNumRows, mNumCols);
    for (int i = 0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            m(i+1,j+1) = mData[i][j];
        }
    }
    return m;
}

// Overload unary -
Matrix Matrix::operator-() const
{
    Matrix m(mNumRows, mNumCols);
    for (int i = 0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            m(i+1,j+1) = -mData[i][j];
        }
    }
    return m;
}

// Overload binary +
Matrix Matrix::operator+(const Matrix& m1) const
{
    assert(mNumRows == m1.mNumRows);
    assert(mNumCols == m1.mNumCols);

    Matrix m(mNumRows, mNumCols);

    for (int i = 0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            m(i+1,j+1) = mData[i][j] + m1.mData[i][j];
        }
    }
    return m;
}

// Overload binary -
Matrix Matrix::operator-(const Matrix& m1) const
{
    assert(mNumRows == m1.mNumRows);
    assert(mNumCols == m1.mNumCols);

    Matrix m(mNumRows, mNumCols);

    for (int i=0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            m(i+1,j+1) = mData[i][j] - m1.mData[i][j];
        }
    }
    return m;
}

// Overload scalar multiplication
Matrix Matrix::operator*(double a) const
{
    Matrix m(mNumRows, mNumCols);

    for (int i=0; i<mNumRows; i++)
    {
        for (int j=0; j<mNumCols; j++)
        {
            m(i+1,j+1) = a * mData[i][j];
        }
    }
    return m;
}

// Calculate determinant of square matrix recursively
double Matrix::CalculateDeterminant() const
{
    assert(mNumRows == mNumCols);

    double det = 0.0;

    if (mNumRows == 1)
    {
        return mData[0][0];
    } else {
        for (int outer_i =0; outer_i <mNumRows; outer_i++)
        {
            Matrix temp(mNumRows-1, mNumRows-1);

            for (int i=0; i<mNumRows-1; i++)
            {
                for (int j=0; j< outer_i; j++)
                {
                    temp(i+1,j+1) = mData[i+1][j];
                }

                for (int j= outer_i; j<mNumRows-1; j++)
                {
                    temp(i+1,j+1) = mData[i+1][j+1];
                }
            }
            double temp_det;
            temp_det = temp.CalculateDeterminant();

            det += pow(- 1.0, outer_i) * mData[0][outer_i] * temp_det;
        }
    }
    return det;
}


// Overload matrix-by-vector multiplication
Vector operator*(const Matrix& m, const Vector& v)
{
    int input_size = v.GetSize();
    assert(m.GetNumberOfColumns() == input_size);

    int output_size = m.GetNumberOfRows();
    Vector out_vector(output_size);
    for (int i=0; i< output_size; i++)
    {
        for (int j=0; j< input_size; j++)
        {
            out_vector[i] += m.mData[i][j] * v.Read(j);
        }
    }
    return out_vector;
}

// Overload vector-by-matrix multiplication
Vector operator*(const Vector& v, const Matrix& m)
{
    int input_size = v.GetSize();
    assert(m.GetNumberOfRows() == input_size);

    int output_size = m.GetNumberOfColumns();
    Vector out_vector(output_size);
    for (int i=0; i< output_size; i++)
    {
        for (int j=0; j< input_size; j++)
        {
            out_vector[i] += v.Read(j)*m.mData[j][i];
        }
    }
    return out_vector;
}

void Matrix::Print() const
{
    int rows = mNumRows;
    int cols = mNumCols;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << mData[i][j] << " ";
        }
        std::cout << "\n";
    }
}