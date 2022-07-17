// Do not remove the include below
#include "PlutoPilot.h"
#include "Control.h"
#include "Sensor.h"
#include "User.h"
#include "Utils.h"
#include "Math.h"
#include "Estimate.h"

Interval forwardtime,sidetimer;
void flyForward()
{
RcCommand.set(RC_PITCH,500);
Interval forward;
RcCommand.set(RC_PITCH,0);


}


void flyBackward(){
RcCommand.set(RC_PITCH,-500);
Interval bacward;
bool bacflag=bacward.set(10,true);
RcCommand.set(RC_PITCH,0);



}

void left()
{
RcCommand.set(RC_ROLL,500);
Interval leftward;
bool leftflag=leftward.set(10,true);
RcCommand.set(RC_PITCH,0);


}

void right()
{
RcCommand.set(RC_PITCH,-500);
Interval rightward;
bool rightflag=rightward.set(10,true);
RcCommand.set(RC_PITCH,0);


}

void autopilot(int a,int b)
	{
	if(a==1)
	{
		for(int i=0;i<b;i++)
		{
			flyForward();
		}
	}
	else if(a==2)
	{
		for(int i=0;i<b;i++)
		{
			flyBackward();
		}
	}
	else if(a==3)
	{
		for(int i=0;i<b;i++)
		{
			right();
		}
	}
	else if(a==4)
	{
		for(int i=0;i<b;i++)
		{
			left();
		}
	}else if(a==5)
	{

	}

	}


//The setup function is called once at Pluto's hardware startup
void plutoInit()
{
//Add your hardware initialization code here



}




//The function is called once before plutoLoop() when you activate developer mode
void onLoopStart()
{
	LED.flightStatus(DEACTIVATE);
	Command.takeOff(50);
	DesiredPosition.set(Z,50);




//Do your one time stuff here

}



//The loop function is called in an endless loop
void plutoLoop()
{
	if(Position.get(Z)>=50){
	int path[10][2]={{1,3},{5,0},{2,3},{5,0},{3,3},{5,0},{4,3},{5,0},{5,0},{5,0}};
	for(int com=0;com<10;com++)
	{
		int direction=path[com][0];
		int magnitude=path[com][1];
		autopilot(direction,magnitude);
	}
	}




}
//The function is called once after plutoLoop() when you deactivate developer mode
void onLoopFinish()
{
//Do your cleanup stuff here
	LED.flightStatus(ACTIVATE);
	Command.land(105);
	Interval landtime;
	bool disarmflag=landtime.set(500,true);
	if(disarmflag){
		Command.disArm();

	}
}




