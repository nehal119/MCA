#!/bin/bash

# NEHAL AHMAD 20MCA44

exec_cmd_nobail() {
    echo "+ $1"
    bash -c "$1"
}

exec_cmd() {
    exec_cmd_nobail "$1" || bail
}

echo "Enter path: "

read DIR_PATH

exec_cmd "mkdir ./JMI_Dir ./JMI_Txt ./JMI_Others"

# exec_cmd "rsync -a --exclude $DIR_PATH/*.* $DIR_PATH/* ./JMI_Dir/"

exec_cmd "cp -R $DIR_PATH/* ./JMI_Dir/"

exec_cmd "find ./JMI_Dir/ -maxdepth 1 -type f -exec rm -rf {}  \;"

exec_cmd "find $DIR_PATH -maxdepth 1 -type f -size +1500b -exec cp "{}" ./JMI_Others  \;"

exec_cmd "find $DIR_PATH -maxdepth 1 -type f -size +1000b -exec cp "{}" ./JMI_Txt  \;"
