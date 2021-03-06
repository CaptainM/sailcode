#include "buffer.h"

template <class T>
Buffer<T>::Buffer(int s)  : size(s), n(0){
	this->buf = new T[s];
	for(int i = 0; i < this->size; i ++)
	{
		this->buf[i] = -1000;
	}
	return;
}

template<class T>
void Buffer<T>::add(T item) {
	//Adds an item to the buffer
	this->buf[this->n] = item;
	if(n+1<size) {
		n=0;//Wrap around
	} else {
		n++;
	}
	return;
}

template<class T>
T Buffer<T>::pop() {
	//Removes the last added item from the buffer, and returns it.

	if(n==0) {
		n=size;
	}
	n--;
	return this->buf[n];
}

template<class T>
T* Buffer<T>::get() {
	//Returns the buffer array, out of order
	T* temp = new T[this->size];
	for(int i=0; i<this->size;i++) {
		temp[i] = this->buf[i];
	}
	return temp;
}

template<class T>
T Buffer<T>::peek() {
	//Returns the last added item in the buffer, without removing it.
	int i = n-1;
	if(i<0){
		i=size-1;
	}
	return buf[i];
}

template<class T>
int Buffer<T>::peek(T* item) {
	//Copys the last added item in the buffer into item,
	//And returns its index;
	int i = n-1;
	if(i<0) {
		i=this->size-1;
	}
	*item = buf[i];
	return i;
}

template<class T>
T Buffer<T>::average(){
	//returns the current average of the buffer
	T sum = 0;
	int num = this->size;
	for(int i = 0; i <this->size; i++)
	{
		if (this->buf[i] == -1000){
			num--;
		}
		else{
			sum+= this->buf[i];
		}

	}
	this->avg = sum/num;
	return avg;
}


template class Buffer<float>;
template class Buffer<int>;
template class Buffer<long>;