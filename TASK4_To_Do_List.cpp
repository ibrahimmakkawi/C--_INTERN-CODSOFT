#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> taskMap;

struct Task {
    string name;
    bool status = false;
    Task* next = nullptr;
};

Task* head = nullptr;
Task* last = nullptr;

void addTask(const string& name) {
    if (taskMap[name] == 1) {
        cout << "Task already exists." << endl;
        return;
    }

    Task* newTask = new Task();
    newTask->name = name;

    if (last == nullptr) {
        head = newTask;
        last = newTask;
    } else {
        last->next = newTask;
        last = newTask;
    }

    taskMap[newTask->name] = 1;
    cout << "Task has been added successfully." << endl;
}

void viewTasks() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    int num = 1;
    Task* current = head;

    cout << "============================================================" << endl;
    while (current != nullptr) {
        cout << "Task# " << num << " - " << current->name << ", Status: ";
        cout << (current->status ? "Completed" : "Pending") << endl;

        num++;
        current = current->next;
    }
    cout << "============================================================" << endl;
}

void markCompleted(int taskNumber) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    int num = 1;
    Task* current = head;

    while (current != nullptr) {
        if (num == taskNumber) {
            current->status = true;
            cout << endl << "Task# " << taskNumber << " has been marked as completed." << endl;
            return;
        }
        current = current->next;
        num++;
    }
    cout << "No such task exists." << endl;
}

void removeTask(int taskNumber) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Task* current = head;
    Task* previous = nullptr;

    if (taskNumber == 1) {
        if (head == last) {
            taskMap.erase(current->name);
            delete head;
            head = last = nullptr;
        } else {
            head = head->next;
            taskMap.erase(current->name);
            delete current;
        }
        cout << "Task deleted." << endl;
        return;
    }

    int num = 1;
    while (current != nullptr) {
        if (num == taskNumber) {
            previous->next = current->next;
            if (current == last) {
                last = previous;
            }
            taskMap.erase(current->name);
            delete current;
            cout << "Task deleted." << endl;
            return;
        }
        previous = current;
        current = current->next;
        num++;
    }

    cout << "No such task exists." << endl;
}

int main() {
    cout << "====================================================================================================" << endl;
    cout << "                                                To-Do List                                          " << endl;
    cout << "====================================================================================================" << endl;

    char choice;
    do {
        cout << endl;
        cout << "Press 1 to add a new task" << endl;
        cout << "Press 2 to view all tasks" << endl;
        cout << "Press 3 to mark a task as completed" << endl;
        cout << "Press 4 to remove a task" << endl;
        cout << "Press any other key to end the program" << endl;
        cout << "Choice: "; 
        cin >> choice;
        cout << endl;

        switch (choice) {
            case '1': {
                string taskName;
                cout << "Enter task: ";
                cin >> taskName;
                addTask(taskName);
                break;
            }
            case '2': {
                viewTasks();
                break;
            }
            case '3': {
                int taskNumber;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskNumber;
                markCompleted(taskNumber);
                break;
            }
            case '4': {
                int taskNumber;
                cout << "Enter the task number to remove: ";
                cin >> taskNumber;
                removeTask(taskNumber);
                break;
            }
            default:
                cout << "Program ended." << endl;
                return 0; // End the program if an invalid choice is entered
        }

        cout << endl << "Would you like to do something else? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Program ended." << endl;
    return 0;
}
