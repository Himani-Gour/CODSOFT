#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string name;
    bool completed;
};

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n1. Add Task";
        cout << "\n2. View Tasks";
        cout << "\n3. Mark Complete";
        cout << "\n4. Remove Task";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1) {
            Task t;
            cin.ignore();
            cout << "Enter task: ";
            getline(cin, t.name);
            t.completed = false;
            tasks.push_back(t);
        }

        else if(choice == 2) {
            cout << "\nTasks:\n";
            for(int i=0;i<tasks.size();i++) {
                cout << i+1 << ". "
                     << tasks[i].name
                     << " [" << (tasks[i].completed ? "Completed" : "Pending")
                     << "]\n";
            }
        }

        else if(choice == 3) {
            int num;
            cout << "Enter task number: ";
            cin >> num;

            if(num>=1 && num<=tasks.size())
                tasks[num-1].completed = true;
        }

        else if(choice == 4) {
            int num;
            cout << "Enter task number: ";
            cin >> num;

            if(num>=1 && num<=tasks.size())
                tasks.erase(tasks.begin()+num-1);
        }

    } while(choice != 5);

    return 0;
}