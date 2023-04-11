#include <iostream>

using namespace std;

int password = 1221;
int size, count = 2;
string user_name[50], vaccine_name[50];
int normal_year[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap_year[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int date[50], month[50], year[50], number_of_vaccination[50];
long long aadhaar_number[50], phone_number[50];
int date_of_vaccination1[50], month_of_vaccination1[50], year_of_vaccination1[50];
int date_of_vaccination2[50], month_of_vaccination2[50], year_of_vaccination2[50];

class vaccination_tracker
{
public:
    vaccination_tracker()
    {
        // 1st person
        user_name[0] = "Hamid";
        date[0] = 12;
        month[0] = 2;
        year[0] = 2002;
        phone_number[0] = 9992033333;
        aadhaar_number[0] = 212223321221;
        number_of_vaccination[0] = 2;
        vaccine_name[0] = "Co-Vaccine";
        date_of_vaccination1[0] = 20;
        month_of_vaccination1[0] = 9;
        year_of_vaccination1[0] = 2020;
        date_of_vaccination2[0] = 18;
        month_of_vaccination2[0] = 10;
        year_of_vaccination2[0] = 2020;

        // 2nd person
        user_name[1] = "Ojusvi";
        date[1] = 9;
        month[1] = 8;
        year[1] = 2003;
        phone_number[1] = 6420135793;
        aadhaar_number[1] = 918826625223;
        number_of_vaccination[1] = 1;
        vaccine_name[1] = "Co-Vaccine";
        date_of_vaccination1[1] = 19;
        month_of_vaccination1[1] = 10;
        year_of_vaccination1[1] = 2021;
        date_of_vaccination2[1] = 0;
        month_of_vaccination2[1] = 0;
        year_of_vaccination2[1] = 0;
    }

    // ~vaccination_tracker()
    // {
    //     // delete
    // }
};

int remaning_dose(int j, int date_vacc, int month_vacc, int year_vacc)
{

    if (normal_year[month_vacc] == 30)
    {

        if (normal_year[month_vacc] - date_vacc == 29)
        {

            date_of_vaccination2[j] = date_vacc + 29;
            month_of_vaccination2[j] = month_vacc;
            year_of_vaccination2[j] = year_vacc;
        }
        else if (normal_year[month_vacc] - date_vacc <= 28)
        {

            date_of_vaccination2[j] = date_vacc - 1;
            month_of_vaccination2[j] = month_vacc + 1;
            year_of_vaccination2[j] = year_vacc;
        }
    }
    else if (normal_year[month_vacc] == 31)
    {
        if (normal_year[month_vacc] - date_vacc == 30)
        {

            date_of_vaccination2[j] = date_vacc + 30;
            month_of_vaccination2[j] = month_vacc;
            year_of_vaccination2[j] = year_vacc;
        }
        else if (normal_year[month_vacc] - date_vacc == 29)
        {

            date_of_vaccination2[j] = date_vacc + 29;
            month_of_vaccination2[j] = month_vacc;
            year_of_vaccination2[j] = year_vacc;
        }
        else if (normal_year[month_vacc] - date_vacc <= 28)
        {

            date_of_vaccination2[j] = date_vacc - 2;
            month_of_vaccination2[j] = month_vacc + 1;
            year_of_vaccination2[j] = year_vacc;
        }
    }
    else if (normal_year[month_vacc] == 28 || leap_year[month_vacc] == 29)
    {
        if (normal_year[month_vacc] - date_vacc <= 28 || leap_year[month_vacc] - date_vacc <= 29)
        {

            date_of_vaccination2[j] = date_vacc + 1;
            month_of_vaccination2[j] = month_vacc + 1;
            year_of_vaccination2[j] = year_vacc;
        }
    }

    cout<<"\nYou can take the vaccine within 1 week of allocated date\n";
}

void vaccination_details_display_by_phone_number()
{

    int check_phone_number;

    cout << "Enter your phone number\n";
    cin >> check_phone_number;

    for (int i = 0; i < count; i++)
    {
        if (check_phone_number == phone_number[i])
        {
            cout << "\nYour User Name is : " << user_name[i] << endl;
            cout << "\nYour DOB is : " << date[i] << "-" << month[i] << "-" << year[i] << endl;
            cout << "\nYour Aadhaar Number is : " << aadhaar_number[i] << endl;
            cout << "\nYou have taken \"" << number_of_vaccination[i] << "\" vaccine" << endl;
            cout << "\nYour have taken First dose on  : " << date_of_vaccination1[i] << "-" << month_of_vaccination1[i] << "-" << year_of_vaccination1[i] << endl;
            cout << "\nYour have taken Second dose on  : " << date_of_vaccination2[i] << "-" << month_of_vaccination2[i] << "-" << year_of_vaccination2[i] << endl;
        }
    }

    int choice;
    cout<<"\nEnter \"1\" if you have taken second dose and it is not showing the date here :\n";
    cin>> choice;

    if (choice==1)
    {
        cout << "Enter your phone number\n";
        cin >> check_phone_number;

        for (int i = 0; i < count; i++)
        {
            if (check_phone_number == phone_number[i])
            {
                cout<<"\nEnter the Date: \n";
                cout<<"Enter Date\n";
                cin>>date_of_vaccination2[i];
                cout<<"Enter Month\n";
                cin>>month_of_vaccination2[i];
                cout<<"Enter Year\n";
                cin>>year_of_vaccination2[i];           
            }
        }

    }
    
}

void vaccination_details()
{

    if (count = 2)
    {

        cout << "Enter the number of people\n";
        cin >> size;

        for (int i = 2; i < size + 2; i++)
        {
            cout << "Enter your \"User Name\" :\n";
            cin >> user_name[i];

            cout << "Enter your \"Date Of Birth\" :\n";

            cout << "Enter the \"Date\" :\n";
            cin >> date[i];
            if (date[i] > 31 || date[i] == 0)
            {
                cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                goto end;
            }

            cout << "Enter the \"month\" :\n";
            cin >> month[i];
            if (month[i] > 12 || month[i] == 0)
            {
                cout<<"Error!\" -- Entered Number is greater than 12 and month can not exceed 12 months -- \"";
                goto end;
            }

            cout << "Enter the \"year\" :\n";
            cin >> year[i];
            if (year[i] < 1960 || year[i] == 0)
            {
                cout<<"Error!\" -- Entered Number should be greater than 1960 -- \"";
                goto end;
            }

            cout << "Enter your phone number :\n";
            cin >> phone_number[i];
            cout << "Enter your \"Aadhaar Number :\"\n";
            cin >> aadhaar_number[i];
            cout << "Enter the name of vaccine you have taken (Note: Only For Co-Vaccine) :\n";
            cin >> vaccine_name[i];

            cout << "Enter the number of vaccine taken :\n";
            cin >> number_of_vaccination[i];
            if (number_of_vaccination[i] == 0)
            {
                date_of_vaccination1[i] = 20;
                month_of_vaccination1[i] = 2;
                year_of_vaccination1[i] = 2021;   
            }

            if (number_of_vaccination[i] == 2)
            {
                cout << "Enter the date of First vaccine dose taken :\n";

                cout << "Enter the \"Date\" :\n";
                cin >> date_of_vaccination1[i];
                if (date_of_vaccination1[i] > 31 || date_of_vaccination1[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                    goto end;
                }

                cout << "Enter the \"month\" :\n";
                cin >> month_of_vaccination1[i];
                if (month_of_vaccination1[i] > 12 || month_of_vaccination1[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                    goto end;
                }

                cout << "Enter the \"year\" :\n";
                cin >> year_of_vaccination1[i];
                if (year_of_vaccination1[i] < 1960 || year_of_vaccination1[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number should be greater than 1960 -- \"";
                    goto end;
                }

                cout << "Enter the date of second vaccine dose taken :\n";

                cout << "Enter the \"Date\" :\n";
                cin >> date_of_vaccination2[i];
                if (date_of_vaccination2[i] > 31 || date_of_vaccination2[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                    goto end;
                }
                cout << "Enter the \"month\" :\n";
                cin >> month_of_vaccination2[i];
                if (month_of_vaccination2[i] > 12 || month_of_vaccination2[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                    goto end;
                }
                cout << "Enter the \"year\"\n :";
                cin >> year_of_vaccination2[i];
                if (year_of_vaccination2[i] < 1960 || year_of_vaccination2[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number should be greater than 1960 -- \"";
                    goto end;
                }
            }
            else
            {

                cout << "Enter the date of First vaccine dose taken :\n";

                cout << "Enter the \"Date\" :\n";
                cin >> date_of_vaccination1[i];
                if (date_of_vaccination1[i] > 31 || date_of_vaccination1[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                    goto end;
                }

                cout << "Enter the \"month\" :\n";
                cin >> month_of_vaccination1[i];
                if (month_of_vaccination1[i] > 12 || month_of_vaccination1[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                    goto end;
                }

                cout << "Enter the \"year\" :\n";
                cin >> year_of_vaccination1[i];
                if (year_of_vaccination1[i] < 1960 || year_of_vaccination1[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number should be greater than 1960  -- \"";
                    goto end;
                }

                date_of_vaccination2[i] = 0;
                month_of_vaccination2[i] = 0;
                year_of_vaccination2[i] = 0;
            }

            count++;
        }
    }
    else
    {

        cout << "Enter the number of people\n";
        cin >> size;

        for (int i = count; i < size + count; i++)
        {
            cout << "Enter your \"User Name\" :\n";
            cin >> user_name[i];

            cout << "Enter your \"Date Of Birth\" :\n";

            cout << "Enter the \"Date\" :\n";
            cin >> date[i];
            if (date[i] > 31 || date[i] == 0)
            {
                cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                goto end;
            }

            cout << "Enter the \"month\" :\n";
            cin >> month[i];
            if (month[i] > 12 || month[i] == 0)
            {
                cout<<"Error!\" -- Entered Number is greater than 12 and month can not exceed 12 months -- \"";
                goto end;
            }

            cout << "Enter the \"year\" :\n";
            cin >> year[i];
            if (year[i] < 1960 || year[i] == 0)
            {
                cout<<"Error!\" -- Entered Number should be greater than 1960 -- \"";
                goto end;
            }

            cout << "Enter your phone number :\n";
            cin >> phone_number[i];
            cout << "Enter your \"Aadhaar Number\" :\n";
            cin >> aadhaar_number[i];

            cout << "Enter the number of vaccine taken :\n";
            cin >> number_of_vaccination[i];
            if (number_of_vaccination[i] == 0)
            {
                date_of_vaccination1[i] = 20;
                month_of_vaccination1[i] = 2;
                year_of_vaccination1[i] = 2021;   
            }

            if (number_of_vaccination[i] == 2)
            {
                cout << "Enter the date of First vaccine dose taken :\n";

                cout << "Enter the \"Date\" :\n";
                cin >> date_of_vaccination1[i];
                if (date_of_vaccination1[i] > 31 || date_of_vaccination1[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                    goto end;
                }

                cout << "Enter the \"month\" :\n";
                cin >> month_of_vaccination1[i];
                if (month_of_vaccination1[i] > 12 || month_of_vaccination1[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                    goto end;
                }

                cout << "Enter the \"year\" :\n";
                cin >> year_of_vaccination1[i];
                if (year_of_vaccination1[i] < 1960 || year_of_vaccination1[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number should be greater than 1960 -- \"";
                    goto end;
                }

                cout << "Enter the date of second vaccine dose taken :\n";

                cout << "Enter the \"Date\" :\n";
                cin >> date_of_vaccination2[i];
                if (date_of_vaccination2[i] > 31 || date_of_vaccination2[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                    goto end;
                }
                cout << "Enter the \"month\" :\n";
                cin >> month_of_vaccination2[i];
                if (month_of_vaccination2[i] > 12 || month_of_vaccination2[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                    goto end;
                }
                cout << "Enter the \"year\"\n :";
                cin >> year_of_vaccination2[i];
                if (year_of_vaccination2[i] < 1960 || year_of_vaccination2[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number should be greater than 1960 -- \"";
                    goto end;
                }
            }
            else
            {

                cout << "Enter the date of First vaccine dose taken :\n";

                cout << "Enter the \"Date\" :\n";
                cin >> date_of_vaccination1[i];
                if (date_of_vaccination1[i] > 31 || date_of_vaccination1[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                    goto end;
                }

                cout << "Enter the \"month\" :\n";
                cin >> month_of_vaccination1[i];
                if (month_of_vaccination1[i] > 12 || month_of_vaccination1[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number is greater than 31 and date can not exceed 31 days -- \"";
                    goto end;
                }

                cout << "Enter the \"year\" :\n";
                cin >> year_of_vaccination1[i];
                if (year_of_vaccination1[i] < 1960 || year_of_vaccination1[i] == 0)
                {
                    cout<<"Error!\" -- Entered Number should be greater than 1960 -- \"";
                    goto end;
                }

                date_of_vaccination2[i] = 0;
                month_of_vaccination2[i] = 0;
                year_of_vaccination2[i] = 0;
            }

            count++;
        }
    }

    cout << "Do you want us to allocate the date for your remaning dose\n";
    cout << "Enter \"1\" for Yes or \"2\" for No\n";
    int decision;
    cin >> decision;

    for (int i = 2; i < count; i++)
    {
        if (decision == 1 && number_of_vaccination[i] == 1)
        {

            for (int j = 2; j < count; j++)
            {
                remaning_dose(j, date_of_vaccination1[j], month_of_vaccination1[j], year_of_vaccination1[j]);
            }
        }
        else
        {
            break;
        }
    }

    cout << "Do you want see your details\n";
    cout << "Enter \"1\" for Yes or \"2\" for No\n";
    cin >> decision;
    if (decision == 1)
    {

        vaccination_details_display_by_phone_number();

    }

    end:

    cout<<"\nGoing to the \"Main Menu\"\n";
}

void vaccination_details_display()
{
    vaccination_tracker h;

    int pass;
    cout << "This section can be only accessed by an \"Admin\"\n";
    cout << "Enter 4-digit password to enter\n";
    cin >> pass;

    if (pass == password)
    {

        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

        cout << "Sr.no.\tUser Name\tDOB\t\tPhone No.\tAadhaar No.\tVaccine Name\tTotal vaccine taken.\tDate Of First Dose\tDate Of Second Dose\n";

        cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------";

        for (int i = 0; i < count; i++)
        {
            cout << endl;
            cout << i + 1 << "\t" << user_name[i] << "\t\t" << date[i] << "/" << month[i] << "/" << year[i] << "\t" << phone_number[i] << "\t" << aadhaar_number[i] << "\t" << vaccine_name[i] << "\t" << number_of_vaccination[i] << "\t\t\t" << date_of_vaccination1[i] << "/" << month_of_vaccination1[i] << "/" << year_of_vaccination1[i] << "\t\t" << date_of_vaccination2[i] << "/" << month_of_vaccination2[i] << "/" << year_of_vaccination2[i] << "\t";
            cout << endl;
        }

        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    }
    else
    {
        cout << "Error!... Please Retry\n";
    }

    int choice;
    cout<<"\nDo you want to enter the second vaccine details that if not present here\n";
    cout<<"Enter \"1\" if YES or \"0\" for NO\n";
    cin>>choice;

    if (choice == 1)
    {
        vaccination_details_display_by_phone_number();
    }
    else {
        cout<<"\nStay Safe, Stay Healthy\n";
    }
}

int main()
{
    int choice = 0;

    do
    {

        cout << "Enter \"1\" if you want to enter the details of your vaccination\n";
        cout << "Enter \"2\" if you want to know the details of added vaccinated people\n";
        cout << "Enter \"3\" to exit\n";
        cin >> choice;

        switch (choice)
        {

        case 1:
            vaccination_details();
            break;

        case 2:
            vaccination_details_display();
            break;

        default:
            cout << "ERROR!\nEnter from right choices\n";
            break;
        }

    } while (choice != 3);

    cout << "\n\n------ \"Precaution\" is better than \"cure\" ------\n";
    cout << "------ Stay healthy Stay Safe -----\n";

    return 0;
}
