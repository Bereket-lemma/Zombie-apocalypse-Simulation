// <Bereket> <Salim> <Joha> <Jagjot>
// <12/16/2022>
// <Course Code: CS-273-2>
// License: Copyright <2022> <Bereket><Salim> <Joha> <Jagjot>
// Resources used: <http://www.cplusplus.com/forum/beginner/66092/>
// <Final Project-Zombie Apocalypse simulation>
#include <iostream>
#include <string>
#include <algorithm>
#include "citizen.h"

#ifndef IGNORANT_H
#define IGNORANT_H

// class called Ignorant, which is a derived class of Citizen.
//  The Ignorant class represents an ignorant citizen and stores data about where they live and work.
// This information will be used to define the move function for the IgnorantCitizen class,
//  which determines how the ignorant citizen will move from one location to another.

class Ignorant : public Citizen
{
private:
    std::string live;
    std::string work;

public:
    // Default constructor
    Ignorant()
    {
        state = "Ignorant";
        live = "None assigned";
        work = "None assigned";
        curLocation = "None assigned";
    }

    // Constructor for Ignorant type
    // Input: where an ignorant citizen lives and works
    Ignorant(std::string live, std::string work)
    {
        state = "Ignorant";
        this->live = live;
        this->work = work;
        curLocation = live; // initialized to be where they live
    }

    // Defines how a citizen will move
    // Input: layout map
    void move(std::map<std::string, std::vector<std::string>> &layout)
    {
        if (curLocation == live)
        { // go to work if at home
            curLocation = work;
        }
        else
        { // got to home if at work
            curLocation = live;
        }
    }

    // Indicates where a citizen lives
    // Output: which district a citizen lives in
    std::string getLive()
    {
        return live;
    }

    // Ignorant citizens will not interact with other citizens
    void interact(Citizen *&other, std::deque<Citizen *> &citizens, int X, int Y, int Z){};

    // Destructor
    ~Ignorant(){};
};
#endif