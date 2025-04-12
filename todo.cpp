#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i=0; i<32; i++) {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for (int i=0; i<32; i++) {
        delete[] tasks[i];
        tasks[i] = nullptr;
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int i = 0;
    while (true) {
        if (str[i] == '\0') {
            break;
        }
        i++;
    }
    return i;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int i = 0;
    while (true) {
        dest[i] = src[i];
        if (src[i] == '\0') {
            break;
        }
        i++;
    }
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size == 32) {
        throw std::invalid_argument("Too Many Tasks");
    }
    int length = string_length(task);
    tasks[size] = new char[length + 1];
    string_copy(tasks[size], task);
    size++;
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if ((index >= size) || (index < 0)) {
        throw std::invalid_argument("Invalid Index");
    }
    delete[] tasks[index];
    for (int i=index; i<size-1; i++) {
        tasks[i] = tasks[i+1];
    }
    tasks[size-1] = nullptr;
    size -= 1;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    const char** list = new const char*[size];
    count = size;
    for (int i=0; i<size; i++) {
        list[i] = tasks[i];
    }
    return list;
}