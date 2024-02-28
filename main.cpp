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
void addJob(const string &dateJ,const string &nameJ, const string &areaJ,int years_experienceJ,double salaryJ,const string &typeJ);
void searchForJob();
void searchByDate();
void searchByName();
void searchByArea();
void searchByYears();
void searchBySalary();
void searchByType();
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
    cin>>name;
    while (id.size()!=9) {
        cout << "Enter your id: " << endl;
        cin >> id;
    }

    cout<< "Enter your password: "<<endl;
    cin>>password;
    cout<<"Enter your birth date: "<<birth_date<<endl;
    cin>>birth_date;
    cout<<"Enter your email: "<<email<<endl;
    cin>>email;
    cout<<"Enter your phone number: "<<phone<<endl;
    cin>>phone;
    cout<<"Enter your address: "<<address<<endl;
    cin>>address;
    cout<<"Enter your education: High school level / BA / Master's degree / Doctorate"<<endl;
    cin>>education;
    cout<<"Enter your skills: (for example - increases head, highly motivated...)"<<endl;
    cin>>skills;

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
    cout << "Enter ID: " << endl;
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
    cout << "Enter your choice: "<<endl;
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
            searchForJob();
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
void addJob(const string &dateJ,const string &nameJ,const string &areaJ,int years_experienceJ,double salaryJ,const string &typeJ) {
    ofstream file("job.txt", ios::app);
    if (file.is_open()) {
        file <<"Published " << dateJ <<endl;
        file <<"Job name: " << nameJ <<endl;
        file <<"Area: " << areaJ <<endl;
        file <<"Years of experience required: "<<years_experienceJ<<endl;
        file <<"The salary is: "<<salaryJ<<endl;
        file <<"Job's type: "<<typeJ<<endl; //if it is a full-time job or a part-time job
        file << endl;
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
void editJob(const string &nameToEdit,const string &n_dateJ,const string &n_nameJ,const string &n_areaJ,int n_years_experienceJ,double n_salaryJ,const string &n_typeJ) {
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
            outputFile <<"Published " << n_dateJ <<endl;
            outputFile <<"Job name: " << n_nameJ <<endl;
            outputFile <<"Area: " << n_areaJ <<endl;
            outputFile <<"Years of experience required: "<<n_years_experienceJ<<endl;
            outputFile <<"The salary is: "<<n_salaryJ<<endl;
            outputFile <<"Job's type: "<<n_typeJ<<endl; //if it is a full-time job or a part-time job
            outputFile << endl;
            outputFile.close();
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
        searchByDate();
    }
    if(choice == 2){
        searchByName();
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
    cout << "Enter the date: " << endl;
    cin >> date;
    ifstream inputFile("job.txt");
    if (inputFile.is_open()) {
        string line;
        vector<string> found_jobs;  // To store found jobs

        while (getline(inputFile, line)) {
            // Assuming the date is at a specific position in the line (adjust accordingly)
            string dateInLine = line.substr(0, 20); // Assuming the date is 20 characters starting at position 0

            if (dateInLine == date) {
                // Store the job details in the vector
                found_jobs.push_back(line);
            }
        }

        // Display the found jobs
        if (!found_jobs.empty()) {
            cout << "Jobs found for the specified date: " << endl;
            for (const auto &job: found_jobs) {
                cout << job << endl;
            }
        } else {
            cout << "No jobs found for the specified date. " << endl;
        }

        inputFile.close();
    }
}

// function to search jobs by a specific published name
void searchByName() {
    string name;
    cout << "Enter the job's name you want: " << endl;
    cin >> name;
    ifstream inputFile("job.txt");
    if (inputFile.is_open()) {
        string line;
        vector<string> foundJobs;  // To store the found jobs

        // Read each line from the file
        while (getline(inputFile, line)) {
            // Assuming the job name is at a specific position in the line
            string nameInLine = line.substr(0, 20); // Assuming the name is 0 characters starting at position 20

            if (nameInLine == name) {
                // Store the job details in the vector
                foundJobs.push_back(line);
            }
        }

        // Display the found jobs
        if (!foundJobs.empty()) {
            cout << "Jobs found for the specified name: " << endl;
            for (const auto &job: foundJobs) {
                cout << job << endl;
            }
        } else {
            cout << "No jobs found for the specified name." << endl;
        }
        inputFile.close();
    }
}

// function to search jobs by a specific published area
void searchByArea() {
    string area;
    cout << "Enter the area you prefer to work in: " << endl;
    cin >> area;
    ifstream inputFile("job.txt");
    if (inputFile.is_open()) {
        string line;
        vector<string> foundJobs;  // To store found jobs

        // Read each line from the file
        while (getline(inputFile, line)) {
            // Assuming the area is at a specific position in the line
            string areaInLine = line.substr(0, 20); // Assuming the area is 20 characters starting at position 0

            if (areaInLine == area) {
                // Store the job details in the vector
                foundJobs.push_back(line);
            }
        }

        // Display the found jobs
        if (!foundJobs.empty()) {
            cout << "Jobs found for the specified area: " << endl;
            for (const auto &job: foundJobs) {
                cout << job << endl;
            }
        } else {
            cout << "No jobs found for the specified area. " << endl;
        }
        inputFile.close();
    }
}

// function to search jobs by a specific published years of experience
void searchByYears(){
    int year_experience;
    cout<<"Enter the years of experience you want: "<<endl;
    cin>>year_experience;
    ifstream inputFile("job.txt");
    if (inputFile.is_open()) {
        string line;
        vector<std::string> foundJobs;  // To store found jobs

        // Read each line from the file
        while (getline(inputFile, line)) {
            // Assuming the years of experience is at a specific position in the line
            string expInLine = line.substr(0, 2); // Assuming the experience is 2 characters starting at position 50

            int experience = stoi(expInLine);
            while(experience >= year_experience){
                foundJobs.push_back(line);
            }

        }

        // Display the found jobs
        if (!foundJobs.empty()) {
            cout << "Jobs found for the specified years of experience or more: "<<endl;
            for (const auto& job : foundJobs) {
                cout << job <<endl;
            }
        } else {
            cout << "No jobs found for the specified years of experience or more. "<<endl;
        }
        inputFile.close();
    }
}

// function to search jobs by a specific published salary
void searchBySalary(){
    double salary;
    cout<<"Enter the salary you want: "<<endl;
    cin>>salary;
    ifstream inputFile("job.txt");
    if (inputFile.is_open()) {
        string line;
        vector<std::string> foundJobs;  // To store found jobs

        // Read each line from the file
        while (getline(inputFile, line)) {
            // Assuming the salary is at a specific position in the line
            string salaryInLine = line.substr(0, 7); // Assuming the salary is 7 characters starting at position 0

            double _salary = stod(salaryInLine);
            while(_salary >= salary){
                foundJobs.push_back(line);
            }
        }
        if (!foundJobs.empty()) {
            cout << "Jobs found for the specified salary or more: "<<endl;
            for (const auto& job : foundJobs) {
                cout << job <<endl;
            }
        } else {
            cout << "No jobs found for the specified salary or more. "<<endl;
        }
        inputFile.close();
    }
}

// function to search jobs by a specific type
void searchByType(){
    string type;
    cout<<"Enter the job's type you prefer: full-time / part-time"<<endl;
    cin>>type;
    ifstream inputFile("job.txt");
    if (inputFile.is_open()) {
        string line;
        vector<string> foundJobs;  // To store found jobs

        // Read each line from the file
        while (getline(inputFile, line)) {
            // Assuming the job type is at a specific position in the lin
            string typeInLine = line.substr(0, 10); // Assuming the type is 10 characters starting at position 0

            if (typeInLine == type) {
                // Store the job details in the vector
                foundJobs.push_back(line);
            }
        }
        // Display the found jobs
        if (!foundJobs.empty()) {
            cout << "Jobs found for the specified type (" << type << ")" << endl;
            for (const auto &job: foundJobs) {
                cout << job << endl;
            }
        } else {
            cout << "No jobs found for the specified type (" << type << ")" << endl;
        }
        inputFile.close();
    }
}