#!/bin/bash

escape_char=$(printf "\u1b")
hasspace=(true true false true false true true true false true false)
read -p "Path to ISO for base OS(skip to download): " iso;

if [[ -n $iso ]] ; then
    if [[ -e $iso ]] ; then
        echo "File found!";
    else
        echo -e "\033[0;31mSpecified file not found!\033[0m";
        exit 1;
    fi
else
    echo -en "Select Ubuntu version (arrow keys): :\e[7m\e[5m";
    echo -n "24.04"
    versions=("24.04  " "23.04  " "22.04.4" "21.04  " "20.04.6" "19.04  " "18.04  " "17.04  " "16.04.7" "14.04.6")
    version=0
    while :;do
        read -rsn1 mode # get 1 character
        if [[ $mode == $escape_char ]]; then
            read -rsn2 mode # read 2 more chars
        fi
        case $mode in
            '[A') let version++ ;;
            '[B') let version-- ;;
            '') break;;
        esac
        version=$(($version>0 ? $version : 0))
        version=$(($version<9?$version:9))
        echo -en "\b\b\b\b\b\b\b"
        echo -n "${versions[version]}"
    done
    echo -e "\e[0m";
    mkdir "downloads" > /dev/null 2>&1
    versionnum=${versions[version]}
    url="https://releases.ubuntu.com/${versionnum}/ubuntu-${versionnum}-live-server-amd64.iso"
    filepath="downloads/${versionnum}.iso"
    url=${url// }
    filepath=${filepath// }
    echo "$filepath,$url"
    curl -L -o $filepath  $url
    iso=$filepath
fi
while :;do
    read -p "Require external signing(y/N):" reqextsign;
    if [[ ${reqextsign,,} == "y" ]] ; then
        reqextsign=${true};
        break
    elif [[ ${reqextsign,,} == "n" ]] ; then
        reqextsign=${false};
        break
    elif [[ -z $reqextsign ]] ; then
        reqextsign=${true};
        break
    else
        echo "Invalid option! y(Yes) or n(No). Or press enter for no."
    fi
done

