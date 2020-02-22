#include <iostream>
#include <string>

using namespace std;

class Classe{
	private:
		string code_cl;
		string nom_cl;
	public:	
		void setCode_cl(string);
		string getCode_cl();
		void setNom_cl(string);
		string getNom_cl();
		
};

void Classe::setCode_cl(string code_cl){
	this->code_cl=code_cl;
}
string Classe::getCode_cl(){
	return this->code_cl;
}

void Classe::setNom_cl(string nom_cl){
	this->nom_cl=nom_cl;
}
string Classe::getNom_cl(){
	return this->nom_cl;
}
