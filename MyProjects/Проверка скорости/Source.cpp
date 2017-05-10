#include <iostream>
#include <time.h>
#define EPS 0.000001

using namespace std;

void random(double **a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(*(a + i) + j) = rand() % 2;
        }
    }
}

double det(double **b, int n)
{
    if (n == 1)
    {
        return b[0][0];
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
            a[i][j] = b[i][j];
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

double det(double *b, int n)
{
    if (n == 1)
    {
        return *b;
    }
    double k, det = 1, tmp;
    int per = 0, g = 0;
    double *a = new double[n*n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(a + i*n + j) = *(b + i*n + j);
        }
    }
    for (int c = 0; c < n - 1; c++)
    {
        for (int i = c + 1; i < n; i++)
        {
            for (int k = c; k <= n - i; k++)
            {
                if (fabs(*(a+ c*n + c)) < fabs(*(a + n*(c + k) +c)))
                {
                    g++;
                    tmp = *(a +n*(c + 1) + c);
                    per++;
                    for (int t = 0; t < n; t++)
                    {
                        swap(*(a +n*c +t), *(a+n*(c + k) +t));
                    }
                }
                if (*(a+n*c+c) == 0 && g == 0)
                {
                    det = 0;
                }
                g = 0;
            }
            if (det != 0)
            {
                k = *(a+n*i+c) / *(a+n*c+c);
                for (int j = 0; j < n; j++)
                {
                    *(a+n*i+j) = *(a+n*i+j) - k*(*(a+n*c+j));
                }
            }
            for (int ix = 0; ix < n; ix++)
            {
                for (int jx = 0; jx < n; jx++)
                {
                    if (fabs(*(a+n*ix+jx)) < EPS)
                    {
                        *(a+n*ix +jx) = 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        det = det*(*(a+i*n+i));
    }
    det = det*pow(-1, per);
    delete[] a;
    return det;
}

int main() {
    system("color f0");
    long t;
    double **a;
    double *b;
    srand(time(0));
    int n;
    cin >> n ;
    a = new double*[n];
    for (int i = 0; i < n; i++) {
        *(a + i) = new double[n];
    }
    b = new double[n*n];
    random(a, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(b + i*n + j) = *(*(a + i) + j);
        }
    }
    t = clock();
    cout << det(a, n) << endl;
    cout << (clock() - t) / 1000.0 << endl;
    t = clock();
    cout << det(b, n) << endl;
    cout << (clock() - t) / 1000.0 << endl;
    system("pause");
    return 0;
}
