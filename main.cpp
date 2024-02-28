#include <iostream>
using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
void EntranceEmploy();
void CreateEmploy();
void Entrance(int);
void registerCandidate(const string& id, const string& password);
int main() {
    int choice1;

    while (choice1<1 || choice1>3){
        cout << "Welcome to Job Search System" << endl;
        cout << "Enter your choice:" << endl;
        cout << "1. Candidate" << endl;
        cout << "2. Employer " << endl;
        cout << "3. Exit" << endl;
        cin >> choice1;
    }
    switch (choice1) {
        case 1: //candidate




            break;
        case 2:



            break;
        case 3:


            break;
        case 4:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Exiting program." << endl;
            return 0;
    }
}
//-----------------------------------------------------job search system

// Method to register a new employer
void registerEmployer(const string& id, const string& password,const string& name) {
    ofstream file("employers.txt", ios::app);
    if (file.is_open()) {
        file <<"id: " << id << " password: " << password  <<" Name: "<<name<< "\n";
        file.close();
        cout << "Registration employer successful.\n";
    } else {
        cerr << "Unable to open file for registration.\n";
    }
}
// Method to register a new candidate
void registerCandidate(const string& id, const string& password) {
    // TO DO: תוסיפי פה את כל השדות לפי דרישה מס 2 ותדאגי לקליטה שלהם בשורה 41
    ofstream file("candidate.txt", ios::app);
    if (file.is_open()) {
        file <<"id: " << id << "password: " << password  << "\n";
        file.close();
        cout << "Registration candidate successful.\n";
    } else {
        cerr << "Unable to open file for registration.\n";
    }
}
// method to read file
void readFile(const string& filename, vector<string>& data) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            data.push_back(line);
        }
        file.close();
    }
}
//if employer in text
bool loginEmployer(const string& id, const string& password) {
    vector<string> employers;
    readFile("employers.txt", employers);
    for (const auto& emp : employers) {
        size_t pos = emp.find(" ");
        if (pos != string::npos) {
            string empId = emp.substr(4, id.size());
            string empPass = emp.substr(24,password.size());
            if (empId == id && empPass == password) {
                cout << "Login employer successful.\n";
                return true;
            }
        }
    }
    cout << "Invalid credentials. Please try again.\n";
    return false;
}
//if candidate in text
bool loginCandidate(const string& id, const string& password) {
    vector<string> candidate;
    readFile("candidate.txt", candidate);
    for (const auto& emp : candidate) {
        size_t pos = emp.find(" ");
        if (pos != string::npos) {
            string empId = emp.substr(4, id.size());
            string empPass = emp.substr(24,password.size());
            if (empId == id && empPass == password) {
                cout << "Login candidate successful.\n";
                return true;
            }
        }
    }
    cout << "Invalid credentials. Please try again.\n";
    return false;
}

//-----------------------------------------------------jobs

// Method to add a new jobs from text file
void addJob(const string &nameJ, const string &areaJ, const string &dateJ) {
    ofstream file("job.txt", ios::app);
    if (file.is_open()) {
        file << "Date: " << dateJ << " Name: " << nameJ << " area: " << areaJ << "." << endl;
        file << endl; // הוספת שורה ריקה
        file.close();
        cout << "add job successful.\n";
    } else {
        cerr << "Unable to add job.\n";
    }
}
// Method to delete job from text file
void deleteJob(const string &nameToDelete) {
    ifstream inputFile("job.txt");
    ofstream outputFile("temp.txt");
    string line;

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file.\n";
        return;
    }

    bool found = false;
    while (getline(inputFile, line)) {
        // Check if the line contains the job name to delete
        if (line.find("Name: " + nameToDelete) != string::npos) {
            found = true;
            continue; // Skip this line, effectively deleting it
        }
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("job.txt");         // Remove the old file
        rename("temp.txt", "job.txt");  // Rename temp file to original name
        cout << "Job '" << nameToDelete << "' deleted successfully.\n";
    } else {
        cout << "Job '" << nameToDelete << "' not found.\n";
        remove("temp.txt"); // Remove the temp file if the job wasn't found
    }
}
// Method to edit job from text file
void editJob(const string &nameToEdit, const string &newName, const string &newArea, const string &newDate) {
    ifstream inputFile("job.txt");
    ofstream outputFile("temp.txt");
    string line;

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file.\n";
        return;
    }

    bool found = false;
    while (getline(inputFile, line)) {
        // Check if the line contains the job name to edit
        if (line.find("Name: " + nameToEdit) != string::npos) {
            found = true;
            // Modify the line with new details
            outputFile << "Date: " << newDate << " Name: " << newName << " area: " << newArea << "." << endl;
        } else {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("job.txt");         // Remove the old file
        rename("temp.txt", "job.txt");  // Rename temp file to original name
        cout << "Job '" << nameToEdit << "' edited successfully.\n";
    } else {
        cout << "Job '" << nameToEdit << "' not found.\n";
        remove("temp.txt"); // Remove the temp file if the job wasn't found
    }
}
// Method to view all jobs from text file
void viewPublishedJobs() {
    ifstream file("job.txt");
    string line;

    if (file.is_open()) {
        cout << "List of Published Jobs:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file.\n";
    }
}

//-----------------------------------------------------
//void Entrance(int choise) {
//    int choice2;
//    while (choice2 < 1 || choice2 > 2) {
//        cout << "Enter your choice:" << endl;
//        cout << "1. register " << endl;
//        cout << "2. login " << endl;
//        cin >> choice2;
//    }
//    switch (choice2) {
//        case 1: //register
//            if (choise == 1)//candidate
//                //add cout<<<
//                registerCandidate("cheaj", "#!3");
//            else {
//                string n, p;
//                cout << "Enter Name: " << endl;
//                cin >> n;
//                cout << "Enter password: " << endl;
//                cin >> n;
//
//
//            }
//
//
//            break;
//        case 2:
//
//
//            break;
//        case 3:
//
//
//            break;
//        case 4:
//            cout << "Exiting program." << endl;
//
//        default:
//            cout << "Invalid choice. Exiting program." << endl;
//
//
//    }
//}

void EntranceEmploy(){
    string id,password;
    cout<< "Enter your id: "<<endl;
    cin>>id;
    cout<< "Enter your password: "<<endl;
    cin>>password;
    loginEmployer(id,password);// בדיקה אם הוא באמת נמצא באתר

}
void CreateEmploy(){
    string id,password,name;
    cout<< "Enter your name: "<<endl;
    cin>>name;
    while (id.size()!=9) {
        cout << "Enter your id: " << endl;
        cin >> id;
    }

    cout<< "Enter your password: "<<endl;
    cin>>password;
    registerEmployer(id,password,name);
}


