#include <iostream>
using namespace std;

class Arr
{
public:
    int *A;
    int size, length;

    Arr() : size(0), length(0) {}
    ~Arr() { delete []A; }

    void createArr()
    {
        int n, i;
        cout << "Insert size of the array: ";
        cin >> size;
        A = new int[size];
        cout << "Enter no of elements: ";
        cin >> length;
        cout << "Enter all the elements: ";
        for(i=0 ; i<length ; i++)
        {
            cin >> A[i];
        }
        cout << "Elements added successfully!" << endl << endl;
    }
    void dummyArray()
    {
        int i;
        length = 10;
        for (i = 0; i < length; i++)
        {
            A[i] = i+1;
        }
    }
    void display()
    {
        int i;
        cout << "The elements are:  ";
        for(i=0 ; i<length ; i++)
            cout <<  A[i] << " ";
        cout << endl;
        cout << "Size: " << size <<endl;
        cout << "Length: " << length <<endl;
    }
    void add(int num)
    {
        A[length] = num;
        length++;
    }
    int pop()
    {
        length--;
        return A[length];
    }
    void insert(int index, int num)
    {

        try
        {
            if(index > length)
            throw index;
            int i;
            for(i=length ; i>index ; i--)
            {
                A[i] = A[i-1];
            }
            A[index] = num;
            length++;
        }
        catch(const int err)
        {
            cerr << "The index you entered is " << err << " which is greater than the size of the array: '" << size << "'" <<'\n';
            exit(1);
        }
    }
    void deleteEl(int index)
    {
        int i;
        for(i=index ; i < length-1 ; i++)
            A[i] = A[i+1];
        length--;
    }
    void swap(int i1, int i2);
    int lSearch(int);
    int bSearch(int);
    int get(int index);
    void set(int index, int value);
    int getMax()
    {
        int i, max = A[0];
        for(i=1 ; i<length ; i++)
        {
            if (A[i] > max)
            {
                max = A[i];
            }
        }
        return max;
    }
    int getMin()
    {
        int i, min = A[0];
        for(i=1 ; i<length ; i++)
        {
            if (A[i] < min)
            {
                min = A[i];
            }
        }
        return min;
    }
    int getSum()
    {
        int sum=0, i;
        for(i=0 ; i<length ; i++)
        {
            sum += A[i];
        }
        return sum;
    }
    float getAvg()
    {
        return (float)getSum()/length;
    }
    void reverse()
    {
        int i, j, temp;
        for(i=0, j=length-1 ; i<j ; i++, j--)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
};

// function definitions outside the class
// using scope resolution (::) operator

void Arr::swap(int i1, int i2)
{
    int temp;
    temp = A[i1];
    A[i1] = A[i2];
    A[i2] = temp;
}
int Arr::lSearch(int key)
{
    int i;
    for (i = 0; i < length ; i++)
    {
        if(key == A[i])
        {
            swap(i, i-1); //trasposition
            return i;
        }
    }
    return -1;
}
int Arr::bSearch(int key)
{
    int l, h, mid;
    l = 0;
    h = length-1;

    while (l <= h)
    {
        mid = (l+h)/2;

        if (A[mid] == key)
            return mid;
        else if (key < A[mid])
            h = mid-1;
        else if (key > A[mid])
            l = mid+1;
    }
    return -1;
}
int Arr::get(int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }
    return -1;
}
void Arr::set(int index, int value)
{
    if (index >= 0 && index < length)
    {
        A[index] = value;
    }
}

// main function

int main()
{
    Arr arr1;
    int ch;

    int i1, i2, n, key, srchResult;

    arr1.createArr();

    do
    {
        arr1.display();
        cout << "Enter the value of Array operation you want to perform: " << endl;
        cout << "1. Add an Element at the end" << endl;
        cout << "2. Delete an Element at the end" << endl;
        cout << "3. Insert an Element at a particular index" << endl;
        cout << "4. Delete an Element at a particular index" << endl;
        cout << "5. Set the value of an Element at a particular index" << endl;
        cout << "6. Swap two elements" << endl;
        cout << "7. Search for a particular element (Linear Search)" << endl;
        cout << "8. Search for a particular element (Binary Search)" << endl;
        cout << "9. Get Max element of the array" << endl;
        cout << "10. Get Min element of the array" << endl;
        cout << "11. Get Sum of elements of the array" << endl;
        cout << "12. Get Avg of elements of the array" << endl;
        cout << "13. Exit" << endl << endl;
        cout << "Choose your Option: ";

        cin >> ch;

        cout << endl ;
        cout << "--------------------------------------------------------------------------------------" << endl ;

        switch (ch)
        {
        case 1:
            cout << "Enter the number you want to insert at the end: " ;
            cin >> n;
            arr1.add(n);
            cout << "The updated array is " << endl ;
            arr1.display();
            break;
        case 2:
            n = arr1.pop();
            cout << "The popped element is: " << n << endl ;
            cout << "The updated array is " << endl ;
            arr1.display();
            break;
        case 3:
            cout << "Enter the index and the value of the element you want to insert: " ;
            cin >> i1 >> n ;
            arr1.insert(i1, n);
            cout << "The updated array is " << endl ;
            arr1.display();
            break;
        case 4:
            cout << "Enter the index of the element you want to delete: " ;
            cin >> i1;
            arr1.deleteEl(i1);
            cout << "The updated array is " << endl ;
            arr1.display();
            break;
        case 5:
            cout << "Enter the index and the value of the element you want to modify/set: " ;
            cin >> i1 >> n ;
            arr1.set(i1, n);
            cout << "The updated array is " << endl ;
            arr1.display();
            break;
        case 6:
            cout << "Enter the indices of the elements you want to swap: " ;
            cin >> i1 >> i2 ;
            arr1.swap(i1, i2);
            cout << "The updated array is " << endl ;
            arr1.display();
            break;
        case 7:
            cout << "Enter the value of the element you want to search: " ;
            cin >> key;
            srchResult = arr1.lSearch(key);
            if (srchResult == -1 )
            {
                cout << "The given element " << key << " was not found in the list!" << endl;
            } 
            else
            {
                cout << "The given element " << key << " was found at index " << srchResult << endl ;
            }
            break;
        case 8:
            cout << "Enter the value of the element you want to search: " ;
            cin >> key;
            srchResult = arr1.bSearch(key);
            if (srchResult == -1 )
            {
                cout << "The given element " << key << " was not found in the list!" << endl;
            } 
            else
            {
                cout << "The given element " << key << " was found at index " << srchResult << endl ;
            }
            break;
        case 9:
            cout << "The Max element in the array is: " << arr1.getMax() << endl ;
            break;
        case 10:
            cout << "The Min element in the array is: " << arr1.getMin() << endl ;
            break;
        case 11:
            cout << "The Sum of the elements in the array is: " << arr1.getSum() << endl ;
            break;
        case 12:
            cout << "The Average of the elements in the array is: " << arr1.getAvg() << endl ;
            break;
        case 13:
            exit(1);
            break;
        default:
            exit(1);
            break;
        }

        cout << "--------------------------------------------------------------------------------------" << endl << endl;

    } while (ch > 0 && ch < 14);
    
    return 0;
}
