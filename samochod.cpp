#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
/* Powyzej linie 1-5 to biblioteki niezbedne do dzialania programu */

/*Chcialem zastosowac funkcje pobierania znaku z klawiatury 'getch()',
 zeby nie uzywac klawisza 'Enter' do potwierdzania wyboru.
 System jednak nie rozpoznaje mi tej funkcji (byc moze brakuje jakiejs
biblioteki albo powodem jest pisanie programu na konsoli Linuxa) dlatego
uzylem funkcji 'getchar()' ktora trzeba potwierdzac klawiszem 'Enter'.
Ponad to domyslna funkcja 'default' (linia 216) na koncu kodu jest przypisana do
pierwszego 'switch'a (linia 43), ale wyswietla 'cout' podwojnie.
Tez nie wiem dlaczego ???
Musialem tez uzywac samych 'if'! Nie wiem dlaczego, ale konstrukcja
'if'-'else if'-'else' w ogole mi tu nie dzialala!*/

using namespace std;

int main() {

int obroty=0, predkosc=0, bieg=0, eksplozja=0;
char zmiana;

	/*-----------Powitanie i menu sterowania-------------*/

	cout << "********Witaj w symulatorze jazdy samochodem********\n\n";
	cout << "MENU STEROWANIA:\n";
	cout << "----------------------------------------------------"<<endl;
	cout << "|Wcisnij klawisz '1' aby wlaczyc silnik.           |"<<endl;
	cout << "|Wcisnij klawisz '0' aby wylaczyc silnik.          |"<<endl;
	cout << "|Wcisnij klawisz 'w' aby przyspieszyc.             |"<<endl;
	cout << "|Wcisnij klawisz 's' aby zwolnic.                  |"<<endl;
	cout << "|Wcisnij klawisz 'u' aby zmienic bieg na wyzszy.   |"<<endl;
	cout << "|Wcisnij klawisz 'j' aby zredukowac bieg na nizszy.|"<<endl;
	cout << "----------------------------------------------------"<<endl;

/*------------------------------------Mechanika dzialania--------------------------------------*/
	while (true)
	{
	    zmiana=getchar();
	    switch(zmiana)
	    {
		    case '1':
		        system("clear");
		        obroty=1100;
		        bieg=0;
		    	cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    	cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    	cout<<"Bieg: "<<bieg<<endl;

		    	while (true)
		    	{
		    		zmiana=getchar();
		    		switch(zmiana)
		    		{

		    	/*-------------------------Zmiana biegow--------------------------*/

		    			case 'u':
		    				obroty=1100;
		    				system("clear");
		    				cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    				cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    				cout<<"Bieg: "<<bieg<<endl;
		    				if (bieg>=-1 && bieg<=5)
		    				{
		    					system("clear");
		    					bieg++;
		    					cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    					cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    					cout<<"Bieg: "<<bieg<<endl;
		    				}
		    				if (bieg>5)
		    				{
		    					system("clear");
		    					cout<<"Nie ma wyzszego biegu!"<<endl;
		    					cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    					cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    					bieg-=1;
		    					cout<<"Bieg: "<<bieg<<endl;
		    				}
		    				break;

		    			case 'j':
		    				system("clear");
		    				cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    				cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    				cout<<"Bieg: "<<bieg<<endl;
		    				if (bieg>=-1 && bieg<=5)
		    				{
		    					system("clear");
		    					bieg--;
		    					cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    					cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    					cout<<"Bieg: "<<bieg<<endl;
		    				}
		    				if (bieg<-1)
		    				{
		    					system("clear");
		    					cout<<"Nie ma nizszego biegu!"<<endl;
		    					cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    					cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    					bieg+=1;
		    					cout<<"Bieg: "<<bieg<<endl;
		    				}

		    				break;

		    	/*--------------------------Przyspieszanie i hamowanie----------------------------*/

		    			case 'w':
		    				if (bieg==0)
		    				{
		    					obroty+=800;
		    					system("clear");
		    					cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    					cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    					cout<<"Bieg: "<<bieg<<endl;
		    				}
		    				if (bieg>0 || bieg<0)
		    				{
		    					obroty+=800;
		    					predkosc+=10;
		    					system("clear");
		    					cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    					cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    					cout<<"Bieg: "<<bieg<<endl;
		    				}
		    				if (bieg==0 && eksplozja==0)
		    				{
		    					cout<<"Wrzuc bieg!"<<endl;
		    				}
		    				if (bieg==0 && eksplozja==1)
		    				{
		    					system("clear");
		    					cout<<"Silnik znieszczony, dalsza jazda niemozliwa!"<<endl;
		    				}
		    				if (obroty >= 5100)
		    				{
		    					cout<<"Zmien bieg na wyzszy bo nastapi eksplozja silnika!"<<endl;
		    				}
		    				if (obroty>=6100)
		    				{
		    					system("clear");
		    					cout<<"Silnik eksplodowal! Bedziesz mial wydatki!"<<endl;
		    					obroty=0, predkosc=0, bieg=0, eksplozja=1;
		    					cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    					cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    					cout<<"Bieg: "<<bieg<<endl;
		    				}
		    				break;
		    			case 's':
		    				if (bieg>0 || bieg<0)
		    				{
		    					obroty-=800;
		    					predkosc-=10;
		    					system("clear");
		    					cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    					cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    					cout<<"Bieg: "<<bieg<<endl;
		    				}
		    				if (bieg==-1 && predkosc<0)
		    				{
		    					predkosc=0;
		    				}

		    				if (obroty<1100 && bieg!=0)
		    				{
		    					obroty=1100;
		    					system("clear");
		    					cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    					cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    					cout<<"Bieg: "<<bieg<<endl;
		    					cout<<"Zbyt niskie obroty! Zmien bieg na nizszy!"<<endl;
		    				}
		    				if (bieg==0 && obroty>1100)
		    				{
		    					obroty-=800;
		    					system("clear");
		    					cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    					cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    					cout<<"Bieg: "<<bieg<<endl;
		    				}
		    				if (predkosc<=0 && bieg>0 || bieg<0 && obroty<=700)
		    				{
		    					obroty=1100;
		    					predkosc=0;
		    					bieg=0;
		    					system("clear");
		    					cout<<"Zatrzymales sie!"<<endl;
		    					cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    					cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    					cout<<"Bieg: "<<bieg<<endl;
		    				}
		 					break;
		    			case '0':
		        			system("clear");
		        			obroty=0, predkosc=0;
		        			cout<<"Silnik wylaczony !"<<endl;
		        			cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    				cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    				cout<<"Bieg: "<<bieg<<endl;
		    				break;
		    			case '1':
		    				obroty=1100;
		        			system("clear");
		    				cout<<"Obroty silnika: "<<obroty<<"rpm"<<endl;
		    				cout<<"Predkosc: "<<predkosc<<" km/h"<<endl;
		    				cout<<"Bieg: "<<bieg<<endl;
		    				break;
		    		}
		}
		    
		    default: 
		    cout<<"Bledny klawisz!  Uzyj klawiszy opisanych w menu sterowania."<<endl;
			cout<<"Na poczatek wlacz silnik."<<endl; //Nie wiem dlaczego 'default' wyswietlany jest podwojnie!
	    }
	}
	return 0;
}