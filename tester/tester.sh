#!/bin/bash
$RESULT

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
		echo -e "\033[4;34m-----------------STACK---------------- \033[0m"
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
		echo -e "\033[4;34m-----------------MAP---------------- \033[0m"
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
		echo -e "\033[4;34m-----------------MAP---------------- \033[0m"
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