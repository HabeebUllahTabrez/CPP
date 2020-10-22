#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

class Diagonal
{
private:
    int *A;
    int n;

public:
    Diagonal() 
    {
        n = 2;
        A = new int[2*(2+1)/2];
    }
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~Diagonal()
    {
        delete []A;
    }

    void set(int i, int j, int x)
    {
        if(i == j)
            A[i-1] = x;   
    }

    int get(int i, int j)
    {
        if(i == j)
            return A[i-1];
        else
            return 0;
    }

    void create()
    {
        int x;
        cout << "Enter all the elements: " << endl ;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> x;
                set(i, j, x);
            }
        }
        cout << endl;
    }

    void display()
    {
        cout << "The Elements are " << endl ;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

class LowerTri
{
private:
    int *A;
    int n;

public:
    LowerTri() 
    {
        n = 2;
        A = new int[2*(2+1)/2];
    }
    LowerTri(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~LowerTri()
    {
        delete []A;
    }

    void set(int i, int j, int x)
    {
        if(i >= j)
        {
            A[i*(i-1)/2 + j-1] = x;                         // row major formula
            // A[n*(j-1) - (j-2)*(j-1)/2 + i-j] = x;        // column major formula
        }        
    }

    int get(int i, int j)
    {
        if(i >= j)
        {
            return A[i*(i-1)/2 + j-1];                      // row major formula
            // return A[n*(j-1) - (j-2)*(j-1)/2 + i-j];     // column major formula
        }
        else
            return 0;
    }

    void create()
    {
        int x;
        cout << "Enter all the elements: " << endl ;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> x;
                set(i, j, x);
            }
        }
        cout << endl;
    }

    void display()
    {
        cout << "The Elements are " << endl ;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

class UpperTri
{
private:
    int *A;
    int n;

public:
    UpperTri() 
    {
        n = 2;
        A = new int[2*(2+1)/2];
    }
    UpperTri(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~UpperTri()
    {
        delete []A;
    }

    void set(int i, int j, int x)
    {
        if(i <= j)
        {
            A[n*(i-1) - (i-2)*(i-1)/2 + j-i] = x;          // row major formula
            //  A[j*(j-1)/2 + i-1] = x;                    // column major formula
        }        
    }

    int get(int i, int j)
    {
        if(i <= j)
        {
            return A[n*(i-1) - (i-2)*(i-1)/2 + j-i];      // row major formula
            //  return A[j*(j-1)/2 + i-1];                // column major formula
        }
        else
            return 0;
    }

    void create()
    {
        int x;
        cout << "Enter all the elements: " << endl ;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> x;
                set(i, j, x);
            }
        }
        cout << endl;
    }

    void display()
    {
        cout << "The Elements are " << endl ;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// A symmetrix matrix can be represented by only storing either its upper triangular matrix or lower triangular matrix
// here we take it as lower triangular matrix
class Symmetric
{
private:
    int *A;
    int n;

public:
    Symmetric() 
    {
        n = 2;
        A = new int[2*(2+1)/2];
    }
    Symmetric(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~Symmetric()
    {
        delete []A;
    }

    void set(int i, int j, int x)
    {
        if(i >= j)
        {
            A[i*(i-1)/2 + j-1] = x;                         // row major formula
            // A[n*(j-1) - (j-2)*(j-1)/2 + i-j] = x;        // column major formula
        }        
    }

    int get(int i, int j)
    {
        if(i >= j)
        {
            return A[i*(i-1)/2 + j-1];                      // row major formula
            // return A[n*(j-1) - (j-2)*(j-1)/2 + i-j];     // column major formula
        }
        else
        {
            swap(&i, &j);
            return A[i*(i-1)/2 + j-1];
        }
    }

    void create()
    {
        int x;
        cout << "Enter all the elements: " << endl ;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> x;
                set(i, j, x);
            }
        }
        cout << endl;
    }

    void display()
    {
        cout << "The Elements are " << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, choice;
    cout << "Input size of the Square Matrix: ";
    cin >> n;
    cout << endl;

    cout << "Choose the type of matrix you want to create (1-4): " << endl ;
    cout << "1. Diagonal" << endl ;
    cout << "2. Upper Triangular" << endl ;
    cout << "3. Lower Triangular " << endl ;
    cout << "4. Symmetric" << endl ;
    cout << "--------------------------------------------------------" << endl;
    cout << ": ";
    cin >> choice;
    cout << "--------------------------------------------------------" << endl << endl;

    if (choice == 1)
    {
        Diagonal mtx(n);
        mtx.create();
        mtx.display();
    }
    else if (choice == 2)
    {
        UpperTri mtx(n);
        mtx.create();
        mtx.display();
    }
    else if (choice == 3)
    {
        LowerTri mtx(n);
        mtx.create();
        mtx.display();
    }
    else if (choice == 4)
    {
        Symmetric mtx(n);
        mtx.create();
        mtx.display();
    }
    else
    {
        cout << "Number not in range!" << endl ;
        exit(1);
    }
    
}
