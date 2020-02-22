#include <iostream>
#include <string>

using namespace std;

class Matiere{
	private:
		string code_Mat;
		string nom_Mat;
		string code_Cl;
		int coef;
	public:
		void setCode_Mat(string);
		string getCode_Mat();
		void setCode_Cl(string);
		string getCode_Cl();
		void setNom_Mat(string);
		string getNom_Mat();
		void setCoef(int);
		int getCoef();
};

void Matiere::setCode_Mat(string code_Mat){
	this->code_Mat=code_Mat;
}
string Matiere::getCode_Mat(){
	return this->code_Mat;
}

void Matiere::setNom_Mat(string nom_Mat){
	this->nom_Mat=nom_Mat;
}
string Matiere::getNom_Mat(){
	return this->nom_Mat;
}

void Matiere::setCoef(int coef){
	this->coef=coef;
}
int Matiere::getCoef(){
	return this->coef;
}

void Matiere::setCode_Cl(string code_Cl){
	this->code_Cl=code_Cl;
}
string Matiere::getCode_Cl(){
	return this->code_Cl;
}
