#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
/*#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>*/


using namespace std;

void CreateEmploy();
void readFile(const string& filename, vector<string>& data);
void loginCandidate();
void loginEmployer();
void registerCandidate();
void registerEmployer();
void employerMenu();
void candidateMenu();
void addJob(/*const string &dateJ,const string &nameJ, const string &areaJ,int years_experienceJ,double salaryJ,const string &typeJ*/);
void searchForJob();
void searchByDate();
void searchByName();
void searchByArea();
void searchByYears();
void searchBySalary();
void searchByType();
void publishJob();
//void eraseJobFile();
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
    //eraseJobFile();
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
    cout << "Enter ID: " << endl;
    cin >> i;
    cout << "Enter password: " << endl;
    cin >> p;
    vector<string> employers;
    readFile("employers.txt", employers);
    for (const auto& emp : employers) {
        size_t pos = emp.find(" ");
        if (pos != string::npos) {
            string empId = emp.substr(0, i.size());
            string empPass = emp.substr(0,p.size());
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
            string empId = emp.substr(0, i.size());
            string empPass = emp.substr(0,p.size());
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

    cin >> choice;

    switch (choice) {
        case 1:
            addJob();//works
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
void addJob(){
    string dateJ,nameJ,areaJ,typeJ;
    int years_experienceJ;
    double salaryJ;
    cout<<"Enter published date"<<endl;
    cin.ignore();
    getline(cin,dateJ);

    cout<<"Enter the years of experience required"<<endl;
    cin>>years_experienceJ;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        file <<"Job name: " << nameJ <<endl;
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
        if (line.find("Job name: " + nameToDelete) != string::npos) {
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
            outputFile <<"Published: " << n_dateJ <<endl;
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
    /*string date;
    cout << "Enter the job's date you want: " << endl;
    cin.ignore(); // Clear input buffer
    getline(cin, date);

    ifstream file("job.txt");

    if (file.is_open()) {
        string line;
        bool found = false; // Flag to check if job was found

        while (getline(file, line)) {
            if (line.find("Published: " + date) != string::npos) {
                // Print the entire job information block
                cout << line << endl;

                while (getline(file, line) && !line.empty()) {
                    cout << line << endl;
                }

                found = true; // Job found
                break;
            }
        }

        file.close();

        if (!found) {
            cout << "Job not found." << endl;
        }
    } else {
        cerr << "Unable to open file." << endl;
    }*/
    string date;
    cout << "Enter the job's date you want: " << endl;
    cin.ignore(); // Clear input buffer
    getline(cin, date);

    ifstream file("job.txt");

    if (file.is_open()) {
        string line;
        bool found = false; // Flag to check if job was found
        const int linesBefore = 6;
        int linesCount = 1;
        string previousLines[linesBefore];

        while (getline(file, line)) {
            // Store the last 'linesBefore' lines
            previousLines[linesCount % linesBefore] = line;

            if (line.find("Published: " + date) != string::npos) {
                // Print the last 'linesBefore' lines before the match
                for (int i = 1; i <= linesBefore; ++i) {
                    cout << previousLines[(linesCount - i + linesBefore) % linesBefore] << endl;
                }

                // Print the entire job information block
                cout << line << endl;

                // Print the rest of the information until an empty line is encountered
                while (getline(file, line) && !line.empty()) {
                    cout << line << endl;
                }

                found = true; // Job found
                break;
            }

            linesCount++;
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

                found = true; // Job found
                break;
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

        while (getline(file, line)) {
            if (line.find("Area: " + area) != string::npos) {
                // Print the entire job information block
                cout << line << endl;

                while (getline(file, line) && !line.empty()) {
                    cout << line << endl;
                }

                found = true; // Job found
                break;
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

// function to search jobs by a specific published years of experience
void searchByYears(){
    int years_experience;
    cout << "Enter the job's years experience required: " << endl;
    cin.ignore(); // Clear input buffer
    cin>>years_experience;

    ifstream file("job.txt");

    if (file.is_open()) {
        string line;
        bool found = false; // Flag to check if job was found

        while (getline(file, line)) {
            if (line.find(&"Years of experience required: " [ years_experience]) != string::npos) {
                // Print the entire job information block
                cout << line << endl;

                while (getline(file, line) && !line.empty()) {
                    cout << line << endl;
                }

                found = true; // Job found
                break;
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

// function to search jobs by a specific published salary
void searchBySalary(){
    double salary;
    cout << "Enter the job's salary: " << endl;
    cin.ignore(); // Clear input buffer
    cin>>salary;

    ifstream file("job.txt");

    if (file.is_open()) {
        string line;
        bool found = false; // Flag to check if job was found

        while (getline(file, line)) {
            string _salary = to_string(salary);
            if (line.find("The salary is: " + _salary) != string::npos) {
                // Print the entire job information block
                cout << line << endl;

                while (getline(file, line) && !line.empty()) {
                    cout << line << endl;
                }

                found = true; // Job found
                break;
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

        while (getline(file, line)) {
            if (line.find("Job's type: " + type) != string::npos) {
                // Print the entire job information block
                cout << line << endl;

                while (getline(file, line) && !line.empty()) {
                    cout << line << endl;
                }

                found = true; // Job found
                break;
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

/*void eraseJobFile() {
    std::ofstream file("job.txt", std::ios::trunc);

    if (file.is_open()) {
        std::cout << "Job file erased successfully.\n";
        file.close();
    } else {
        std::cerr << "Unable to open file for erasing.\n";
    }
}*/