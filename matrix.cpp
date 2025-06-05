template<typename T>
class Matrix
{
    public:
    int no_of_row;
    int no_of_col;
    T value;
    T* elem;
    int flag;

    Matrix()
    {
        cout<<"Enter number of row: ";
        cin>>no_of_row;
        cout<<"Enter number of column: ";
        cin>>no_of_col;
        cout<<"Enter '1' for storing in Row-Major or '0' for storing in Column-Major format: ";
        cin>>flag;

        elem = new T[no_of_row*no_of_col];
    }
    void input();
    T store_row_major(int i, int j, T value);
    T store_col_major(int i, int j, T value);
    void display();
    
};

// Storing values in row major format
template<typename T>T Matrix<T>::store_row_major(int i, int j, T value)
{
    elem[i*no_of_col+j]=value;

    
}

//storing values in column major format
template<typename T>T Matrix<T>::store_col_major(int i, int j, T value)
{
    elem[j*no_of_row+i]=value;
}

//input the elements of matrix
template<typename T>void Matrix<T>::input()
{
    cout<<"Enter the elements of the matrix:"<<endl;
    for(int i=0; i<no_of_row; i++)
    {
        for(int j= 0; j<no_of_col; j++)
        {
            cin>>value;
            if (flag == 1)
            {
                store_row_major(i,j, value);
            }
            else
            { 
                store_col_major(i, j, value);
            }
            
        }
    }
}

//printing the matrix
template<typename T>void Matrix<T>::display()
{
    cout<<"The Matrix in ";
    if (flag == 1)
    {
        cout<<"Row-Major format:"<<endl;
        for(int i = 0; i<no_of_row; i++)
        {
            for (int j = 0; j < no_of_col; j++)
            {
                cout<<elem[i*no_of_col+j]<<"\t";
            }
            cout<<endl;
            
        }
    }
    else
    {
        cout<<"Column-Major format:"<<endl;
        for (int i = 0; i < no_of_row; i++)
        {
            for (int j = 0; j < no_of_col; j++)
            {
                cout<<elem[i*no_of_row+j]<<"\t";
            }
            cout<<endl;
        }
        
    }
    
}

int main()
{
    Matrix<int> t;
    t.input();
    t.display();

    return 0;
}
