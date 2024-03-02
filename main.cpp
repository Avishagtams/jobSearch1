#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <limits>
using namespace std;
void menuUpdate();
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
void displayEditMenu();
void deleteJob();
void editJobByName(const string& publisher);
void editJobByArea(const string& publisher);
void editJobByYears(const string& publisher);
void editJobBySalary(const string& publisher);
void editJobByType(const string& publisher);
void editJobByDate(const string& publisher);
void mainMenu();
int main() {

   mainMenu();

    return 0;
}//-----------------------------------------------------job search system
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
    string i, p;
    cout << "Enter id: "<<endl;
    cin >> i;
    cout << "Enter password: "<<endl;
    cin >> p;

    ifstream file("employers.txt");
    if (file.is_open()) {
        string line;
        bool found = false;
        while (getline(file, line)) {
            if (line.find("ID: " + i) != string::npos) {
                getline(file, line);
                if (line.find("Password: " + p) != string::npos) {
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
    string i, p;
    cout << "Enter id: "<<endl;
    cin >> i;
    cout << "Enter password: "<<endl;
    cin >> p;

    ifstream file("candidate.txt");
    if (file.is_open()) {
        string line;
        bool found = false;
        while (getline(file, line)) {
            if (line.find("ID: " + i) != string::npos) {
                getline(file, line);
                if (line.find("Password: " + p) != string::npos) {
                    found = true;
                    break;
                }
            }
        }
        file.close();
        if (found) {
            cout << "Login candidate successful.\n";
            candidateMenu();
        } else {
            cout << "Invalid id or password. Please try again!\n";
        }
    } else {
        cerr << "Unable to open file for candidate login.\n";
    }
}
//after candidate log in
void candidateMenu() {
    // Implement candidate menu options as per requirements
    // You can add options like searching for jobs, submitting resumes, etc.
    int choice;
    cout << endl << "Welcome to Candidate Menu!" << endl;
    cout << "Enter your choice: "<<endl;
    cout << "1. Search for Jobs" << endl;
    cout << "2. Submit Resume" << endl;
    cout << "3. View Submission History" << endl;
    cout << "4. Edit Profile" << endl;
    cout << "5. Logout" << endl;
    cout << "Enter your choice: ";
    while (!(cin >> choice)) {
        cout << "Invalid input. Please choose again: "<<endl;
        cin.clear(); // Clearing the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discarding invalid input
    }

    switch (choice) {
        case 1:
            // Implement job search functionality
            searchForJob();//TODO fix it
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
    cout << "Enter your choice: "<<endl;
    cout << "1. Publish a Job" << endl;
    cout << "2. Delete a Job" << endl;
    cout << "3. Update a Job" << endl;
    cout << "4. View Published Jobs" << endl;
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

            // Implement delete job functionality
            break;
        case 3:
            // Implement update job functionality
            menuUpdate();
            break;
        case 4:
            // Implement view published jobs functionality
            viewPublishedJobs();
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
void menuUpdate(){
    string publisherName;
    cout << "Enter your name as publisher: "<<endl;
    cin >> publisherName;
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
                editJobByName(publisherName);
                break;
            case 2:
                editJobByArea(publisherName);
                break;
            case 3:
                editJobByYears(publisherName);
                break;
            case 4:
                editJobBySalary(publisherName);
                break;
            case 5:
                editJobByType(publisherName);
                break;
            case 6:
                editJobByDate(publisherName);
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
        if (line.find("job name: " + nameToEdit + " publish by: " + publisher)!=string::npos) {
            found = true;
            // Modify the line with new details
            outputFile << "job name: "<<nameNew<<" publish by: "<< publisher<<endl ;
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
        cout << "Job '" << currentArea<< "' edited successfully.\n";
    } else {
        cout << "Job '" << currentArea << "' not found.\n";
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
        cout << "Years '" << currentYears<< "' edited successfully.\n";
    } else {
        cout << "Years '" << currentYears<< "' not found.\n";
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
        cout << "salary '" << currentType << "' edited successfully.\n";
    } else {
        cout << "salary '" << currentType << "' not found.\n";
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
        cout << "salary '" << currentDate << "' edited successfully.\n";
    } else {
        cout << "salary '" << currentDate << "' not found.\n";
        remove("temp.txt"); // Remove the temp file if the job wasn't found
    }
}
// add job in text file
void addJob(){
    string dateJ,nameJ,nameE,areaJ,typeJ;
    int years_experienceJ, salaryJ;
    cout<<"Enter the your name"<<endl;
    cin.ignore();
    getline(cin,nameE);

    cout<<"Enter published date"<<endl;
    cin.ignore();
    getline(cin,dateJ);

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
        file <<"Job name: " << nameJ <<" publish by: "<<nameE<<endl;
        file <<"Area: " << areaJ <<endl;
        file <<"Years of experience required: "<<years_experienceJ<<endl;
        file <<"The salary is: "<<salaryJ<<endl;
        file <<"Job's type: "<<typeJ<<endl; //if it is a full-time job or a part-time job
        file <<"Published: " << dateJ <<endl;
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
        cout << "List of Published Jobs:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file.\n";
    }
}
//---------------------------------->search
void searchForJob(){
    int choice;
    cout<<"Choose according to which criteria you would like to search for jobs:"<<endl;
    cout<<"1. Published date."<<endl;
    cout<<"2. Name."<<endl;
    cout<<"3. Area."<<endl;
    cout<<"4. Years of experience."<<endl;
    cout<<"5. Salary range."<<endl;
    cout<<"6. Type."<<endl; //full-time or part-time
    cin>>choice;
    while(choice < 1 || choice > 6){
        cout<<"You entered an incorrect number, please try again"<<endl;
        cin>>choice;
    }
    if(choice == 1){
        searchByDate();//TODO check why it doesnt work
    }
    if(choice == 2){
        searchByName(); //works
    }
    if(choice == 3){
        searchByArea();//TODO check why it doesnt work
    }
    if(choice == 4){
        searchByYears();//TODO check why it doesnt work
    }
    if(choice == 5){
        searchBySalary();//TODO check why it doesnt work
    }
    if(choice == 6){
        searchByType();//TODO check why it doesnt work
    }
}
// function to search jobs by a specific published date
void searchByDate() {
    string date;
    cout << "Enter the job's date you want: " << endl;
    cin.ignore(); // Clear input buffer
    getline(cin, date);

    ifstream file("job.txt");

    if (file.is_open()) {
        string line;
        bool found = false; // Flag to check if job was found
        vector<string> previousLines; // Store previous 5 lines

        while (getline(file, line)) {
            if (line.find("Published: " + date) != string::npos) {
                // Print previous 5 lines
                for (const auto& prevLine : previousLines) {
                    cout << prevLine << endl;
                }

                // Print the entire job information block
                cout << line << endl;

                while (getline(file, line) && !line.empty()) {
                    cout << line << endl;
                }

                found = true; // Job found
                cout << endl; // Add a blank line after printing the job block
                // No break here, so it continues searching
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
    string name;
    cout << "Enter the job's name you want: " << endl;
    cin.ignore(); // Clear input buffer
    getline(cin, name);

    ifstream file("job.txt");

    if (file.is_open()) {
        string line;
        bool found = false; // Flag to check if job was found

        while (getline(file, line)) {
            if (line.find("Job name: " + name) != string::npos) {
                // Print the entire job information block
                cout << line << endl;

                while (getline(file, line) && !line.empty()) {
                    cout << line << endl;
                }

                cout<<endl;
                found = true; // Job found
                // No break here, so it continues searching
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
// function to search jobs by a specific published area
void searchByArea() {
    string area;
    cout << "Enter the job's area: " << endl;
    cin.ignore(); // Clear input buffer
    getline(cin, area);

    ifstream file("job.txt");

    if (file.is_open()) {
        string line;
        bool found = false; // Flag to check if job was found
        string previousLine; // Store previous line

        while (getline(file, line)) {
            if (line.find("Area: " + area) != string::npos) {
                // Print the previous line
                cout << previousLine << endl;

                // Print the entire job information block
                cout << line << endl;

                // Print the next 4 lines
                for (int i = 0; i < 4 && getline(file, line) && !line.empty(); ++i) {
                    cout << line << endl;
                }
                cout<<endl;

                found = true; // Job found
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
            string line;
            bool found = false; // Flag to check if job was found
            vector<string> previousLines; // Vector to store previous 2 lines

            while (getline(file, line)) {
                // Check if the line contains the years of experience required
                if (line.find("Years of experience required: " + to_string(years_experience)) != string::npos) {
                    // Print previous 2 lines
                    for (const auto& prevLine : previousLines) {
                        cout << prevLine << endl;
                    }
                    // Print the entire job information block
                    cout << line << endl;

                    // Print the next 3 lines
                    for (int i = 0; i < 3 && getline(file, line) && !line.empty(); ++i) {
                        cout << line << endl;
                    }
                    cout<<endl;

                    found = true; // Job found
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
        string line;
        bool found = false; // Flag to check if job was found
        vector<string> surroundingLines; // Store surrounding lines

        while (getline(file, line)) {
            string _salary = to_string(salary);
            if (line.find("The salary is: " + _salary) != string::npos) {
                // Print the surrounding lines
                for (const auto &surroundLine : surroundingLines) {
                    cout << surroundLine << endl;
                }

                // Print the entire job information block
                cout << line << endl;

                for (int i = 0; i < 2 && getline(file, line); ++i) {
                    cout << line << endl;
                }

                found = true; // Job found
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
    string type;
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
                // Print the surrounding lines
                for (const auto& surroundLine : surroundingLines) {
                    cout << surroundLine << endl;
                }

                // Print the entire job information block
                cout << line << endl;

                // Print the next line
                if (getline(file, line)) {
                    cout << line << endl;
                }

                found = true; // Job found
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

