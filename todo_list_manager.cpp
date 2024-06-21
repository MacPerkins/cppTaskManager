#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Task {
    public:
        Task(const string& desc) : description(desc) {}
        string getDescription() const { return description; }
    private:
        string description;
};

class ToDoList {
    public:
        void addTask(const string& taskDesc) {  //Add a task
            tasks.push_back(Task(taskDesc));
            cout << "Task added" << endl;
        }

        void removeTask(int index) {    //Remove a task by index
            if (index >= 0 && index < tasks.size()) {
                tasks.erase(tasks.begin() + index);
                cout << "Task removed" << endl;
            } else {
                cout << "\nInvalid index. Try another" << endl;
            }
        }

        void viewTasks() const {    //Display all the tasks
            cout << "\nTasks: " << endl;
            for (size_t i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". " << tasks[i].getDescription() << endl;
            }
        }

        void writeToFile(const string& filename) {  //Write the tasks to a file
            ofstream file(filename);
            if (file.is_open()) {
                for (const Task& task : tasks) {
                    file << task.getDescription() << endl;
                }
                file.close();
                cout << "Tasks written to file" << endl;
            } else {
                cout << "Unable to open file" << endl;
            }
        }

        void readFromFile(const string& filename) { //Read the tasks from a file
            ifstream file(filename);
            if (file.is_open()) {
                string taskDesc;
                while (getline(file, taskDesc)) {
                    tasks.push_back(Task(taskDesc));
                }
                file.close();
                cout << "Tasks read from file" << endl;
            } else {
                cout << "Unable to open file" << endl;
            }
        }
    private:
        vector<Task> tasks;
};

void choice_menu() {    //Create a menu for adding, removing, and viewing tasks.
    cout << "\n1. Add a Task" << endl;
    cout << "2. Remove a Task" << endl;
    cout << "3. View Tasks" << endl;
    cout << "4. Write Tasks to File" << endl;
    cout << "5. Read Tasks from File" << endl;
    cout << "6. Exit task manager" << endl;
    cout << "Chose an option(1-4): \n";
}

int main() {
    ToDoList toDoList;
    string greeting = "Welcome to To-Do List task manager:";
    string taskDesc;
    int choice;
    int taskIndex;
    string filename;
    cout << endl << greeting << endl << endl;

    while (true) {
        choice_menu();
        cin >> choice;

        if (choice == 1) {
            cout << "\nEnter task description: ";
            cin.ignore();
            getline(cin, taskDesc);
            toDoList.addTask(taskDesc);
            // Add task code
        } else if (choice == 2) {
            cout << "\nEnter task index to remove task: ";
            cin >> taskIndex;
            toDoList.removeTask(taskIndex - 1);
            // Remove task code
        } else if (choice == 3) {
            // View tasks code
            toDoList.viewTasks();
        } else if (choice == 4) {
            cout << "\nEnter filename to write tasks to: ";
            cin >> filename;
            toDoList.writeToFile(filename);
        } else if (choice == 5) {
            cout << "\nEnter filename to read tasks from: ";
            cin >> filename;
            toDoList.readFromFile(filename);
        } else if (choice == 6) {
            cout << "\nGoodbye! Thank you for using task manager. " << endl;
            break;
        } else {
            cout << "\nInvalid Option. Choose again" << endl << endl;
        }
    }
 

    return 0;
}