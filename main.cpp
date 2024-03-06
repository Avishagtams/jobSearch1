#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <limits>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

string candidateName, candidateID, candidatePassword;
string employerName, employerID, employerPassword;

void viewNewJobs();//todo: check why dd/mm/yy
void menuEditCandidate();
void editCandidateName();
void editCandidateEmail();
void editCandidatePassword();
void editCandidateAddress();
void editCandidatePhone();
void menuUpdateJobs();
void loginCandidate();
void loginEmployer();
void registerCandidate();
void registerEmployer();
void employerMenu();
void candidateMenu();
void addJob();
void searchForJob();
void searchByDate();
void searchByName();
void searchByArea();
void searchByYears();
void searchBySalary();
void searchByType();
void viewPublishedJobs();
void submitCandidacy (string jobDetails);

void ViewOfCandidateSubmissions();
void displayEditMenu();
void deleteJob();
void editJobByName(const string& publisher);
void editJobByArea(const string& publisher);
void editJobByYears(const string& publisher);
void editJobBySalary(const string& publisher);
void editJobByType(const string& publisher);
void editJobByDate(const string& publisher);
void mainMenu();
void submitResume();
void viewCandidateSubmissionsForEmployer();
bool findCandidateEducation(const std::string& candidateName, const std::string& userEducation);


int main() {

    mainMenu();

    return 0;

}

//-----------------------------------------------------job search system
void mainMenu() {
    int choice;
    cout << "Welcome to Job Search System" << endl;
    cout << "1. Candidate Login" << endl;
    cout << "2. Employer Login" << endl;
    cout << "3. Register as Candidate" << endl;
    cout << "4. Register as Employer" << endl;
    cout << "5. Exit" << endl;

    cout << "Enter your choice: "<<endl;
    // Checking if the input is an integer
    while (!(cin >> choice)) {
        cout << "Invalid input. Please choose again: "<<endl;
        cin.clear(); // Clearing the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discarding invalid input
    }

    cout << endl;

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
            cout << "Exiting program..." << endl;
            return;
        default:
            cout << "Invalid choice. Please enter again!" << endl << endl;
            mainMenu(); // Recursively calling mainMenu for re-entering choice
    }
}
// Method to register a new employer
void registerEmployer() {
    string id,password,name,email,company_name;
    cout<< "Enter your name: "<<endl;
    cin>>name;
    while (id.size()!=9) {
        cout << "Enter your id: " << endl;
        cin >> id;
    }

    cout<< "Enter your password: "<<endl;
    cin>>password;
    cout<<"Enter your email: "<<endl;
    cin>>email;
    cout<<"Enter your company name: "<<company_name<<endl;
    cin>>company_name;
    ofstream file("employers.txt", ios::app);
    if (file.is_open()) {
        file <<"ID: " << id <<endl;
        file <<"Password: " << password <<endl;
        file <<"Name: "<<name<<endl;
        file <<"Email: "<<email<<endl;
        file <<"Company's name: "<<company_name<<endl;
        file <<endl;
        file.close();
        cout << "Registration employer successful.\n";
        employerMenu();
    } else {
        cerr << "Unable to open file for registration.\n";
    }
}
// Method to register a new candidate
void registerCandidate() {
    string id,password,name,birth_date,email,phone,address,education,skills;
    cout<< "Enter your name: "<<endl;
    cin>>name; // TODO check if: 1.there is numbers in the name ,2.check if there is two same names
    while (id.size()!=9) {
        cout << "Enter your id: " << endl;
        cin >> id; // TODO check if there is no letters in the id
    }
    cin.ignore();
    cout<< "Enter your password: "<<endl;
    cin>>password;

    cin.ignore();
    cout<<"Enter your birth date: "<<birth_date<<endl;
    getline(cin,birth_date);

    cout<<"Enter your email: "<<email<<endl;
    cin>>email;

    cin.ignore();
    cout<<"Enter your phone number: "<<phone<<endl;
    getline(cin,phone);

    cout<<"Enter your address: "<<address<<endl;
    getline(cin,address);

    cout<<"Enter your education: High school level / BA / Master's degree / Doctorate"<<endl;
    cin.ignore();
    getline(cin,education);

    cout<<"Enter your skills: (for example - increases head, highly motivated...)"<<endl;
    cin.ignore();
    getline(cin,skills);

    ofstream file("candidate.txt", ios::app);
    if (file.is_open()) {
        file <<"ID: " << id <<endl;
        file <<"Password: "<< password  <<endl;
        file <<"Name: "<<name<<endl;
        file <<"Birth date: "<<birth_date<<endl;
        file <<"Email: "<<email<<endl;
        file <<"Phone number: "<<phone<<endl;
        file <<"Address: "<<address<<endl;
        file <<"Education: "<<education<<endl;
        file <<"Skills: "<<skills<<endl;
        file <<endl;
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
    cout << "Enter your name: "<<endl;
    cin >> employerName;
    cout << "Enter id: "<<endl;
    cin >> employerID;
    cout << "Enter password: "<<endl;
    cin >> employerPassword;

    ifstream file("employers.txt");
    if (file.is_open()) {
        string line;
        bool found = false;
        while (getline(file, line)) {
            if (line.find("ID: " + employerID) != string::npos) {
                getline(file, line);
                if (line.find("Password: " + employerPassword) != string::npos) {
                    found = true;
                    break;
                }
            }
        }
        file.close();
        if (found) {
            cout << "Login employer successful.\n";
            employerMenu();
        } else {
            cout << "Invalid id or password. Please try again!\n";
        }
    } else {
        cerr << "Unable to open file for employer login.\n";
    }
}
//if candidate in text
void loginCandidate() {

    cout << "Enter id: "<<endl;
    cin >> candidateID;
    cout << "Enter password: "<<endl;
    cin >> candidatePassword;
    cout << "Enter name: "<<endl;
    cin >> candidateName;


    ifstream file("candidate.txt");
    if (file.is_open()) {
        string line;
        bool found = false;
        while (getline(file, line)) {
            if (line.find("ID: " + candidateID) != string::npos) {
                getline(file, line);
                if (line.find("Password: " + candidatePassword) != string::npos) {
                    getline(file, line);
                    if (line.find("Name: " + candidateName) != string::npos) {
                        found = true;
                        break;
                    }
                }
            }
        }
        file.close();
        if (found) {
            cout << "Login candidate successful.\n\n";
            cout << "Hi " << candidateName << endl;
            cout << "Welcome to Candidate Menu!" << endl;
            candidateMenu();
        } else {
            cout << "Invalid id or password. Please try again!\n"; //todo: fix return to menu - exiting program
        }
    } else {
        cerr << "Unable to open file for candidate login.\n";
    }
}
void viewNewJobs() {
    string desiredJob;
    int candidateExperience;
    cout << endl;
    cout << "Enter the desired job: " << endl;
    cin >> desiredJob;
    cout << "Enter your years of experience: " << endl;
    cin >> candidateExperience;
    cout << endl;

    ifstream file("job.txt");
    string line;
    vector<string> matchingJobs;

    while (getline(file, line)) {
        if (line.find("Job name: " + desiredJob) != string::npos) {
            string jobInfo = line + "\n";
            for (int i = 0; i < 5; ++i) {
                getline(file, line);
                jobInfo += line + "\n";
            }
            matchingJobs.push_back(jobInfo);
        }
    }

    file.close();
    if (!matchingJobs.empty()) {
        // Sorting the matching jobs by publish date in ascending order
        sort(matchingJobs.begin(), matchingJobs.end(), [](const string &a, const string &b) {
            size_t posA = a.find("Published: ");
            size_t posB = b.find("Published: ");
            string dateA = a.substr(posA + 11);
            string dateB = b.substr(posB + 11);
            int dayA, monthA, yearA;
            int dayB, monthB, yearB;
            sscanf(dateA.c_str(), "%d/%d/%d", &dayA, &monthA, &yearA);
            sscanf(dateB.c_str(), "%d/%d/%d", &dayB, &monthB, &yearB);

            // Converting two-digit years to four digits (assuming 20th century)
            if (yearA < 100) yearA += 2000;
            if (yearB < 100) yearB += 2000;

            if (yearA != yearB) {
                return yearA < yearB;
            } else if (monthA != monthB) {
                return monthA < monthB;
            } else if (dayA != dayB) {
                return dayA < dayB;
            } else {
                return false; // If the dates are the same, keep the original order.
            }
        });

        // Printing the matching jobs
        for (const auto &job : matchingJobs) {
            size_t pos = job.find("Years of experience required: ");
            int requiredExperience = stoi(job.substr(pos + 30));
            if (candidateExperience >= requiredExperience) {
                cout << job << endl;
            }
        }
    } else {
        cout << "No matching jobs found." << endl;
    }
}
void candidateMenu() {
    // Implement candidate menu options as per requirements
    // You can add options like searching for jobs, submitting resumes, etc.
    int choice;
    cout << "What do you want to do today?" << endl;
    cout << "1. Look for new Jobs" << endl;
    cout << "2. Search for Jobs" << endl;
    cout << "3. Submit Resume" << endl;
    cout << "4. View Submission History" << endl;
    cout << "5. Edit Profile" << endl;
    cout << "6. Logout" << endl;
    cout << "Enter your choice: "<<endl;
    cin >> choice;

    switch (choice) {
        case 1:
            // Search for new jobs by field and years of experience
            viewNewJobs();
            break;
        case 2:
            // Implement job search functionality
            searchForJob();//TODO fix it
            break;
        case 3:
            // Implement resume submission functionality
            //submitResume();
            break;
        case 4:
            // Implement view submission history functionality
            ViewOfCandidateSubmissions();
            break;
        case 5:
            menuEditCandidate();
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
    candidateMenu();
}
//after employer log in
void employerMenu() {
    // Implement employer menu options as per requirements
    // You can add options like publishing, deleting, and updating jobs, viewing submissions, etc.
    int choice;
    cout << endl << "Welcome to Employer Menu!" << endl;
    cout << "Enter your choice: "<<endl;
    cout << "1. Publish a Job" << endl;
    cout << "2. Delete a Job" << endl;
    cout << "3. Update a Job" << endl;
    cout << "4. View relevant jobs that I posted" << endl;
    cout << "5. View Candidate Submissions for a Job" << endl;
    cout << "6. Logout" << endl;
    while (!(cin >> choice)) {
        cout << "Invalid input. Please choose again: "<<endl;
        cin.clear(); // Clearing the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discarding invalid input
    }


    switch (choice) {
        case 1:
            addJob();//works
            break;
        case 2:
            deleteJob();

            break;
        case 3:
            menuUpdateJobs();
            break;
        case 4:
            viewPublishedJobs();
            break;
        case 5:
            viewCandidateSubmissionsForEmployer();
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

//-------------------------------------------------> edit members of candidate
//menu edit member candidate:
void menuEditCandidate(){
    int choice;
    cout<< "hello "<<candidateName<<" what do you want to edit in your profile? "<<endl;
    cout << "Enter your choice: "<<endl;
    cout << "1. update your name." << endl;
    cout << "2. update your password." << endl;
    cout << "3. update your email." << endl;
    cout << "4. update your address." << endl;
    cout << "5. update your phone." << endl;
    cout << "6. Logout" << endl;
    while (!(cin >> choice)) {
        cout << "Invalid input. Please choose again: "<<endl;
        cin.clear(); // Clearing the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discarding invalid input
    }

    switch (choice) {
        case 1:
            editCandidateName();

            break;
        case 2:
            editCandidatePassword();

            break;
        case 3:
            editCandidateEmail();


            break;
        case 4:
            editCandidateAddress();


            break;
        case 5:
            editCandidatePhone();


            break;
        case 6:
            cout << "Logging out..." << endl;

            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }


}
//edit name candidate
void editCandidateName(){
    ifstream inputFile("candidate.txt");
    ofstream outputFile("temp.txt");
    string line;
    string newName;
    cout<<"Enter the new name: "<<endl;
    cin>>newName;

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file.\n";
        return;
    }

    bool found = false;
    while (getline(inputFile, line)) {
        // Check if the line contains the job name to edit
        if (line.find("Name: " + candidateName)!=string::npos) {
            found = true;

            outputFile << "Name: "<<newName<<endl ;
        } else {
            outputFile << line << endl;
        }

    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("candidate.txt");         // Remove the old file
        rename("temp.txt", "candidate.txt");  // Rename temp file to original name
        cout << "Name: " << candidateName << " edited successfully.\n";
        candidateName=newName;
    } else {
        cout << "Name: " << candidateName << " not found.\n";
        remove("temp.txt"); // Remove the temp file if the job wasn't found
    }
}
//edit name Password
void editCandidatePassword(){
    ifstream inputFile("candidate.txt");
    ofstream outputFile("temp.txt");
    string line;
    string newPassword;
    cout<<"Enter the new password:: "<<endl;
    cin>>newPassword;

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file.\n";
        return;
    }

    bool found = false;
    while (getline(inputFile, line)) {
        // Check if the line contains the job name to edit
        if (line.find("Password: " + candidatePassword)!=string::npos) {
            found = true;

            outputFile << "Password: "<<newPassword<<endl ;
        } else {
            outputFile << line << endl;
        }

    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("candidate.txt");         // Remove the old file
        rename("temp.txt", "candidate.txt");  // Rename temp file to original name
        cout << "Password: " << candidateName << " edited successfully.\n";
        candidatePassword=newPassword;
    } else {
        cout << "Password: " << candidateName << " not found.\n";
        remove("temp.txt"); // Remove the temp file if the job wasn't found
    }

}
//edit name Email
void editCandidateEmail(){
    string newEmail;
    cout<<"Enter the new email: "<<endl;
    cin>>newEmail;
    ifstream inputFile("candidate.txt");
    ofstream tempFile("temp.txt");


    if (inputFile.is_open() && tempFile.is_open()) {
        string line;
        bool found = false;

        while (getline(inputFile, line)) {
            // Check if the line contains the ID
            if (line.find("ID: " + candidateID) != string::npos) {
                found = true;

                // Write the ID line
                tempFile << line << endl;

                // Skip the next lines until we reach the email
                while (getline(inputFile, line) && line.find("Email: ") == string::npos) {
                    tempFile << line << endl;
                }

                // Update the email
                tempFile << "Email: " << newEmail << endl;
            } else {
                // If the line doesn't contain the ID, write it as is to the temp file
                tempFile << line << endl;
            }
        }


        inputFile.close();
        tempFile.close();

        if (found) {
            // Replace the original file with the temporary file
            remove("candidate.txt");
            rename("temp.txt", "candidate.txt");

            cout << "Email updated successfully." << endl;
        } else {
            cout << "candidate not found." << endl;
        }
    } else {
        cerr << "Unable to open files." << endl;
    }
}
//edit name Address
void editCandidateAddress(){
    string newAdrress;
    cout<<"Enter the new address: "<<endl;
    cin >> newAdrress;
    ifstream inputFile("candidate.txt");
    ofstream tempFile("temp.txt");


    if (inputFile.is_open() && tempFile.is_open()) {
        string line;
        bool found = false;

        while (getline(inputFile, line)) {
            // Check if the line contains the ID
            if (line.find("ID: " + candidateID) != string::npos) {
                found = true;

                // Write the ID line
                tempFile << line << endl;

                // Skip the next lines until we reach the email
                while (getline(inputFile, line) && line.find("Address: ") == string::npos) {
                    tempFile << line << endl;
                }

                // Update the email
                tempFile << "Address: " << newAdrress << endl;
            } else {
                // If the line doesn't contain the ID, write it as is to the temp file
                tempFile << line << endl;
            }
        }


        inputFile.close();
        tempFile.close();

        if (found) {
            // Replace the original file with the temporary file
            remove("candidate.txt");
            rename("temp.txt", "candidate.txt");

            cout << "Address updated successfully." << endl;
        } else {
            cout << "candidate not found." << endl;
        }
    } else {
        cerr << "Unable to open files." << endl;
    }
}
//edit name Phone number
void editCandidatePhone(){
    string newPhone;
    cout<<"Enter the new phone number: "<<endl;
    cin >> newPhone;
    ifstream inputFile("candidate.txt");
    ofstream tempFile("temp.txt");


    if (inputFile.is_open() && tempFile.is_open()) {
        string line;
        bool found = false;

        while (getline(inputFile, line)) {
            // Check if the line contains the ID
            if (line.find("ID: " + candidateID) != string::npos) {
                found = true;

                // Write the ID line
                tempFile << line << endl;

                // Skip the next lines until we reach the email
                while (getline(inputFile, line) && line.find("Phone number: ") == string::npos) {
                    tempFile << line << endl;
                }

                // Update the email
                tempFile << "Phone number: " << newPhone << endl;
            } else {
                // If the line doesn't contain the ID, write it as is to the temp file
                tempFile << line << endl;
            }
        }


        inputFile.close();
        tempFile.close();

        if (found) {
            // Replace the original file with the temporary file
            remove("candidate.txt");
            rename("temp.txt", "candidate.txt");

            cout << "Phone number updated successfully." << endl;
        } else {
            cout << "candidate not found." << endl;
        }
    } else {
        cerr << "Unable to open files." << endl;
    }
}


//-----------------------------------------------------jobs
//-------------------------------->updateJob
void displayEditMenu() {
    cout << "1. Edit job by name" << endl;
    cout << "2. Edit job by area" << endl;
    cout << "3. Edit job by years of experience " << endl;
    cout << "4. Edit job by salary" << endl;
    cout << "5. Edit job by type" << endl;
    cout << "6. Edit job by date" << endl;
    cout << "7. Exit" << endl;
}
//menu--edit
void menuUpdateJobs(){
    int choice;
    do {
        displayEditMenu();
        cout << "Enter your choice: "<<endl;
        while (!(cin >> choice)) {
            cout << "Invalid input. Please choose again: "<<endl;
            cin.clear(); // Clearing the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discarding invalid input
        }

        switch (choice) {
            case 1:
                editJobByName(employerName);
                break;
            case 2:
                editJobByArea(employerName);
                break;
            case 3:
                editJobByYears(employerName);
                break;
            case 4:
                editJobBySalary(employerName);
                break;
            case 5:
                editJobByType(employerName);
                break;
            case 6:
                editJobByDate(employerName);
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
}
//change name of job
void editJobByName(const string& publisher) {
    ifstream inputFile("job.txt");
    ofstream outputFile("temp.txt");
    string line,nameToEdit,nameNew;
    cout<<"Enter the name that you want to edit: "<<endl;
    cin>>nameToEdit;
    cout<<"Enter the  new name for job: "<<endl;
    cin>>nameNew;


    if (!inputFile.is_open()) {
        cerr << "Unable to open input file.\n";
        return;
    }

    bool found = false;
    while (getline(inputFile, line)) {
        // Check if the line contains the job name to edit
        if (line.find("Job name: " + nameToEdit + " publish by: " + publisher)!=string::npos) {
            found = true;
            // Modify the line with new details
            outputFile << "Job name: "<<nameNew<<" publish by: "<< publisher<<endl ;
        } else {
            outputFile << line << endl;
        }

    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("job.txt");         // Remove the old file
        rename("temp.txt", "job.txt");  // Rename temp file to original name
        cout << "Job: " << nameToEdit << " edited successfully.\n";
    } else {
        cout << "Job: " << nameToEdit << " not found.\n";
        remove("temp.txt"); // Remove the temp file if the job wasn't found
    }
}
//change area of job
void editJobByArea(const string& publisher) {
    string currentArea, newArea;
    cout << "Enter the area of the job you want to update: "<<endl;
    cin >> currentArea;
    cout << "Enter the new area: "<<endl;
    cin >> newArea;


    ifstream inputFile("job.txt");
    ofstream outputFile("temp.txt");
    string line,line1;

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file.\n";
        return;
    }

    bool found = false;
    while (getline(inputFile, line) ) {
        // Check if the line contains the job name to edit
        if (line.find(" publish by: " + publisher) != string::npos ) {

            if (getline(inputFile, line1) && line1.find("Area: " + currentArea) != string::npos) {
                // Modify the line with new details
                found = true;
                outputFile << line << endl;
                outputFile << "Area: " << newArea << endl;
            } else{
                outputFile << line << endl;
                outputFile << line1 << endl;
            }

        } else {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("job.txt");         // Remove the old file
        rename("temp.txt", "job.txt");  // Rename temp file to original name
        cout << "Area '" << currentArea<< "' edited successfully.\n";
    } else {
        cout << "Area '" << currentArea << "' not found.\n";
        remove("temp.txt"); // Remove the temp file if the job wasn't found
    }
}
//change years experience of job
void editJobByYears(const string& publisher) {
    string currentYears, newYears;
    cout << "Enter the Years of the job you want to update: "<<endl;
    cin >> currentYears;
    cout << "Enter the new Years: "<<endl;
    cin >> newYears;


    ifstream inputFile("job.txt");
    ofstream outputFile("temp.txt");
    string line,line1;

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file.\n";
        return;
    }

    bool found = false;
    while (getline(inputFile, line) ) {
        // Check if the line contains the job name to edit
        if (line.find(" publish by: " + publisher) != string::npos ) {
            getline(inputFile, line1);
            outputFile << line << endl;
            outputFile << line1 << endl;

            if (getline(inputFile, line) && line.find("Years of experience required: " + currentYears) != string::npos) {
                // Modify the line with new details
                found = true;

                outputFile << "Years of experience required: " << newYears << endl;
            } else{
                outputFile << line << endl;

            }

        } else {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("job.txt");         // Remove the old file
        rename("temp.txt", "job.txt");  // Rename temp file to original name
        cout << "Years of experience '" << currentYears<< "' edited successfully.\n";
    } else {
        cout << "Years of experience '" << currentYears<< "' not found.\n";
        remove("temp.txt"); // Remove the temp file if the job wasn't found
    }
}
//change salary of job
void editJobBySalary(const string& publisher) {
    string currentSalary, newSalary;
    cout << "Enter the salary of the job you want to update: "<<endl;
    cin >> currentSalary;
    cout << "Enter the new salary: "<<endl;
    cin >> newSalary;


    ifstream inputFile("job.txt");
    ofstream outputFile("temp.txt");
    string line,line1,line2;

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file.\n";
        return;
    }

    bool found = false;
    while (getline(inputFile, line) ) {
        // Check if the line contains the job name to edit
        if (line.find(" publish by: " + publisher) != string::npos ) {
            getline(inputFile, line1);
            getline(inputFile, line2);
            outputFile << line << endl;
            outputFile << line1 << endl;
            outputFile << line2 << endl;

            if (getline(inputFile, line) && line.find("The salary is: " + currentSalary) != string::npos) {
                // Modify the line with new details
                found = true;
                outputFile << "The salary is: " << newSalary << endl;
            } else{
                outputFile << line << endl;

            }

        } else {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("job.txt");         // Remove the old file
        rename("temp.txt", "job.txt");  // Rename temp file to original name
        cout << "salary '" << currentSalary << "' edited successfully.\n";
    } else {
        cout << "salary '" << currentSalary << "' not found.\n";
        remove("temp.txt"); // Remove the temp file if the job wasn't found
    }
}
//change type of job
void editJobByType(const string& publisher) {
    string currentType, newType;
    cout << "Enter the type of the job you want to update: "<<endl;
    cin >> currentType;
    cout << "Enter the new type: "<<endl;
    cin >> newType;


    ifstream inputFile("job.txt");
    ofstream outputFile("temp.txt");
    string line,line1,line2,line3;

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file.\n";
        return;
    }

    bool found = false;
    while (getline(inputFile, line) ) {
        // Check if the line contains the job name to edit
        if (line.find(" publish by: " + publisher) != string::npos ) {
            getline(inputFile, line1);
            getline(inputFile, line2);
            getline(inputFile, line3);
            outputFile << line << endl;
            outputFile << line1 << endl;
            outputFile << line2 << endl;
            outputFile << line3 << endl;


            if (getline(inputFile, line) && line.find("Job's type: " + currentType) != string::npos) {
                // Modify the line with new details
                found = true;
                outputFile << "Job's type: " << newType << endl;
            } else{
                outputFile << line << endl;

            }

        } else {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("job.txt");         // Remove the old file
        rename("temp.txt", "job.txt");  // Rename temp file to original name
        cout << "Job's type:" << currentType << " edited successfully.\n";
    } else {
        cout << "Job's type:" << currentType << " not found.\n";
        remove("temp.txt"); // Remove the temp file if the job wasn't found
    }
}
//change type of date
void editJobByDate(const string& publisher) {
    string currentDate, newDate;
    cout << "Enter the date of the job you want to update: "<<endl;
    cin >> currentDate;
    cout << "Enter the new date: "<<endl;
    cin >> newDate;


    ifstream inputFile("job.txt");
    ofstream outputFile("temp.txt");
    string line,line1,line2,line3,line4;

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file.\n";
        return;
    }

    bool found = false;
    while (getline(inputFile, line) ) {
        // Check if the line contains the job name to edit
        if (line.find(" publish by: " + publisher) != string::npos ) {
            getline(inputFile, line1);
            getline(inputFile, line2);
            getline(inputFile, line3);
            getline(inputFile, line4);

            outputFile << line << endl;
            outputFile << line1 << endl;
            outputFile << line2 << endl;
            outputFile << line3 << endl;
            outputFile << line4 << endl;


            if (getline(inputFile, line) && line.find("Published: " + currentDate) != string::npos) {
                // Modify the line with new details
                found = true;
                outputFile << "Published: " << newDate << endl;
            } else{
                outputFile << line << endl;

            }

        } else {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("job.txt");         // Remove the old file
        rename("temp.txt", "job.txt");  // Rename temp file to original name
        cout << "date of the job: " << currentDate << " edited successfully.\n";
    } else {
        cout << "date of the job: " << currentDate << " not found.\n";
        remove("temp.txt"); // Remove the temp file if the job wasn't found
    }
}
// add job in text file
void addJob(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string nameJ,areaJ,typeJ;
    int years_experienceJ, salaryJ;

    cout<<"Enter the years of experience required"<<endl;
    cin>>years_experienceJ;

    cout<<"Enter the job's salary"<<endl;
    cin>>salaryJ;

    cout<<"Enter the job's name"<<endl;
    cin.ignore();
    getline(cin,nameJ);

    cout<<"Enter the job's area"<<endl;
    getline(cin,areaJ);

    cout<<"Enter the job's type (full-time / part-time)"<<endl;
    getline(cin,typeJ);


    ofstream file("job.txt", ios::app);
    if (file.is_open()) {
        file <<"Job name: " << nameJ <<" publish by: "<<employerName<<endl;
        file <<"Area: " << areaJ <<endl;
        file <<"Years of experience required: "<<years_experienceJ<<endl;
        file <<"The salary is: "<<salaryJ<<endl;
        file <<"Job's type: "<<typeJ<<endl; //if it is a full-time job or a part-time job
        file <<"Published: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year <<endl;
        file << endl;
        file.close();
        cout << "add job successful.\n";
    } else {
        cerr << "Unable to add job.\n";
    }
}
// Method to delete job from text file
void deleteJob() {
    string nameE, nameToDelete;
    cout << "Enter your name: " << endl;
    cin >> nameE;
    cout << "Enter the name of the job that you want to delete: " << endl;
    cin.ignore(); // Ignore the newline character from previous input
    getline(cin, nameToDelete);

    ifstream inputFile("job.txt");
    ofstream outputFile("temp.txt");
    string line;

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file.\n";
        return;
    }

    bool found = false;
    bool deleteMode = false; // Flag to indicate when to start deleting lines

    while (getline(inputFile, line)) {
        // Check if the line contains both the job name and the publisher
        if (line.find("Job name: " + nameToDelete) != string::npos && line.find("publish by: " + nameE) != string::npos) {
            found = true;
            deleteMode = true;
            continue;
        }
        // If in delete mode, check for empty line (indicating end of job details)
        if (deleteMode && line.empty()) {
            deleteMode = false;
        }
        // Write the line to the output file if not in delete mode
        if (!deleteMode) {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("job.txt");                 // Remove the old file
        rename("temp.txt", "job.txt");     // Rename temp file to original name
        cout << "Job '" << nameToDelete << "' deleted successfully.\n";
    } else {
        cout << "Job '" << nameToDelete << "' not found.\n";
        remove("temp.txt"); // Remove the temp file if the job wasn't found
    }
}
// Method to view all jobs from text file
void viewPublishedJobs() {
    ifstream file("job.txt");
    string line;

    if (file.is_open()) {
        bool foundPublisher = false;
        while (getline(file, line)) {
            if (line.find("publish by: " + employerName) != string::npos) {
                foundPublisher = true;
                cout << line << endl;  // Print the line with publisher name
                for (int i = 0; i < 5; ++i) {
                    getline(file, line);  // Skip the next 5 lines
                    cout << line << endl;  // Print the job details
                }
                cout<<endl;
            }
        }
        if (!foundPublisher) {
            cout << "No published jobs found for publisher: " << employerName << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file.\n";
    }

}
//view all job that employer publish
void ViewOfCandidateSubmissions() {
    std::ifstream file("submissions.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::string line;
    bool foundPublisher = false;
    std::string prevLine;
    while (std::getline(file, line)) {
        if (line.find("publish by: " + employerName) != std::string::npos) {
            // Print the line before job details
            if (!prevLine.empty()) {
                std::cout << prevLine << std::endl;
            }
            foundPublisher = true;
            // Print the line with publisher name
            std::cout << line << std::endl;
            // Print the job details
            for (int i = 0; i < 6; ++i) {
                std::getline(file, line);
                std::cout << line << std::endl;
            }
            // Empty line after each job
            std::cout << std::endl;
        }
        prevLine = line;
    }
}
//---------------------------------->search
void searchForJob(){
    int choice;
    cout<<endl;
    cout<<"Choose according to which criteria you would like to search for jobs:"<<endl;
    cout<<"1. Published date."<<endl;
    cout<<"2. Name."<<endl;
    cout<<"3. Area."<<endl;
    cout<<"4. Years of experience."<<endl;
    cout<<"5. Salary range."<<endl;
    cout<<"6. Type."<<endl; //full-time or part-time
    cout<<"Enter your choice: ";
    cin>>choice;
    while(choice < 1 || choice > 6){
        cout<<"You entered an incorrect number, please try again"<<endl;
        cin>>choice;
    }
    if(choice == 1){
        searchByDate();
    }
    if(choice == 2){
        searchByName(); //works
    }
    if(choice == 3){
        searchByArea();
    }
    if(choice == 4){
        searchByYears();
    }
    if(choice == 5){
        searchBySalary();
    }
    if(choice == 6){
        searchByType();
    }
}
// function to search jobs by a specific published date
void searchByDate() {
    string date;
    cout << "Enter the job's date you want in format d/m/yy: " << endl;
    cin.ignore(); // Clear input buffer
    getline(cin, date);

    ifstream file("job.txt");

    if (file.is_open()) {
        string line , jobDetails;
        bool found = false; // Flag to check if job was found
        vector<string> previousLines; // Store previous 5 lines

        while (getline(file, line)) {
            if (line.find("Published: " + date) != string::npos) {
                jobDetails = ""; // Reset jobDetails for each new job

                // Print previous 5 lines
                for (const auto& prevLine : previousLines) {
                    cout << prevLine << endl;
                    jobDetails += prevLine + "\n";
                }

                // Print the entire job information block
                cout << line << endl;
                jobDetails += line + "\n";


                while (getline(file, line) && !line.empty()) {
                    cout << line << endl;
                    jobDetails += line + "\n";
                }

                found = true; // Job found
                cout << endl; // Add a blank line after printing the job block
                // No break here, so it continues searching
                submitCandidacy (jobDetails);
            }

            // Store previous 5 lines
            previousLines.push_back(line);
            if (previousLines.size() > 5) {
                previousLines.erase(previousLines.begin());
            }
        }

        file.close();

        if (!found) {
            cout << "Job not found." << endl;
        }
    } else {
        cerr << "Unable to open file." << endl;
    }
}

// function to search jobs by a specific published name
void searchByName() {
    string name, jobDetails;
    cout << endl << "Enter the job's name you want: " << endl;
    cin.ignore(); // Clear input buffer
    getline(cin, name);
    cout << endl;
    ifstream file("job.txt");

    if (file.is_open()) {
        string line;
        bool found = false; // Flag to check if job was found

        while (getline(file, line)) {
            if (line.find("Job name: " + name) != string::npos) {
                // Print the entire job information block
                cout << line << endl;
                string jobDetails = line + "\n";
                while (getline(file, line) && !line.empty()) {
                    cout << line << endl;
                    jobDetails += line + "\n";
                }

                cout<<endl;
                found = true; // Job found
                submitCandidacy (jobDetails);
                // No break here, so it continues searching
            }

        }

        file.close();

        if (!found) {
            cout << "Job not found." << endl<<endl;
        }
    } else {
        cerr << "Unable to open file." << endl;
    }
}
// function to search jobs by a specific published area
void searchByArea() {
    string area;
    cout << "Enter the job's area: " << endl;
    cin.ignore(); // Clear input buffer
    getline(cin, area);

    ifstream file("job.txt");

    if (file.is_open()) {
        string line, jobDetails;
        bool found = false; // Flag to check if job was found
        string previousLine; // Store previous line

        while (getline(file, line)) {
            if (line.find("Area: " + area) != string::npos) {
                jobDetails = ""; // Reset jobDetails for each new job

                // Print the previous line
                cout << previousLine << endl;
                jobDetails += previousLine + "\n";

                // Print the entire job information block
                cout << line << endl;
                jobDetails += line + "\n";

                // Print the next 4 lines
                for (int i = 0; i < 4 && getline(file, line) && !line.empty(); ++i) {
                    cout << line << endl;
                    jobDetails += line + "\n";
                }
                cout<<endl;

                found = true; // Job found
                submitCandidacy (jobDetails);
                // No break here, so it continues searching
            }

            previousLine = line; // Save the current line
        }

        file.close();

        if (!found) {
            cout << "Job not found." << endl;
        }
    } else {
        cerr << "Unable to open file." << endl;
    }
}
// function to search jobs by a specific published years of experience
void searchByYears(){
    int years_experience;
    cout << "Enter the job's years experience required: " << endl;
    cin.ignore(); // Clear input buffer
    cin >> years_experience;

    ifstream file("job.txt");

    if (file.is_open()) {
        string line, jobDetails;
        bool found = false; // Flag to check if job was found
        vector<string> previousLines; // Vector to store previous 2 lines

        while (getline(file, line)) {
            // Check if the line contains the years of experience required
            if (line.find("Years of experience required: " + to_string(years_experience)) != string::npos) {
                jobDetails = ""; // Reset jobDetails for each new job
                // Print previous 2 lines
                for (const auto& prevLine : previousLines) {
                    cout << prevLine << endl;
                    jobDetails += prevLine + "\n";
                }
                // Print the entire job information block
                cout << line << endl;
                jobDetails += line + "\n";

                // Print the next 3 lines
                for (int i = 0; i < 3 && getline(file, line) && !line.empty(); ++i) {
                    cout << line << endl;
                    jobDetails += line + "\n";

                }
                cout<<endl;

                found = true; // Job found
                submitCandidacy (jobDetails);
            }

            // Update previous lines vector
            if (previousLines.size() == 2) {
                previousLines.erase(previousLines.begin());
            }
            previousLines.push_back(line);
        }

        file.close();

        if (!found) {
            cout << "No jobs found for the specified years of experience." << endl;
        }
    } else {
        cerr << "Unable to open file." << endl;
    }
}
// function to search jobs by a specific published salary
void searchBySalary() {
    int salary;
    cout << "Enter the job's salary: " << endl;
    cin.ignore(); // Clear input buffer
    cin >> salary;

    ifstream file("job.txt");

    if (file.is_open()) {
        string line, jobDetails;
        bool found = false; // Flag to check if job was found
        vector<string> surroundingLines; // Store surrounding lines

        while (getline(file, line)) {
            string _salary = to_string(salary);
            if (line.find("The salary is: " + _salary) != string::npos) {
                jobDetails = ""; // Reset jobDetails for each new job
                // Print the surrounding lines
                for (const auto &surroundLine : surroundingLines) {
                    cout << surroundLine << endl;
                    jobDetails += surroundLine + "\n";
                }

                // Print the entire job information block
                cout << line << endl;
                jobDetails += line + "\n";

                for (int i = 0; i < 2 && getline(file, line); ++i) {
                    if (!line.empty()) {
                        cout << line << endl;
                        jobDetails += line + "\n";
                    } else {
                        break; // Exit the loop if an empty line is encountered
                    }
                }

                found = true; // Job found
                submitCandidacy (jobDetails);
            }

            // Store the surrounding lines
            surroundingLines.push_back(line);
            if (surroundingLines.size() > 5) {
                surroundingLines.erase(surroundingLines.begin());
            }

            // If job found, reset found flag to continue searching
            if (found) {
                found = false;
            }
        }

        file.close();

        if (!found) {
            cout << "Job not found." << endl;
        }
    } else {
        cerr << "Unable to open file." << endl;
    }
}
// function to search jobs by a specific type
void searchByType() {
    string type, jobDetails;
    cout << "Enter the job's type (full-time / part-time): " << endl;
    cin.ignore(); // Clear input buffer
    getline(cin, type);

    ifstream file("job.txt");

    if (file.is_open()) {
        string line;
        bool found = false; // Flag to check if job was found
        vector<string> surroundingLines; // Store surrounding lines

        while (getline(file, line)) {
            if (line.find("Job's type: " + type) != string::npos) {
                jobDetails = ""; // Reset jobDetails for each new job
                // Print the surrounding lines
                for (const auto& surroundLine : surroundingLines) {
                    cout << surroundLine << endl;
                    jobDetails += surroundLine + "\n";

                }

                // Print the entire job information block
                cout << line << endl;
                jobDetails += line + "\n";

                // Print the next line
                if (getline(file, line)) {
                    cout << line << endl;
                    jobDetails += line + "\n";
                }

                found = true; // Job found
                submitCandidacy (jobDetails);
            }

            // Store the surrounding lines
            surroundingLines.push_back(line);
            if (surroundingLines.size() > 5) {
                surroundingLines.erase(surroundingLines.begin());
            }
        }

        file.close();

        if (!found) {
            cout << "Job not found." << endl;
        }
    } else {
        cerr << "Unable to open file." << endl;
    }
}
//A function that allows submitting a candidacy request for a certain position
void submitCandidacy (string jobDetails){
    int applyChoice;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "Do you want to apply for this job?" << endl;
    cout << "1. Apply" << endl;
    cout << "Any key. Continue to the next offer" << endl;
    cout << "Enter your choice: ";
    cin >> applyChoice;
    cout << endl;

    if (applyChoice == 1) {
        // Save the job in submissions.txt with candidate's details
        ofstream submissionsFile("submissions.txt", ios::app);
        if (submissionsFile.is_open() ) {
            submissionsFile << "Submitted by: " << candidateName << " .  on date: "
                            <<ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year <<  endl;

            submissionsFile << jobDetails << endl;
            submissionsFile << endl;

            submissionsFile.close();

            cout << "Job application submitted successfully!" << endl<<endl;
        } else {
            cerr << "Unable to open files." << endl;
        }
    }
}
bool findCandidateEducation(const std::string& candidateName1, const std::string& userEducation) {
    std::ifstream candidatesFile("candidate.txt");
    if (!candidatesFile.is_open()) {
        std::cerr << "Error opening candidates file!" << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(candidatesFile, line)) {
        if (line == candidateName1) {
            std::getline(candidatesFile, line); // Read education line
            if (line == userEducation) {
                return true; // Education matches
            }
        }
    }

    return false; // Education not found or doesn't match
}
void viewCandidateSubmissionsForEmployer() {
    string jobTitle;
    cout << "Enter the job title you want to filter candidates for: ";
    cin.ignore();
    getline(cin , jobTitle);
    int choiceFilter;
    cout << "View the candidates who have applied" << endl;
    cout << "1. All the Candidates" << endl;
    cout << "2. Filter by education's candidate" << endl;
    cin >> choiceFilter;

    if (choiceFilter == 1) {
        std::ifstream file("submissions.txt");
        if (!file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return;
        }

        std::string line;
        bool foundCandidate = false;
        std::string prevLine;
        while (std::getline(file, line)) {
            if (line.find("Job name: " + jobTitle) != std::string::npos) {
                // Print the line before job details
                if (!prevLine.empty()) {
                    std::cout << prevLine << std::endl;
                }
                foundCandidate = true;

                // Empty line after each job
                std::cout << std::endl;
            }
            prevLine = line;

        }
    } else {
        if (choiceFilter == 2) {
            std::ifstream submissionsFile("submissions.txt");
            if (!submissionsFile.is_open()) {
                std::cerr << "Error opening submissions file!" << std::endl;
                return ;
            }
            std::string userEducation;

            // Get job title and required education from user
            std::cout << "Enter education qualification: "<<endl;
            cin.ignore();
            std::getline(std::cin, userEducation);

            std::string line;
            std::vector<std::string> foundCandidates; // Vector to store found candidates

            // Search for candidates for the given job title in submissions file
            while (std::getline(submissionsFile, line)) {
                if (line.find("Job name: " + jobTitle) != std::string::npos) {
                    std::string candidateName1 = line.substr(10); // Extract candidate name
                    bool educationMatch = findCandidateEducation(candidateName, userEducation);
                    if (educationMatch) {
                        foundCandidates.push_back(candidateName);
                    }
                }
            }

            // Print the found candidates
            if (foundCandidates.empty()) {
                std::cout << "No matching candidates found." << std::endl;
            } else {
                std::cout << "Matching candidates:" << std::endl;
                for (const auto& candidate : foundCandidates) {
                    std::cout << candidate << std::endl;
                }
            }

        }else {
            cout << "Invalid choice." << endl;}
    }
}