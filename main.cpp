#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

void CreateEmploy();
void readFile(const string& filename, vector<string>& data);
void loginCandidate();
void loginEmployer();
void registerCandidate();
void registerEmployer();
void employerMenu();
void candidateMenu();
int main() {
    int choice;

    cout << "Welcome to Job Search System" << endl;
    cout << "1. Candidate Login" << endl;
    cout << "2. Employer Login" << endl;
    cout << "3. Register as Candidate" << endl;
    cout << "4. Register as Employer" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: " << endl;


    cin >> choice;


    switch (choice) {
        case 1:
            loginCandidate();
            break;
        case 2:
            loginEmployer();
            break;
        case 3:
            registerCandidate();
            break;
        case 4:
            registerEmployer();
            break;
        case 5:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter again!" << endl<<endl;
            return main();
    }

    return 0;
}//-----------------------------------------------------job search system

// Method to register a new employer
void registerEmployer() {
    string id,password,name;
    cout<< "Enter your name: "<<endl;
    cin>>name;
    while (id.size()!=9) {
        cout << "Enter your id: " << endl;
        cin >> id;
    }

    cout<< "Enter your password: "<<endl;
    cin>>password;
    ofstream file("employers.txt", ios::app);
    if (file.is_open()) {
        file <<"id: " << id << " password: " << password  <<" Name: "<< name << "\n";
        file.close();
        cout << "Registration employer successful.\n";
        employerMenu();
    } else {
        cerr << "Unable to open file for registration.\n";
    }
}
// Method to register a new candidate
void registerCandidate() {
    string id,password,name;
    cout<< "Enter your name: "<<endl;
    cin>>name;
    while (id.size()!=9) {
        cout << "Enter your id: " << endl;
        cin >> id;
    }

    cout<< "Enter your password: "<<endl;
    cin>>password;
    // TO DO: תוסיפי פה את כל השדות לפי דרישה מס 2 ותדאגי לקליטה שלהם בשורה 41
    ofstream file("candidate.txt", ios::app);
    if (file.is_open()) {
        file <<"id: " << id << " password: " << password  << "\n";
        file.close();
        cout << "Registration candidate successful.\n";
        candidateMenu();
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
void loginEmployer() {
    string i, p;
    cout << "Enter id: " << endl;
    cin >> i;
    cout << "Enter password: " << endl;
    cin >> p;
    vector<string> employers;
    readFile("employers.txt", employers);
    for (const auto& emp : employers) {
        size_t pos = emp.find(" ");
        if (pos != string::npos) {
            string empId = emp.substr(4, i.size());
            string empPass = emp.substr(24,p.size());
            if (empId == i && empPass == p) {
                cout << "Login employer successful.\n";
                employerMenu();
            } else {
            cout << "Employer does not exist in the system. Please try again!\n\n";
            loginEmployer();
        }
        }
    }
}



//if candidate in text
void loginCandidate() {
    string i, p;
    cout << "Enter id: " << endl;
    cin >> i;
    cout << "Enter password: " << endl;
    cin >> p;
    vector<string> candidate;
    readFile("candidate.txt", candidate);
    for (const auto& emp : candidate) {
        size_t pos = emp.find(" ");
        if (pos != string::npos) {
            string empId = emp.substr(4, i.size());
            string empPass = emp.substr(24,p.size());
            if (empId == i && empPass == p) {
                cout << "Login candidate successful.\n";
                candidateMenu();
            } else{
                cout << "Candidate does not exist in the system. Please try again!\n\n";
                loginCandidate();
            }

        }
    }

}
//after candidate log in
void candidateMenu() {
    // Implement candidate menu options as per requirements
    // You can add options like searching for jobs, submitting resumes, etc.
    int choice;
    cout << endl << "Welcome to Candidate Menu!" << endl;
    cout << "Enter your choice: ";
    cout << "1. Search for Jobs" << endl;
    cout << "2. Submit Resume" << endl;
    cout << "3. View Submission History" << endl;
    cout << "4. Edit Profile" << endl;
    cout << "5. Logout" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            // Implement job search functionality
            break;
        case 2:
            // Implement resume submission functionality
            break;
        case 3:
            // Implement view submission history functionality
            break;
        case 4:
            // Implement edit profile functionality
            break;
        case 5:
            cout << "Logging out..." << endl;
            // Return to main menu
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }

    // Recursive call to the menu until logout
    candidateMenu();
}
//after employer log in
void employerMenu() {
    // Implement employer menu options as per requirements
    // You can add options like publishing, deleting, and updating jobs, viewing submissions, etc.
    int choice;

    cout << endl << "Welcome to Employer Menu!" << endl;
    cout << "Enter your choice: ";
    cout << "1. Publish a Job" << endl;
    cout << "2. Delete a Job" << endl;
    cout << "3. Update a Job" << endl;
    cout << "4. View Published Jobs" << endl;
    cout << "5. View Candidate Submissions for a Job" << endl;
    cout << "6. Logout" << endl;

    cin >> choice;

    switch (choice) {
        case 1:
            // Implement publish job functionality
            break;
        case 2:
            // Implement delete job functionality
            break;
        case 3:
            // Implement update job functionality
            break;
        case 4:
            // Implement view published jobs functionality
            break;
        case 5:
            // Implement view candidate submissions functionality
            break;
        case 6:
            cout << "Logging out..." << endl;
            // Return to main menu
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }

    // Recursive call to the menu until logout
    employerMenu();

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


