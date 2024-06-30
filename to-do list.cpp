#include <iostream>
#include <vector>
#include <string>
using namespace std;
class ToDoListManager {
public:
    void addTask(const string& task) {
        tasks.push_back({task, false});
        cout << "Task \"" << task << "\" added." << endl;
    }
    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks to show." << endl;
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            string status = tasks[i].second ? "Completed" : "Pending";
            cout << i + 1 << ". " << tasks[i].first << " - " << status << endl;
        }
    }
    void markTaskCompleted(size_t taskIndex) {
        if (isValidIndex(taskIndex)) {
            tasks[taskIndex - 1].second = true;
            cout << "Task \"" << tasks[taskIndex - 1].first << "\" marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
    void removeTask(size_t taskIndex) {
        if (isValidIndex(taskIndex)) {
            cout << "Task \"" << tasks[taskIndex - 1].first << "\" removed." << endl;
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
private:
    vector<pair<string, bool>> tasks;
    bool isValidIndex(size_t index) const {
        return index >= 1 && index <= tasks.size();
    }
};
void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}
int main() {
    ToDoListManager manager;
    int choice;
    string task;
    size_t taskIndex;
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter the task: ";
                getline(cin, task);
                manager.addTask(task);
                break;
            case 2:
                manager.viewTasks();
                break;
            case 3:
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;
                manager.markTaskCompleted(taskIndex);
                break;
            case 4:
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                manager.removeTask(taskIndex);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
