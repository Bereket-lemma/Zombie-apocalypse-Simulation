// <Bereket> <Salim> <Joha> <Jagjot>
// <12/16/2022>
// <Course Code: CS-273-2>
// License: Copyright <2022> <Bereket><Salim> <Joha> <Jagjot>
// Resources used: <http://www.cplusplus.com/forum/beginner/66092/>
// <Final Project-Zombie Apocalypse simulation>
#include <iostream> //header files for file io
#include <string>   //for string
#include <map>      //for STL map
#include <ctime>    //for seeding random

#include <fstream>

#include "simulator.h"
#include "zombie.h"
#include "alarmed.h"
#include "citizen.h"
#include "ignorant.h"
using namespace std;

// start of main function
int main()
{

//fstream anyname("./tests/anyname.csv",ios::in | ios::out|ios::binary);

ofstream file;

file.open("Report.csv");

if(file.is_open()){
    cout << "File opened correctly" << endl;
} else{
    cout << "File not open correctly." << endl;
}

 
    srand(time(NULL)); // seed current time
    int maxTime;       // variable for total days simulation lasts
    int X;             // for probability an ignorant person becomes a zombie
    int Y;             // for probability an ignorant person becomes alarmed
    int Z;             // for the probability an alarmed person becomes a zombie
    int Q;             // for probability a citizen moves districts

    std::cout << "----------Welcome to the Zombie Apocalypse Simulator!-------" << std::endl;
    std::cout << "Please enter how many days you would like the simulator to run: ";
    std::cin >> maxTime;
    file<<"Max Time : " << maxTime<<endl;
    std::cout << "Please enter the probability an ignorant person becomes a zombie: ";
    std::cin >> X;
    file <<"Ignorant to Zombie : "<< X <<endl;
    std::cout << "Please enter the probability an ignorant person becomes alarmed: ";
    std::cin >> Y;
    file<<"Ignorant to Alarmed : "<<Y<<endl;
    std::cout << "Please enter the probability an alarmed person becomes a zombie: ";
    std::cin >> Z;
    file<<"Alamed to Zombie : "<<Z<<endl;
    std::cout << "Please enter the probability a citizen moves districts: ";
    std::cin >> Q;
    file<<"Moving Districts : "<<Z<<endl;
    cout<<"=========================================================="<<endl;

    ZombieSim simulator(maxTime, X, Y, Z, Q); // calling zombie simulator object to pass the probabilities
    simulator.runSim();                       // calling simulator to run the simulation



   file.close();
    return 0;
}