#include <iostream>
#include <unistd>
#include <ctime>

using namespace std;

const std::string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

int main(void){
	if( fork() == 0){
		if(execl("/usr/bin/xclock", "myXclock", NULL) == -1){
		cout << "Error. xClock not working right.";
		}
	}
	else{
		int count = 0;
		while(true){
			
			cout <<  currentDateTime();
			count++;
			
			if( count == 3 ){
				cout << "\"This program has gone on for far too long. Type Ctrl+C to abort this silly application.\"\n";
				count = 0;
			}
			sleep(10);
		}
	}
 }
