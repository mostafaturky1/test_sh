#!/bin/bash

# Compile the C program
gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Starting the program..."
    echo "[*] Running Mandatory Test Cases"
    echo "[**] Runnning First Set of Tests"
    echo "[****] Runnning Test Case 1 in 1"
    echo " /bin/ls
/bin/ls
/bin/ls" | ./hsh

    echo "[****] Runnning Test Case 2 in 1"
    echo “ /bin/ls” | ./hsh
    
    echo "[****] Runnning Test Case 3 in 1"
    echo “                             /bin/ls” | ./hsh

    echo "[****] Runnning Test Case 4 in 1"
    echo "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       " | ./hsh

    echo "[****] Runnning Test Case 5 in 1"
    echo "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               " | ./hsh

    echo "[****] Runnning Test Case 6 in 1"
    echo "                " | ./hsh

    echo "[**] Runnning Second Set of Tests"
    
    echo "[****] Runnning Test Case 1 in 2"
    echo "/bin/ls -l" | ./hsh

    echo "[****] Runnning Test Case 2 in 2"
    echo "/bin/ls /var" | ./hsh.  

    echo "[****] Runnning Test Case 3 in 2"
    echo "/bin/echo Holberton" | ./hsh  

    echo "[**] Runnning Third Set of Tests"
    echo "[****] Runnning Test Case 1 in 3"
    echo "/bin/ls -l" | ./hsh

    echo "[****] Runnning Test Case 1 in 3"
    echo "hbtn_cmd" | ./hsh

    echo "[****] Runnning Test Case 2 in 3"
    echo "ls" | ./hsh

    echo "[****] Runnning Test Case 3 in 3"
    echo "ls -l" | ./hsh

    echo "[****] Runnning Test Case 4 in 3"
    echo "ls" | ./hsh

    echo "[****] Runnning Test Case 5 in 3"
    echo "./.././../hbtn_ls /var" | ./hsh

    echo "[****] Runnning Test Case 6 in 3"
    echo "./.././../////././hbtn_ls /var" | ./hsh

    echo "[****] Runnning Test Case 7 in 3"
    echo "../../hbtn_ls /var" | ./hsh
    
    echo "[****] Runnning Test Case 8 in 3"
    echo "ls


 /bin/ls


     ls
ls
 ls     " | ./hsh


    echo "[****] Runnning Test Case 9 in 3"
    echo "hbtn_ls" | ./hsh

    echo "[****] Runnning Test Case 10 in 3"
    echo "hbtn" | ./hsh


    echo "[**] Runnning Fourth Set of Tests"
    echo "[****] Runnning Test Case 1 in 4"
    echo "/bin/ls /test_hbtn
exit" | ./hsh

    echo "[****] Runnning Test Case 2 in 4"
    echo "exit" | ./hsh


    echo "[**] Runnning Fiveth Set of Tests"
    echo "[****] Runnning Test Case 1 in 5"
    echo "env" | ./hsh
    
    echo "[****] Runnning Test Case 2 in 5"
    echo "env" | ./hsh

    echo "[****] Runnning Test Case 1 in 5"
    
    echo "[*] Running Advanced Test Cases"
    echo "[**] Runnning First Set of Tests"
    echo "[****] Runnning Test Case 1 in 1"
    echo "exit 1000" | ./hsh

    echo "[****] Runnning Test Case 2 in 1"
    echo "exit -98" | ./hsh

    echo "[****] Runnning Test Case 3 in 1"
    echo "/bin/ls /test_hbtn
exit" | ./hsh

    echo "[****] Runnning Test Case 4 in 1"
    
    echo "[****] Runnning Test Case 5 in 1"
    
    echo "[****] Runnning Test Case 6 in 1"
    
    echo "[****] Runnning Test Case 7 in 1"
    
    echo "[****] Runnning Test Case 8 in 1"
    
    echo "[****] Runnning Test Case 9 in 1"
    
    echo "[****] Runnning Test Case 10 in 1"
    echo "exit" | ./hsh

    echo "[****] Runnning Test Case 11 in 1"
    echo "exit HBTN" | ./hsh

else
    echo "Compilation failed. Check your code."
fi
