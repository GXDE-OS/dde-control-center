#!/bin/bash
function check_is_installed(){
dpkg -l | grep "^ii" | grep -w "$1" 
}

if [[ $(check_is_installed gxde-testing-source) ]];then
	if garma --question --text="您已经加入过内测了，是否退出内测？";then
		gxde-app-uninstaller package-name gxde-testing-source 
	else
		exit
	fi
else
    gxde-app-installer gxde-testing-source 
fi
