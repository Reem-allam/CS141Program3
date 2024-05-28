/****************************
 * Program 3: Password Check
 * Course: CS 141, Fall 2022.
 * System: MacOS using Clion
 * Starter Code Author: Dr. Sara Riazi
 * Student Author: Reem Allam
 **************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const string rule_msg_1 = "The selected password must be at least eight characters long.";
const string rule_msg_2 = "The selected password must have at least one uppercase letter.";
const string rule_msg_3 = "The selected password must have at least one lowercase letter.";
const string rule_msg_4 = "The selected password must have at least one digit.";
const string rule_msg_5 = "The selected password must have at least one of special characters: [@,!,#,^,&,*,$]";
const string rule_msg_6 = "The selected password has been leaked.";
const string rule_msg_7 = "The selected password cannot contain a dictionary word.";

/****
 * Runs the main part of the program
 ****/
void pass(bool rule1,bool rule2, bool rule3, bool rule4, bool rule5, bool rule6, bool rule7){

    if (rule1 == false){
        cout << rule_msg_1 << endl;
    }

    if(rule2 == false){
        cout << rule_msg_2 << endl;
    }

    if(rule3 == false){
        cout << rule_msg_3 << endl;
    }

    if(rule4 == false){
        cout << rule_msg_4 << endl;
    }

    if(rule5 == false){
        cout << rule_msg_5 << endl;
    }

    if (rule6 == false) {
        cout << rule_msg_6 << endl;
    }
    if(rule6 == false){
        cout << rule_msg_7 << endl;
    }
}

int run (string leaked_password_file, string english_word_file) {

    string userPassword;
    cout << "Enter password: ";
    cin >> userPassword;

    bool rule1 = false;
    if (userPassword.length() >= 8) {
        rule1 = true;
    }

    bool rule2 = false;
    for (int i = 0; i < userPassword.length(); i++) {
        if (isupper(userPassword.at(i))) {
            rule2 = true;
        }
    }

    bool rule3 = false;
    for (int i = 0; i < userPassword.length(); i++) {
        if (islower(userPassword.at(i))) {
            rule3 = true;
        }
    }
    bool rule4 = false;
    for (int i = 0; i < userPassword.length(); i++) {
        if (isdigit(userPassword.at(i))) {
            rule4 = true;
        }
    }
    bool rule5 = false;
    for (int i = 0; i < userPassword.length(); i++) {
        if (ispunct(userPassword.at(i))) {
            rule5 = true;
        }
    }

    string temp = cleanpass(userPassword);
    bool rule6 = false;
    if (leaked(userPassword,leaked_password_file)) {rule6 = true;}
    pass(rule1,rule2,rule3,rule4,rule5,rule6)
}

string cleanpass (string userPassword){
    //loop through password
    //make every letter lowercase using tolower()

    //loop through password
    // ifpassword[i]= any special character
    //password. erase (i, 1)
    //i--
    string returnS = "";
    for (int i = 0; i < userPassword.length(); i++) {
        if (isupper(userPassword[i])) {
            returnS = tolower(userPassword[i]);
        }
        else if (ispunct(userPassword[i])) {
            returnS = userPassword.erase(i,1);
        }
    }
    return returnS;
}





bool leaked(string userPassword, string leakedfile)
vector <string> leakedpass;

ifstream infile;

infile.open(leakedfile);
if(!infile.is_open()){
    cout<< "Could not open file." << endl;
}
while (!infile.eof()){
    string lek;
    while(getline(infile, lek)){
        leakedpass.push_back(lek);
    }
}
infile.close();


int low, high, mid;
high = leakedpass.size() -1;
low = 0;
while(low <= high){
    mid = (low + high)/2;
    if(cleanpass == leakedpass.at(mid) ){
        // run compare and compare returns true then this funcion
        // also returns true;
        // otherwise return false;
        return compare(userPassword,leakedpass[mid])
    }
    if (userPassword < leakedpass[mid]) {
        high = mid - 1;
    }
    else {
        low = mid + 1;
    }
    return true;
}













int main() {
    /** Change the address of the files appropriatly based on your local machine.
     * This main function will be replaced during testing. Do not add any line of code to the main function
     **/
    string leaked_password_file = "passwords.txt"; //change this based on the location of the file on your machine
    string english_word_file = "words.txt"; //change this based on the location of the file on your machine
    run(leaked_password_file, english_word_file);
    return 0;
}





