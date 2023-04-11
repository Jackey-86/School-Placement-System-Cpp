#include <iostream>
#include <conio.h>
#define CLS() system("cls")
#include<windows.h>
#include <unistd.h>
#define delay(x) usleep(x*1000)
#define RULE(x) cout<<'\n'; for(int _=0;_<80;_++) cout<<x; cout<<'\n'
using namespace std;

void gotoxy(int x,int y){					//gotoxy for Windows - it isn't my code
	y--;
	static HANDLE h=NULL;
	if(!h){
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c = {x,y};
	SetConsoleCursorPosition(h,c);
}
void load(){								//Loader function [c-p cp]
	CLS();
	cout<<"\n\n\n\n\t\t\t\t  Loading\n\n";
	for (int i=0;i<80;i++){
		cout<<"!";
		gotoxy(i,3);						//Top Loading line
		cout<<"!";
		cout.flush();						//Flush output buffer for delay()
		gotoxy(i+1,7);						//Bottom Loading line
		delay((rand()%80) + 20);
	}
	cout.flush();
	delay(200);
}

class Student{
    // student class // Includes all functions of voids
    public:
    string firstName,lastName;
    int StudentID;
    int English, Maths, Science, Physics, Elective_Maths, Chemistry, Econs, Accounting;
    int cutoff;
    char School;
    char ch0;
    char ch1;

    void First_Display()
    {
        //First display function
       RULE("*");
       cout << "\t\t\t WELCOME TO THE SCHOOL PLACEMENT SYSTEM";
       RULE("*");
       cout << " " <<endl;
       cout << "\t1. New Applicant\n";
       cout << "\t0. Exit\n";
    }

    void Student_Details()
    {
        //Getting details from the user
         cout << "STUDENT DETAILS\n";
         cout << "-----------------\n";
         cout << "First Name: ";
         cin >> firstName, ' ';
         cout << "Last Name: ";
         cin >> lastName;
         cout << "Student ID: ";
         cin >> StudentID;
         for (char& c : firstName) {
            c = std::toupper(c);}
    }


    //Scores Evaluation after Course-Engineering has been chosen
    void getENGScore()
    {
        //This function calculates and evaluates results of the applicant
        int COMcutoff;
        int ELECcutoff;
        int BIOcutoff;
        int MECcutoff;

        cout << "\n";
        cout << "Enter subject's score.\n";
        cout << "\n";
        cout << "SUBJECT\t\tSCORE\n";
        cout << "PHYSICS:  \t ";
        cin >> Physics;
        cout << "ELECTIVE MATHS:  ";
        cin >> Elective_Maths;
        cout << "CHEMISTRY: \t ";
        cin >> Chemistry;
        cout << "ENGLISH:  \t ";
        cin >> English;

        COMcutoff = (Physics + Elective_Maths + Chemistry + English)/4;
        ELECcutoff = (Physics + Elective_Maths + Chemistry + English)/4;
        BIOcutoff = (Physics + Elective_Maths + Chemistry + English)/4;
        MECcutoff = (Physics + Elective_Maths + Chemistry + English)/4;

        const int MAX_INPUT = 99; // maximum input value

         if (Physics < 0 || Physics > MAX_INPUT || Elective_Maths < 0 || Elective_Maths > MAX_INPUT || Chemistry < 0 || Chemistry > MAX_INPUT || English < 0 || English > MAX_INPUT)
            {
                //A function to exclude input-cutoffs score that exceed 100
                cout << "\n";
                cout << "Error: invalid input\n";
                cout << "Scores should not exceed 2 digits\n";
                cout << "For single digit scores, format should be:\n 01,02,03 etc\n";
                cout << "\n";
                RULE("=");
                getENGScore();

            }

        if(COMcutoff >= 85, ELECcutoff >= 85, BIOcutoff >= 70, MECcutoff >= 75)
            {
                //For cutoffs meeting requirement
                load();
                CLS();
                cout << "\n";
                RULE("-");
                cout << "CONGRATULATIONS!! You're qualified for this offer\n";
                delay(800);
                cout << "\n";
                cout << "KINDLY VIST THE SCHOOL FOR BIOMETRIC VERIFICATION"<<endl;
                delay(800);
                RULE("-");
                int exit;
                cout << "\n";
                cout << "1. Exit Program\n2. Go Back\n";
                cout << "\n";
                cout << "Choice: ";
                cin >> exit;
                if(exit==1)
                {
                    //To exit the program
                    endProgram();
                }
                else
                    CLS();
                    School_choosen();
            }
            else if(COMcutoff <= 85, ELECcutoff <= 85, BIOcutoff <= 70, MECcutoff <= 75)
                {
                    //A function to determine if the applicant isn't not
                    load();
                    CLS();
                    cout << "||===========================================||\n";
                    cout << "||Dear "<<firstName<<", You are not qualified!...\n";
                    cout << "||===========================================||\n";
                    cout << "\n";
                    delay(200);
                    cout << ".\n";
                    delay(200);
                    cout << ".\n";
                    delay(200);
                    cout << ".\n";
                    delay(200);
                    cout << ".\n";
                    delay(200);
                    cout << ".\n";
                    delay(500);
                    cout << "--------------------------------------------\n";
                    cout << "GO BACK AND KINDLY REFER TO COURSE-CUTOFF!!!\n";
                    cout << "--------------------------------------------\n";
                    cout << "\n";
                    delay(900);

                    int exit;
                    cout << "\n";
                    cout << "1. Exit Program\n2. Go Back\n";
                    cout << "\n";
                    cout << "Choice: ";
                    cin >> exit;
                    if(exit==1)
                        {
                            CLS();
                            endProgram();
                        }
                    else
                        CLS();
                        School_choosen();
                }

    }

    //A function to get scores and cutoffs for Course-Sciences
    void getSCIScore()
    {
        int COMSCIcutoff;
        int MEDCcutoff;
        int PHARMcutoff;
        int DENcutoff;

        cout << "\n";
        cout << "Enter subject's score.\n";
        cout << "\n";
        cout << "SUBJECT\t\tSCORE\n";
        cout << "PHYSICS:  \t";
        cin >> Physics;
        cout << "ELECTIVE MATHS:  ";
        cin >> Elective_Maths;
        cout << "CHEMISTRY: \t";
        cin >> Chemistry;
        cout << "ENGLISH:  \t";
        cin >> English;

        COMSCIcutoff = (Physics + Elective_Maths + Chemistry + English)/4;
        MEDCcutoff = (Physics + Elective_Maths + Chemistry + English)/4;
        PHARMcutoff = (Physics + Elective_Maths + Chemistry + English)/4;
        DENcutoff = (Physics + Elective_Maths + Chemistry + English)/4;

        const int MAX_INPUT = 99; // maximum input value

         if (Physics < 0 || Physics > MAX_INPUT || Elective_Maths < 0 || Elective_Maths > MAX_INPUT || Chemistry < 0 || Chemistry > MAX_INPUT || English < 0 || English > MAX_INPUT)
            {
                cout << "\n";
                cout << "Error: invalid input\n";
                cout << "Scores should not exceed 2 digits\n";
                cout << "For single digit scores, format should be: 01,02,03 etc\n";
                cout << "\n";
                getSCIScore();

            }


        if(COMSCIcutoff >= 65, MEDCcutoff >= 85, PHARMcutoff >= 70, DENcutoff >= 75)
            {
                load();
                CLS();
                cout << "\n";
                RULE("-");
                cout << "CONGRATULATIONS!! You're qualified for this offer\n";
                delay(800);
                cout << "\n";
                cout << "KINDLY VIST THE SCHOOL FOR BIOMETRIC VERIFICATION"<<endl;
                delay(800);
                RULE("-");
                int exit;
                cout << "\n";
                cout << "1. Exit Program\n2. Go Back\n";
                cout << "\n";
                cout << "Choice: ";
                cin >> exit;
                if(exit==1)
                {
                    endProgram();
                }
                else
                    CLS();
                    School_choosen();
            }
            else if(COMSCIcutoff <= 65, MEDCcutoff <= 85, PHARMcutoff <= 70, DENcutoff <= 75)
                {
                    load();
                    CLS();
                    cout << "||============================================||\n";
                    cout << "||Dear "<<firstName<<", You are not qualified!...\n";
                    cout << "||============================================||\n";
                    cout << "\n";
                    delay(200);
                    cout << ".\n";
                    delay(200);
                    cout << ".\n";
                    delay(200);
                    cout << ".\n";
                    delay(200);
                    cout << ".\n";
                    delay(200);
                    cout << ".\n";
                    delay(500);
                    cout << "--------------------------------------------\n";
                    cout << "GO BACK AND KINDLY REFER TO COURSE-CUTOFF!!!\n";
                    cout << "--------------------------------------------\n";
                    cout << "\n";
                    delay(900);

                    int exit;
                    cout << "\n";
                    cout << "1. Exit Program\n2. Go Back\n";
                    cout << "\n";
                    cout << "Choice: ";
                    cin >> exit;
                    if(exit==1)
                        {
                            CLS();
                            endProgram();
                        }
                    else
                        CLS();
                        School_choosen();
                }
    }

    //Getting scores and cutoffs for Course_Business
    void getBIScore()
    {
        int BISADcutoff;
        int ACCcutoff;
        int MARcutoff;
        int LOGcutoff;

        cout << "\n";
        cout << "Enter subject's score.\n";
        cout << "\n";
        cout << "SUBJECT\t\tSCORE\n";
        cout << "Economics:  \t ";
        cin >> Econs;
        cout << "Accounting:\t ";
        cin >> Accounting;
        cout << "Elective Maths:  ";
        cin >> Elective_Maths;
        cout << "ENGLISH:  \t ";
        cin >> English;



        BISADcutoff = (Econs + Elective_Maths + English + Accounting)/4;
        ACCcutoff = (Science + Elective_Maths + English + Accounting)/4;
        MARcutoff = (Econs + Elective_Maths + English + Accounting)/4;
        LOGcutoff = (Econs + Elective_Maths + English + Accounting)/4;

        const int MAX_INPUT = 99; // maximum input value

         if (Econs < 0 || Econs > MAX_INPUT || Elective_Maths < 0 || Elective_Maths > MAX_INPUT || Accounting < 0 || Accounting > MAX_INPUT || English < 0 || English > MAX_INPUT)
            {
                cout << "\n";
                cout << "Error: invalid input\n";
                cout << "Scores should not exceed 2 digits\n";
                cout << "For single digit scores, format should be: 01,02,03 etc\n";
                cout << "\n";
                getBIScore();

            }


        if(BISADcutoff >= 75, ACCcutoff >= 75, MARcutoff >= 65, LOGcutoff >= 70)
            {
                load();
                CLS();
                cout << "\n";
                RULE("-");
                cout << "CONGRATULATIONS!! You're qualified for this offer\n";
                delay(800);
                cout << "\n";
                cout << "KINDLY VIST THE SCHOOL FOR BIOMETRIC VERIFICATION"<<endl;
                delay(800);
                RULE("-");
                int exit;
                cout << "\n";
                cout << "1. Exit Program\n2. Go Back\n";
                cout << "\n";
                cout << "Choice: ";
                cin >> exit;
                if(exit==1)
                {
                    endProgram();
                }
                else
                    CLS();
                    School_choosen();
            }
            else if(BISADcutoff <= 75, ACCcutoff <= 75, MARcutoff <= 65, LOGcutoff <= 70)
                {
                    load();
                    CLS();
                    cout << "||============================================||\n";
                    cout << "||Dear "<<firstName<<", You are not qualified!...\n";
                    cout << "||============================================||\n";
                    cout << "\n";
                    delay(200);
                    cout << ".\n";
                    delay(200);
                    cout << ".\n";
                    delay(200);
                    cout << ".\n";
                    delay(200);
                    cout << ".\n";
                    delay(200);
                    cout << ".\n";
                    delay(500);
                    cout << "--------------------------------------------\n";
                    cout << "GO BACK AND KINDLY REFER TO COURSE-CUTOFF!!!\n";
                    cout << "--------------------------------------------\n";
                    cout << "\n";
                    delay(900);

                    int exit;
                    cout << "\n";
                    cout << "1. Exit Program\n2. Go Back\n";
                    cout << "\n";
                    cout << "Choice: ";
                    cin >> exit;
                    if(exit==1)
                        {
                            CLS();
                            endProgram();
                        }
                    else
                        CLS();
                        School_choosen();
                }
    }


    //Displaying of courses in University A
    void Uni_A_Courses()
    {
                cout << "\t University A offers:\n";
                cout << "\n";
                cout << "\t\t\t Courses\n";
                cout << "\n";
                cout << "\t\t 1. Computer Engineering\n";
                cout << "\t\t 2. Electrical Engineering\n";
                cout << "\t\t 3. BioMedical Engineering\n";
                cout << "\t\t 4. Mechanical Engineering\n";
                cout << "\t\t 0. Go back\n";
                cout << "Enter Choice: ";
    }

    //Displaying of courses in University B
    void Uni_B_Courses()
    {
                cout << "\t University B offers:\n";
                cout << "\n";
                cout << "\t\t\t Courses\n";
                cout << "\n";
                cout << "\t\t 1. Business Administration\n";
                cout << "\t\t 2. Accounting\n";
                cout << "\t\t 3. Marketing\n";
                cout << "\t\t 4. Logistics and supply Chain\n";
                cout << "\t\t 0. Go back\n";
                cout << "Enter Choice: ";
    }


    //Displaying of courses in University B
    void Uni_C_Courses()
    {
                cout << "\t University C offers:\n";
                cout << "\n";
                cout << "\t\t\t Courses\n";
                cout << "\n";
                cout << "\t\t 1. Computer Science\n";
                cout << "\t\t 2. Medicine\n";
                cout << "\t\t 3. Pharmacy\n";
                cout << "\t\t 4. Dentistry\n";
                cout << "\t\t 0. Go back\n";
                cout << "Enter Choice: ";
    }


    //Function for University/school selection

    void School_choosen(){

        do{
        char School;
        RULE("*");
        cout << "\t\t\t WELCOME NEW APPLICANT, "<< firstName <<endl;
        RULE("*");
        cout << "\t Choose your preferred School";
        RULE("-");
        cout << "\n";
        cout << "\t\t1. University A\n";
        cout << "\t\t2. University B\n";
        cout << "\t\t3. University C\n";
        cout << "\t\t4. Universities and Course-Cutoffs\n";
        cout << "\t\t0. Go to Main Menu\n";
        cout << "Enter Choice: ";
        cin >> School;



        CLS();

        //After the University/school has been displayed, the chosen option call respective function

            if(School == '1') //University A
            {
                do
                {
                    CLS();   //Clear screen for next display
                    RULE("-");
                    char ch1;
                    Uni_A_Courses();
                    cin >> ch1;

                switch(ch1){ //Switch for school selection
                    case '1':
                        cout << "\t\t\t|| COURSE CHOSEN:::COMPUTER ENGINEERING ||\n";
                        cout <<"\n";
                        delay(150);
                        getENGScore();

                        break;

                    case '2':
                        cout << "\t\t\t|| COURSE CHOSEN:::ELECTRICAL ENGINEERING ||\n";
                        cout <<"\n";
                        delay(150);
                        getENGScore();
                        break;

                    case '3':
                        cout << "\t\t\t|| COURSE CHOSEN:::BIOMEDICAL ENGINEERING ||\n";
                        cout <<"\n";
                        delay(150);
                        getENGScore();
                        break;

                    case '4':
                        cout << "\t\t\t|| COURSE CHOSEN:::MECHANICAL ENGINEERING ||\n";
                        cout <<"\n";
                        delay(150);
                         getENGScore();
                        break;

                    case '0':
                        CLS();
                        School_choosen();
                        break;

                }
                }while(ch1!='0');

            }


            else if(School == '2') //University B
            {
                do
                {
                    CLS();
                    RULE("-");
                    char ch1;
                    Uni_B_Courses();
                    cin >> ch1;


                switch(ch1){
                    case '1':
                        cout << "\t\t\t|| COURSE CHOSEN:::BUSINESS ADMINISTRATION ||\n";
                        cout <<"\n";
                        delay(150);
                        getBIScore();
                        break;


                    case '2':
                        cout << "\t\t\t|| COURSE CHOSEN:::ACCOUNTING ||\n";
                        cout <<"\n";
                        delay(150);
                        getBIScore();
                        break;

                    case '3':
                        cout << "\t\t\t|| COURSE CHOSEN:::MARKETING ||\n";
                        cout <<"\n";
                        delay(150);
                        getBIScore();
                        break;

                    case '4':
                        cout << "\t\t\t|| COURSE CHOSEN:::LOGISTICS AND SUPPLY CHAIN ||\n";
                        cout <<"\n";
                        delay(150);
                        getBIScore();
                        break;

                    case '0':
                        CLS();
                        School_choosen();
                        break;

                }
                }while(ch1!='0');
            }


            else if(School == '3') //University C
            {
                do{
                        CLS();
                        RULE("-");
                        char ch1;
                        Uni_C_Courses();
                        cin >> ch1;


                switch(ch1){
                    case '1':
                        cout << "\t\t\t|| COURSE CHOSEN:::COMPUTER SCIENCE ||\n";
                        cout <<"\n";
                        delay(150);
                        getSCIScore();
                        break;

                    case '2':
                        cout << "\t\t\t|| COURSE CHOSEN:::MEDICINE ||\n";
                        cout <<"\n";
                        delay(150);
                        getSCIScore();
                        break;

                    case '3':
                        cout << "\t\t\t|| COURSE CHOSEN:::PHARMACY ||\n";
                        cout <<"\n";
                        delay(150);
                        getSCIScore();
                        break;

                    case '4':
                        cout << "\t\t\t|| COURSE CHOSEN:::DENTISTRY ||\n";
                        cout <<"\n";
                        delay(150);
                        getSCIScore();
                        break;

                    case '0':
                        CLS();
                        School_choosen();
                        break;

                }
                }while(ch1!='0'); //Do-while loop for wrong selection
            }

            else if(School == '4')
            {
                CUTOFFS(); //Function to Display CUTOFFS
            }

            else if (School == '0')
            {
                //Go Back to first display if school=0
                CLS();
                First_Display();
                cout << "\n";
                cout << "Enter choice: ";
                int ch3;
                cin >> ch3;
                if(ch3==0)
                {
                    endProgram();
                }
            }

        }while(School!='0');
    }


    void CUTOFFS()
    {
        //Cutoffs for all courses in all universities
        cout << "CUTOFFS FOR VARIOUS COURSES\n";
        cout << "===========================\n";
        cout << "\tUniversity A\t\t\tUniversity B \t\t\t   University C \n";
        cout << "   Computer Engineering   [85]\t Business Administration [75]\t\tComputer Science [65]\n";
        cout << "   Electrical Engineering [85]\t Accounting\t\t [75]\t\tMedicine\t [85]\n";
        cout << "   BioMedical Engineering [70]\t Marketing\t\t [65]\t\tPharmacy\t [70]\n";
        cout << "   Mechanical Engineering [75]\t Logistics/supply Chain  [70]\t\tDentistry\t [75]\n";
    }

    void endProgram() {
        //function to end program
    cout << "\n";
    cout << "Exiting the program..." <<endl;
    cout << "\n";
    cout << "Please Wait";
    cout << "_";
    delay(150);
    cout << "_";
    delay(150);
    cout << "_";
    delay(150);
    cout << "_";
    delay(150);
    cout << "\n";
    cout << "\n";
    cout << "*******WE HOPE YOU HAD YOUR PREFERRED CHOICE :)*******\n";
    cout << "\n";
    delay(1000);
    CLS();
    exit(0);
}
    };



int main(){
    string StudentName;
    int StudentID;
    int English, Science, Physics, Elective_Maths, Chemistry, Econs;
    int School;
    char ch0;
    int ch1;

    load();

do
    {
    CLS();
    Student stud1;
    stud1.First_Display();
    cout << "\n";
    cout << "Enter choice: ";
    char ch0 = getch();

    if(ch0=='1')
        {
            CLS();
            stud1.Student_Details();
            cout << "\n";
            cout << "Please Wait";
            cout << "_";
            delay(150);
            cout << "_";
            delay(150);
            cout << "_";
            delay(150);
            cout << "_";
            delay(150);
            CLS();
            stud1.School_choosen();
        }

     else if(ch0=='0')
     {
         stud1.endProgram();
     }
     else if(ch0!='1')
     {
         cout << "\n";
         cout << "Invalid input";
     }

    }
    while(ch0!='0'); //Do-while loop for when first display's selection is wrong

    CLS();
    cout << "\n";
    cout << "*******WE HOPE YOU HAD YOUR PREFERRED CHOICE :)\n";
    cout << "\n";

    return 0;
}

















