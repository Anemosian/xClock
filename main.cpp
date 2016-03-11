#include <iostream>
#include <unistd>
#include <ctime>
using namespace std;
 
 int main(void){
	std::clock_t start;
	
	if( fork() == 0){
		if(execl("/usr/bin/xclock / usr/share/man/man1/xclock.1.gz", "myXclock") == -1){
		cout << "Error. xClock not working right.";
		}
	}
	else{
		int count = 0;
		while(true){
			if( count == 3 ){
				cout << "\"This program has gone on for far too long. Type Ctrl+C to abort this silly application.\"\n";
				count = 0;
			}
			else{
				cout << "something...\n";
				count++;
				sleep(10);
			}
		}
	 
	}
	 
	 
 }
