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
 
int Heltal::fib(){
	if (val <= 1) {
		return val;
	} else {
		Heltal n1(val-1);
		Heltal n2(val-2);
		return (n1.fib()+n2.fib());
	}
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

int main() {
	Heltal num(5);
	std::cout << num.fib();
	std::cout << "Done!";
}
