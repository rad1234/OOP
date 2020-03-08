#pragma once
#include <iterator>

template <typename T>
class dynamicVector 
{
private:
	T* elements;
	int size;
	int capacity;

public:
	dynamicVector(int capacity = 10);

	dynamicVector(const dynamicVector& vector);

	~dynamicVector();

	dynamicVector& operator=(const dynamicVector& vector);

	T& operator[](int position);


	void add(const T& element);

	void remove(const T& element);

	int getSize() const;

	void setSize(int value) { size = value; }

private:
	void resize(double factor = 2);

public:
	class iterator
	{
	private:
		T* pointer;
	public:
		iterator(T* pointer) {
			this->pointer = pointer;
		}

		iterator operator++() const
		{
			this->pointer++;
			return *this;
		}

		iterator operator++(int)
		{ 
			iterator currentIterator = *this;
			this->pointer++;
			return currentIterator;
		}

		T operator*()
		{
			return *this->pointer;
		}

		bool operator !=(const iterator& compare)
		{
			return this->pointer != compare.pointer;
		}

		bool operator ==(const iterator& compare)
		{
			return this->pointer == compare.pointer;
		}

	};

	iterator begin()
	{
		return iterator{ elements };
	}

	iterator end()
	{
		return iterator{ elements + size };
	}
};

template <typename T>
dynamicVector<T>::dynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new T[capacity];
}

template <typename T>
dynamicVector<T>::dynamicVector(const dynamicVector<T>& vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;

	this->elements = new T[this->capacity];
	for (int index = 0; index < this->size; index++)
		this->elements[index] = vector.elements[index];
}

template <typename T>
dynamicVector<T>::~dynamicVector()
{
	delete[] this->elements;
}

template <typename T>
dynamicVector<T>& dynamicVector<T>::operator=(const dynamicVector<T>& vector)
{
	if (this == &vector)
		return *this;

	this->size = vector.size;
	this->capacity = vector.capacity;

	delete[] this->elements;
	this->elements = new T[this->capacity];
	for (int index = 0; index < this->size; index++)
		this->elements[index] = vector.elements[index];

	return *this;
}

template <typename T>
void dynamicVector<T>::add(const T& element)
{
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size] = element;
	this->size++;
}

template <typename T>
void dynamicVector<T>::remove(const T& element)
{
	for (int index = 0; index < this->size; index++)
	{
		if (this->elements[index] == element)
			for (int jndex = index; jndex < this->size - 1; jndex++)
				this->elements[jndex] = this->elements[jndex + 1];
		this->size--;
		index = this->size;
	}
}



template <typename T>
T& dynamicVector<T>::operator[](int position)
{
	return this->elements[position];
}




template <typename T>
void dynamicVector<T>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	T* newElements = new T[this->capacity];
	for (int index = 0; index < this->size; index++)
	newElements[index] = this->elements[index];

	delete[] this->elements;
	this->elements = newElements;
}

template <typename T>
int dynamicVector<T>::getSize() const
{
	return this->size;
}
