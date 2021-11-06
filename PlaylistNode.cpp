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
PlaylistNode::PlaylistNode(string ID, string sngName, string artstName,int songLength ,PlaylistNode* next){
    this->uniqueID = ID;
    this->songName = sngName;
    this->artistName = artstName;
    this->nextNodePtr = next;
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
   if(this->uniqueID == "none"){ // if the values passed in are defualt then this is the head node needing to be initialized
       this-> uniqueID = id;
       this->songName = songName;
       this->artistName = artistName;
       this->songLength = length;
       this->nextNodePtr = nullptr;
   }
   else { //if the passed in values are not detected as default we have received the last node in the current list
       PlaylistNode *newSong = new PlaylistNode(id, songName, artistName, length, nextNode);
       this->nextNodePtr = newSong; //this sets the ptr to the new created node.
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
    this->artistName;
}
int PlaylistNode::GetSongLength(){
    this->songLength;
}
PlaylistNode* PlaylistNode::GetNext(){
    return this->nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode(){
    PlaylistNode* tempNext = this;
    if (this->uniqueID == "none") {
        cout << "This is an empty list" << endl;
    }
    while(tempNext->nextNodePtr != nullptr) {

            cout << "Song Name: " << tempNext->songName << "  " << endl;
            tempNext = tempNext->nextNodePtr;

    }
    if (tempNext->uniqueID != "none" && tempNext->nextNodePtr == nullptr) {
        cout << "SongName:" << tempNext->songName <<"\n";
    }
}