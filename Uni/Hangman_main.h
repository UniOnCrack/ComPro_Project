#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <windows.h> // Color Library //
#include <vector>
#include<fstream>

using namespace std;

void HangManCreate(int tries){

    cout << endl << endl;
    cout << "   -----" << endl;
    cout << "   |   |" << endl;
    cout << "   |"; if(tries >= 1) cout << "   O   "; cout << endl;
    cout << "   |"; if(tries >= 2) cout << "  /"; 
                    if(tries >= 3) cout << "|";
                    if(tries >= 4) cout << "\\"; cout << endl;
    cout << "   |"; if(tries >= 5) cout << "  /";
                    if(tries >= 6) cout << " \\"; cout << endl;
    cout << "   |" << endl;
    cout << "  _|_" << endl;
	cout << "     " << endl;
	cout << "     " << endl;
}

void importWord(int lv, vector<string> &x){
    string textline;
	string A;

	if(lv = 1){
		ifstream word;
    	word.open("word/lv1");
		char word_1[500];

		while(getline(word,textline)){
			sscanf(textline.c_str(),"%d",word_1);
			A = word_1;
			x.push_back(A);
		}
    }
	
}


void HangManPlay(int lv){

	srand (time(NULL));

	HANDLE Text_Color = GetStdHandle(STD_OUTPUT_HANDLE); // Set for text-color //
		SetConsoleTextAttribute(Text_Color,15);

	vector<string> wordList;
	string word;
	string guessed;
	
	importWord(lv,wordList);
	word = wordList[rand()%500];

	int wordLength = word.length();
	string dispWord (wordLength, '_');
	
	int found = 0;
	char guess = ' ';
	int tries = 0;
	int flagFound = 0;
    int WRONGTRIES = 6;


	while(tries>=0){

		system("cls");
		cout << "Guess Fruit Name: " << endl << endl;
		 
		for(int i = 0; i < wordLength; i++)
			cout << " " << dispWord[i] << " "; 
		cout << endl << endl << endl;
		 	
			SetConsoleTextAttribute(Text_Color,4);
		cout << "Wrong Attempts: " << tries << " / " << WRONGTRIES << endl;
			SetConsoleTextAttribute(Text_Color,15);
		cout << "Guessed Letters: " << guessed << endl; 

			SetConsoleTextAttribute(Text_Color,1);
		HangManCreate(tries);
			SetConsoleTextAttribute(Text_Color,15);
		
		if( found == wordLength ){
			cout << endl;
			cout << "*****************" << endl;
			cout << "*    You Win    *" << endl;
			cout << "*****************" << endl;
			break;
		}
		
		if(tries == 6) break; 
		
		cout<<"Pick a Letter:";
		guess = getche();
		
		guessed = guessed + " " + guess;
		
		if( dispWord.find(guess) != string::npos ) tries++;
		
		flagFound = 0;
		for(int i=0; i<wordLength; i++){
			if( word[i]==guess && dispWord[i]=='_' ){
				dispWord[i] = guess;
				found++;
				flagFound = 1; 
			}
		}
		 
		if( !flagFound )
			tries++;
	}

	if( found != wordLength ){

		cout << endl;
		cout << "******************" << endl;
		cout << "*    You Lose    *" << endl;
		cout << "******************" << endl;
	}
	
	getch();
}