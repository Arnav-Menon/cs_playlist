#include "Playlist.h"
//#include "PlaylistNode.h"

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

PlaylistNode::PlaylistNode() {
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) {
	this->uniqueID = uniqueID;
	this->songName = songName;
	this->artistName = artistName;
	this->songLength = songLength;
	nextNodePtr = nullptr;
}

void PlaylistNode::InsertAfter(PlaylistNode* currNode) {
	// WORKS!!!!!


	PlaylistNode* tmpNext = nullptr;

	tmpNext = this->nextNodePtr;    // Remember next
	this->nextNodePtr = currNode;    // this -- node -- ?
	currNode->nextNodePtr = tmpNext;


	//this->SetNext(currNode->GetNext()); // sets currentNode next to the one after the parameter's next
	//currNode->SetNext(this); // sets parameters next with the currentNode
}

void PlaylistNode::SetNext(PlaylistNode* newPtr) {
	nextNodePtr = newPtr;
}

string PlaylistNode::GetID() {
	return uniqueID;
}

string PlaylistNode::GetSongName() {
	return songName;
}

string PlaylistNode::GetArtistName() {
	return artistName;
}

int PlaylistNode::GetSongLength() {
	return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
	return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
	cout << "Unique ID: " << uniqueID << endl;
	cout << "Song Name: " << songName << endl;
	cout << "Artist Name: " << artistName << endl;
	cout << "Song Length (in seconds): " << songLength << endl << endl;
}





Playlist::Playlist() {
	head = nullptr;
	tail = nullptr;
}

Playlist::~Playlist() {
	PlaylistNode* temp = head;

	while (temp) {
		PlaylistNode* next = temp->GetNext();
		delete temp;
		temp = next;
	}
}

void Playlist::AddSong() {
	string id, song, name;
	int time;
	cout << "ADD SONG" << endl;
	cout << "Enter song's unique ID:" << endl;
	cin >> id;
	cout << "Enter song's name:" << endl;
	cin.ignore();
	getline(cin, song);
	cout << "Enter artist's name:" << endl;
	getline(cin, name);
	cout << "Enter song's length (in seconds):" << endl;
	cin >> time;
	cout << endl;

	AddSong(id, song, name, time);
}

void Playlist::AddSong(string id, string song, string artist, int length) {
	PlaylistNode* newSong = new PlaylistNode(id, song, artist, length);

	if (head == nullptr) {
		head = newSong;
		tail = newSong;
	}
	else {
		tail->InsertAfter(newSong);
		tail = newSong;
	}
}

void Playlist::RemoveSong() {
	PlaylistNode* currNode = head;
	PlaylistNode* prevNode = nullptr;
	string ID, song;

	cout << "REMOVE SONG" << endl;
	cout << "Enter song's unique ID:" << endl;
	cin >> ID;

	while (currNode != nullptr) {
		if (currNode->GetID() == ID) {
			break;
		}
		else {
			prevNode = currNode;
			currNode = currNode->GetNext();
		}
	}

	song = currNode->GetSongName();

	if (prevNode != nullptr) {
		prevNode->SetNext(currNode->GetNext());
	}
	else {
		head = currNode->GetNext();
		tail = currNode->GetNext();
	}

	if (tail == currNode) {
		tail = prevNode;
		/*cout << quoted(song) << " removed" << endl;*/
		//delete currNode;
	}
	delete currNode;
	cout << quoted(song) << " removed." << endl << endl;
}

void Playlist::ChangePosition() {
	PlaylistNode* changeNode = head;
	PlaylistNode* newNode = nullptr;

	string song;
	int i = 1;
	int currPos, newPos;
	cout << "CHANGE POSITION OF SONG" << endl;
	cout << "Enter song's current position:" << endl;
	cin >> currPos;
	cout << "Enter new position for song:" << endl;
	cin >> newPos;

	// find node that needs to be moved
	while (changeNode != nullptr && i < currPos) {
		newNode = changeNode;
		changeNode = changeNode->GetNext();
		i++;
	}

	if (changeNode != nullptr) {
		song = changeNode->GetSongName();

		if (newNode != nullptr) {
			newNode->SetNext(changeNode->GetNext());
			//head = changeNode->GetNext();
		}
		else {
			head = changeNode->GetNext();
		}

		if (changeNode == tail) {
			tail = newNode;
		}

		// find new position
		PlaylistNode* tempNode = changeNode;
		newNode = nullptr;
		changeNode = head;
		i = 1;
		while (changeNode != nullptr && i < newPos) {
			newNode = changeNode;
			changeNode = changeNode->GetNext();
			i++;
		}

		if (newNode != nullptr) {
			newNode->InsertAfter(tempNode);
		}
		else {
			tempNode->SetNext(head);
			head = tempNode;
		}

		if (changeNode == nullptr) {
			tail = tempNode;
		}

		cout << quoted(song) << " moved to position " << newPos << endl << endl;
	}
	else {
		cout << "Invalid position" << endl;
	}

}

void Playlist::SongsByArtist() {
	string name;

	cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
	cout << "Enter artist's name:" << endl << endl;
	cin.ignore();
	getline(cin, name);

	SongsByArtist(name);

}

void Playlist::SongsByArtist(string name) {
	PlaylistNode* nameNode = head;
	int i = 1;

	while (nameNode != nullptr) {
		if (nameNode->GetArtistName() == name) {
			cout << i << "." << endl;
			nameNode->PrintPlaylistNode();
		}

		nameNode = nameNode->GetNext();
		i++;
	}
}

void Playlist::TotalTime() {
	PlaylistNode* timeNode = head;;
	int time = 0;

	while (timeNode != nullptr) {
		time += timeNode->GetSongLength();
		timeNode = timeNode->GetNext();
	}

	cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
	cout << "Total time: " << time << " seconds" << endl << endl;

	totTime = time;

}

void Playlist::PrintList(string playlistTitle) {
	if (head == nullptr) {
		cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
		cout << "Playlist is empty" << endl << endl;
	}
	else {
		PlaylistNode* printNode = head;
		int i = 1;

		cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;

		while (printNode != nullptr) {
			//cout << &printNode << endl;
			cout << i << "." << endl;
			printNode->PrintPlaylistNode();
			printNode = printNode->GetNext();
			i++;
		}
	}
}
