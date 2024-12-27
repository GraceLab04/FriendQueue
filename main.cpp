
//File: main.cpp
//Description: FRIENDQUEUE

#include "Facebook.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

//Profile struct for President's name and State
struct Profile {
    string name;
    string state;
};

//Overload << operator
//Purpose: To output Profile name and State to ostream
//Parameters: ostream& os, const Profile& profile
//Post-Conditions: Profile's (President's) name and state are returned to output stream
ostream& operator<<(ostream& os, const Profile& profile) {
    return os << profile.name << ", " << profile.state;
}

//parsePresidentData
//Purpose: To separate name and state sections in line
//Parameters: const string& line
//Post-Conditions: Return Profile object with President's name and State
Profile parsePresidentData(const string& line) {
    istringstream parseString(line);
    string name, state, presidentData;
    while (parseString >> presidentData) {
        if (presidentData.size() == 2 && isupper(presidentData[0]) && isupper(presidentData[1])) { // Simple check for state abbreviation
            state = presidentData;
            break; // Assumes state is the last word in the line
        } else {
            if (!name.empty()) name += " ";
            name += presidentData;
        }
    }
    return Profile{name, state};
}

int main() {
    ifstream file("presidentsWstates.txt"); //open file
    string line;
    Facebook<Profile> facebookProfile;

    //If file does not open correctly (error)
    if (!file) {
        cerr << "File error.\n";
        return 1;
    }

    //Reads line by line from file, parse data, adds friend to facebookProfile
    while (getline(file, line)) {
        Profile profile = parsePresidentData(line);
        facebookProfile.addFriend(profile);
    }

    file.close(); //close file stream

    // Demonstrates the functionality (test set)
    cout << "First friend: " << facebookProfile.firstFriend() << endl;
    cout << endl;
    cout << "Friends list:" << endl;
    facebookProfile.printFriendsF();

    auto removedFriend = facebookProfile.removeFriend();
    cout << endl;
    cout << "Removed friend: " << removedFriend << endl;

    cout << "Number of Friends: " << facebookProfile.getNumberOfFriends() << endl;

    cout << endl;
    cout <<"Friends list (reverse order):" << endl;
    facebookProfile.printFriendsR();

    cout << endl;
    facebookProfile.resetFriends();
    cout << "Reset friends list" << endl;

    cout << "Number of Friends: " << facebookProfile.getNumberOfFriends() << endl;

    cout << "Friends list is: " << (facebookProfile.checklist() ? "Empty" : "Not empty") << endl;

    return 0;
}