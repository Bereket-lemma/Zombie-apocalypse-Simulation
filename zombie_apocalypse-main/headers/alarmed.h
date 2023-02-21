// <Bereket> <Salim> <Joha> <Jagjot>
// <12/16/2022>
// <Course Code: CS-273-2>
// License: Copyright <2022> <Bereket><Salim> <Joha> <Jagjot>
// Resources used: <http://www.cplusplus.com/forum/beginner/66092/>
// <Final Project-Zombie Apocalypse simulation>
#include <iostream>
#include <ctime>
#include "citizen.h"

#ifndef ALARMED_H
#define ALARMED_H

//Class called Alarmed, which is a derived class of Citizen.
// The AlarmedCitizen class represents an alarmed citizen and defines how they will interact with ignorant citizens.
// The class also stores information about the current location and state of the alarmed citizen.
class Alarmed : public Citizen {
public:
    //Alarmed constructor
    //Input: location of citizen
    Alarmed(std::string location) {
        curLocation = location;
        state = "Alarmed";
    }

    //Defines an interaction of an alarmed citizens
    //Input: other citizen to interact with, deque of citizens, and probabilities
    void interact(Citizen*& other, std::deque<Citizen*>& citizens, int X, int Y, int Z) {
        int randnum; //stores random number to determine how the two citizens interact
        //If the alarmed citizen is interacting with an ignorant person
        if (other->getState() == "Ignorant") { 
            randnum = rand() % 100;
            if(randnum < Y) { //If the citizen becomes alarmed
                delete other;
                other = NULL;
                other = new Alarmed(this->curLocation); //have pointer point to alarmed
                citizens.push_back(other); //add to interaction list
            }
        }
    }

    //Alarmed destructor
    ~Alarmed(){
    }
};

//end of alarmed class
#endif