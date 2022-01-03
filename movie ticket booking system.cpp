#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

//movie ticket booking system

class movieticketbookingsystem{
    char moviename[100];
    char starttime[10];
    char endtime[10];
    int ticketprice;
    char option;
	char name[100];
public:
    void startmenu(){
     system("cls");
        cout<<"\n\t\t\t\t\t\t------------------------------";
        cout<<"\n\t\t\t\t\t\t MOVIE TICKET BOOKING SYSTEM ";
        cout<<"\n\t\t\t\t\t\t------------------------------";
        cout<<"\n\t----------------------";
        cout<<"\n\tWhat do you want to open";
        cout<<"\n\t------------------------";
        cout<<"\n\t1- Management System ";
        cout<<"\n\t--------------------";
        cout<<"\n\t2- Viewers System ";
        cout<<"\n\t--------------------";
        int file;
        cout<<"\n\n\tEnter Number Of File:";
        cin>>file;
        switch(file){
            case 1:
            movieticketbookingsystem m;
            m.menu();
                break;
            case 2:
            m.Menuev();
                break;

			}
    }
    void menu(){
    system("cls");
    char h;
    int choise;
    do{
    system("cls");
    cout<<"\n\t\t\t\t\t\t-----------------";
    cout<<"\n\t\t\t\t\t\tMANANGEMENT SYTEM ";
    cout<<"\n\t\t\t\t\t\t-----------------";
    cout<<"\n\n\t-----------------";
    cout<<"\n\t1- Add new movie";
    cout<<"\n\t-----------------";
    cout<<"\n\t2- Edit movie details";
    cout<<"\n\t-----------------";
    cout<<"\n\t3- delete movie ";
    cout<<"\n\t-----------------";
    cout<<"\n\t4- read movies Details";
    cout<<"\n\t-----------------";
    cout<<"\n\t5- read Viewers Details";
    cout<<"\n\t-----------------";
    cout<<"\n\t6- Go back";
    cout<<"\n\t-----------------";
    cout<<"\n\n\tEnter your choice: ";
    cin>>choise;
    switch(choise){
    case 1:
        addmovie();
       break;
    case 2:
        editmovie();
        break;
    case 3:
        deletemovie();
        break;
    case 4:
        readfile();
        break;
    case 5:
        ReadViewers();
        break;
    case 6:
       startmenu();
        break;
    default:
        cout<<"\n\n\t Invalid value ... please try again\n\n";
    }
    cout << "\n\n\tBack to Manger system (Y/N)?";
    cin >>h;
    }
    while(h=='Y'||h=='y');
}
void addmovie(){
    system("cls");
    fstream file;
    file.open("movie.txt",ios::app|ios::out);
    char ch;
    do{
    system("cls");
	cout<<"\n\t-----------------";
	cout<<"\n\tEnter Movie Name without spaces: ";
	cin>>moviename;
	cout<<"\n\t-----------------";
	cout<<"\n\tEnter Start time: ";
	cin>>starttime;
	cout<<"\n\t-----------------";
	cout<<"\n\tEnter end time: ";
	cin>>endtime;
	cout<<"\n\t-----------------";
    cout<<"\n\tEnter ticket price: ";
	cin>>ticketprice;
	cout<<"\n\t-----------------";
    file << " " << moviename << " " << starttime << " " << endtime << " " << ticketprice << "\n";
	cout<<"\n\tIf you want to add another movie enter (Y/N): ";
    cin>>ch;
    }
    while(ch=='Y'||ch=='y');
	file.close();
}
void readfile(){
    system("cls");
    fstream file;
    cout << "\n\n";
    cout << "\t\t\t\t\t\t All Movies Details \n";
    cout<<"\t\t\t\t\t\t---------------------\n";
    file.open("movie.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Recorded... ";
        file.close();
    }
    else
    {
        cout<<"\n";
        file >> moviename >> starttime >> endtime >> ticketprice ;
        while (!file.eof())
        {
            cout << "\tMovie Name: " << moviename;
            cout << "\t\tStart Time: " << starttime;
            cout << "\t\tEnd Time: " << endtime;
            cout << "\t\tTicket Price: " << ticketprice << "\n";
            file >> moviename >> starttime >> endtime >> ticketprice ;
        }
    }
    file.close();
}
void editmovie(){
    char ch;
	do{
    system("cls");
	ifstream in;
	ofstream out("shmovie.txt");
	char str[100];
	cout<<"\n\n\tEnter a movie name to Edit Details :";
	cin>>str;
	cout<<"\n\t-------------------------------";
	bool found=false;
	in.open("movie.txt",ios::in);
	if (in.is_open()){
			in >> moviename >> starttime >> endtime >> ticketprice ;
	while(!in.eof()){
		if(strcmp(str,moviename)!=0){
		 out << " " << moviename << " " << starttime << " " << endtime << " " << ticketprice << "\n";
	}else{
        found=true;
         cout << "\n\t\t\tEnter Name: ";
         cin >> moviename;
         cout << "\t\t\tEnter start time: ";
         cin >> starttime;
         cout << "\t\t\tEnter end time: ";
         cin >> endtime;
         cout << "\t\t\tEnter ticketprice: ";
         cin >> ticketprice;
         out << " " << moviename << " " << starttime << " " << endtime << " " << ticketprice << "\n";
	}
		in >> moviename >> starttime >> endtime >> ticketprice ;
	}
	in.close();
	out.close();
    if(found==true)
        cout<<"\n\n\t Successfully Edited Data";
    else
    cout<<"\n\n\tNot Founded";
	remove("movie.txt");
	rename("shmovie.txt","movie.txt");
	}else{
    cout<<"\n\n\tcannot open";
	}cout<<"\n\n\tDo you want to edit another movie (Y/N) ?";
    cin>>ch;
    }
		  while(ch=='Y'||ch=='y');

}
void deletemovie(){
	char ch;
	do{
    system("cls");
	ifstream in;
	ofstream out("shiftmovie.txt");
	char str[30];
	cout<<"\n\n\tEnter a movie name to delete :";
	cin>>str;
	cout<<"\n\t-------------------------------";
	bool found=false;
	in.open("movie.txt",ios::in);
	if (in.is_open()){
			in >> moviename >> starttime >> endtime >> ticketprice ;
	while(!in.eof()){
		if(strcmp(str,moviename)!=0){
		 out << " " << moviename << " " << starttime << " " << endtime << " " << ticketprice << "\n";
	}else
        found=true;
		in >> moviename >> starttime >> endtime >> ticketprice ;
	}
	in.close();
	out.close();
    if(found==true)
        cout<<"\n\n\t Successfully Delete Data";
    else
        cout<<"\n\n\tNot Founded";
	remove("movie.txt");
	rename("shiftmovie.txt","movie.txt");
	}else{
    cout<<"\n\n\tcannot open";
	}cout<<"\n\n\tDo you want to delete another movie (Y/N) ?";
    cin>>ch;
    }
		  while(ch=='Y'||ch=='y');
    }

void Menuev(){
system("cls");

           char ch;
	       do{
	       	system("cls");
			cout<<"\n\n\t-----------------";
			cout<<"\n\t 1-movies details";
            cout<<"\n\t-----------------";
            cout<<"\n\t 2-Insert Viewers";
            cout<<"\n\t-----------------";
            cout<<"\n\t 3-Read Viewers";
            cout<<"\n\t-----------------";
            cout<<"\n\t 4-Search Viewers";
            cout<<"\n\t-----------------";
            cout<<"\n\t 5-Update Viewers";
            cout<<"\n\t-----------------";
            cout<<"\n\t 6-Delete Viewers";
            cout<<"\n\t-----------------";
            cout<<"\n\t 7-Go back";
            cout<<"\n\t-----------------";
	       char choice;
	       cout<<"\n\tEnter Choice:";
	       cin>>choice;

        switch(choice){
            case '1':
                readfile();
                break;
		    case '2':
		       InsertViewers();
		       break;
		    case'3':
			    ReadViewers();
		        break;
		    case'4':
		        SearchViewers();
		        break;
		    case'5':
		        updateViewers();
		        break;
		    case'6':
		        deleteViewers();
		        break;
            case '7':
                startmenu();

		    }
			cout<<"\n\tDo you want to run any process again(Y/N)?";
			cin>>ch;
		}
			while(ch=='Y'||ch=='y');
}

void InsertViewers(){
	char ch;
	fstream out;
	out.open("Viewers Information.txt",ios::out|ios::app);
	do{
		system("cls");
	cout<<"\n\tEnter name:";
	cin>>name;
	cout<<"\n\t-----------------";
	cout<<"\n\tEnter movie name:";
	cin>>moviename;
	cout<<"\n\t-----------------";
	cout<<"\n\tEnter tickets price: ";
	cin>>ticketprice;
	cout<<"\n\t-----------------";
	out << " " << name << " " << moviename << " "<< ticketprice << "\n";
	cout<<"\n\tDo you want to Record again(Y/N) ?";
		cin>>ch;
	}
	while(ch=='Y'||ch=='y');
	out.close();
}
void ReadViewers(){
    system("cls");
    fstream file;
    cout << "\n\n";
    cout << "\t\t\t\t\t\t All Viewers Details \n";
    cout<<"\t\t\t\t\t\t---------------------\n";
    file.open("Viewers Information.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Recorded... ";
        file.close();
    }
    else
    {
        cout<<"\n";
        file >> name >> moviename >> ticketprice ;
        while (!file.eof())
        {
            cout << "\tViewer Name: " << name;
            cout << "\t\tMovie Name: " << moviename;
            cout << "\t\tTicket Price: " << ticketprice << "\n";
            file >> name >> moviename >> ticketprice ;
        }
    }
    file.close();

}
void SearchViewers(){
 system("cls");
	char ch;
	ifstream in;
	do{
		system("cls");
		char str[100];
		ifstream in;
	bool found=false;
	cout<<"\n\t-----------------";
	cout<<"\n\tEnter Name To Search:";
	cin>>str;
	cout<<"\n\t-----------------\n";
	in.open("Viewers Information.txt");
	in>>name>>moviename>>ticketprice;
	while(!in.eof()){
		if(strcmp(str, name)==0){
	        cout << "\tViewer Name: " << name;
            cout << "\t\tMovie Name: " << moviename;
            cout << "\t\tTicket Price: " << ticketprice << "\n";
	      found=true;
		  break;
		  }

	in>>name>>moviename>>ticketprice;
	}
	if(!found){
		cout<<"\tNot Record!\n";}
		cout<<"\n\tDo you want to search again(Y/N) ?";
        cin>>ch;
        }
        while(ch=='Y'||ch=='y');
}
void updateViewers(){
    char ch;
	do{
    system("cls");
	ifstream in;
	ofstream out("shviewer.txt");
	char str[100];
	cout<<"\n\n\tEnter Viewer name to Edit Details: ";
	cin>>str;
	cout<<"\n\t-------------------------------";
	bool found=false;
	in.open("Viewers Information.txt",ios::in);
	if (in.is_open()){
			in >> name >> moviename >> ticketprice ;
	while(!in.eof()){
		if(strcmp(str,name)!=0){
		 out << " " << name << " " << moviename << " " << ticketprice << "\n";
	}else{
        found=true;
         cout << "\n\t\t\tEnter Viewer Name: ";
         cin >> name;
         cout << "\t\t\tEnter Movie Name: ";
         cin >> moviename;
         cout << "\t\t\tEnter ticket price: ";
         cin >> ticketprice;
         out << " " << name << " " << moviename << " "<< ticketprice << "\n";
	}
		in >> name >> moviename >> ticketprice ;
	}
	in.close();
	out.close();
    if(found==true)
        cout<<"\n\n\t Successfully Edited Data";
    else
    cout<<"\n\n\tNot Founded";
	remove("Viewers Information.txt");
	rename("shviewer.txt","Viewers Information.txt");
	}else{
    cout<<"\n\n\tcannot open";
	}cout<<"\n\n\tDo you want to edit another movie (Y/N) ?";
    cin>>ch;
    }
		  while(ch=='Y'||ch=='y');

}
void deleteViewers(){
    char ch;
	do{
    system("cls");
	ifstream in;
	ofstream out("shiftviewer.txt");
	char str[30];
	cout<<"\n\n\tEnter Viewer name to delete: ";
	cin>>str;
	cout<<"\n\t-------------------------------";
	bool found=false;
	in.open("Viewers Information.txt",ios::in);
	if (in.is_open()){
			in >>name >> moviename >> ticketprice ;
	while(!in.eof()){
		if(strcmp(str, name)!=0){
		 out << " " << name << " " << moviename << " " << ticketprice << "\n";
	}else
        found=true;
		in >> name >> moviename >> ticketprice ;
	}
	in.close();
	out.close();
    if(found==true)
        cout<<"\n\n\t Successfully Delete Data";
    else
        cout<<"\n\n\tNot Founded";
	remove("Viewers Information.txt");
	rename("shiftviewer.txt","Viewers Information.txt");
	}else{
    cout<<"\n\n\tcannot open";
	}cout<<"\n\n\tDo you want to delete another viewer (Y/N) ?";
    cin>>ch;
    }
		  while(ch=='Y'||ch=='y');
}
};

int main()
{
    char X;
	do{
        system("cls");
        cout<<"\n\t\t\t\t\t\t------------------------------";
        cout<<"\n\t\t\t\t\t\t MOVIE TICKET BOOKING SYSTEM ";
        cout<<"\n\t\t\t\t\t\t------------------------------";
        cout<<"\n\t----------------------";
        cout<<"\n\tWhat do you want to open";
        cout<<"\n\t------------------------";
        cout<<"\n\t1- Management System ";
        cout<<"\n\t--------------------";
        cout<<"\n\t2- Viewers System ";
        cout<<"\n\t--------------------";
        int file;
        cout<<"\n\n\tEnter Number Of File:";
        cin>>file;
        switch(file){
            case 1:
            movieticketbookingsystem m;
            m.menu();
                break;
            case 2:
            m.Menuev();
                break;

			}
			cout<<"\n\n\tDo you want to run any file again(Y/N)?";
			cin>>X;
	}
			while(X=='Y'||X=='y');

    return 0;
}

