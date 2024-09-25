#!/bin/bash
function check_is_installed(){
dpkg -l | grep "^ii" | grep -w "$1" 
}

if [[ $(check_is_installed gxde-testing-source) ]];then
	if garma --question --text="You've already been Internal Testing Group. Do you want to quit?";then
		gxde-app-uninstaller package-name gxde-testing-source 
	else
		exit
	fi
else
    garma --warning --text="Are you sure to join Internal Testing Group?\n\nJoin the testing to experience the latest features, but be aware that it may come with stability issues. \nRecommended for experienced users.\n\nYou need internet connection when joining."
    if [[ "$?" = "0" ]];then
        gxde-app-installer gxde-testing-source 
        garma --info --text="Sucsessfully joined the Internal Testing Group. Enjoy\n\nYou should join our QQ Group to feedback\nGroup number: 881201853"
    else
        exit
    fi
fi
