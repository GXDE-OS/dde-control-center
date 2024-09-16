#!/bin/bash
(
    pkexec aptss update; 
    pkexec aptss install gxde-testing-source; 
    if [[ $? == 0 ]]; then 
        garma --info --text="加入完成！\n在终端输入命令 sudo apt update; sudo apt full-upgrade 即可获取更新"
    else 
        garma --error --text="加入失败！"
    fi
) | garma --progress --auto-close --pulsate --no-cancel --text="正在添加 GXDE 内测源，请不要使用其它应用直到加入完成\n在此过程中需要多次输入密码"