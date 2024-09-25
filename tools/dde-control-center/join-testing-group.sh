#!/bin/bash
function check_is_installed(){
dpkg -l | grep "^ii" | grep -w "$1" 
}
source /opt/bashimport/transhell.sh
load_transhell_debug
HERE=$(dirname $(realpath $0))

if check_is_installed gxde-testing-source ;then
	if zenity --question --text="${TRANSHELL_CONTENT_QUIT_TEST_DIALOG}";then
		gxde-app-uninstaller package-name gxde-testing-source 
	else
		exit
	fi
else
    zenity --warning --text="${TRANSHELL_CONTENT_JOIN_TEST_DIALOG}"
    if [[ "$?" = "0" ]];then
        gxde-app-installer gxde-testing-source 
        if ! check_is_installed gxde-testing-source ;then
            garma --error --text="${TRANSHELL_CONTENT_ERROR_IN_PROCESS}"
            exit -1
        fi
        garma --info --text="${TRANSHELL_CONTENT_JOIN_USER_GROUP}"
        xdg-open ${HERE}/QQ.jpg
    else
        exit
    fi
fi
