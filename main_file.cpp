#include <bits/stdc++.h>
#include "LinkedList_version_two.h"
#include "Exceptions.h"

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::cerr;

int main() {
    try {
        // Создание пустого двусвязного списка строк
        LinkedList<string> lst;

        // Проверка пустого списка
        if (lst.empty()) {
            cout << "Список пуст (корректно)." << endl;
        } else {
            cout << "Ошибка: Список не пуст, хотя должен быть." << endl;
        }

        // Добавление элементов в конец и начало списка
        lst.push_back("hello");
        lst.push_back("C++");
        lst.push_front("OOP");
        lst.push_front("Balakirev");
        lst.push_front("Sergey");

        cout << "Список после добавления элементов:" << endl;
        lst.print();
        cout << "Размер списка: " << lst.size() << endl;
        cout << endl;

        // Удаление последнего и первого элемента
        lst.pop_back();
        lst.pop_front();

        cout << "Список после удаления первого и последнего элементов:" << endl;
        lst.print();
        cout << "Размер списка: " << lst.size() << endl;
        cout << endl;

        // Удаление элемента по индексу
        unsigned index_1 = 1;
        lst.remove(index_1);

        cout << "Список после удаления элемента с индексом " << index_1 << ":" << endl;
        lst.print();
        cout << "Размер списка: " << lst.size() << endl;
        cout << endl;

        // Вставка элемента по индексу
        unsigned index_2 = 1;
        lst.insert(index_2, "Inserted Element");

        cout << "Список после вставки элемента с индексом " << index_2 << ":" << endl;
        lst.print();
        cout << "Размер списка: " << lst.size() << endl;
        cout << endl;

        // Получение элемента по индексу
        string s = lst[0];
        cout << "Элемент с индексом 0: " << s << endl;

        // Изменение элемента по индексу
        lst[0] = "Updated";
        cout << "Список после изменения элемента с индексом 0:" << endl;
        lst.print();
        cout << endl;

        // Перебор элементов с конца в начало
        cout << "Перебор элементов с конца в начало:" << endl;
        shared_ptr<Object<string>> ptr_lst = lst.get_tail();
        while (ptr_lst) {
            cout << ptr_lst->get_data() << " ";
            ptr_lst = ptr_lst->get_prev();
        }
        cout << endl;

        // Создание второго списка с числами
        LinkedList<unsigned> lst_u;
        lst_u.push_back(1);
        lst_u.push_back(2);
        lst_u.push_back(3);

        cout << "Второй список после добавления элементов:" << endl;
        lst_u.print();
        cout << "Размер второго списка: " << lst_u.size() << endl;
        cout << endl;

        // Изменение элемента по индексу
        lst_u[0] = 15;
        cout << "Второй список после изменения элемента с индексом 0:" << endl;
        lst_u.print();
        cout << endl;

        // Перебор элементов с начала до конца
        cout << "Перебор элементов второго списка с начала до конца:" << endl;
        shared_ptr<Object<unsigned>> ptr_lst_u = lst_u.get_head();
        while (ptr_lst_u) {
            cout << ptr_lst_u->get_data() << " ";
            ptr_lst_u = ptr_lst_u->get_next();
        }
        cout << endl;

        // Проверка исключений
        cout << "Проверка исключений:" << endl;

        try {
            string invalidElement = lst[-1]; // Недопустимый индекс
            cout << "Ошибка: Исключение не было выброшено при доступе к недопустимому индексу." << endl;
        } 
        catch (const LinkedListIndexError& e) {
            cout << "Исключение при доступе к недопустимому индексу: " << e.what() << endl;
        }

        try {
            lst_u.insert(-2, 123); // Недопустимый индекс для вставки
            cout << "Ошибка: Исключение не было выброшено при вставке в недопустимый индекс." << endl;
        } 
        catch (const LinkedListIndexError& e) {
            cout << "Исключение при вставке в недопустимый индекс: " << e.what() << endl;
        }

        try {
            lst_u.remove(100); // Недопустимый индекс для удаления
            cout << "Ошибка: Исключение не было выброшено при удалении из недопустимого индекса." << endl;
        } 
        catch (const LinkedListIndexError& e) {
            cout << "Исключение при удалении из недопустимого индекса: " << e.what() << endl;
        }

        // Проверка пустого списка
        LinkedList<int> emptyList;
        if (emptyList.empty()) {
            cout << "Пустой список определен корректно." << endl;
        } else {
            cout << "Ошибка: Список не пуст, хотя должен быть." << endl;
        }

        // Проверка размера списка
        cout << "Размер первого списка: " << lst.size() << endl;
        cout << "Размер второго списка: " << lst_u.size() << endl;

        // Проверка удаления из пустого списка
        try {
            emptyList.pop_front();
            cout << "Ошибка: Исключение не было выброшено при удалении из пустого списка." << endl;
        } 
        catch (const LinkedListEmptyError& e) {
            cout << "Исключение при удалении из пустого списка: " << e.what() << endl;
        }

        try {
            emptyList.pop_back();
            cout << "Ошибка: Исключение не было выброшено при удалении из пустого списка." << endl;
        } 
        catch (const LinkedListEmptyError& e) {
            cout << "Исключение при удалении из пустого списка: " << e.what() << endl;
        }

        // Проверка вставки в пустой список
        try {
            emptyList.insert(0, 42); // Вставка в пустой список
            cout << "Вставка в пустой список выполнена успешно." << endl;
        } 
        catch (const LinkedListIndexError& e) {
            cout << "Ошибка: Исключение при вставке в пустой список: " << e.what() << endl;
        }

    } 
    catch (const std::exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }
    

    return 0;
}
