#pragma once
#include <iostream>
#include <iterator>

template<typename T>
class List {
public:
	List() = default;
	~List() {
		while (head) {
			Node *first = head;
			head = head->next;
			delete first;
		}
	}
	void push_back(T value) {
		if (!tail) {
			head = tail = new Node{ std::move(value) };
			return;
		}
		tail->next = new Node{ std::move(value), nullptr, tail };
		tail = tail->next;
	}
	void push_front(T value) {
		if (!head) {
			head = tail = new Node{ std::move(value) };
			return;
		}
		head = new Node{ std::move(value), head };
		head->next->prev = head;
	}
	T pop_front() {
		Node *tmp = head;
		if (!tmp) throw std::exception();
		T value = std::move(tmp->data);
		head = head->next;
		if (head)
			head->prev = nullptr;
		else
			tail = nullptr;
		delete tmp;
		return value;
	}
	T pop_back() {
		Node *tmp = tail;
		if (!tmp)
			throw std::exception();
		tail = tail->prev;
		if (tail)
			tail->next = nullptr;
		else
			head = nullptr;
	}
	bool empty() const { return head == nullptr; }
	const T& front() const { return head->data; }
	const T& back() const { return tail->data; }

private:
	struct Node {
		T data;
		Node *next = nullptr;
		Node *prev = nullptr;
	};
	Node *head = nullptr;
	Node *tail = nullptr;
};

