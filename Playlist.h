#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

//#include "PlaylistNode.h"

#include <string>

using namespace std;


class PlaylistNode {
public:
	PlaylistNode();
	PlaylistNode(string, string, string, int);

	void InsertAfter(PlaylistNode* ptr);
	void SetNext(PlaylistNode* ptr);
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

class Playlist
{
public:
	Playlist();
	~Playlist();
	void AddSong();
	void RemoveSong();
	void PrintList(string);
	void ChangePosition();
	void SongsByArtist();
	void TotalTime();
private:
	void AddSong(string, string, string, int);
	void SongsByArtist(string);
	int totTime = 0;
	PlaylistNode* head;
	PlaylistNode* tail;
};

#endif
