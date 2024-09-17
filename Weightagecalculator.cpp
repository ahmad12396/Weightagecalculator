#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm> // Include algorithm header for the transform function
#include <cctype>
using namespace std;

double gradeToGPA(const string &grade);
double marksToGPA(int marks);
double calculateSubjectGPA(const string &subjectName, int inputType);

int main()
{
    int Choice;
    double sumGPA = 0, sumCreditHours = 0;
    int numSubjects;
    string subjectName;
A:
    cout << "********************************\n";
    cout << "Enter subject to find weightage.\n";
    cout << "Enter '1' for Theory GPA Calculation:\n";
    cout << "Enter '2' for Lab GPA Calculation :\n";
    cout << "Enter '3' for Semester GPA calculation:\n";
    cout << "Enter '4' for CGPA calculation:\n";
    cout << "Enter '5' for EXIT:\n";
    cout << "********************************\n";
    cin >> Choice;
    switch (Choice)
    {
    case 1:
    {
        // Theory subject
        double Assignments_Weightage, Assignments_Total, Assignments, Quizes_Weightage, Quizes_Total, Quizes, Mids, Finals, Presentation;
        double Mids_Total, Mids_Weightage, Finals_Total, Finals_Weightage, Presentation_Weightage, Presentation_Total, Weightage_Sum;
        double Assignment_Percentage, Quizes_Percentage, Mids_Percentage, Finals_Percentage, Presentation_Percentage;
        double Obtained_Assignments_Weightage, Obtained_Quizes_Weightage, Obtained_Mids_Weightage, Obtained_Finals_Weightage, Obtained_Presentation_Weightage;
        double Obtained_Sum;

        cout << "Enter your Obtained number in all assignments: ";
        cin >> Assignments;
        cout << "Enter your Total number in all assignments: ";
        cin >> Assignments_Total;
        cout << "Enter your weightage number of all assignments: ";
        cin >> Assignments_Weightage;
        Assignment_Percentage = static_cast<double>(Assignments) / Assignments_Total;
        cout << Assignment_Percentage * 100 << "%\n"; // Output as percentage

        // Quizzes
        cout << "Enter your Obtained number in all Quizzes: ";
        cin >> Quizes;
        cout << "Enter your Total number in all Quizzes: ";
        cin >> Quizes_Total;
        cout << "Enter your weightage number of all Quizzes: ";
        cin >> Quizes_Weightage;
        Quizes_Percentage = static_cast<double>(Quizes) / Quizes_Total;
        cout << Quizes_Percentage * 100 << "%\n"; // Output as percentage

        // Mids
        cout << "Enter Obtained number in Midterms: ";
        cin >> Mids;
        cout << "Enter total number in Midterms: ";
        cin >> Mids_Total;
        cout << "Enter your weightage number in Midterms: ";
        cin >> Mids_Weightage;
        Mids_Percentage = static_cast<double>(Mids) / Mids_Total;
        cout << Mids_Percentage * 100 << "%\n"; // Output as percentage

        // Finals
        cout << "Enter obtained number in Finals: ";
        cin >> Finals;
        cout << "Enter total number in Finals: ";
        cin >> Finals_Total;
        cout << "Enter your weightage number in Finals: ";
        cin >> Finals_Weightage;
        Finals_Percentage = static_cast<double>(Finals) / Finals_Total;
        cout << Finals_Percentage * 100 << "%\n"; // Output as percentage

        // Presentation
        char n;
        cout << "Presentation Yes / No : ";
        cin >> n;
        n = towlower(n);
        if (n == 'y')
        {

            cout << "Enter obtained number in Presentation: ";
            cin >> Presentation;
            cout << "Enter total number in Presentation: ";
            cin >> Presentation_Total;
            cout << "Enter your weightage number in Presentation: ";
            cin >> Presentation_Weightage;
            Presentation_Percentage = static_cast<double>(Presentation) / Presentation_Total;
            cout << Presentation_Percentage * 100 << "%\n"; // Output as percentage

            // Calculation
            Weightage_Sum = Assignments_Weightage + Quizes_Weightage + Mids_Weightage + Finals_Weightage + Presentation_Weightage;
            // Obtained Numbers
            Obtained_Assignments_Weightage = Assignment_Percentage * Assignments_Weightage;
            Obtained_Quizes_Weightage = Quizes_Percentage * Quizes_Weightage;
            Obtained_Mids_Weightage = Mids_Percentage * Mids_Weightage;
            Obtained_Finals_Weightage = Finals_Percentage * Finals_Weightage;
            Obtained_Presentation_Weightage = Presentation_Percentage * Presentation_Weightage;
            // Result
            Obtained_Sum = Obtained_Assignments_Weightage + Obtained_Quizes_Weightage + Obtained_Mids_Weightage + Obtained_Finals_Weightage + Obtained_Presentation_Weightage;
            Obtained_Sum = ceil(Obtained_Sum);
            cout << "Your total Obtained number is " << Obtained_Sum << " out of " << Weightage_Sum << " with a weighted average of " << (Obtained_Sum / Weightage_Sum) * 100 << "%." << endl;
        }
        else if (n == 'n')
        {
            // Calculation
            Weightage_Sum = Assignments_Weightage + Quizes_Weightage + Mids_Weightage + Finals_Weightage;
            // Obtained Numbers
            Obtained_Assignments_Weightage = Assignment_Percentage * Assignments_Weightage;
            Obtained_Quizes_Weightage = Quizes_Percentage * Quizes_Weightage;
            Obtained_Mids_Weightage = Mids_Percentage * Mids_Weightage;
            Obtained_Finals_Weightage = Finals_Percentage * Finals_Weightage;
            // Obtained_Presentation_Weightage = Presentation_Percentage * Presentation_Weightage;
            // Result
            Obtained_Sum = Obtained_Assignments_Weightage + Obtained_Quizes_Weightage + Obtained_Mids_Weightage + Obtained_Finals_Weightage;
            Obtained_Sum = ceil(Obtained_Sum);
            cout << "Your total Obtained number is " << Obtained_Sum << " out of " << Weightage_Sum << " with a weighted average of " << (Obtained_Sum / Weightage_Sum) * 100 << "%." << endl;
        }

        else
            cout << "Invalid Enter ";

        string theoryGrade;
        string theoryGPA;
        if (Obtained_Sum >= 85)
        {
            theoryGrade = "A";
            theoryGPA = "4.00";
        }
        else if (Obtained_Sum >= 80 && Obtained_Sum <= 84)
        {
            theoryGrade = "A-";
            theoryGPA = "3.66";
        }
        else if (Obtained_Sum >= 75 && Obtained_Sum <= 79)
        {
            theoryGrade = "B+";
            theoryGPA = "3.33";
        }
        else if (Obtained_Sum >= 70 && Obtained_Sum <= 74)
        {
            theoryGrade = "B";
            theoryGPA = "3.00";
        }
        else if (Obtained_Sum >= 68 && Obtained_Sum <= 70)
        {
            theoryGrade = "B-";
            theoryGPA = "2.66";
        }
        else if (Obtained_Sum >= 64 && Obtained_Sum <= 67)
        {
            theoryGrade = "C+";
            theoryGPA = "2.33";
        }
        else if (Obtained_Sum >= 61 && Obtained_Sum <= 63)
        {
            theoryGrade = "C";
            theoryGPA = "2.00";
        }
        else if (Obtained_Sum >= 58 && Obtained_Sum <= 60)
        {
            theoryGrade = "C-";
            theoryGPA = "1.66";
        }
        else if (Obtained_Sum >= 54 && Obtained_Sum <= 57)
        {
            theoryGrade = "D";
            theoryGPA = "1.30";
        }
        else if (Obtained_Sum >= 50 && Obtained_Sum <= 53)
        {
            theoryGrade = "D+";
            theoryGPA = "1.30";
        }
        else
            theoryGrade = "F";

        cout << "Your GPA for Theory is: " << theoryGPA << endl;
        cout << "Your Grade for Theory is: " << theoryGrade << endl;

        char ch;
        cout << "Do you want to go back to selction process 'Y' for Yes and 'N' for No";
        cin >> ch;
        ch = toupper(ch);
        if (ch == 'Y')
        {
            goto A;
        }
        else
            break;
    }

    case 2:
    {
        // Lab subject
        int Final_Exam_Total, Final_Exam_Obtained, Final_Exam_Weightage, Subject_Viva_Total, Subject_Viva_Obtained, Subject_Viva_Weightage, Team_Project_Total, Team_Project_Obtained, Team_Project_Weightage;
        double Final_Exam_Percentage, Subject_Viva_Percentage, Team_Project_Percentage, Obtained_Final_Exam_Weightage, Obtained_Subject_Viva_Weightage, Obtained_Team_Project_Weightage;
        double Obtained_Sum, Weightage_Sum;

        // Your code for lab subject

        cout << "Enter obtained number in Final Exam: ";
        cin >> Final_Exam_Obtained;
        cout << "Enter total number in Final Exam: ";
        cin >> Final_Exam_Total;
        cout << "Enter weightage number in Final Exam: ";
        cin >> Final_Exam_Weightage;
        Final_Exam_Percentage = static_cast<double>(Final_Exam_Obtained) / Final_Exam_Total;

        // Subject Viva
        cout << "Enter obtained number in Subject Viva: ";
        cin >> Subject_Viva_Obtained;
        cout << "Enter total number in Subject Viva: ";
        cin >> Subject_Viva_Total;
        cout << "Enter weightage number in Subject Viva: ";
        cin >> Subject_Viva_Weightage;
        Subject_Viva_Percentage = static_cast<double>(Subject_Viva_Obtained) / Subject_Viva_Total;

        // Team Project
        cout << "Enter obtained number in Team Project: ";
        cin >> Team_Project_Obtained;
        cout << "Enter total number in Team Project: ";
        cin >> Team_Project_Total;
        cout << "Enter weightage number in Team Project: ";
        cin >> Team_Project_Weightage;
        Team_Project_Percentage = static_cast<double>(Team_Project_Obtained) / Team_Project_Total;

        // Calculation
        Weightage_Sum = Final_Exam_Weightage + Subject_Viva_Weightage + Team_Project_Weightage;

        // Obtained Numbers
        Obtained_Final_Exam_Weightage = Final_Exam_Percentage * Final_Exam_Weightage;
        Obtained_Subject_Viva_Weightage = Subject_Viva_Percentage * Subject_Viva_Weightage;
        Obtained_Team_Project_Weightage = Team_Project_Percentage * Team_Project_Weightage;

        // Result
        Obtained_Sum = Obtained_Final_Exam_Weightage + Obtained_Subject_Viva_Weightage + Obtained_Team_Project_Weightage;
        Obtained_Sum = ceil(Obtained_Sum);
        cout << "Your total Obtained number is " << Obtained_Sum << " out of " << Weightage_Sum << " with a weighted average of " << (Obtained_Sum / Weightage_Sum) * 100 << "%." << endl;

        string LabGrade;
        string LabGPA;
        if (Obtained_Sum >= 85)
        {
            LabGrade = "A";
            LabGPA = "4.00";
        }
        else if (Obtained_Sum >= 80 && Obtained_Sum <= 84)
        {
            LabGrade = "A-";
            LabGPA = "3.66";
        }
        else if (Obtained_Sum >= 75 && Obtained_Sum <= 79)
        {
            LabGrade = "B+";
            LabGPA = "3.33";
        }
        else if (Obtained_Sum >= 70 && Obtained_Sum <= 74)
        {
            LabGrade = "B";
            LabGPA = "3.00";
        }
        else if (Obtained_Sum >= 68 && Obtained_Sum <= 70)
        {
            LabGrade = "B-";
            LabGPA = "2.66";
        }
        else if (Obtained_Sum >= 64 && Obtained_Sum <= 67)
        {
            LabGrade = "C+";
            LabGPA = "2.33";
        }
        else if (Obtained_Sum >= 61 && Obtained_Sum <= 63)
        {
            LabGrade = "C";
            LabGPA = "2.00";
        }
        else if (Obtained_Sum >= 58 && Obtained_Sum <= 60)
        {
            LabGrade = "C-";
            LabGPA = "1.66";
        }
        else if (Obtained_Sum >= 54 && Obtained_Sum <= 57)
        {
            LabGrade = "D";
            LabGPA = "1.30";
        }
        else if (Obtained_Sum >= 50 && Obtained_Sum <= 53)
        {
            LabGrade = "D+";
            LabGPA = "1.30";
        }
        else
            LabGrade = "F";
        cout << "Your GPA for Lab is: " << LabGPA << endl;
        cout << "Your Grade for Lab is: " << LabGrade << endl;

        char ch;
        cout << "Do you want to go back to selction process 'Y' for Yes and 'N' for No";
        cin >> ch;
        ch = toupper(ch);
        if (ch == 'Y')
        {
            goto A;
        }
        else
            break;

        break;
    }

    case 3:
    {
        // Grades
        cout << "According to the superior grading system:\n";
        cout << "Percentage Marks |   Grade   |   Grade Points\n";
        cout << "'85' and Above   |     A     |      4.00\n";
        cout << "'80' - '84'      |     A-    |      3.66\n";
        cout << "'75' - '79'      |     B+    |      3.33\n";
        cout << "'71' - '74'      |     B     |      3.00\n";
        cout << "'68' - '70'      |     B-    |      2.66\n";
        cout << "'64' - '67'      |     C+    |      2.33\n";
        cout << "'61' - '63'      |     C     |      2.00\n";
        cout << "'58' - '60'      |     C-    |      1.66\n";
        cout << "'54' - '57'      |     D+    |      1.30\n";
        cout << "'50' - '53'      |     D     |      1.00\n";
        cout << "Below '50'       |     F     |      0.00\n\n";

        // GPA calculation

        // GPA calculation
        do
        {
            cout << "Enter the number of subjects: ";
            cin >> numSubjects;
        } while (numSubjects < 0 && numSubjects > 10);

        cout << "Select the type of input for all subjects:\n";
        cout << "1. Grade (e.g., A, B+, C-)\n";
        cout << "2. Grade points (e.g., 4.00, 3.66, 2.33)\n";
        cout << "3. Marks (out of 100)\n";

        int inputType;
        do
        {
            cout << "Enter your choice (1, 2, or 3): ";
            cin >> inputType;

            if (inputType < 1 || inputType > 3)
            {
                cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
            }
        } while (inputType < 1 || inputType > 3);
        for (int i = 0; i < numSubjects; ++i)
        {
            cout << "Enter subject name for subject " << i + 1 << ": ";
            string subjectName;
            getline(cin >> ws, subjectName);

            double subjectGPA = calculateSubjectGPA(subjectName, inputType);

            if (subjectGPA != -1.0)
            {
                cout << "Enter credit hours for subject " << subjectName << ": ";
                double creditHours;
                cin >> creditHours;

                sumGPA += subjectGPA * creditHours;
                sumCreditHours += creditHours;
            }
        }

        if (sumCreditHours != 0)
        {
            double gpa = sumGPA / sumCreditHours;
            cout << "Your GPA is: " << fixed << setprecision(2) << gpa << endl;
        }
        else
        {
            cout << "No credit hours entered. GPA calculation is not possible." << endl;
        }
        char ch;
        cout << "Do you want to go back to selction process 'Y' for Yes and 'N' for No";
        cin >> ch;
        ch = toupper(ch);
        if (ch == 'Y')
        {
            goto A;
        }
        else
            break;
        break;
    }
    case 4:
    {
        //     int numSubjects;
        //     cout << "Enter the number of subjects: ";
        //     cin >> numSubjects;

        //     float totalGradePoints = 0, totalCreditHours = 0;
        //     float gradePoints, creditHours;

        //     for (int i = 0; i < numSubjects; i++)
        //     {
        //         cout << "Enter grade points for subject " << i + 1 << ": ";
        //         cin >> gradePoints;
        //         cout << "Enter credit hours for subject " << i + 1 << ": ";
        //         cin >> creditHours;

        //         totalGradePoints += gradePoints * creditHours;
        //         totalCreditHours += creditHours;
        //     }

        //     if (totalCreditHours != 0)
        //     {
        //         float cgpa = totalGradePoints / totalCreditHours;
        //         cout << "Your CGPA is: " << cgpa << endl;
        //     }
        //     else
        //     {
        //         cout << "Total credit hours cannot be zero.\n";
        //     }
        //     break;
        // }
        int choice;
        cout << "Select calculation method:\n";
        cout << "1. Calculate CGPA by semesters\n";
        cout << "2. Calculate CGPA by individual courses\n";
        cin >> choice;

        if (choice == 1)
        {
            // CGPA by semesters
            int numSemesters;
            cout << "Enter the number of semesters: ";
            cin >> numSemesters;

            float totalGPA = 0, totalCreditHours = 0;
            float gpa, creditHours;

            for (int i = 0; i < numSemesters; i++)
            {
                cout << "Enter GPA for semester " << i + 1 << ": ";
                cin >> gpa;
                cout << "Enter credit hours for semester " << i + 1 << ": ";
                cin >> creditHours;

                totalGPA += gpa * creditHours;
                totalCreditHours += creditHours;
            }

            if (totalCreditHours != 0)
            {
                float cgpa = totalGPA / totalCreditHours;
                cout << "Your CGPA is: " << cgpa << endl;
            }
            else
            {
                cout << "Total credit hours cannot be zero.\n";
            }
        }
        else if (choice == 2)
        {
            int numSubjects;
            cout << "Enter the number of subjects: ";
            cin >> numSubjects;

            float totalGradePoints = 0, totalCreditHours = 0;
            float gradePoints, creditHours;
            int inputType;

            cout << "Select the type of input for all subjects:\n";
            cout << "1. Grade (e.g., A, B+, C-)\n";
            cout << "2. Grade points (e.g., 4.00, 3.66, 2.33)\n";
            cout << "3. Marks (out of 100)\n";
            cin >> inputType;

            for (int i = 0; i < numSubjects; i++)
            {
                cout << "Enter credit hours for subject " << i + 1 << ": ";
                cin >> creditHours;

                if (inputType == 1)
                {
                    string grade;
                    cout << "Enter grade for subject " << i + 1 << ": ";
                    cin >> grade;
                    gradePoints = gradeToGPA(grade);
                }
                else if (inputType == 2)
                {
                    cout << "Enter grade points for subject " << i + 1 << ": ";
                    cin >> gradePoints;
                }
                else if (inputType == 3)
                {
                    float marks;
                    cout << "Enter marks for subject " << i + 1 << ": ";
                    cin >> marks;
                    gradePoints = marksToGPA(marks);
                }

                totalGradePoints += gradePoints * creditHours;
                totalCreditHours += creditHours;
            }

            if (totalCreditHours != 0)
            {
                float cgpa = totalGradePoints / totalCreditHours;
                cout << "Your CGPA is: " << cgpa << endl;
            }
            else
            {
                cout << "Total credit hours cannot be zero.\n";
            }
            break;
        }
    }

    case 5:
    {
        cout << "Exiting program.\n";
        break;
    }
    default:
        cout << "Invalid choice. Try again.\n";

        return 0;
    }
}

double gradeToGPA(const string &grade)
{
    if (grade == "A" || grade == "a")
        return 4.00;
    else if (grade == "A-" || grade == "a-")
        return 3.66;
    else if (grade == "B+" || grade == "b+")
        return 3.33;
    else if (grade == "B" || grade == "b")
        return 3.00;
    else if (grade == "B-" || grade == "b-")
        return 2.66;
    else if (grade == "C+" || grade == "c+")
        return 2.33;
    else if (grade == "C" || grade == "c")
        return 2.00;
    else if (grade == "C-" || grade == "c-")
        return 1.66;
    else if (grade == "D+" || grade == "d+")
        return 1.30;
    else if (grade == "D" || grade == "d")
        return 1.00;
    else if (grade == "F" || grade == "f")
        return 0.00;
    else
        return -1.0; // Invalid grade
}

double marksToGPA(int marks)
{
    if (marks >= 85)
        return 4.00;
    else if (marks >= 80 && marks <= 84)
        return 3.66;
    else if (marks >= 75 && marks <= 79)
        return 3.33;
    else if (marks >= 71 && marks <= 74)
        return 3.00;
    else if (marks >= 68 && marks <= 70)
        return 2.66;
    else if (marks >= 64 && marks <= 67)
        return 2.33;
    else if (marks >= 61 && marks <= 63)
        return 2.00;
    else if (marks >= 58 && marks <= 60)
        return 1.66;
    else if (marks >= 54 && marks <= 57)
        return 1.30;
    else if (marks >= 50 && marks <= 53)
        return 1.00;
    else
        return 0.00;
}

double calculateSubjectGPA(const string &subjectName, int inputType)
{
    string input;
    double gpa;
    double marks = 0; // Initialize marks variable outside the switch statement

    switch (inputType)
    {
    case 1: // Grade
        cout << "Enter grade (A, A-, B+, etc.) for subject " << subjectName << ": ";
        getline(cin >> ws, input);
        gpa = gradeToGPA(input);
        break;
    case 2: // Grade points
        cout << "Enter grade points for subject " << subjectName << ": ";
        getline(cin >> ws, input);
        gpa = stod(input);
        break;
    case 3: // Marks
        cout << "Enter marks for subject " << subjectName << ": ";
        getline(cin >> ws, input);
        marks = stod(input); // Assign value to marks variable
        marks = ceil(marks); // Round off marks
        gpa = marksToGPA(static_cast<int>(marks));
        break;
    default:
        cout << "Invalid input type for subject " << subjectName << ". Skipping..." << endl;
        gpa = -1.0;
        break;
    }

    if (gpa == -1.0)
    {
        cout << "Invalid input for subject " << subjectName << ". Skipping..." << endl;
    }

    return gpa;
}
