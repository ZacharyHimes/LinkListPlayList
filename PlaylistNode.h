#define  PLAYLIST_NODE_H

using namespace std;
#include <string>

class PlaylistNode{
    public:
        PlaylistNode();
        PlaylistNode(string, string, string, int, PlaylistNode* );
        void InsertAfter();
        void SetNext(PlaylistNode*);
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void PrintPlaylistNode();

    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
};