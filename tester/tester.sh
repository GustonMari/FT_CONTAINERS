#!/bin/bash
$RESULT

	if [ "$1" == "vector" ] || [$# == 0]; then
	{
		echo -e "\033[4;34m-----------------VECTOR---------------- \033[0m"
		#simple test
		../ft_container/./ft_containers 0 > ft_tester.txt
		../ft_container/./std_containers 0 > std_tester.txt
		if diff ft_tester.txt std_tester.txt >/dev/null; then
			echo -e "\033[32;1mPassed\033[0m";
		else
			echo -e "\033[1;31mFailed\033[0m";
		fi
		#hard test
		../ft_container/./ft_containers 6 0 > ft_tester.txt
		../ft_container/./std_containers 6 0 > std_tester.txt
		if diff ft_tester.txt std_tester.txt >/dev/null; then
			echo -e "\033[32;1mPassed\033[0m";
		else
			echo -e "\033[1;31mFailed\033[0m";
		fi
	}
	fi

	echo -e "\033[4;34m-----------------STACK---------------- \033[0m"
	#simple test
	../ft_container/./ft_containers 1 > ft_tester.txt
	../ft_container/./std_containers 1 > std_tester.txt
	if diff ft_tester.txt std_tester.txt >/dev/null; then
		echo -e "\033[32;1mPassed\033[0m";
	else
		echo -e "\033[1;31mFailed\033[0m";
	fi
	
	echo -e "\033[4;34m-----------------MAP---------------- \033[0m"
	#simple test
	../ft_container/./ft_containers 2 > ft_tester.txt
	../ft_container/./std_containers 2 > std_tester.txt
	if diff ft_tester.txt std_tester.txt >/dev/null; then
		echo -e "\033[32;1mPassed\033[0m";
	else
		echo -e "\033[1;31mFailed\033[0m";
	fi
