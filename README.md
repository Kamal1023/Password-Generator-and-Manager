# Password-Generator-and-Manager
A simple password generator and manager made using c++

Problem Statement: 
As people use a variety of online program and services in their daily lives, remembering multiple
passwords can be difficult. This can result in the same password being used for several accounts,
increasing the risk of account hacking. Yet using weak and simple passwords is a recipe for data
breaches, account takeovers, and other forms of cyberattack. As a result, the goal of this program
is to develop a password generator and manager that can generate strong, unique passwords for
each account and securely store them. Users can sign up in this program and login using their
email address and password. Users can set new passwords, access saved passwords, and erase
passwords for each application or service they use after checking in. By generating and managing
secure and unique passwords, the program seeks to simplify password management for users
and increase their online security.

Methodology and Working:
1. The program begins by including necessary header files, such as iostream and map.
2. A const char array named "char_set" is declared to hold a set of characters used in
generating passwords.
3. A class named "User" is declared, which includes a private map variable named "users"
to store email and password pairs.
4. The class "User" includes a signUp() function which takes user input for email and
password, and adds the email and password to the "users" map.
5. The class "User" includes a login() function which takes user input for email and
password, and checks if the email exists in the "users" map and if the password matches
the associated password.
6. A class named "Password" is declared, which includes a private map variablenamed
"passwords" to store application name, username, and password vectors.
7. The "Password" class includes a private generatePassword() function which takes an
integer parameter representing the length of the password to be generated. It randomly
selects characters from the "char_set" array to generate a password, and returns the
generated password as a string.
8. The "Password" class includes a setNewPassword() function which takes input for an
application name and username, and calls the generatePassword() function to generate a
new password. The generated password is then added to the "passwords" map,
associated with the given application name and username.
9. The "Password" class includes an accessSavedPassword() function which takes input
for an application name and username, and checks if there are any saved passwords
associated with the given application name and username. If there are, it prints out the
saved passwords.
10. The "Password" class includes a deleteSavedPassword() function which takes input for
an application name and username, and deletes any saved passwords associated with
the given application name and username.
11. The main() function begins by declaring objects of the "User" and "Password" classes.
12. The main() function begins an infinite loop which displays a menu of options for the
user.
13. The main() function prompts the user to enter a choice from the menu.
14. The main() function uses a switch statement to execute different code based on the
user's menu choice.
15. If the user chooses option 1, the signUp() function of the "User" class is called to create
a new user account.
16. If the user chooses option 2, the login() function of the "User" class is called to verify
the user's email and password.
17. If the user is logged in, the main() function enters another infinite loop which displays a
menu of options for the user.
18. The main() function prompts the user to enter a choice from the menu.
19. The main() function uses a switch statement to execute different code based on the
user's menu choice.
20. If the user chooses option 1, the setNewPassword() function of the "Password" class is
called to generate a new password for the given application name and username.
21. If the user chooses option 2, the accessSavedPassword() function of the "Password"
class is called to display any saved passwords for the given application name and
username.
22. If the user chooses option 3, the deleteSavedPassword() function of the "Password"
class is called to delete any saved passwords for the given application name and
username.
23. If the user chooses option 4, the program exits.
24. If the user enters an invalid menu choice, an error message is displayed and the user is
prompted to enter a choice again.

Overall, the Password Generator and Manager project in C++ is an essential tool for preventing
Users files and data and ensuring that user can only able to access his/her saved passwords.
