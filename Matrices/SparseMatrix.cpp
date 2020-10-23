#include <iostream>
using namespace std;

// element class containing row number, column number and value of the element in the matrix
class Element
{
public:
    int row;
    int col;
    int val;
};

// sparse matrix class containing no of rows, columns and non-zero elements in the sparse matrix
class Sparse
{
private:
    int m;
    int n;
    int num;
    Element *ele;    // a pointer to an array to store details of each element 

public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }

    ~Sparse()
    {
        delete []ele;
    }

    // operator overloading of + operator to add two sparse matrices
    Sparse operator +(Sparse &s);

    // operator overloading of extraction operator to read the matrix using cin function
    friend istream & operator >> (istream &is, Sparse &s);
    // operator overloading of insertion operator to display the matrix using cout function
    friend ostream & operator << (ostream &os, Sparse &s);

};

Sparse Sparse::operator+(Sparse &s)
{
    // taking three variables to keep the track of elements in s1, s2 and sum
    int i, j, k;
    Sparse sum(m, n, num + s.num);

    // exit if row and col size are not equal
    if (m != s.m || n != s.n)
        exit(1);

    i=j=k=0;
    while (i < num && j < s.num)
    {
        if (ele[i].row < s.ele[j].row)
            sum.ele[k++] = ele[i++];
        else if (ele[i].row > s.ele[j].row)
            sum.ele[k++] = s.ele[j++];
        else
        {
            if (ele[i].col < s.ele[j].col)
                sum.ele[k++] = ele[i++];
            else if (ele[i].col > s.ele[j].col)
                sum.ele[k++] = s.ele[j++];
            else
            {
                sum.ele[k] = ele[i++];
                sum.ele[k++].val += s.ele[j++].val;
            }
        }
    }
    for (; i < num ; i++)
        sum.ele[k++] = ele[i];
    for (; j < s.num ; j++)
        sum.ele[k++] = s.ele[j];

    sum.num = k;
    
    return sum;
}

istream & operator >> (istream &is, Sparse &s)
{
    cout << "Enter the row, column and value of all the elements: " << endl ;
    for(int i=0 ; i < s.num ; i++)
        cin >> s.ele[i].row >> s.ele[i].col >> s.ele[i].val ;
    cout << endl ;
    return is;
}


ostream & operator << (ostream &os, Sparse &s)
{
    int k=0; 
    cout << "The Sparse Matrix is: " << endl ;
    for (int i = 0 ; i < s.m ; i++)
    {
        for (int j = 0 ; j < s.n ; j++)
        {
            if (s.ele[k].row == i && s.ele[k].col == j)
            {
                cout << s.ele[k++].val << " " ;
            }
            else
                cout << "0 ";
        }
        cout << endl ;
    }
    cout << endl ;
    return os;
}

int main()
{
    // creating two sparse matrices s1 and s2
    Sparse s1(5, 5, 5);
    Sparse s2(5, 5, 5);

    // reading matrices as input from the user
    cout << "First Matrix" << endl ;
    cin >> s1;
    cout << "Seccond Matrix" << endl ;
    cin >> s2;
    
    // performing matric addition
    Sparse sum = s1 + s2;

    // displaying all the matrices
    cout << "First Matrix" << endl << s1 ;
    cout << "Second Matrix" << endl << s2 ;
    cout << "Addition Matrix" << endl << sum ;

    return 0;
}