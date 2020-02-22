#include <iostream>
#include <string>

using namespace std;

class Note{
	private:
		double note;
		string matricule_Et;
		string code_Mat;
	public:	
		void setNote(double);
		double getNote();
		void setMatricule_Et(string);
		string getMatricule_Et();
		void setCode_Mat(string);
		string getCode_Mat();
		
};

void Note::setNote(double note){
	this->note=note;
}
double Note::getNote(){
	return this->note;
}

void Note::setMatricule_Et(string matricule_Et){
	this->matricule_Et=matricule_Et;
}
string Note::getMatricule_Et(){
	return this->matricule_Et;
}

void Note::setCode_Mat(string code_Mat){
	this->code_Mat=code_Mat;
}
string Note::getCode_Mat(){
	return this->code_Mat;
}
