#include <iostream>
#include <string>
#include "PlaylistNode.h"

PlaylistNode::PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}
PlaylistNode::PlaylistNode(string ID, string sngName, string artstName,int songLength){ //,PlaylistNode* next){
    this->uniqueID = ID;
    this->songName = sngName;
    this->artistName = artstName;
    this->songLength = songLength;
    //this->nextNodePtr = next;
}

void PlaylistNode::InsertAfter(){
    // PlaylistNode(int, string, string, string, int ,PlaylistNode* );
    string id = "none";
    string songName = "none";
    string artistName = "none";
    int length = 0;
    PlaylistNode* nextNode = nullptr;

    cout << "ADD SONG" <<endl;
    cout << "Enter song's unique ID:" <<endl;
    cin >> id;
    cin.ignore();
    cout << "Enter song's name:" <<endl;
    getline(cin, songName);
    cout << "Enter artist's name:" <<endl;
    getline(cin, artistName);
    cout << "Enter song's length (in seconds):" <<endl;
    cin >> length;
    cin.ignore();
    cout<<endl;
    if(this->uniqueID == "none"){ // if the values passed in are defualt then this is the head node needing to be initialized
        this-> uniqueID = id;
        this->songName = songName;
        this->artistName = artistName;
        this->songLength = length;
        this->nextNodePtr = nullptr;
    }
    else { //if the passed in values are not detected as default we have received the last node in the current list
        PlaylistNode *newSong = new PlaylistNode(id, songName, artistName, length);  //passsing without next* because it will defualt  init as nullptr
        this->nextNodePtr = newSong; //this sets the ptr to the new created node.
    }

}
void PlaylistNode::RemoveNode(){
    PlaylistNode* currentNode = nullptr;
    PlaylistNode* prevNode = nullptr;
    string searchID = "none";
    cout << "REMOVE SONG" <<endl;
    cout << "Enter song's unique ID:"<<endl;
    getline(cin, searchID);

    currentNode = this->nextNodePtr;
    prevNode = this;
    while(currentNode != nullptr) {
        if (currentNode->GetID() == searchID) {
            prevNode->nextNodePtr = currentNode->nextNodePtr;
            cout << "\"" << currentNode->GetSongName() << "\" removed." << endl << endl;
            delete currentNode;
            break;
        } else {
            prevNode = currentNode;
            currentNode = currentNode->nextNodePtr;
            continue;
        }
    }

    //add same while loop and extra if statement as insertAFter()
    //When loop for when we find the string we should remove the node by:
    //      changing the previous nodes next to the node to be deleted next
    //      we should remove the node from memory
    //      look at "rule of 3"

}

void PlaylistNode::ChangePosition(){
    int curPosition = 0;
    int newPosition = 0;
    int countFind = 0;
    int countChange = 0;
    PlaylistNode* tempPtr = this;
    PlaylistNode* findNodePrevLocation = nullptr;
    PlaylistNode* changeNodePrevLocation = nullptr;

    PlaylistNode* nodeChange = nullptr;

    cout << "CHANGE POSITION OF SONG"<<endl;
    cout << "Enter song's current position:"<<endl;
    cin >> curPosition;
    cin.ignore();
    cout<<"Enter new position for song:"<<endl;
    cin >> newPosition;

    while(this->nextNodePtr != nullptr){
        countFind++;
        if(countFind == curPosition){
            nodeChange = tempPtr;
            findNodePrevLocation = tempPtr->nextNodePtr;
            tempPtr->RemoveNode();
            break;
        }
        else{
            findNodePrevLocation = tempPtr;
            tempPtr = tempPtr->nextNodePtr;
            continue;
        }
    }
    while(this->nextNodePtr != nullptr){
        countChange++;
        changeNodePrevLocation = tempPtr;
        if(countChange == newPosition){
            nodeChange->nextNodePtr = changeNodePrevLocation->nextNodePtr;
            changeNodePrevLocation->nextNodePtr = nodeChange;
            break;
        }
        else{
            tempPtr = tempPtr->nextNodePtr;
            continue;
        }
    }
}

void PlaylistNode::SetNext(PlaylistNode* next){ //takes node to set as next
    this->nextNodePtr = next;
}
string PlaylistNode::GetID(){
    return this->uniqueID;
}
string PlaylistNode::GetSongName(){
    return this-> songName;
}
string PlaylistNode::GetArtistName(){
    return this->artistName;
}
int PlaylistNode::GetSongLength(){
    return this->songLength;
}
PlaylistNode* PlaylistNode::GetNext(){
    return this->nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode(){
    int count = 0;
    PlaylistNode* tempNext = this;
    if (this->uniqueID == "none") {
        cout << "This is an empty list" << endl;
    }
    while(tempNext->nextNodePtr != nullptr) {
        count++;
        cout << count <<"." <<endl;
        cout << "Unique ID: " << tempNext->uniqueID<< endl;
        cout << "Song Name: " << tempNext->songName<< endl;
        cout << "Artist Name: " << tempNext->artistName<< endl;
        cout << "Song Length (in seconds): " << tempNext->songLength << "\n" << endl;

        tempNext = tempNext->nextNodePtr;

    }
    if (tempNext->uniqueID != "none" && tempNext->nextNodePtr == nullptr) {
        count++;
        cout << count <<"." <<endl;
        cout << "Unique ID: " << tempNext->uniqueID<< endl;
        cout << "Song Name: " << tempNext->songName << endl;
        cout << "Artist Name: " << tempNext->artistName << endl;
        cout << "Song Length (in seconds): " << tempNext->songLength << "\n" << endl;
    }
}