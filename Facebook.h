
//File: Facebook.h
//Description: FRIENDQUEUE

#ifndef FRIENDQUEUE_FACEBOOK_H
#define FRIENDQUEUE_FACEBOOK_H

#include "Queue.h"
#include <string>
#include <iostream>

using namespace std;

template <typename DataType>
class Facebook {

private:
    Queue<DataType> friendList;
    int numOfFriends;

public:
    //Facebook Constructor
    //Purpose: Create Facebook Object and initialize numOfFriends
    //Parameters: None
    //Post-Conditions: Facebook Object is created, numOfFriends initialized to 0
    Facebook() : numOfFriends(0) {}

    //addFriend function
    //Purpose: Add friend to friendList Queue
    //Parameters: const DataType& friendProfile
    //Post-Conditions: Friend is added to friendList Queue, numOfFriends is increased
    void addFriend(const DataType& friendProfile) {
        friendList.enqueue(friendProfile);
        numOfFriends++;
    }

    //removeFriend function
    //Purpose: Remove friend from frinedList Queue
    //Parameters: None
    //Post-Conditions: Friend is removed from friendList Queue, numOfFriends is decreased or underflow_error is thrown
    DataType removeFriend() {
        if (!friendList.isEmpty()) {
            numOfFriends--;
            return friendList.dequeue();
        } else {
            throw underflow_error("Friend list is empty");
        }
    }

    //printFriendsF Function
    //Purpose: Print all elements in friendsList to console, front to back
    //Parameters: None
    //Post-Conditions: All elements in friendList are output to console
    void printFriendsF() const {
        friendList.print();
    }

    //printFriendsR Function
    //Purpose: Print all elements in friendList to console in reverse order
    //Parameters: None
    //Post-Conditions: All elements in friendList are output to console in reverse order
    void printFriendsR() const {
        friendList.reversePrint();
    }

    //firstFriend Function
    //Purpose: return the data of the first element (friend) in friendList, does not remove first element
    //Parameters: None
    //Post-Conditions: Returns data of first element in friendList
    DataType firstFriend() const {
        return friendList.peek();
    }

    //resetFriends Function
    //Purpose: Remove all elements (friends) from friendsList
    //Parameters: None
    //Post-Conditions: FriendList is empty, numOfFriends set to 0
    void resetFriends() {
        friendList.makeEmpty();
        numOfFriends = 0;
    }

    //checklist Function
    //Purpose: Check if friendList is empty
    //Parameters: None
    //Post-Conditions: Return true if friendList is empty and false if not empty
    [[nodiscard]] bool checklist() const {
        return friendList.isEmpty();
    }

    //getNumberOfFriends
    //Purpose: Return the number of friends in friendList
    //Parameters: None
    //Post-Conditions: Return the number of friends (numOfFriends) in friendList
    [[nodiscard]] int getNumberOfFriends() const {
        return numOfFriends;
    }

};

#endif //FRIENDQUEUE_FACEBOOK_H
