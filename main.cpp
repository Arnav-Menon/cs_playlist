#include "Playlist.h"

#include <string>
#include <iostream>


bool PrintMenu(string playlistTitle);
void PrintMenuOnly(string title);

int main() {

	//Playlist list;
	string song;
	cout << "Enter playlist's title:" << endl;
	getline(cin, song);
	PrintMenu(song);
	//list.AddSong("SD123", "Peg", "Steely Dan", 237);
	//list.AddSong("JJ234", "All For You", "Janet Jackson", 391);
	//list.AddSong("J345", "Canned Heat", "Jamiroquai Dan", 330);
	//list.AddSong("JJ456", "Black Eagle", "Janet Jackson", 197);
	//list.AddSong("SD567", "I Got The News", "Steely Dan", 306);
	//list.PrintList(song);
	//cout << "SONGS BY JANET JACKSON" << endl;
	//list.SongsByArtist("Janet Jackson");

	return 0;
}



bool PrintMenu(string playlistTitle) {
	Playlist list;
	bool isTrue = true;
	cout << endl;

	PrintMenuOnly(playlistTitle);
	/*string title;
	getline(cin, title);*/

	char c;
	cin >> c;

	while (true) {
		if (c == 'a' || c == 'A') {
			list.AddSong();
			PrintMenuOnly(playlistTitle);
			cin >> c;
		}
		else if (c == 'd' || c == 'D') {
			list.RemoveSong();
			PrintMenuOnly(playlistTitle);
			cin >> c;
		}
		else if (c == 'c' || c == 'C') {
			list.ChangePosition();
			PrintMenuOnly(playlistTitle);
			cin >> c;
		}
		else if (c == 's' || c == 'S') {
			list.SongsByArtist();
			PrintMenuOnly(playlistTitle);
			cin >> c;
		}
		else if (c == 't' || c == 'T') {
			list.TotalTime();
			PrintMenuOnly(playlistTitle);
			cin >> c;
		}
		else if (c == 'o' || c == 'O') {
			list.PrintList(playlistTitle);
			PrintMenuOnly(playlistTitle);
			cin >> c;
		}
		else if (c == 'q' || c == 'Q') {
			isTrue = false;
			break;
		}
		else {
			cout << "Command not recognized, please try again: " << endl;
			PrintMenuOnly(playlistTitle);
			cin >> c;
		}

	}

	return isTrue;
}


void PrintMenuOnly(string title) {
	cout << title << " PLAYLIST MENU" << endl;
	cout << "a - Add song" << endl;
	cout << "d - Remove song" << endl;
	cout << "c - Change position of song" << endl;
	cout << "s - Output songs by specific artist" << endl;
	cout << "t - Output total time of playlist (in seconds)" << endl;
	cout << "o - Output full playlist" << endl;
	cout << "q - Quit" << endl << endl;
	cout << "Choose an option:" << endl;
}