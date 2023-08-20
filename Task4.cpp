/* Build a simple console-based to-do list manager that allows users to add, view, and delete tasks */

#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// Definition of the Task struct
struct Task
{
    string description; // Holds the task description
    bool isComplete;    // Indicates if the task is complete or not

    // Constructor for Task
    Task(const string &desc) : description(desc), isComplete(false) {}
};

// Function to display the menu and get user input
int menu()
{
    int opt;
    cout << "\n\n\n";
    cout << "\t\t************Menu************\n";
    cout << "1. Add Task\n2. Delete Task\n3. Mark as Complete\n4. Show Tasks\n5. -1 to exit()\n";
    cout << "Enter from the menu above: ";

    // Input validation loop
    while (!(cin >> opt))
    {
        cout << "\n****Invalid Input****\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return opt;
}

// Function to add a task to the list
void addTask(vector<Task> &tasks)
{
    string taskDesc;
    cout << "\nEnter your task to add: ";
    cin.ignore();
    getline(cin, taskDesc);

    tasks.push_back(Task(taskDesc)); // Create a Task object and add it to the vector
    cout << "\n\t\t***Task Added***";
}

// Function to print all tasks
void printAll(const vector<Task> &tasks)
{
    int i = 1;
    cout << "\n\t\t*****Task List*****";
    if (tasks.empty())
    {
        cout << "\n\t\t****The List is empty****";
    }
    else
    {
        for (const Task &task : tasks)
        {
            cout << "\n"
                 << i << ". " << task.description << " [" << (task.isComplete ? "Complete" : "Pending") << "]";
            i++;
        }
    }
}

// Function to mark a task as complete or pending
void markComplete(vector<Task> &tasks)
{
    printAll(tasks);

    int taskIndex;
    cout << "\nSelect a task to mark as Complete/Pending: ";
    while (!(cin >> taskIndex) || taskIndex > tasks.size() || taskIndex < 1)
    {
        cout << "\nInvalid input. Choose a valid task: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int c_p;
    cout << "\nMark as:\n";
    cout << "1. Complete\n2. Pending\n";
    while (!(cin >> c_p) || (c_p != 1 && c_p != 2))
    {
        cout << "\nInvalid input. Choose 1 for Complete or 2 for Pending: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    tasks[taskIndex - 1].isComplete = (c_p == 1);
    cout << "\n***Marked as " << (c_p == 1 ? "Complete" : "Pending") << "***";
}

// Function to delete a task from the list
void deleteTask(vector<Task> &tasks)
{
    // check if the vector is empty or not ;
    if (tasks.empty())
    {
        cout << endl
             << endl
             << endl
             << "***** Add Some Tasks First *****";
        return;
    }
    printAll(tasks);

    int delTask;
    cout << "\nEnter the task number you want to delete: ";
    while (!(cin >> delTask) || delTask > tasks.size() || delTask < 1)
    {
        cout << "\nInvalid input. Choose a valid task: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    tasks.erase(tasks.begin() + delTask - 1);
    cout << "\n***Task deleted***";
}

// Function to process user input
void process(int opt, vector<Task> &tasks)
{
    switch (opt)
    {
    case 1:
        addTask(tasks);
        break;
    case 2:
        deleteTask(tasks);
        break;
    case 3:
        markComplete(tasks);
        break;
    case 4:
        printAll(tasks);
        break;
    default:
        cout << "\nIncorrect input";
    }
}

// Main function
int main()
{
    int option = 0;
    cout << "\n\t\t********Welcome to my to-do list********";

    vector<Task> to_do_list;

    do
    {
        option = menu();

        if (option == -1)
        {
            break;
        }

        process(option, to_do_list);

    } while (true);

    return 0;
}
