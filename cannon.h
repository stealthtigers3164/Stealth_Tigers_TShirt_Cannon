#ifndef Cannon_H
#define Cannon_H

#import "WPIlib.h"

class Cannon{
	public:
		Cannon(int port);
		int port;
		int angle;
		void Fire();
		void UpdateAngle();
};

#endif
