#include <iostream>

template <typename T>
class ring_buffer{
int size;//actual size of buffer
T* data;//the set of elems
int capacity;//size+free place
int index_put=0;//index of following elem
int index_old=0;//index of old elem

public:
ring_buffer(); //initialization of fields
ring_buffer(int _size);//initialization of fields with particular size
ring_buffer(T* _data,int _size);//initialization of fields with particular size and set of elems
ring_buffer(ring_buffer& ring_buf);//copying constructor
~ring_buffer();//erase dynamic fields
void push(T new_elem);//addition of new elem into buffer(if it's overflowed,new elem puts on the place of old one)
T& top();//get the reference to the next elem
void pop();//deleting the following elem
int Size();//getter of an actual size of buffer

bool operator<(ring_buffer& a);
bool operator==(ring_buffer& a);
friend std::ostream& operator<<(std::ostream& out, const ring_buffer& a){
        for(int i=0;i<size;i++)
            out<<a.data[i];
        return out;
}

};

template<typename T>
ring_buffer<T>::ring_buffer(){
        size=128;
        capacity=0;
        data=new T[size];

    }

template<typename T>
ring_buffer<T>::  ring_buffer(int _size){
        size=_size;
        capacity=0;
        data=new T[size];

    }

template<typename T>
ring_buffer<T>::  ring_buffer(T* _data,int _size){
        size=_size;
        capacity=_size;
        data=new T[size];
        for(int i=0;i<size;i++){
            data[i]=_data[i];
        }

    }

template<typename T>
ring_buffer<T>::  ring_buffer(ring_buffer& ring_buf){
        size=ring_buf.size;
        capacity=ring_buf.capacity;
        index_put=ring_buf.index_put;
        index_next=ring_buf.index_old;
        data=new T[size];
        for(int i=0;i<size;i++)
            data[i]=ring_buf.data[i];

    }

template<typename T>
ring_buffer<T>:: ~ring_buffer(){
    delete[] data;
}

template<typename T>
void ring_buffer<T>:: push(T new_elem){
        data[index_put]=new_elem;
        index_put=(index_put+1)%size;

    }

template<typename T>
 T& ring_buffer<T>:: top(){
        return &data[index_old];

    }

template<typename T>
void ring_buffer<T>:: pop(){
        index_old=(index_old+1)%size;

    }

template<typename T>
int ring_buffer<T>::Size(){
        return size;
    }

template<typename T>
bool ring_buffer<T>:: operator<(ring_buffer& a){

        if(size<a.size)
            return true;
        if(size==a.size)
            for(int i=0;i<size-1;i++)
                if((data[i]<a.data[i])||(data[i]==a.data[i]&&data[i+1]<a.data[i+1]))
                    return true;

                else
                    return false;

    }

template<typename T>
bool ring_buffer<T>::operator==(ring_buffer& a){
        if(size!=a.size) return false;
        else
            for (int i=0;i<size;i++)
                if(data[i]!=a.data[i])
                    return false;
        return true;
    }

int main(){


    return 0;
}

