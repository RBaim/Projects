#include "matrix.h"

Matrix::Matrix(const Matrix &Copy) {
    this->matr = new double*[Copy.n];
    for (int i = 0; i < Copy.n; i++) {
        *(this->matr + i) = new double[Copy.m];
    }
    this->n = Copy.n;
    this->m = Copy.m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(*(this->matr + i) + j) = *(*(Copy.matr + i) + j);
        }
    }
}
int Matrix::razstrok()
{
    return n;
}
int Matrix::razstolb()
{
    return m;
}
Matrix Matrix::transporn()
{
    Matrix Ci(m, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Ci.formelem(j, i, *(*(matr + i) + j));
        }
    }
    return Ci;
}
Matrix Matrix:: operator+(Matrix &A)
{
    if (n == A.razstrok() && m == A.razstolb())
    {
        Matrix *Ci = new Matrix(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                Ci->formelem(i, j, *(*(matr + i) + j) + A(i, j));
            }
        }
        return *Ci;
    }
    else
    {
        Matrix *B = new Matrix(1, 1);
        return *B;
    }
}
Matrix Matrix:: operator-(Matrix &A)
{
    if (n == A.razstrok() && m == A.razstolb())
    {
        Matrix *Ci = new Matrix(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                Ci->formelem(i, j, *(*(matr + i) + j) - A(i, j));
            }
        }
        return *Ci;
    }
    else
    {
        Matrix *B = new Matrix(1, 1);
        return *B;
    }
}
Matrix Matrix:: operator*(Matrix &A)
{
    if (m == A.razstrok())
    {
        double tmp;
        double **c = new double*[n];
        int k = A.razstolb();
        Matrix *Ci = new Matrix(n, k);
        for (int i = 0; i < k; i++)
        {
            c[i] = new double[k];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                tmp = 0;
                for (int ki = 0; ki < m; ki++)
                {
                    tmp = tmp + *(*(matr + i) + ki) * A(ki, j);
                }
                Ci->formelem(i, j, tmp);
            }
        }
        return *Ci;
    }
    else
    {
        Matrix *B = new Matrix(1, 1);
        return *B;
    }
}
Matrix Matrix:: operator*(double A)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(*(matr + i) + j) = (*(*(matr + i) + j))*A;
        }
    }
    return *this;
}
Matrix & Matrix :: operator= (Matrix &A)
{
    if (this != &A) {
        n = A.n;
        m = A.m;
        matr = new double*[n];
        for (int i = 0; i < n; i++)
        {
            matr[i] = new double[m];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                *(*(matr + i) + j) = A(i, j);
            }
        }
    }
    return *this;
}
double Matrix:: operator()(int i, int j)
{
    return *(*(matr + i) + j);
}
Matrix Matrix::minormat(int i, int j, int n, int m)
{
    if (i - 1 < n&&j - 1 < m)
    {
        Matrix *Ci = new Matrix(n, m);
        bool perep = false;
        int lk = 0, mk = 0;
        for (int mi = 0; mi < n + 1; mi++)
        {
            for (int dj = 0; dj < m + 1; dj++)
            {
                if (mi != i && dj != j)
                {
                    perep = true;
                    Ci->formelem(lk, mk, *(*(matr + mi) + dj));
                    mk++;
                }
            }
            if (perep == true)
            {
                lk++;
                perep = false;
                mk = 0;
            }
        }
        return *Ci;
    }
    else
    {
        Matrix *B = new Matrix(1, 1);
        return *B;
    }
}
Matrix Matrix::minormat(int i, int j)
{
    i--; j--;
    Matrix Ci(n - 1, m - 1);
    if (i - 1 < n&&j - 1 < m)
    {
        bool perep = false;
        int lk = 0, mk = 0;
        for (int mi = 0; mi < n; mi++)
        {
            for (int dj = 0; dj < m; dj++)
            {
                if (mi != i && dj != j)
                {
                    perep = true;
                    Ci.formelem(lk, mk, *(*(matr + mi) + dj));
                    mk++;
                }
            }
            if (perep == true)
            {
                lk++;
                perep = false;
                mk = 0;
            }
        }
        return Ci;
    }
    else
    {
        return Ci;
    }
}
Matrix Matrix::obrat()
{
    double D = det(), a;
    if (D != 0 && n == m&& n > 1)
    {
        Matrix *ras = new Matrix(n - 1, m - 1);
        Matrix *Obrat = new Matrix(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                *ras = minormat(i, j, n - 1, m - 1);
                a = (pow(-1, i + j + 2)*ras->det());
                a /= D;
                Obrat->formelem(j, i, a);
            }
        }
        return *Obrat;
    }
    else
    {
        Matrix *Obrat = new Matrix(1, 1);
        return *Obrat;
    }
}
double Matrix::det()
{
    if (n == m)
    {
        if (n == 1) {
            return this->operator()(0, 0);
        }
        double k, det = 1, tmp;
        int per = 0, g = 0;
        double **a = new double*[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = new double[n];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = this->operator()(i, j);
            }
        }
        for (int c = 0; c < n - 1; c++)
        {
            for (int i = c + 1; i < n; i++)
            {
                for (int k = c; k <= n - i; k++)
                {
                    if (fabs(a[c][c]) < fabs(a[c + k][c]))
                    {
                        g++;
                        tmp = a[c + 1][c];
                        per++;
                        for (int t = 0; t < n; t++)
                        {
                            swap(a[c][t], a[c + k][t]);
                        }
                    }
                    if (a[c][c] == 0 && g == 0)
                    {
                        det = 0;
                    }
                    g = 0;
                }
                if (det != 0)
                {
                    k = a[i][c] / a[c][c];
                    for (int j = 0; j < n; j++)
                    {
                        a[i][j] = a[i][j] - k*a[c][j];
                    }
                }
                for (int ix = 0; ix < n; ix++)
                {
                    for (int jx = 0; jx < n; jx++)
                    {
                        if (fabs(a[ix][jx]) < EPS)
                        {
                            a[ix][jx] = 0;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            det = det*(a[i][i]);
        }
        det = det*pow(-1, per);
        for (int i = 0; i < n; i++)
            delete[] a[i];
        delete[] a;
        return det;
    }
    else { return 0; }
}
Matrix::Matrix(double **a, int n, int m)
{
    this->n = n;
    this->m = m;
    matr = new double*[n];
    for (int i = 0; i < n; i++)
    {
        matr[i] = new double[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(*(matr + i) + j) = *(*(a + i) + j);
        }
    }
}
Matrix::Matrix()
{
    n = 0;
    m = 0;
    matr = NULL;
}
Matrix::Matrix(int n, int m)
{
    this->n = n;
    this->m = m;
    matr = new double*[n];
    for (int i = 0; i < n; i++)
    {
        matr[i] = new double[m];
    }
    null();
}
Matrix::~Matrix()
{
    for (int i = 0; i < n; i++)
    {
        delete[] * (matr + i);
    }
    delete[] matr; n = m = 0;
}
void Matrix::matrget()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

        }
    }
}
void Matrix::matrput()
{

}
void Matrix::formelem(int i, int j, double a)
{
    *(*(matr + i) + j) = a;
}
void Matrix::newmatr(int n, int m)
{
    this->~Matrix();
    this->n = n;
    this->m = m;
    matr = new double*[n];
    for (int i = 0; i < n; i++)
    {
        *(matr + i) = new double[m];
    }
    null();
}
void Matrix::eden()
{
    if (this->n == this->m)
    {
        null();
        for (int i = 0; i < n; i++)
        {
            *(*(matr + i) + i) = 1;
        }
    }
    else
    {
        newmatr(1, 1);//Для удобства в WinForm
    }
}
void Matrix::null()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(*(matr + i) + j) = 0;
        }
    }
}
int Matrix::rang()
{
    int r;
    if (!cheknull())
    {
        double **a;
        int n = razstrok(), m = razstolb();
        double max, k;
        int im = 0, j = 0, swapstolb = 0;
        bool key;
        a = new double*[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = new double[m];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                *(*(a + i) + j) = this->operator()(i, j);
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            max = *(*(a + i) + j);
            im = i;
            while (fabs(max) < EPS && im < n - 1)
            {
                im++;
                max = *(*(a + im) + j);
            }
            if (im == n - 1 && j != 0)
            {
                while (fabs(*(*(a + i) + j)) < EPS && j < m)
                {
                    j++;
                }
            }
            if (fabs(max) < EPS)
            {
                swapstolb = j + 1;
                if (swapstolb < m)
                {
                    swapstolb++;
                    for (int sp = 0; sp < n; sp++)
                    {
                        swap(*(*(a + sp) + j), *(*(a + sp) + swapstolb));
                    }
                    i--;
                    im = 0;
                }
                else
                {
                    i = n - 1;
                    j = -1;
                }
            }
            else
            {
                for (int sp = 0; sp < m; sp++)
                {
                    swap(*(*(a + im) + sp), *(*(a + i) + sp));
                }
                max = *(*(a + i) + j);
                for (int sp = 0; sp < m; sp++)
                {
                    *(*(a + i) + sp) /= max;
                }
                for (int v = i + 1; v < n; v++)
                {
                    k = *(*(a + v) + j);
                    for (int q = 0; q < m; q++)
                    {
                        *(*(a + v) + q) -= k*(*(*(a + i) + q));
                    }
                }
                j++;
            }
            for (int ix = 0; ix < n; ix++)
            {
                for (int jx = 0; jx < m; jx++)
                {
                    if (fabs(*(*(a + ix) + jx)) < EPS)
                    {
                        *(*(a + ix) + jx) = 0;
                    }
                }
            }
        }
        if (j != -1)
        {
            j = 0;
            for (j; j < m; j++)
            {
                if (*(*(a + n - 1) + j) != 0)
                {
                    break;
                }
            }
            max = *(*(a + n - 1) + j);
            for (int sp = 0; sp < m && max != 0; sp++)
            {
                *(*(a + n - 1) + sp) /= max;
            }
        }
        for (int ix = 0; ix < n; ix++)
        {
            for (int jx = 0; jx < m; jx++)
            {
                if (fabs(*(*(a + ix) + jx)) < EPS)
                {
                    *(*(a + ix) + jx) = 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            key = false;
            for (int j = 0; j < m; j++)
            {
                if (*(*(a + i) + j) != 0)
                {
                    key = true;
                    break;
                }
            }
            if (key)
            {
                r = i + 1;
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            delete[] * (a + i);
        }
        delete[] a;
    }
    else
    {
        r = 0;
    }
    return r;
}
bool Matrix::cheknull()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (*(*(matr + i) + j) != 0)
            {
                return false;
            }
        }
    }
    return true;
}
