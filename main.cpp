#include <iostream>
#include "PlaylistNode.h"
using namespace std;

void PrintMenu(const string playlistTitle) {
    cout << playlistTitle <<" PLAYLIST MENU" <<endl;
   cout << "a - Add song" <<endl;
   cout << "d - Remove song" <<endl;
   cout << "c - Change position of song" <<endl;
   cout << "s - Output songs by specific artist" <<endl;
   cout << "t - Output total time of playlist (in seconds)" <<endl;
   cout << "o - Output full playlist" <<endl;
   cout << "q - Quit" <<endl<<endl;


}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
    switch (option){
        case 'a':{
            if(headNode->GetID() == "none")
            {
                cout << playlistTitle << " - OUTPUT FULL PLAYLIST" <<endl;
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
        case 'c':{
            headNode->ChangePosition();
            break;
        }
        case 'd':{
            headNode->RemoveNode();
            break;
        }
        case 'o':{
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" <<endl;
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
    cout <<endl;
    PrintMenu(title);

    while(option != 'q'){
        option = ' ';
        cout << "Choose an option:"<<endl;
        cin >> option;
        cin.ignore();
        if(option == 'q'){
            return 0;
        }
        ExecuteMenu(option, title, headNode);
        PrintMenu(title);
    }

    return 0;
}

