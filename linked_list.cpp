#include "iostream"
#include "linked_list.h"

Database::Database() {
    head = new Element;
    tail = new Element;
    head->prev = nullptr;
    head->next = tail;
    tail->prev = head;
    tail->next = nullptr;

}

Database::~Database() {
    while (!is_empty()) {
        delete_first();
    }
    delete head;
    delete tail;
}

bool Database::is_empty() {
    return head->next == tail;
}

void Database::delete_first() {
    if (!is_empty()) {
        Element *p = head->next;
        head->next = p->next;
        p->next->prev = head;
        delete p;
    }
}

void Database::add_to_beginning(string surname, string name, float age) {
    Element *p = new Element;

    p->name = name;
    p->surname = surname;
    p->age = age;

    p->prev = head;
    p->next = head->next;

    p->prev->next = p;
    p->next->prev = p;
}

void Database::add_to_end(string surname, string name, float age) {
    Element *q = new Element;

    q->surname = surname;
    q->name = name;
    q->age = age;

    q->prev = tail->prev;
    q->next = tail;

    q->next->prev = q;
    q->prev->next = q;
}

void Database::print() {
    Element *p = head->next;
    while (p->next != nullptr) {
        cout << p->surname << " ";
        cout << p->name << "\n";
        p = p->next;
    }
}

float Database::num_of_ages() {
    int n = 0;
    Element *p = head->next;
    while (p->next != nullptr) {
        n = n + 1;
        p = p->next;
    }
    return n;
}

float Database::sum_of_ages() {
    Element *p = head->next;
    float s = 0;
    while (p->next != nullptr) {
        s += p->age;
        p = p->next;
    }
    return s;
}

float Database::average_age() {
    return sum_of_ages() / num_of_ages();
}