#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class zad{
ifstream wejscie;
ofstream wyjscie;
vector <string> obraz;
	
public:
zad();
~zad();
void wczytaj();
vector <int> rozklad(int);
bool nieskr(vector <int>, vector<int>);
};

zad::zad() {
wejscie.open("dane_ulamki.txt");
wyjscie.open("wyniki_ulamki.txt");
}

	void zad::wczytaj() {
vector <int> czynnik_nr_1;
vector <int> czynnik_nr_2;
 			int liczba_pierwsza, liczba_druga, liczba_nieskr=0;
 	
			if(wejscie.good()) {
					while(!wejscie.eof()) {
							wejscie>>liczba_pierwsza;
							czynnik_nr_1 = rozklad(liczba_pierwsza);
							wejscie>>liczba_druga;
							czynnik_nr_2 = rozklad(liczba_druga);	
										if(nieskr(czynnik_nr_1, czynnik_nr_2)) {
													liczba_nieskr++;
			
			
			
			}
			
			
			
		}
		
		
cout<<"zad: "<<liczba_nieskr;
		
			}
}
	
vector <int> zad::rozklad(int liczba) {
vector <int> czynniki;
					for (int i=2; i<=liczba; i++) {
	   					while (liczba%i == 0) {
	        					liczba/=i;
	        					czynniki.push_back(i);
}


}
	
return czynniki;


}

		bool zad::nieskr(vector <int> czynnik_nr_1, vector <int> czynnik_nr_2) {
			for (int i=0; i<czynnik_nr_1.size(); i++) {
				for (int j=0; j<czynnik_nr_2.size(); j++) {
						if(czynnik_nr_1[i]==czynnik_nr_2[j]) {
								return false;
}
}
}
return true;
}

zad::~zad() {
wejscie.close();
wyjscie.close();
}

int main(int argc, char** argv) {
zad z;
z.wczytaj();
	
return 0;
}
