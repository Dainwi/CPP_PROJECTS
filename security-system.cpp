#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int a;
    string name, password0, age, user, pass;

    cout << "     Security System     " << endl;
    cout << "_________________________" << endl;
    cout << "|    1. Register        |" << endl;
    cout << "|    2. Log in          |" << endl;
    cout << "|    3. Change password |" << endl;
    cout << "|    4. Exit            |" << endl;
    cout << "|____5. Main menu_______|" << endl
         << endl;

    do
    {
        cout << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> a;

        switch (a)
        {
            {
            case 1:
                // Registration
                cout << "____________________" << endl
                     << endl;
                cout << "|-----Register-----|" << endl;
                cout << "|__________________|" << endl
                     << endl;
                cout << "User Name: ";
                cin >> name;
                cout << "Password: ";
                cin >> password0;
                cout << "Age: ";
                cin >> age;

                // Save registration details to file.txt
                ofstream of1("file.txt");
                if (of1.is_open())
                {
                    of1 << name << "\n";
                    of1 << password0 << "\n";
                    of1 << age << "\n";
                    cout << "Registration Successful" << endl;
                }
                else
                {
                    cout << "Error: Could not open the file" << endl;
                }
                break;
            }

        case 2:
        { // Login
            cout << "____________________" << endl;
            cout << "|------Login-------|" << endl;
            cout << "|__________________|" << endl;

            // Read credentials from file.txt
            ifstream of2("file.txt");
            cout << "User Name: ";
            cin >> user;
            cout << "Password: ";
            cin >> pass;

            if (of2.is_open())
            {
                string storedUser, storedPass, storedAge;
                bool found = false;

                while (of2 >> storedUser >> storedPass >> storedAge)
                {
                    if (user == storedUser && pass == storedPass)
                    {
                        found = true;
                        cout << "---Log in successful---" << endl
                             << endl;
                        cout << "Details: " << endl;
                        cout << "Username: " + storedUser << endl;
                        cout << "Password: " + storedPass << endl;
                        cout << "Age: " + storedAge << endl;
                        break;
                    }
                }

                if (!found)
                {
                    cout << endl
                         << "Incorrect Credentials" << endl;
                    cout << "|    1. Press 2 to Login              |" << endl;
                    cout << "|    2. Press 3 to change password    |" << endl;
                }
            }
            else
            {
                cout << "Error: Could not open the file" << endl;
            }
            break;
        }

        case 3:
        { // Change password
            cout << "-----------Change Password-----------" << endl;
            ifstream of0("file.txt");
            string old, newPass, confirmPass;

            cout << "Enter the old password: ";
            cin >> old;

            if (of0.is_open())
            {
                string storedUser, storedPass, storedAge;
                bool found = false;
                ofstream of1("temp.txt");

                while (of0 >> storedUser >> storedPass >> storedAge)
                {
                    if (old == storedPass)
                    {
                        found = true;
                        cout << "Enter the new password: ";
                        cin >> newPass;
                        cout << "Confirm your password: ";
                        cin >> confirmPass;

                        if (newPass == confirmPass)
                        {
                            of1 << storedUser << " " << newPass << " " << storedAge << "\n";
                            cout << "Password changed successfully" << endl;
                        }
                        else
                        {
                            of1 << storedUser << " " << storedPass << " " << storedAge << "\n";
                            cout << "New password does not match the confirmation" << endl;
                        }
                    }
                    else
                    {
                        of1 << storedUser << " " << storedPass << " " << storedAge << "\n";
                    }
                }

                if (!found)
                {
                    cout << "Old password does not match" << endl;
                }

                of0.close();
                of1.close();

                // Replace the original file with the modified one
                remove("file.txt");
                rename("temp.txt", "file.txt");
            }
            else
            {
                cout << "Error: Could not open the file" << endl;
            }
            break;
        }
        case 4:
        { // Exit
            cout << "_____________Thank You______________" << endl;
            return 0;
        }

        case 5:
        { // Go back to the main menu
            continue;
        }

        default:
        {
            cout << "Enter a valid choice" << endl;
        }
        }

        // Ask the user if they want to return to the main menu
        int backToMainMenu;
        cout << "Do you want to go back to the main menu? (1: Yes, 0: No): ";
        cin >> backToMainMenu;
        if (backToMainMenu == 1)
        {
            continue; // Go back to the main menu
        }
        else
        {
            cout << "_____________Thank You______________" << endl;
            return 0;
        }

    } while (true); // Loop continues until explicitly exited
}
