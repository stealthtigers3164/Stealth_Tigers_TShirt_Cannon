#include "cannon.h"

Cannon::Cannon(int portInput){
	port=portInput;
	
	Relay valve(port); //These 3 lines make sure the cannon valve is closed on startup.
	valve.Set(Relay::kOn);
	delete &valve;

}

void RunFireAsync(int port){
	Relay valve(port);
	valve.Set(Relay::kOff);
	sleep(200);	//keep valve open for 2 secs.
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




