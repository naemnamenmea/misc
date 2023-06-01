/*------------------------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h> // usefull collection of standart libraries

std::string line;
while(std::getline(std::cin, line)) {
    std::cout << line << "\n";
}

/*------------------------------------------------------------------------------------------------------------*/

#include <cstdio>

freopen ("input.txt","r",stdin);
freopen("output.txt", "w", stdout);
//fclose(stdin);
//fclose(stdout);

/*------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>

using namespace std;


ifstream in("in.txt");
ofstream out("out.txt");
/*
fstream file;
file.open("cout.txt", ios::out);
file.close();

ios_base::sync_with_stdio(false);
cin.tie(0);

cin.ignore(numeric_limits<streamsize>::max(), '\n');
cin.clear();
getline(cin,str);

auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save and redirect
*/
streambuf *cinbuf = cin.rdbuf();
streambuf *coutbuf = cout.rdbuf();

cin.rdbuf(in.rdbuf());
cout.rdbuf(out.rdbuf());

/*CODE HERE*/

cin.rdbuf(cinbuf);
cout.rdbuf(coutbuf);

in.close();
out.close();
/*------------------------------------------------------------------------------------------------------------*/

FILE* in = fopen("input.txt", "r");
FILE* out = fopen("output.txt", "w");
fscanf(in, "%d %d", &a, &b);
fprintf(out, "%d %d\n", a,b);
fclose(in);
fclose(out);

/*------------------------------------------------------------------------------------------------------------*/