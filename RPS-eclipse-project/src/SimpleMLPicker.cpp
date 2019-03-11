/*
 * SimpleMLPicker.cpp
 *
 *  Created on: Mar 8, 2019
 *      Author: JieFu
 */
#include "stdlib.h"
#include "stdio.h"
#include "cstdio"
#include "SimpleMLPicker.h"

SimpleMLPicker::~SimpleMLPicker() {
	// TODO Auto-generated destructor stub
}

SimpleMLPicker::SimpleMLPicker()
{
	queuelength=0;
	count=0;
	human_previous='P';
	npc_previous='P';
	importdata.open("database.txt");
	exportdata.open("database.txt");
	if (importdata.fail()) cerr<< "Error opening file[i]"<<endl;
	if (exportdata.fail()) cerr<< "Error opening file[e"<<endl;
	filldatabase();
}

char SimpleMLPicker::pick(char c)
{
	char choice;
	if (c=='I')
	{
		choice=random();
		npc_previous=choice;
	}
	else
	{
		human_previous=c;
		updatequeue();
		if (queuelength>=4) choice=compute();
		else choice=random();
		if (queuelength==5)	updatedatabase();
	}
	npc_previous=choice;
	return choice;
}

char SimpleMLPicker::compute()
{
	char choice='x';
	string comb1=queue.substr(0, 4)+"P";
	string comb2=queue.substr(0, 4)+"R";
	string comb3=queue.substr(0, 4)+"S";
	string temp;
	int pcount, rcount, scount=0;
	importdata.open("database.txt");
	if (importdata.fail()) cerr<<"Error opening file in compute"<<endl;
	importdata.seekg(0);
	while (!importdata.eof())
	{
		importdata>>temp;
		if (temp==comb1) importdata>>pcount;
		else if (temp==comb2) importdata>>rcount;
		else if (temp==comb3) importdata>>scount;
	}
	if ((pcount>rcount)&&(pcount>scount)) choice='S';
	else if ((rcount>pcount)&&(rcount>scount)) choice='P';
	else if ((scount>pcount)&&(scount>rcount)) choice='R';
	else choice=random();
	importdata.close();
	return choice;
}

void SimpleMLPicker::filldatabase()
{
	for (int a=0; a<3; a++)
	{
		for (int b=0; b<3; b++)
		{
			for (int c=0; c<3; c++)
			{
				for (int d=0; d<3; d++)
				{
					for (int e=0; e<3; e++)
					{
						exportdata<<choice[a]<<choice[b]<<choice[c]<<choice[d]<<choice[e]<<" "<<count<<endl;
					}
				}
			}
		}
	}
	importdata.close();
	exportdata.close();
}

void SimpleMLPicker::updatequeue()
{
	if (queuelength<3)
	{
		queue.push_back(human_previous);
		queue.push_back(npc_previous);
		queuelength+=2;
	}
	else if (queuelength==4)
	{
		queue.push_back(human_previous);
		queuelength++;
	}
	else if (queuelength==5)
	{
		queue[0]=queue[2];
		queue[1]=queue[3];
		queue[2]=queue[4];
		queue.erase(2,2);
		queue.push_back(npc_previous);
		queue.push_back(human_previous);
	}
	cout<<queue<<endl;
}

void SimpleMLPicker::updatedatabase()
{
	importdata.open("database.txt");
	if (importdata.fail()) cerr<< "Error opening file[i]"<<endl;
	if (queuelength==5)
	{
		int line=0;
		switch(queue[0])
		{
		case 'P': {line+=0; break;}
		case 'R': {line+=81; break;}
		case 'S': {line+=162; break;}
		}
		switch(queue[1])
		{
		case 'P': {line+=0; break;}
		case 'R': {line+=27; break;}
		case 'S': {line+=54; break;}
		}
		switch(queue[2])
		{
		case 'P': {line+=0; break;}
		case 'R': {line+=9; break;}
		case 'S': {line+=18; break;}
		}
		switch(queue[3])
		{
		case 'P': {line+=0; break;}
		case 'R': {line+=3; break;}
		case 'S': {line+=6; break;}
		}
		switch(queue[4])
		{
		case 'P': {line+=1; break;}
		case 'R': {line+=2; break;}
		case 'S': {line+=3; break;}
		}
		importdata.seekg(0);
		ofstream exportdata_temp;
		exportdata_temp.open("database_temp.txt");
		if (exportdata_temp.fail()) cerr<<"Error opening file [t]"<<endl;
		string comb;
		int num;
		for (int i=1; i<244; i++)
		{
			if (i==line)
			{
				importdata>>comb;
				exportdata_temp<<comb<<" ";
				importdata>>num;
				num++;
				exportdata_temp<<num<<endl;
			}
			else
			{
				importdata>>comb;
				exportdata_temp<<comb<<" ";
				importdata>>num;
				exportdata_temp<<num<<endl;
			}
		}
		importdata.close();
		exportdata_temp.close();
		remove ("database.txt");
		rename ("database_temp.txt", "database.txt");
	}
}

char SimpleMLPicker::random()
{
	int a=rand()%3;
	char c;
	switch (a)
	{
	case 0: {c='P'; break;}
	case 1: {c='R'; break;}
	case 2: {c='S'; break;}
	}
	npc_previous=c;
	return c;
}

