#include<iostream>
#include<conio.h>	
#include<string>
#include<fstream>  //File Stream
using namespace std;

void LearnReadFromTextFile()
{
    string path = "C:\\SoftwareDev\\test.txt";

  //ifstream = 'input stream'   ifs is the name, pass in the file path to be read
    ifstream ifs(path);

    string line;
    while (getline(ifs, line)) 
    {
        cout << line << "\n";
    }
    ifs.close();
}

void LearnGetLine()
{
//1st (worst) way, bad because cin >> name only stores characters up until the first whitespace (ex: user enters "Rafael Parra", console prints "Rafael", excluding " Parra"
  /*  string name;
    cin >> name;
    cout << name;*/


//2nd (best) way, getline gets the full string, including whitespaces  (ex: user enters "Rafael Parra", console prints "Rafael Parra", getline() grabs the full line of characters, including whitespaces
    string name;   

    getline(cin, name);

    cout << name;
}


void CreateFile()
{
    string path = "C:\\SoftwareDev\\test.txt";

    ofstream ofs(path);
    ofs << "H0249h24f9h29gh29gh249ghf";
    ofs.close();
}

int main()
{
    LearnReadFromTextFile();

    LearnGetLine();

    CreateFile();

    _getch();
    return 0;
}
