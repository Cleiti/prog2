#include <cstdlib>
#include <iostream>
// Integer class 

class Heltal{
	public:
		Heltal(int);
		int get();
		void set(int);
		int fib();
	private:
		int val;
		int fibb(int);
	};
 
Heltal::Heltal(int n){
	val = n;
	}
 
int Heltal::fibb(int n){
	if (n<= 1) {
		return n;
	} else {
		return (fibb(n-1)+fibb(n-2));
	}
}
 
int Heltal::get(){
	return val;
	}
 
void Heltal::set(int n){
	val = n;
	}
 
int Heltal::fib(){
	return (fibb(val));
 }

extern "C"{
	Heltal* Heltal_new(int n) {return new Heltal(n);}
	int Heltal_get(Heltal* heltal) {return heltal->get();}
	void Heltal_set(Heltal* heltal, int n) {heltal->set(n);}
	int Heltal_fib(Heltal* heltal) {return heltal->fib();}
	void Heltal_delete(Heltal* heltal){
		if (heltal){
			delete heltal;
			heltal = nullptr;
			}
		}
	}
