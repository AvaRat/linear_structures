#pragma once
#ifndef AISDI_LINEAR_VECTOR_H
#define AISDI_LINEAR_VECTOR_H

#include <iostream>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <cmath>

namespace aisdi
{

	template <typename Type>
	class Vector
	{
	public:
		// aliases for objects types used later
		using difference_type = std::ptrdiff_t;
		using size_type = std::size_t;
		using object_type = Type;
		using pointer = Type * ;
		using reference = Type & ;
		using const_pointer = const Type*;
		using const_reference = const Type&;
		class ConstIterator;
		class Iterator;
		using iterator = Iterator;
		using const_iterator = ConstIterator;

	private:
		object_type *v_buffer;
		size_type v_size;
		size_type v_capacity;
		size_type object_size;
		size_type object_count;


	public:
		Vector()
		{
			std::cout << "default Vector constructor\n";
			v_capacity = object_size * 20;
			v_buffer = new object_type[20];
			object_size = sizeof(object_type);
			v_size = 0;
			object_count = 0;
		}
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		Vector(std::initializer_list<Type> init)
		{
			auto *tmp = init.begin();
			size_type i = 1;
			v_buffer = new object_type[init.size() + 20 * object_size];

				v_buffer[i] = *tmp;

				object_size = sizeof(object_type);
				object_count = i;
				v_capacity = init.size() + 20 * object_size;

		//	std::cout << "copied " << i << " elements\n";
			(void)init; // disables "unused argument" warning, can be removed when method is implemented.
		//	throw std::runtime_error("TODO");
		}

		Vector(const Vector& other)
		{
			v_buffer = new object_type[other.v_capacity];
			v_capacity = other.v_capacity;
			for (size_t i = 0; i < v_capacity; ++i)
			{
				v_buffer[i] = other.v_buffer[i];
			}
			v_size = other.v_size;
			object_size = other.object_size;
			object_count = other.object_count;

			(void)other;
		//	throw std::runtime_error("TODO");
		}

		Vector(Vector&& other)
		{
			(void)other;
			throw std::runtime_error("TODO");
		}

		~Vector()
		{
			delete[] v_buffer;
			std::cout << "default Vector destructor\n";
		}

		Vector& operator=(const Vector& other)
		{
			(void)other;
			throw std::runtime_error("TODO");
		}

		Vector& operator=(Vector&& other)
		{
			(void)other;
			throw std::runtime_error("TODO");
		}

		bool isEmpty() const
		{
			//return begin() == end(); 
			if (object_count == 0)
				return 1;
			else return 0;
			throw std::runtime_error("TODO");
		}

		size_type getSize() const
		{
			return v_size;
			throw std::runtime_error("TODO");
		}

		void print()
		{
			for (size_type i = 0; i < object_count; ++i)
				std::cout << v_buffer[i] << std::endl;
			std::cout << "v_size = " << v_size << std::endl << "v_capacity = " << v_capacity << std::endl
				<< "object_size = " << object_size << std::endl
				<< "object_count = " << object_count << std::endl;
		}
		void printStats()
		{
				float sum = 0.0, mean, standardDeviation = 0.0;

				size_t i;

				for (i = 0; i < object_count; ++i)
				{
					sum += v_buffer[i];
				}
				mean = sum / object_count;
				for (i = 0; i < object_count; ++i)
					standardDeviation += pow(v_buffer[i] - mean, 2);

				std::cout <<"standart deviation: " <<  sqrt(standardDeviation / 10) << std::endl;
				std::cout << "mean: " << mean << std::endl;
		}

		void reserve(size_type capac)
		{
			object_type * newBuff = new object_type[capac];
			for (size_type i = 0; i < object_count; ++i)
			{
				newBuff[i] = v_buffer[i];
			}
			v_capacity = capac;
			delete[] v_buffer;
			v_buffer = newBuff;
			std::cout << "reserving space\n";
		}

		void append(const Type& item)
		{
			if (v_size + object_size >= v_capacity )
				reserve(v_capacity * 2 + 10*object_size);
			v_buffer[object_count++] = item;
			v_size += object_size;
			
			(void)item;
		//	throw std::runtime_error("TODO");
		}

		void prepend(const Type& item)
		{
			object_type *newBuff = new object_type[v_capacity + object_size];

			for (size_type i = 1; i < object_count; ++i)
			{
				newBuff[i] = v_buffer[i-1];
			}
				newBuff[0] = item;
				delete[] v_buffer;
				v_buffer = newBuff;
			
			(void)item;
	//		throw std::runtime_error("TODO");
		}

		void insert(const const_iterator& insertPosition, const Type& item)
		{
			(void)insertPosition;
			(void)item;
			throw std::runtime_error("TODO");
		}

		Type popFirst()
		{
			return v_buffer[0];
			throw std::runtime_error("TODO");
		}

		Type popLast()
		{
			/*this->_M_impl._M_finish;
	_Alloc_traits::destroy(this->_M_impl, this->_M_impl._M_finish);*/
			return v_buffer[object_count-1];
			throw std::runtime_error("TODO");
		}

		void erase(const const_iterator& possition)
		{
			(void)possition;
			throw std::runtime_error("TODO");
		}

		void erase(const const_iterator& firstIncluded, const const_iterator& lastExcluded)
		{
			(void)firstIncluded;
			(void)lastExcluded;
			throw std::runtime_error("TODO");
		}

		iterator begin()
		{
		//	return iterator(this-> first_element)	
			throw std::runtime_error("TODO");
		}

		iterator end()
		{
			//	return iterator(this-> last_element)
			throw std::runtime_error("TODO");
		}

		const_iterator cbegin() const
		{
			//	return ConstIterator(this-> first_element)
			throw std::runtime_error("TODO");
		}

		const_iterator cend() const
		{
			//	return ConstIterator(this-> last_element)
			throw std::runtime_error("TODO");
		}

		const_iterator begin() const
		{
			//	return ConstIterator(this-> first_element)	
			return cbegin();
		}

		const_iterator end() const
		{
			//	return ConstIterator(this-> last_element)
			return cend();
		}
	};

	template <typename Type>
	class Vector<Type>::ConstIterator
	{
	public:
		using iterator_category = std::bidirectional_iterator_tag;
		using value_type = typename Vector::value_type;
		using difference_type = typename Vector::difference_type;
		using pointer = typename Vector::const_pointer;
		using reference = typename Vector::const_reference;
	private:
		/*		difference_type pointer_difference;
		size_t object_size;
		value_type object;
		pointer object_pointer;
		reference object_reference;*/

	public:
		explicit ConstIterator()
		{
			std::cout << "default (explicit) ConstIterator constructor\n";
		}


		reference operator*() const
		{
			throw std::runtime_error("TODO");
		}

		ConstIterator& operator++()
		{
			throw std::runtime_error("TODO");
		}

		ConstIterator operator++(int)
		{
			throw std::runtime_error("TODO");
		}

		ConstIterator& operator--()
		{
			throw std::runtime_error("TODO");
		}

		ConstIterator operator--(int)
		{
			throw std::runtime_error("TODO");
		}

		ConstIterator operator+(difference_type d) const
		{
			(void)d;
			throw std::runtime_error("TODO");
		}

		ConstIterator operator-(difference_type d) const
		{
			(void)d;
			throw std::runtime_error("TODO");
		}

		bool operator==(const ConstIterator& other) const
		{
			(void)other;
			throw std::runtime_error("TODO");
		}

		bool operator!=(const ConstIterator& other) const
		{
			(void)other;
			throw std::runtime_error("TODO");
		}
	};

	template <typename Type>
	class Vector<Type>::Iterator : public Vector<Type>::ConstIterator
	{
	public:
		using pointer = typename Vector::pointer;
		using reference = typename Vector::reference;

		explicit Iterator()
		{
			std::cout << "default (explicit) Iterator constructor\n";
		}

		Iterator(const ConstIterator& other)
			: ConstIterator(other)
		{
			
		}

		Iterator& operator++()
		{
			ConstIterator::operator++();
			return *this;
		}

		Iterator operator++(int)
		{
			auto result = *this;
			ConstIterator::operator++();
			return result;
		}

		Iterator& operator--()
		{
			ConstIterator::operator--();
			return *this;
		}

		Iterator operator--(int)
		{
			auto result = *this;
			ConstIterator::operator--();
			return result;
		}

		Iterator operator+(difference_type d) const
		{
			return ConstIterator::operator+(d);
		}

		Iterator operator-(difference_type d) const
		{
			return ConstIterator::operator-(d);
		}

		reference operator*() const
		{
			// ugly cast, yet reduces code duplication.
			return const_cast<reference>(ConstIterator::operator*());
		}
	};

}

#endif // AISDI_LINEAR_VECTOR_H


