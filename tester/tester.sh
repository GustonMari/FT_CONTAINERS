#!/bin/bash

	echo -e "\033[32;1m      ___           ___           ___           ___                  \033[0m"
	echo -e "\033[32;1m     /\__\         /\  \         /\  \         /\  \                 \033[0m"
	echo -e "\033[32;1m    /:/ _/_       |::\  \       /::\  \       /::\  \         ___    \033[0m"
	echo -e "\033[32;1m   /:/ /\  \      |:|:\  \     /:/\:\  \     /:/\:\__\       /|  |   \033[0m"
	echo -e "\033[32;1m  /:/ /::\  \   __|:|\:\  \   /:/ /::\  \   /:/ /:/  /      |:|  |   \033[0m"
	echo -e "\033[32;1m /:/__\/\:\__\ /::::|_\:\__\ /:/_/:/\:\__\ /:/_/:/__/___    |:|  |   \033[0m"
	echo -e "\033[32;1m \:\  \ /:/  / \:\~~\  \/__/ \:\/:/  \/__/ \:\/:::::/  /  __|:|__|   \033[0m"
	echo -e "\033[32;1m  \:\  /:/  /   \:\  \        \::/__/       \::/~~/~~~~  /::::\  \   \033[0m"
	echo -e "\033[32;1m   \:\/:/  /     \:\  \        \:\  \        \:\~~\      ~~~~\:\  \  \033[0m"
	echo -e "\033[32;1m    \::/  /       \:\__\        \:\__\        \:\__\          \:\__\ \033[0m"
	echo -e "\033[32;1m     \/__/         \/__/         \/__/         \/__/           \/__/ \033[0m"
	echo -e "\\n"

	spinner() {
		local i sp n
		sp='/-\|'
		n=${#sp}
		printf ' '
		while sleep 0.1; do
			printf "%s\b" "${sp:i++%n:1}"
		done
	}

	printf 'Rendering tests [...] '
	spinner &

	sleep 10 

	kill "$!"
	printf '\n'

	if [ "$1" == "show" ]; then
		../ft_container/./ft_containers all > ft_tester.txt
		../ft_container/./std_containers all > std_tester.txt
		diff -y ft_tester.txt std_tester.txt
		exit 0
	fi

	if [ "$1" == "vector" ] || [ "$#" -ne 1 ]; then
	{
		echo -e "\033[4;34m-----------------VECTOR---------------- \033[0m"
		#simple test
		../ft_container/./ft_containers 0 > ft_tester.txt
		../ft_container/./std_containers 0 > std_tester.txt
		if diff ft_tester.txt std_tester.txt ; then
			echo -e "\033[32;1mPassed\033[0m";
		else
			echo -e "\033[1;31mFailed\033[0m";
		fi
		#hard test
		../ft_container/./ft_containers 6 0 > ft_tester.txt
		../ft_container/./std_containers 6 0 > std_tester.txt
		# if diff ft_tester.txt std_tester.txt >/dev/null; then
		if diff ft_tester.txt std_tester.txt ; then
			echo -e "\033[32;1mPassed\033[0m";
		else
			echo -e "\033[1;31mFailed\033[0m";
		fi
	}
	fi

	if [ "$1" == "stack" ] || [ "$#" -ne 1 ]; then
	{
		echo -e "\033[4;34m-----------------STACK----------------- \033[0m"
		#simple test
		../ft_container/./ft_containers 1 > ft_tester.txt
		../ft_container/./std_containers 1 > std_tester.txt
		if diff ft_tester.txt std_tester.txt ; then
			echo -e "\033[32;1mPassed\033[0m";
		else
			echo -e "\033[1;31mFailed\033[0m";
		fi
	}
	fi

	if [ "$1" == "map" ] || [ "$#" -ne 1 ]; then
	{
		echo -e "\033[4;34m-----------------MAP------------------- \033[0m"
		#simple test
		../ft_container/./ft_containers 2 > ft_tester.txt
		../ft_container/./std_containers 2 > std_tester.txt
		if diff ft_tester.txt std_tester.txt ; then
			echo -e "\033[32;1mPassed\033[0m";
		else
			echo -e "\033[1;31mFailed\033[0m";
		fi
	}
	fi

	if [ "$1" == "impossible" ]; then
	{
		echo -e "\033[4;34m-----------------IMPOSSIBLE------------------- \033[0m"
		#simple test
		../ft_container/./ft_containers 6 impossible > ft_tester.txt
		../ft_container/./std_containers 6 impossible > std_tester.txt
		if diff ft_tester.txt std_tester.txt ; then
			echo -e "\033[32;1mPassed\033[0m";
		else
			echo -e "\033[1;31mFailed\033[0m";
		fi
	}
	fi

	if [ "$1" == "set" ] || [ "$#" -ne 1 ]; then
	{
		echo -e "\033[4;34m-----------------SET------------------- \033[0m"
		#simple test
		../ft_container/./ft_containers 3 > ft_tester.txt
		../ft_container/./std_containers 3 > std_tester.txt
		if diff ft_tester.txt std_tester.txt ; then
			echo -e "\033[32;1mPassed\033[0m";
		else
			echo -e "\033[1;31mFailed\033[0m";
		fi
	}
	fi

	if [ "$1" == "pair" ] || [ "$#" -ne 1 ]; then
	{
		echo -e "\033[4;34m-----------------PAIR------------------ \033[0m"
		#simple test
		../ft_container/./ft_containers 4 > ft_tester.txt
		../ft_container/./std_containers 4 > std_tester.txt
		if diff ft_tester.txt std_tester.txt ; then
			echo -e "\033[32;1mPassed\033[0m";
		else
			echo -e "\033[1;31mFailed\033[0m";
		fi
	}
	fi