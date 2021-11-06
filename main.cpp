#include <iostream>
#include "PlaylistNode.h"
using namespace std;

void PrintMenu(const string playlistTitle) {
    cout << "JAMZ PLAYLIST MENU" <<endl;
   cout << "a - Add song" <<endl;
   cout << "d - Remove song" <<endl;
   cout << "c - Change position of song" <<endl;
   cout << "s - Output songs by specific artist" <<endl;
   cout << "t - Output total time of playlist (in seconds)" <<endl;
   cout << "o - Output full playlist" <<endl;
   cout << "q - Quit" <<endl;


}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
    switch (option){
        case 'a':{
            if(headNode->GetID() == "none")
            {
                headNode->InsertAfter();
            }
            else{
                PlaylistNode* tempNextNode = headNode;
                while(tempNextNode->GetNext() != nullptr){
                    tempNextNode = tempNextNode->GetNext();
                }
                tempNextNode->InsertAfter();
            }
            break;
        }
        case 'o':{
            headNode->PrintPlaylistNode();
            break;
        }
    }

    return headNode;
}

int main() {
    string title;
    char option;
    PlaylistNode* headNode;
    headNode = new PlaylistNode();
    cout << "Enter playlist's title:"<<endl;
    getline(cin, title);
    PrintMenu(title);

    while(option != 'q'){
        option = ' ';
        cout << "Choose option:"<<endl;
        cin >> option;
        cin.ignore();
        ExecuteMenu(option, title, headNode);
    }

    return 0;
}

