/*
 * SimpleMLPicker.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Zoie & Jie Fu
 */

#ifndef SIMPLEMLPICKER_H_
#define SIMPLEMLPICKER_H_

#include "PickNPCHand.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SimpleMLPicker : public PickNPCHand {
public:
	SimpleMLPicker();
	~SimpleMLPicker();
	char pick(char c);
	char prediction();
private:
	char compute();        //predict human next move, and provide corresponding npc move
	void updatedatabase(); //update the databse.txt
	void updatequeue ();   //update the queue
	void filldatabase ();  //fill out the database.txt
	char random();         //return a random npc chioce
	//these two for for updating the queue
	string queue;
	int queuelength;
	char human_previous;
	char npc_previous;
	char human_prediction;
	//these two are for filling out the database.txt
	char choice[3]={'P', 'R', 'S'};
	int count;
	//these two are for importing and exporting from the databse.txt
	ifstream importdata;
	ofstream exportdata;
};


#endif /* SIMPLEMLPICKER_H_ */

