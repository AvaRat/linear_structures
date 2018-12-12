#pragma once
#ifndef AISDI_LINEAR_LINKEDLIST_H
#define AISDI_LINEAR_LINKEDLIST_H

#include <cstddef>
#include <initializer_list>
#include <stdexcept>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

namespace aisdi
{

	template <typename Type>
	class LinkedList
	{
	public:
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
		struct Node{
			object_type data;
			Node *next;
			Node *previous;
		};
		Node *first = nullptr;
		Node *last = nullptr;
		size_type count;



	public:
		using node_ptr = Node *;
		LinkedList()
		{
			first = nullptr;
			last = nullptr;
			count = 0;
		}

		LinkedList(std::initializer_list<Type> init)
		{

			auto *init_ptr = init.begin();
			size_type i;
			first = DBG_NEW Node;
			Node *tmp = first;
			Node *prev = nullptr;
			for (i = 0; i+1 < init.size(); ++i, ++init_ptr)
			{
				tmp->data = *init_ptr;
				//if(init.size() - i  != 1)
					tmp->next = DBG_NEW Node;
				tmp->previous = prev;
				prev = tmp;
				tmp = tmp->next;			
			}
			tmp->data = *init_ptr;
			tmp->previous = prev;
			tmp->next = nullptr;
			last = tmp;
			count = init.size();
	//		(*tmp)->next = nullptr;
		//	(void)init; // disables "unused argument" warning, can be removed when method is implemented.
		//	throw std::runtime_error("TODO");
		}

		LinkedList(const LinkedList& other)
		{
			first = DBG_NEW Node;
			Node *tmp = first;
			Node *other_tmp = other.first;
			Node *prev = nullptr;
			for (; other_tmp != other.last; tmp = tmp->next, other_tmp = other_tmp->next)
			{
				tmp->data = other_tmp->data;
				tmp->next = DBG_NEW Node;
				tmp->previous = prev;
				prev = tmp;
			}
			tmp->data = other_tmp->data;
			tmp->previous = prev;
			tmp->next = nullptr;
			last = tmp;
			count = other.count;
			(void)other;
		//	throw std::runtime_error("TODO");
		}

		LinkedList(LinkedList&& other)
		{
			(void)other;
			throw std::runtime_error("TODO");
		}

		~LinkedList()
		{
			if ((*this).isEmpty())
				return;

			node_ptr tmp = nullptr;
			while (first != nullptr)
			{
				tmp = first;
				first = first->next;
				delete tmp;
			}
			first = nullptr;
			last = nullptr;
			count = 0;
			_CrtDumpMemoryLeaks();
		}

		void destroy()
		{
			node_ptr tmp = nullptr;
			while (first != nullptr)
			{
				tmp = first;
				first = first->next;
				delete tmp;
			}
			first = nullptr;
			last = nullptr;
			count = 0;
		}

		void print()
		{
			if (first == nullptr)
				return;
			std::cout << "first: " << first->data << std::endl;
			if(!first->previous)
				std::cout << "\tprevious: nullptr\n " << std::endl;

			std::cout << "last: " << last->data << std::endl;
			if (!last->next)
				std::cout << "\tnext: nullptr\n " << std::endl;

			std::cout << "count: " << count << std::endl;
			Node *tmp = first;
			for (; tmp != nullptr; tmp = tmp->next)
			{
				std::cout << tmp->data << std::endl;
			}
		}

		LinkedList& operator=(const LinkedList& other)
		{
			(void)other;
			throw std::runtime_error("TODO");
		}

		LinkedList& operator=(LinkedList&& other)
		{
			(void)other;
			throw std::runtime_error("TODO");
		}

		bool isEmpty() const
		{
			if (first == nullptr)
				return 1;
			else return 0;
			throw std::runtime_error("TODO");
		}

		size_type getSize() const
		{
			
			//throw std::runtime_error("TODO");
			return count;
		}

		void append(const Type& item)
		{
			if ((*this).isEmpty())
			{
				first = DBG_NEW Node;
				first->data = item;
				first->next = nullptr;
				first->previous = nullptr;
				last = first;
				++count;
				return;
			}
			last->next = DBG_NEW Node;
			Node * tmp = last->next;
			tmp->data = item;
			tmp->next = nullptr;
			tmp->previous = last;
			last = tmp;
			++count;
			
			(void)item;
		//	throw std::runtime_error("TODO");
		}

		void prepend(const Type& item)
		{
			if ((*this).isEmpty())
			{
				first = DBG_NEW Node;
				first->data = item;
				last = first;
				++count;
				return;
			}
			Node * tmp = DBG_NEW Node;
			tmp->data = item;
			tmp->previous = nullptr;
			tmp->next = first;
			first->previous = tmp;
			first = tmp;
			++count;
			(void)item;
		//	throw std::runtime_error("TODO");
		}

		void insert(const const_iterator& insertPosition, const Type& item)
		{
			(void)insertPosition;
			(void)item;
			throw std::runtime_error("TODO");
		}

		Type popFirst()
		{
			if ((*this).getSize() == 1)
			{
				object_type obj = first->data;
				destroy();
				return obj;
			}
			if ((*this).isEmpty())
				throw std::logic_error("no elements in this list");
			object_type obj =  first->data;
			Node *right = first->next;
			right->previous = nullptr;
			delete first;
			first = right;
			--count;
			return obj;
			throw std::runtime_error("TODO");
		}

		Type popLast()
		{
			if ((*this).getSize() == 1)
			{
				object_type obj = first->data;
				destroy();
				return obj;
			}
			if ((*this).isEmpty())
				throw std::logic_error("no elements in this list");
				
			object_type value = last->data;
			Node *left = last->previous;
			left->next = nullptr;
			delete last;
			last = left;
			--count;
			return value;
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
			return iterator(first);
			throw std::runtime_error("TODO");
		}

		iterator end()
		{
			return iterator(last->next);
			throw std::runtime_error("TODO");
		}

		const_iterator cbegin() const
		{
			return ConstIterator(first);
			throw std::runtime_error("TODO");
		}

		const_iterator cend() const
		{
			return ConstIterator(last->next);
			throw std::runtime_error("TODO");
		}

		const_iterator begin() const
		{
			return cbegin();
		}

		const_iterator end() const
		{
			return cend();
		}
	};

	template <typename Type>
	class LinkedList<Type>::ConstIterator
	{
	public:
		using iterator_category = std::bidirectional_iterator_tag;
		using object_type_type = typename LinkedList::object_type;
		using difference_type = typename LinkedList::difference_type;
		using pointer = typename LinkedList::const_pointer;
		using node_ptr = typename LinkedList::node_ptr;
		using reference = typename LinkedList::const_reference;
	private:
		node_ptr node;

	public:
		explicit ConstIterator()
		{}

		ConstIterator(node_ptr node): node(node)
		{}

		reference operator*() const
		{
			if(node->next == nullptr)
				throw std::out_of_range("cannot dereference end iterator");
			return node->data;
			throw std::runtime_error("TODO");
		}

		ConstIterator& operator++()
		{
			if (node->next == nullptr)
				throw std::out_of_range("cannot increment, iterator is pointing at last element");
			node = node->next;
			return *this;
		//	throw std::runtime_error("TODO");
		}

		ConstIterator operator++(int)
		{
			if (node->next == nullptr)
				throw std::out_of_range("cannot increment, iterator is pointing at last element\n");
			ConstIterator tmp = *this;
			++(*this);
			return tmp;
		}

		ConstIterator& operator--()
		{
			if(node->previous == nullptr)
				throw std::out_of_range("cannot decrement, iterator is pointing at first element\n");
			node = node->previous;
			return *this;
			throw std::runtime_error("TODO");
		}

		ConstIterator operator--(int)
		{
			if (node->previous == nullptr)
				throw std::out_of_range("cannot decrement, iterator is pointing at first element\n");
			ConstIterator tmp = *this;
			--(*this);
			return tmp;
		//	throw std::runtime_error("TODO");
		}

		ConstIterator operator+(difference_type d) const
		{
			ConstIterator tmp = *this;
			for (difference_type i=0; i < d; ++tmp, ++i) 
			{
				if(tmp == nullptr)
					throw std::out_of_range("cannot increment, list is too small\n");
			}

			return tmp;
			(void)d;
			throw std::runtime_error("TODO");
		}

		ConstIterator operator-(difference_type d) const
		{
			ConstIterator tmp = *this;
			for (difference_type i = 0; i < d; --tmp, ++i)
			{
				if (tmp == nullptr)
					throw std::out_of_range("cannot increment, list is too small\n");
			}

			return tmp;
			(void)d;
			throw std::runtime_error("TODO");
		}

		bool operator==(const ConstIterator& other) const
		{
			return (node == other.node);
			(void)other;
			throw std::runtime_error("TODO");
		}

		bool operator!=(const ConstIterator& other) const
		{
			return (!(*this == other));
			(void)other;
			throw std::runtime_error("TODO");
		}
	};

	template <typename Type>
	class LinkedList<Type>::Iterator : public LinkedList<Type>::ConstIterator
	{
	public:
		using node_ptr = typename LinkedList::node_ptr;
		using pointer = typename LinkedList::pointer;
		using reference = typename LinkedList::reference;

		explicit Iterator()
		{}

		Iterator(const ConstIterator& other)
			: ConstIterator(other)
		{}

		Iterator(node_ptr node) :ConstIterator(node) {}

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

#endif // AISDI_LINEAR_LINKEDLIST_H
