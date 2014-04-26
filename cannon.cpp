#include "cannon.h"

Cannon::Cannon(int portInput){
	
	cerr<<"Cannon Class Constructing ";
	port=portInput;
	
	Relay valve(port); //These 3 lines make sure the cannon valve is closed on startup.
	valve.Set(Relay::kOn);
	delete &valve;
	cerr<<"Valve Set ";

}

void RunFireAsync(int port){
	cerr<<"Asynchronous firing process started";
	Relay valve(port);
	valve.Set(Relay::kOff);
	sleep(2000);	//keep valve open for 2 secs.
	valve.Set(Relay::kOn);
	delete &valve;
}

void Cannon::Fire(){ 
	Task FireTask("FireTask", (FUNCPTR)RunFireAsync);
	if(FireTask.Start(port)){ //starts task. If it fails (because task already running), it restarts it.
		FireTask.Restart();
	}
	//The task is kept alive even after done, but it doesn't loop. 
	//Tasks are unable to kill themselves because you can only pass them ints.
	//For more info on tasks, see WPILib doxygen for Task Class Reference.
}

void Cannon::UpdateAngle(){
	//insert gyro stuff here.
}




