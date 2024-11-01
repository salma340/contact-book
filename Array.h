#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
#include<algorithm>
using namespace std;
template <typename T>
class Array
{
public:

    Array(size_t cap=10)
    {
        current_size=0;
        Size=cap;
        arr=new T [Size];
    }
    Array(const Array&other)
    {
        current_size=other.current_size;
        arr=new T [current_size];
        for(size_t i=0; i<current_size; i++)
            arr[i] = other.arr[i];
    }
    Array& operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] arr;
            current_size = other.current_size;
            arr = new T[current_size];
            for (int i = 0; i < current_size; ++i)
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    void append(const T &value)
    {
        if( current_size>=Size)
        {
            Resize(current_size*2);//new current size
        }
        arr[ current_size++]=value;

    }
    void Insert(T element,size_t index)
    {
        if(current_size>=Size)
        {
            Resize(current_size*2);
        }
        if(index>=Size)
        {
            throw out_of_range("Index out of range");
        }
        else
        {

            for(size_t i=current_size; i>index; i--)
            {
                arr[i]=arr[i-1];
            }
            arr[index]=element;
            current_size++;
        }
    }
    void Remove()
    {
        arr[--current_size];
        if(current_size<=Size/4)
        {
            Resize(Size/2);
        }
    }
    void Delete(size_t index)
    {
        if(index>=current_size)
            throw out_of_range("Index out of range");
        else
        {
            for(size_t i=index; i<current_size; i++)
            {
                arr[i]=arr[i+1];
            }

            current_size--;

        }


    }
    void Clear()
    {
        current_size=0;
        //shrink
        Resize(10);
    }
    T get(size_t index) const
    {
        if(index>=current_size)
            throw out_of_range("Index out of range");
        else
            return arr[index];
    }
    size_t get_size()const
    {
        return current_size;
    }
    void Reverse()
    {
        size_t s=0;
        size_t e=current_size-1;
        while(s<e)
        {
            T temp=arr[s];
            arr[s]=arr[e];
            arr[e]=temp;
            s++;
            e--;
        }
    }
    void Search(T element)
    {
        Sort();
        size_t low=0;
        size_t heigh=current_size-1;
        size_t middle=0;
        while(low<=heigh)
        {
            middle=(low+(heigh-low)/2);
            if(arr[middle]== element)
            {
                cout<<"The element "<<element<<" is Found "<<endl;
                break;
            }
            else if(element>arr[middle])
            {
                low=middle+1;

            }
            else
            {
                heigh=middle-1;
            }

        }
        if(low>heigh)
            cout<<"Element not found "<<endl;



    }
    void Sort()
    {
        for(size_t i=0; i<current_size-1; i++)
        {
            for(size_t j=0; j<current_size-i-1; j++)
            {
                if(arr[j]>arr[j+1])
                {
                    size_t temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }
    void display()const
    {
        for(size_t i=0; i<current_size; i++)
        {
            arr[i].display();// display every element in the array of persons
        }
        cout<<endl;
    }
    T& operator[](size_t index)
    {
        if(index>=0 && index<Size)
            return arr[index];
    }
    ~Array()
    {
        delete []arr;
    }
private:

    size_t current_size;
    size_t Size;
    T *arr;

    //helper function
    void Resize(size_t newsize)
    {
        T*ptr=new T[newsize];
        for(size_t i=0; i<current_size; i++)
        {
            ptr[i]=arr[i];
        }
        delete []arr;
        arr=ptr;
        Size=newsize;
    }

};

#endif // ARRAY_H
