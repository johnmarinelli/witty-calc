#!usr/bin/bash

g++ -std=c++11 -o calculator CalculatorDisplay.cpp OperationButton.cpp NumberButton.cpp CalculatorWidget.cpp main.cpp -lwthttp -lwt -lboost_random -lboost_regex -lboost_signals -lboost_system -lboost_thread -lboost_filesystem -lboost_program_options -lboost_date_time
