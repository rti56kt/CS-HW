// Author       : 0516220-Nicholas_Li
// Date         : 2019.04.17
// Version      : 1.0
// Description  :
//      This file launches a flood attack to 127.0.0.1, so becareful to execute it.
#include<unistd.h>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int main(){
    string ping_command = "ping -c 1 -s 1600 127.0.0.1 >/dev/null 2>&1";
    while(1){
        system(ping_command.c_str());
    }
    return 0;
}
