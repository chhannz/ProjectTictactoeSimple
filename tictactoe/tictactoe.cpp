// tictactoe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

const char X = 'X';
const char O = 'O';
const char KOSONG = ' ';
const char SERI = 'S';
const char BELUM = 'B';
const int MAKS_KOTAK = 9;
char giliran = X;

void intro();
char pilihan_bidak();
void tampilkan_board(const vector<char>& board);
char bidak_musuh(char bidak_pemain);
int pilih_kotak(const vector<char>& board);
int tanyaAngka(int max, int min = 0);
char pemenang(const vector<char>& board);
int acak_giliran();
int komputer_move(const vector<char>& board);

int main(int argc, const char * argv[]) {
	int nomor;
	int acak;	
	int pil_komputer;
	intro();
	vector<char> board(MAKS_KOTAK, KOSONG);
	char player = pilihan_bidak();
	char musuh = bidak_musuh(player);
	cout << "Anda memilih bidak : " << player << endl;
	cout << "Komputer memilih bidak : " << musuh << endl;
	cout << "Giliran pertama adalah : ";
	acak = acak_giliran();
	if (acak == 1) {
		giliran = player;
	}
	else {
		giliran = musuh;
	}
	cout << giliran << "\n\n";
	
	while ((pemenang(board) == BELUM) && (pemenang(board) != SERI)) {
		if (giliran == player) {
			nomor = pilih_kotak(board);
			board[nomor] = player;
			tampilkan_board(board);
			giliran = musuh;
		}
		else if (giliran == musuh) {
			//cout << "(Ini adalah giliran musuh.)\n";
			//cout << "Ganti giliran player... \n";
			pil_komputer = komputer_move(board);
			cout << "\nPilihan komputer : " << pil_komputer << endl;
			board[pil_komputer] = musuh;
			tampilkan_board(board);
			giliran = player;
		}
	}
	cout << "\nPemenangnya adalah : " << pemenang(board) << endl;
	cout << "End game !" << endl;
	int pause;
	cin >> pause;
	return pause;
}


void intro() {
	cout << "Selamat datang di Tic Tac Toe." << endl;
	cout << "\nMasukkan nomor board sesuai dengan gambar berikut." << endl;
	cout << "0 | 1 | 2" << endl;
	cout << "---------" << endl;
	cout << "3 | 4 | 5" << endl;
	cout << "---------" << endl;
	cout << "6 | 7 | 8" << endl;
}

char pilihan_bidak() {
	char pilihan;
	do {
		cout << "Pilih bidak Anda (X / O) = ";
		cin >> pilihan;
		pilihan = toupper(pilihan);
	} while (pilihan != X && pilihan != O);

	return pilihan;
}

char bidak_musuh(char bidak_player) {
	char bidak;
	if (bidak_player == X) {
		bidak = O;
	}
	else bidak = X;

	return bidak;
}

void tampilkan_board(const vector<char>& board) {
	cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "---------" << endl;
	cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "---------" << endl;
	cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

int pilih_kotak(const vector<char>& board) {
	int pilihan;
	do {
		cout << "Pilih kotak : ";
		pilihan = tanyaAngka(MAKS_KOTAK - 1);
		if (board[pilihan] != KOSONG) {
			cout << "Kotak tersebut sudah terisi, silakan pilih kotak yang lain !!" << endl;
		}
	} while (board[pilihan] != KOSONG);

	return pilihan;
}

int tanyaAngka(int max, int min) {
	int angka;
	do {
		cout << "\nMasukkan angka antara " << min << " dan " << max << " = ";
		cin >> angka;
	} while (angka < min || angka > max);

	return angka;
}

char pemenang(const vector<char>& board) {
	char menang;
	const int DAFTAR_KOTAK_MENANG[8][3] = {
		{0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6}
	};
	const int TOTAL_KOTAK_MENANG = 8;
	for (int baris = 0; baris < TOTAL_KOTAK_MENANG; ++baris) {
		if ((board[DAFTAR_KOTAK_MENANG[baris][0]] != KOSONG) &&
			(board[DAFTAR_KOTAK_MENANG[baris][0]] == board[DAFTAR_KOTAK_MENANG[baris][1]]) &&
			(board[DAFTAR_KOTAK_MENANG[baris][1]] == board[DAFTAR_KOTAK_MENANG[baris][2]])) {

			return board[DAFTAR_KOTAK_MENANG[baris][0]];
		}
	}

	if (count(board.begin(), board.end(), KOSONG) == 0) {
		return SERI;
	}

	return BELUM;
}

int acak_giliran() {
	int acak;
	srand(static_cast<unsigned int> (time(0)));
	acak = rand()%2;
	return acak;
}

int komputer_move(const vector<char>& board) {
	int pilihan_komputer;
	
	/*move acak*/
	/*srand(static_cast<unsigned int>(time(0)));
	do {		
		pilihan_komputer = rand()%9; //gerak acak
		
	} while (board[pilihan_komputer] != KOSONG);
	*/
	return pilihan_komputer;
}


