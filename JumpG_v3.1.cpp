#include<iostream>
#include<windows.h> //for setting the cursor and for Sleep()
#include<conio.h> //for system(), _kbhit(), _getch()
#include<ctime> //for rand() and srand(time(0))
using namespace std;

long highScore = 0;
int highestLevel = 0;
bool soundSetting = 1;
int temp=0;
int i,j,r;

int playerJump, obstacleHit;
char a[21]={'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','*'};

void gameover(long& score, int& level,int& Count,double& sec);

//SETTING THE OBJECT AND OBSTACLES POSITIONS IN CONSOLE
void game(long& score, int& level)
{
    double sec = 500;
    int Count=0;

    //setting the cursor or object position
    if (1)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { 24,6 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << "Level=" << level;
	}
	if (1)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { 34,6 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << "Score=" << score;
	}

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 20,10 };
	SetConsoleCursorPosition(hConsole, pos);
	cout << "#";

    srand(time(0));
    for(i=0;i<20;i++)
        cout<<a[i];
    for( ; ; )
    {
        obstacleHit=30;
        playerJump=40;

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = {21,10};
        SetConsoleCursorPosition(hConsole,pos);
        for(i=0;i<20;i++)
         a[i]=a[i+1];
        a[19]=a[0];
        if(a[19]=='*'&&a[18]=='*')
            a[19]='__';
        if((a[18]=='_') && (a[17]=='*'))
        {
            a[19]='_';
            for(i=0;i<20;i++)
                cout<<a[i];

            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD pos = {21,10};
            SetConsoleCursorPosition(hConsole,pos);

        }
        if(a[19]=='*'||a[9]=='*')
        {
            for(i=0;i<20;i++)
                cout<<a[i];
            Sleep(sec);
            gameover(score, level,Count,sec);
            if(temp==1)
            {
               temp=0;
               return;
            }
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD pos = {21,10};
            SetConsoleCursorPosition(hConsole,pos);

            r=rand()% 7 +3;//creating random distance between obstacles

            for(j=0;j<r;j++)
            {
                for(i=0;i<20;i++)
                    a[i]=a[i+1];
                a[19]=a[0];
                if(a[19]=='*')
                    a[19]='__';

                for(i=0;i<20;i++)
                    cout<<a[i];
                Sleep(sec);
                gameover(score, level,Count,sec);
                if(temp==1)//if the game is over return to menu
                {
                    temp=0;
                    return;
                }
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                COORD pos = {21,10};
                SetConsoleCursorPosition(hConsole,pos);

            }
            a[20]='*';
            for(i=0;i<20;i++)
                a[i]=a[i+1];

        }
        for(i=0;i<20;i++)
          cout<<a[i];
        Sleep(sec); //the obstacle will pause for 'sec' amount of time



        gameover(score, level,Count,sec);
        if(temp==1)
        {
            temp=0;
            return;
        }
    }
}

//WHILE THE PLAYER IS PLAYING
void gameover(long& score, int& level,int& Count,double& sec)
{
    int ch=0;
    if (Count==2)//after every 2 obstacles game speed will increase
    {
        sec = sec * .80; //to increase the speed
        level++;
        if (soundSetting == 1)
        {
            int p=350;
            int q=50;
            for(int b=0;b<2;b++)//level increasing sound
            {
                Beep(p,q);
                p=p+550;
                q=q+50;
            }
        }
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = { 30,6 };
        SetConsoleCursorPosition(hConsole, pos);
        cout << level;

        Count=0;
    }

    //display live score
    if (1)
    {
        score++;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = { 40,6 };
        SetConsoleCursorPosition(hConsole, pos);
        cout << score;
    }

    if(a[0]=='*')
    {
        playerJump=0;
        obstacleHit=0;
        Count++;
    }

    //when player hit spacebar,the object will jump
    if (_kbhit())
    {
        ch = _getch();
        if (ch == 32) //for jumping
        {
            if (soundSetting == 1)
                Beep(3500, 100);

            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD pos = { 21,10 };
            SetConsoleCursorPosition(hConsole, pos);
            WriteConsole(hConsole, "\b", 2, NULL, NULL);

            if (1)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                COORD pos = { 20,9 };
                SetConsoleCursorPosition(hConsole, pos);
                WriteConsole(hConsole, "#", 1, NULL, NULL);
                Sleep(100);
                WriteConsole(hConsole, "\b", 2, NULL, NULL);
            }
            if (1)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                COORD pos = { 20,8 };
                SetConsoleCursorPosition(hConsole, pos);
                WriteConsole(hConsole, "#", 1, NULL, NULL);
                Sleep(100);
                WriteConsole(hConsole, "\b", 2, NULL, NULL);
            }

            if (1)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                COORD pos = { 20,9 };
                SetConsoleCursorPosition(hConsole, pos);
                WriteConsole(hConsole, "#", 1, NULL, NULL);
                Sleep(100);
                WriteConsole(hConsole, "\b", 2, NULL, NULL);
            }
            if (1)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                COORD pos = { 20,10 };
                SetConsoleCursorPosition(hConsole, pos);
                WriteConsole(hConsole, "#", 1, NULL, NULL);
                playerJump=50;
            }

        }
			if (ch == 27)//when player hit ESC
            {
                temp=1;
            }

    }


        //if the object is hitting the obstacle
		if (playerJump == obstacleHit)
		{
			if (soundSetting == 1)
             {
                int j,t;
                j=350;
                for(i=0;i<20;i++)//game over sound
                {
                    Beep(j,50);
                    j=j-20;
                }
             }

			cout << "\n\n\n\n\n\n\n\t\t\t\tGame Over!";
			cout << "\n\n\t\t\t\tScore : " << score << "\n";
			temp=1;
			Sleep(2000);
			system("PAUSE");

		}

}

//MAIN MENU OF THE GAME
int menu()
{
	long score = 0;
	int level = 0;

	int line = 1, line1 = 1, exit_flag;
	char nav, option, option1, option2 = 0;
	cout << "\n\n\n\n";
	cout << "\t\t***************\n";
	cout << "\t\t*  J U M P G  *\n";
	cout << "\t\t***************\n";
	cout << "\t\t     v3.1     \n\n\n\n\n\n";
	cout << "\t\t   Loading";
	Sleep(1000);
	for(int j=0;j<3;j++){
        cout << ".";
        Sleep(1000);
	}
	Sleep(1000);
	system("CLS");


	while (1) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { 10,3 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << "\t\tJUMPG";
		cout << "\n\n\t\t MAIN MENU\n\n\t\t";
		cout << (line == 1 ? ">" : " ") << "1.Play\n\t\t";
		cout << (line == 2 ? ">" : " ") << "2.HighScore\n\t\t";
		cout << (line == 3 ? ">" : " ") << "3.Help\n\t\t";
		cout << (line == 4 ? ">" : " ") << "4.Settings\n\t\t";
		cout << (line == 5 ? ">" : " ") << "5.About\n\t\t";
		cout << (line == 6 ? ">" : " ") << "6.Exit\n\t\t";

		nav = _getch();

		switch (nav) {
		case 80:if (line == 6)
			line = 1;
				else
			line++;
			break;
		case 72:if (line == 1)
			line = 6;
				else
			line--;
			break;
		}

		if (nav == 13) {
			if (1) {
				system("CLS");
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				COORD pos = { 10,3 };
				SetConsoleCursorPosition(hConsole, pos);
				cout << "\t\tJUMPG";
			}
			switch (line) {
			case 1:
				score = 0;
				level = 1;
				game(score, level);
				system("CLS");
				break;
			case 2:
				if (score > highScore)
					highScore = score;
				if (level > highestLevel)
					highestLevel = level;

				cout << "\n\n\t\t HIGHSCORE\n\n\t\t";
				cout << " Your High Score : " << highScore << "\n\n\t\t";
				cout << " Your Highest Level : " << highestLevel << "\n\n\t\t ";
				system("PAUSE");
				system("CLS");
				break;
			case 3:
				cout << "\n\n\t\t HELP\n\n\t\t";
				cout << " 1.Press SPACEBAR to jump and avoid obstacles\n\n\t\t";
				cout << " 2.Press ESC to go back to main menu\n\n\t\t ";
				system("PAUSE");
				system("CLS");
				break;
			case 4:
				while (1) {
					if (1) {

						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						COORD pos = { 10,3 };
						SetConsoleCursorPosition(hConsole, pos);
						cout << "\t\tJUMPG";
					}
					cout << "\n\n\t\t SETTINGS\n\n\t\t";
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					COORD pos = { 16,7 };
					SetConsoleCursorPosition(hConsole, pos);
					cout << " Sound : " << (soundSetting == 1 ? "ON " : "OFF");
					cout<<"\n\n\n\n\n\t\t * Use SPACEBAR to change the settings";
					option2 = _getch();
					if (option2 == 32) {
						soundSetting = (soundSetting == 1) ? 0 : 1;
					}
					else
						break;
				}
				option2 = 0;
				system("CLS");
				break;
			case 5:
				cout << "\n\n\t\t ABOUT\n\n\t\t";
				cout << "   What's new in v3.1\n\t\t";
				cout << " * Settings option added\n\t\t";
				cout << " * New sounds!\n\t\t";
				cout << " * Now obstacles appear randomly\n\n\t\t";
				cout << "   v3.0\n\t\t";
				cout << " * Level and score live display\n\t\t";
				cout << " * Sound added!\n\n\t\t";
				cout << "   v2.1.1\n\t\t";
				cout << " * Aesthetic upgrade!\n\n\t\t";
				cout << "   v2.1\n\t\t";
				cout << " * Game size reduced to 55kb!\n\t\t";
				cout << " * Game speed now increases gradually!\n\t\t";
				cout << " * Score bug fixed.\n\n\t\t";
				cout << "   v2.0\n\t\t";
				cout << " * Main menu was added\n\n\t\t";
				cout << "  Press spacebar to see credits\n\n\t\t ";;
				option1 = _getch();
				if (option1 == 32) {
					if (1) {
						system("CLS");
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						COORD pos = { 10,3 };
						SetConsoleCursorPosition(hConsole, pos);
						cout << "\t\tJUMPG";
					}
					cout << "\n\n\t\t CREDITS\n\n\t\t";
					cout << " \tProgrammers\n\n\t\t\tSIDDHANTA MANDAL\n\t\t\tKARTHIKESHWAR\n\n\t\t ";
					system("PAUSE");
				}
				system("CLS");
				break;
			case 6:
				exit_flag = 0;

				while (1) {
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					COORD pos = { 10,3 };
					SetConsoleCursorPosition(hConsole, pos);
					cout << "\t\tJUMPG";
					cout << "\n\n\t\t EXIT?\n\n\t\t";
					cout << (line1 == 1 ? ">" : " ") << "1.Yes\n\t\t";
					cout << (line1 == 2 ? ">" : " ") << "2.No\n\t\t";

					option = _getch();

					switch (option) {
					case 80:line1 = (line1 == 2) ? 1 : 2;
						break;
					case 72:line1 = (line1 == 1) ? 2 : 1;
						break;
					}

					if (option == 13) {
						switch (line1) {
						case 1:return 0;
						case 2:exit_flag = 1;
							break;
						default:continue;
						}
					}
					if (exit_flag == 1)
						break;
				}
				system("CLS");
				break;
			default:continue;
			}
		}
	}
}

int main()
{
	menu();
	return 0;
}

