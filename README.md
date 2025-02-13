# Doubly Linked List Implementation in C++

Этот проект представляет собой реализацию двусвязного списка на языке C++. Двусвязный список — это структура данных, которая состоит из узлов, где каждый узел содержит данные и указатели на предыдущий и следующий узлы. В проекте реализованы основные операции, такие как добавление, удаление, вставка элементов, а также обработка исключений для обеспечения безопасности и надежности кода.

## Структура проекта

- **src/Exceptions.h**: Файл с пользовательскими исключениями.
- **src/LinkedList_version_two.h**: Основной файл с реализацией двусвязного списка.
- **src/main.cpp**: Пример использования двусвязного списка.
- **CMakeLists.txt**: Файл для сборки проекта с помощью CMake.
- **.gitignore**: Файл для игнорирования ненужных файлов в репозитории.

## Сборка и запуск

1. Убедитесь, что у вас установлен CMake и компилятор C++ (например, g++).
2. Клонируйте репозиторий:

   ```bash
   git clone https://github.com/yourusername/DoublyLinkedList.git
   cd DoublyLinkedList

    Создайте директорию для сборки:
    bash
    Copy

    mkdir build
    cd build

    Соберите проект с помощью CMake:
    bash
    Copy

    cmake ..
    make

    Запустите программу:
    bash
    Copy

    ./DoublyLinkedList

Основные функции

    Добавление элементов: push_front, push_back

    Удаление элементов: pop_front, pop_back

    Вставка элемента по индексу: insert

    Удаление элемента по индексу: remove

    Получение элемента по индексу: operator[]

    Проверка на пустоту: empty

    Получение размера списка: size

Пример использования
cpp
Copy

#include "LinkedList_version_two.h"
#include "Exceptions.h"

int main() {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);

    std::cout << "List size: " << list.size() << std::endl;
    list.print();

    return 0;
}

Исключения

    LinkedListIndexError: Выбрасывается при попытке доступа к недопустимому индексу.

    LinkedListMemoryError: Выбрасывается при невозможности выделить память для нового узла.

    LinkedListEmptyError: Выбрасывается при попытке удаления из пустого списка.
