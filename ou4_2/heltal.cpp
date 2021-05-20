#include <cstdlib>
// Integer class 

class Heltal{
	public:
		Heltal(int);
		int get();
		void set(int);
		int fib(int);
	private:
		int val;
	};
 
Heltal::Heltal(int n){
	val = n;
	}
 
int Heltal::get(){
	return val;
	}
 
void Heltal::set(int n){
	val = n;
	}
 
int Heltal::fib(int n){
	if (n <= 1) {
		return n;
	} else {
		return (fib(int n-1)+fib(int n-2));
	}
 
extern "C"{
	Heltal* Heltal_new(int n) {return new Heltal(n);}
	int Heltal_get(Heltal* heltal) {return heltal->get();}
	void Heltal_set(Heltal* heltal, int n) {heltal->set(n);}
	void Heltal_delete(Heltal* heltal){
		if (heltal){
			delete heltal;
			heltal = nullptr;
			}
		}
	}
