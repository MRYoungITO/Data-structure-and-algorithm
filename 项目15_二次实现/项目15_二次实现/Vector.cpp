#include "Vector.h"

template <typename T>
Vector<T>::Vector(int size) {
	this->m_len = size;
	this->m_base = new T[m_len];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& object) {
	this->m_len = object.m_len;
	this->m_base = new T[m_len];

	for (int i = 0; i < this->getLength(); i++) {
		this->m_base[i] = object.m_base[i];
	}
}

template <typename T>
int Vector<T>::getLength() {
	return this->m_len;
}

template <typename T>
ostream& operator<<(const ostream& os, const Vector<T>& object) {

}

template <typename T>
T& Vector<T>::operator[](int index) {
	return this->m_base[index];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& object) {
	if (this->m_base) {
		delete[] m_base;
		m_base = NULL;
		m_len = 0;
	}

	this->m_len = object.m_len;
	this->m_base = new T[m_len];

	for (int i = 0; i < this->getLength(); i++) {
		this->m_base[i] = object.m_base[i];
	}

	return *this;
}

template <typename T>
Vector<T>::~Vector() {
	if (this->m_base) {
		delete[] m_base;
		m_base = NULL;
		m_len = 0;
	}
}