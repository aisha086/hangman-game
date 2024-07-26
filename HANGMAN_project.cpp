#include<iostream>
#include <Windows.h>
#include<vector>
#include<fstream>
#include<ctime>
#include<cstdlib>

using namespace std;

void intro();
void menu();
void title();
void display_hangman(int lives);
void display_status(vector<char> wrong, string answer);
void end_game(string answer, string codeword);

int main()
{
  intro();
  system("pause");
  system("cls");
  
  menu();
  system("pause");
  system("cls");
  
  play_again:
  	
  string codeword , wordlist[100],answer;
  int lives = 0,levels,Random,again;
  vector<char> wrong;
  bool guess = false;
  char letter;
  fstream myfile;
	
  srand(time(0));
  
  cout<<endl<<endl<<endl;
  cout<<"\t\t\t------CHOOSE A LEVEL!!------"<<endl<<endl;
  cout<<"\t\t\tENTER 1 FOR EASY LEVEL"<<endl<<endl;
  cout<<"\t\t\tENTER 2 FOR MEDIUM LEVEL"<<endl<<endl;
  cout<<"\t\t\tENTER 3 FOR HARD LEVEL"<<endl<<endl;
  re_enter:
  cout<<"\t\t\tLEVEL : ";
  cin>>levels;
  switch(levels)
  {
  	case 1:
  		myfile.open("easywords.txt");
 		 for(int i=0;i<100;i++)
 	 	{
  		myfile>>wordlist[i];
 	 	}
 	 	Random = rand() % 100;
 		codeword=wordlist[Random];
  		myfile.close();
 		answer = "______";
  		break;
	case 2:
		myfile.open("mediumwords.txt");
 		 for(int i=0;i<100;i++)
 	 	{
  		myfile>>wordlist[i];
 	 	}
 	 	Random = rand() % 100;
 		codeword=wordlist[Random];
  		myfile.close();
 		answer = "________";
  		break;
	case 3:
		myfile.open("hardwords.txt");
 		 for(int i=0;i<100;i++)
 	 	{
  		myfile>>wordlist[i];
 	 	}
 	 	Random = rand() % 100;
 		codeword=wordlist[Random];
  		myfile.close();
 		answer = "__________";
  		break;
	default:
  		cout<<"\t\t\tINVALID ENTRY!!ENTER LEVEL AGAIN!!"<<endl<<endl;
  		goto re_enter;
  }

	display_hangman(lives);
    display_status(wrong, answer);

  while(answer!=codeword && lives < 6)
  {	
	
	cout<<"\n\nPlease enter your guess: ";
   	cin>>letter;

    for(int i = 0; i<codeword.length(); i++)
 	{
   	  if(letter==codeword[i])
       {
    	answer[i] = letter;
        guess = true;
       }
   	}
	if(guess==false)
  	{
    	wrong.push_back(letter);
    	lives++;
	}
    guess = false;
    	
	display_hangman(lives);
    display_status(wrong, answer);
  }

  end_game(answer, codeword);
  cout<<endl<<endl<<"Press 1 to play again\n";
  cin>>again;
  if(again)
  {
  	system("cls");
  	goto play_again;
  }
  else
  {
  	cout<<endl<<endl<<"*****************************END*****************************";	
  }
  return 0;
}
void intro()
{
	cout<<endl<<endl<<endl;
	string var= "\t******************************************************************\n"
				"\t*                         ______                                 *\n"
				"\t*    |    |   /\\   |\\   | |      |\\      /|   /\\   |\\   |        *\n"
				"\t*    |____|  /  \\  | \\  | |  ___ | \\    / |  /  \\  | \\  |        *\n"
				"\t*    |    | /----\\ |  \\ | |     ||  \\  /  | /----\\ |  \\ |        *\n"
				"\t*    |    |/      \\|   \\| |_____||   \\/   |/      \\|   \\|        *\n" 
				"\t*               ______                    _____                  *\n"
				"\t*               |         /\\   |\\      /||                       *\n"
				"\t*               |  ___   /  \\  | \\    / ||_____                  *\n"
				"\t*               |     | /----\\ |  \\  /  ||                       *\n"
				"\t*               |_____|/      \\|   \\/   ||_____                  *\n"
				"\t*                                                                *\n"
				"\t******************************************************************\n"; 
for(int i=0;i<var.size();i++)
 {
 	Sleep(1);
 	cout<<var[i];
 }
	cout<<endl<<endl<<endl<<endl;
	
}
void menu()
{
	cout<<endl<<endl<<endl;
	cout<<"\t\t\tWELCOME TO HANGMAN GAME"<<endl<<endl;
 	cout<<"\t\t\t------------------RULES---------------------"<<endl<<endl;
 	cout<<"\t\t\t*YOU NEED TO GUESS THE LETTERS OF A CODEWORD"<<endl<<endl;
 	cout<<"\t\t\t*YOU HAVE 6 LIVES"<<endl<<endl;
 	cout<<"\t\t\t*YOU LOSE A LIFE WITH EVERY WRONG GUESS"<<endl<<endl;
	cout<<"\t\t\t*YOU CAN CHOOSE 3 LEVELS BASED ON DIFFICULTY"<<endl<<endl;
	cout<<"\t\t\t*EASY   = 6  LETTER WORDS"<<endl<<endl;
	cout<<"\t\t\t*MEDIUM = 8  LETTER WORDS"<<endl<<endl;
	cout<<"\t\t\t*HARD   = 10 LETTER WORDS"<<endl<<endl;
	cout<<"\t\t\t*SAVE THE MAN FROM BEING HANGED!!!!!"<<endl<<endl<<endl<<endl;
	
}
void title()
{
  	cout << "==========================================================================================\n";
 	cout << "\t\t\t\tHangman: The Game\n";
    cout << "==========================================================================================\n";
    cout << "Instructions: Save your friend from being hanged by guessing the letters in the codeword.\n";
}

void display_hangman(int lives)
{
  if(lives==0)
  {
  	system("cls");
  	title();
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(lives==1)
  {
  	system("cls");
  	title();
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(lives==2)
  {
  	system("cls");
  	title();
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(lives==3)
  {
  	system("cls");
  	title();
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(lives==4)
  {
  	system("cls");
  	title();
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(lives==5)
  {
  	system("cls");
  	title();
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<" /    | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(lives==6)
  {
  	system("cls");
  	title();
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<" / \\  | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }

}


void display_status(vector<char> wrong, string answer)
{
  cout<<"Incorrect Guesses: \n";

  for(int i = 0; i<wrong.size(); i++)
  {
    cout<<wrong[i]<<" ";
  }

  cout<<"\nCodeword:\n";

  for(int i = 0; i<answer.length(); i++)
  {
    cout<<answer[i]<<" ";
  }
  cout<<endl;
}


void end_game(string answer, string codeword)
{
  if(answer==codeword)
  {
    cout<<endl<<"Hooray! You saved the person from being hanged!!!\n"<<endl;
    cout<<"Congratulations!\n"<<endl;
    cout<<"Answer = "<<codeword<<endl;
  }
  else
  {
    cout<<endl<<"On no! The man is hanged!\n"<<endl;
    cout<<"Answer = "<<codeword<<endl;
  }
}
