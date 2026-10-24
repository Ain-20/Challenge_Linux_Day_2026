#!/bin/bash

if [ "$1" = "C_1.c" ]; then

    gcc -Wall -O2 C_1.c -o user
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file utente."
        exit 1
    fi

    gcc -Wall -O2 C_1_sol.c -o solution
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file soluzione."
        exit 1
    fi

    ./user > user_output.txt
    ./solution > solution_output.txt

    if diff -q sol_utente soluzione1 > /dev/null; then
        echo "Esito: CORRETTO. L'output coincide con la soluzione."
    else
        echo "Esito: ERRATO. L'output differisce dalla soluzione."
        echo "Differenze riscontrate:"
    fi


elif [ "$1" = "C_2.c" ]; then

    gcc -Wall -O2 C_2.c -o user
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file utente."
        exit 1
    fi

    gcc -Wall -O2 C_2_sol.c -o solution
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file soluzione."
        exit 1
    fi

    ./user > user_output.txt
    ./solution > solution_output.txt

    if diff -q user_output.txt solution_output.txt > /dev/null; then
        echo "Esito: CORRETTO. L'output coincide con la soluzione."
    else
        echo "Esito: ERRATO. L'output differisce dalla soluzione."
        echo "Differenze riscontrate:"
    fi

elif [ "$1" = "C_3.c" ]; then

    gcc -Wall -O2 C_3.c -o user
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file utente."
        exit 1
    fi

    gcc -Wall -O2 C_3_sol.c -o solution
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file soluzione."
        exit 1
    fi

    ./user > user_output.txt
    ./solution > solution_output.txt

    if diff -q user_output.txt solution_output.txt > /dev/null; then
        echo "Esito: CORRETTO. L'output coincide con la soluzione."
    else
        echo "Esito: ERRATO. L'output differisce dalla soluzione."
        echo "Differenze riscontrate:"
    fi

elif [ "$1" = "C_4.c" ]; then

    gcc -Wall -O2 C_4.c -o user
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file utente."
        exit 1
    fi

    gcc -Wall -O2 C_4_sol.c -o solution
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file soluzione."
        exit 1
    fi

    ./user > user_output.txt
    ./solution > solution_output.txt

    if diff -q user_output.txt solution_output.txt > /dev/null; then
        echo "Esito: CORRETTO. L'output coincide con la soluzione."
    else
        echo "Esito: ERRATO. L'output differisce dalla soluzione."
        echo "Differenze riscontrate:"
    fi

elif [ "$1" = "C_5.c" ]; then

    gcc -Wall -O2 C_5.c -o user
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file utente."
        exit 1
    fi

    gcc -Wall -O2 C_5_sol.c -o solution
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file soluzione."
        exit 1
    fi

    ./user > user_output.txt
    ./solution > solution_output.txt

    if diff -q user_output.txt solution_output.txt > /dev/null; then
        echo "Esito: CORRETTO. L'output coincide con la soluzione."
        cat solution_output.txt
    else
        echo "Esito: ERRATO. L'output differisce dalla soluzione."
        echo "Differenze riscontrate:"
    fi

elif [ "$1" = "C_6.c" ]; then

    gcc -Wall -O2 C_6.c -o user
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file utente."
        exit 1
    fi

    gcc -Wall -O2 C_6_sol.c -o solution
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file soluzione."
        exit 1
    fi

    ./user > user_output.txt
    ./solution > solution_output.txt

    if diff -q user_output.txt solution_output.txt > /dev/null; then
        echo "Esito: CORRETTO. L'output coincide con la soluzione."
        cat solution_output.txt
    else
        echo "Esito: ERRATO. L'output differisce dalla soluzione."
        echo "Differenze riscontrate:"
    fi

elif [ "$1" = "C_7.c" ]; then

    gcc -Wall -O2 C_7.c -o user
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file utente."
        exit 1
    fi

    gcc -Wall -O2 C_7_sol.c -o solution
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file soluzione."
        exit 1
    fi

    ./user > user_output.txt
    ./solution > solution_output.txt

    if diff -q user_output.txt solution_output.txt > /dev/null; then
        echo "Esito: CORRETTO. L'output coincide con la soluzione."
        cat solution_output.txt
    else
        echo "Esito: ERRATO. L'output differisce dalla soluzione."
        echo "Differenze riscontrate:"
    fi

elif [ "$1" = "C_8.c" ]; then

    gcc -Wall -O2 C_8.c -o user
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file utente."
        exit 1
    fi

    gcc -Wall -O2 C_8_sol.c -o solution
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file soluzione."
        exit 1
    fi

    ./user > user_output.txt
    ./solution > solution_output.txt

    if diff -q user_output.txt solution_output.txt > /dev/null; then
        echo "Esito: CORRETTO. L'output coincide con la soluzione."
        cat solution_output.txt
    else
        echo "Esito: ERRATO. L'output differisce dalla soluzione."
        echo "Differenze riscontrate:"
    fi

elif [ "$1" = "C_9.c" ]; then

    gcc -Wall -O2 C_9.c -o user
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file utente."
        exit 1
    fi

    gcc -Wall -O2 C_9_sol.c -o solution
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file soluzione."
        exit 1
    fi

    ./user > user_output.txt
    ./solution > solution_output.txt

    if diff -q user_output.txt solution_output.txt > /dev/null; then
        echo "Esito: CORRETTO. L'output coincide con la soluzione."
        cat solution_output.txt
    else
        echo "Esito: ERRATO. L'output differisce dalla soluzione."
        echo "Differenze riscontrate:"
    fi

elif [ "$1" = "C_10.c" ]; then

    gcc -Wall -O2 C_10.c -o user
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file utente."
        exit 1
    fi

    gcc -Wall -O2 C_10_sol.c -o solution
    if [ $? -ne 0 ]; then
        echo "Errore di compilazione nel file soluzione."
        exit 1
    fi

    ./user > user_output.txt
    ./solution > solution_output.txt

    if diff -q user_output.txt solution_output.txt > /dev/null; then
        echo "Esito: CORRETTO. L'output coincide con la soluzione."
        cat solution_output.txt
    else
        echo "Esito: ERRATO. L'output differisce dalla soluzione."
        echo "Differenze riscontrate:"
    fi

fi

rm user solution user_output.txt solution_output.txt
