#ifndef MAX_H
#define MAX_H
 
#include <Arduino.h>
 
class MAX {
public:
        MAX();
        ~MAX();
		void a(int time);
		void b(int time);
		void c(int time);
		void d(int time);
		void e(int time);
private:
	    void maxAll (byte reg, byte col);
		void maxSingle( byte reg, byte col);
		void putByte(byte data);
};
 
#endif