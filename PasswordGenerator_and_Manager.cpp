#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>
using namespace std;
const char char_set[] ="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_{}";

class User
{
    private:
    map < string, string > users;
    public:
    void signUp (){
        string email, password;
        cout << "Enter your email address: ";
        cin >> email;
        if (users.find (email) != users.end ()){
            cout << "An account with this email already exists." << endl;
            return;
        }
        cout << "Enter a password: ";
        cin >> password;
        users[email] = password;
        cout << "Account created successfully." << endl;
    }

    bool login (string email, string password){
        if (users.find (email) == users.end () || users[email] != password){
            cout << "Invalid email or password. Please try again." << endl;
            return false;
        }
        return true;
    }
};

class Password{
    private:
    map < pair < string, string >, vector < string >> passwords;
    string generatePassword (int length){
        const int char_set_size = strlen (char_set);
        string password = "";
        for (int i = 0; i < length; i++){
            int index = rand () % char_set_size;
            password += char_set[index];
        }
        return password;
    }

    public:
    void setNewPassword (string app_name, string username){
        string password = generatePassword (12);
        passwords[{app_name, username}].push_back(password);
	    cout << "Generated password: " << password << endl;
    }

    void accessSavedPassword (string app_name, string username){
        if (passwords.find ({app_name, username}) == passwords.end ()){
            cout << "No saved password found." << endl;
        }else{
            vector < string > saved_passwords = passwords[{app_name, username}];
            cout << "Saved passwords:" << endl;
            for (string password:saved_passwords){
                cout << password << endl;
            }
        }
    }

    void deleteSavedPassword (string app_name, string username){
        if (passwords.find ({app_name, username}) == passwords.end ()){
            cout << "No saved password found." << endl;
        }else{
            passwords.erase ({app_name, username});
            cout << "Password deleted successfully." << endl;
        }
    }
};

int main()
{
    User user;
    Password password;

    while (true){
        cout << endl;
        cout << "Welcome. ... " << endl;
        cout << "1. Sign Up" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit program" << endl;
        cout << endl;
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        cout << endl;

        switch (choice){
            case 1:
                user.signUp ();
                break;
            case 2:
            {
                string email, pwd;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> pwd;
                cout << endl;
                if (user.login (email, pwd))
                {
                    int choice;
                    while (true){
                        cout << endl;
                        cout << "==============================" << endl;
                        cout << "Password Generator and Manager" << endl;
                        cout << "==============================" << endl;
                        cout << endl;
                        cout << "1. Generate a new password" << endl;
                        cout << "2. Access the saved passwords" << endl;
                        cout << "3. Delete a saved password" << endl;
                        cout << "4. Logout" << endl;
                        cout << "Enter choice: ";
                        cin >> choice;
                        cout << endl;
                        cout << endl;

                        switch (choice){
                            case 1:
                            {
                                string app_name, username;
                                cout << "Enter application name: ";
                                cin >> app_name;
                                cout << "Enter username: ";
                                cin >> username;
                                password.setNewPassword (app_name, username);
                            }
                            break;
                            case 2:
                            {
                                string app_name, username;
                                cout << "Enter application name: ";
                                cin >> app_name;
                                cout << "Enter username: ";
                                cin >> username;
                                password.accessSavedPassword (app_name, username);
                            }
                            break;
                            case 3:
                            {
                                string app_name, username;
                                cout << "Enter application name: ";
                                cin >> app_name;
                                cout << "Enter username: ";
                                cin >> username;
                                password.deleteSavedPassword (app_name, username);
                            }
                            break;
                            case 4:
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                                break;
                        }

                        if (choice == 4){
                            break;
                        }
                    }
                }
            }
            break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}