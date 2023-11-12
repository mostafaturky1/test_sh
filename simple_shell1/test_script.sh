#!/bin/bash

# ANSI color codes
RED='\033[0;31m'   # Red
GREEN='\033[0;32m' # Green
YELLOW='\033[0;33m' # Yellow
BLUE='\033[0;34m' 
BROWN='\033[1;33m'
CYAN='\033[0;36m' 
NC='\033[0m'       # No Color

hsh_output="../hsh_output"
sh_output="../sh_output"
hsh_diff="../hsh_diff"
error_log="../error_log"

echo "" > $error_log

 # Clean up
cleanup(){
    rm $hsh_output
    rm $sh_output
    rm $hsh_diff
}

# Display usage message
usage() {
    echo "Usage: $0 [-m] [-a] [-b] [-set1] [-set2] [-set3] [-set4] [-set5]"
    echo "Options:"
    echo "  -m: Run Mandatory Test Cases"
    echo "  -a: Run Advanced Test Cases"
    echo "  -b: Run Bonus Test Cases (if applicable)"
    echo "Set Options (Use with -m or -a):"
    echo "  -s1: Run Set 1"
    echo "  -s2: Run Set 2"
    echo "  -s3: Run Set 3"
    echo "  -s4: Run Set 4"
    echo "  -s5: Run Set 5"
}

# Check for the number of arguments
if [ $# -eq 0 ]; then
    usage
    exit 1
fi

# Compile the C program
gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "[*] Compilation successful. Starting the program..."

    # Define a function to run tests and compare output
    run_test() {
        echo "\n[*] Running Test Case [${BLUE}$1${NC} in Set ${BLUE}$2${NC}]"
        echo "$3" | ./hsh > $hsh_output 2>&1
        echo "$3" | /bin/bash > $sh_output 2>&1
        
        if diff $sh_output $hsh_output > $hsh_diff; then
            echo "[+] Test Case $1 ${GREEN}PASSED${NC}"
        else
            echo "[-] Test Case $1 ${RED}FAILED${NC}"
            echo "[*] Command: ${CYAN}$3${NC}"
            echo "${YELLOW}[-] Differences:"
            cat $hsh_diff
            echo "${NC}"

            echo "\n\n[-] Test Case $1 FAILED" >> $error_log
            echo "[*] Command: $3" >> $error_log
            echo "[-] Standard Output:" >> $error_log
            cat $sh_output >> $error_log
            echo "[-] hsh Ouput:" >> $error_log
            cat $hsh_output >> $error_log
            echo "[-] The Difference:" >> $error_log
            cat $hsh_diff >> $error_log
        fi

        cleanup
    }

    mandatory=0
    advanced=0
    set1=0
    set2=0
    set3=0
    set4=0
    set5=0

    # Check the options and sets
    while [ $# -gt 0 ]; do
        case $1 in
            -m)
                mandatory=1
                echo "[*] Running Mandatory Test Cases"
                ;;
            -a)
                advanced=1
                echo "[*] Running Advanced Test Cases"
                ;;
            -s1)
                set=1
                echo "[**] Running Set 1"
                ;;
            -s2)
                set=2
                echo "[**] Running Set 2"
                ;;
            -s3)
                set=3
                echo "[**] Running Set 3"
                ;;
            -s4)
                set=4
                echo "[**] Running Set 4"
                ;;
            -s5)
                set=5
                echo "[**] Running Set 5"
                ;;
            *)
                usage
                exit 1
                ;;
        esac
        shift
    done

    # Execute the selected tests
    if [ "$mandatory" -eq 1 ]; then
        if [ "$set" -eq 1 ]; then
            run_test 1 1 " /bin/ls
/bin/ls
/bin/ls"

            run_test 2 $set " /bin/ls"
            run_test 3 $set "                             /bin/ls"

            run_test 4 $set "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       "

            run_test 5 $set "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               "

            run_test 6 $set "                "

        fi
        if [ "$set" -eq 2 ]; then
            run_test 1 $set "/bin/ls -l" 

            run_test 2 $set "/bin/ls /var"

            run_test 3 $set "/bin/echo Holberton"

        fi
        if [ "$set" -eq 3 ]; then
            run_test 1 $set "/bin/ls -l"

            run_test 2 $set "hbtn_cmd"

            run_test 3 $set "ls"

            run_test 4 $set "ls -l"

            run_test 5 $set "ls"

            run_test 6 $set "./.././../hbtn_ls /var"

            run_test 7 $set "./.././../////././hbtn_ls /var"

            run_test 8 $set "../../hbtn_ls /var"
            
            run_test 9 $set "ls


        /bin/ls


            ls
        ls
        ls     "

            run_test 10 $set "hbtn_ls"

            run_test 11 $set "hbtn"

        fi
        if [ "$set" -eq 4 ]; then
           
            run_test 1 $set "/bin/ls /test_hbtn
exit"

            run_test 2 $set "exit"

        fi

        if [ "$set" -eq 5 ]; then
           
            run_test 1 $set "env"

            run_test 2 $set "exit"

        fi

    fi

    if [ "$advanced" -eq 1 ]; then
        run_test 1 1 "exit 1000"

        run_test 2 1 "exit -98"

        run_test 3 1 "/bin/ls /test_hbtn
    exit"
         
        run_test 4 1 "exit"

        run_test 5 1 "exit HBTN"
    fi

    #rm hsh
else
    echo "Compilation failed. Check your code."
fi
