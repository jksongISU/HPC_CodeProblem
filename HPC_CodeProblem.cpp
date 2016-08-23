// HPC_CodeProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Parallel.h"
using namespace std;

int main(int argc, char *argv[])
{
	// prepare input string
	string str;
	if (argc > 1) {
		ifstream stream(argv[1]);
		string inputStr((istreambuf_iterator<char>(stream)), istreambuf_iterator<char>());
		str = inputStr;
	}
	else {
		str = "37665812358859416220545400502284475141627778694123"
			"07699482907769113268717216818322831603491835999456"
			"01530691500919666142759145290987121421979248577608"
			"72532863869459426639499562803023773889717142364156"
			"05168862773550156548824873689737766284562457836197"
			"90267499773473790838765037184440800942110091405076"
			"55218277816551828061290585223528384729896526885716"
			"83680665438395803243794489830567998343203397981373"
			"55264430987979595732288302067190166929070449775168"
			"58705395755436321776237250287268408700164295035643"
			"54896057020404025619555440159796686935523081354355"
			"11938776620189520237114790711277888496926653928093"
			"54520037126389704223408907919622445290174946515502"
			"89995762505866212386393472458374741386036991340760"
			"97032702244710650271125767170818208783169867713007"
			"79277316264661950215131319523227626594093024527187"
			"43061757527857578831917621650745174966732316231446"
			"87060553443156897487857600601202693945524717448604"
			"06030964956461822175572004233802373135873698360785"
			"74982810508277521659834594761360129982400036745363";
	}

	// prepare output variables
	int maxProduct;
	char* digits = new char[8];

	// call parallel function		
	EightDigits(str, &maxProduct, digits);

	// print output
	cout << "============ from Parallel ==============" << endl;
	cout << "Maximum product of eight adjacent digits = " << maxProduct << " " << endl;
	cout << "The eight digits = ";
	for (int i = 0; i < 8; i++) {
		cout << digits[i];
	}	
	cout << endl;

	// release assigned memories
	if (digits != NULL) {
		delete[](digits);
		digits = NULL;
	}	
    return 0;
}

