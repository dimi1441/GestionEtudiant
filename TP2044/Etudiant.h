#include <iostream>
#include <string>

using namespace std;

class Etudiant{
	private:
		string matricule;
		string nom;
		string prenom;
		string date;
		string genre;
		string code_cl;
	public:
		void setMatricule(string);
		string getMatricule();
		void setNom(string);
		string getNom();
		void setPrenom(string);
		string getPrenom();
		void setDate(string);
		string getDate();
		void setGenre(string);
		string getGenre();
		void setCode_cl(string);
		string getCode_cl();
		
};

void Etudiant::setMatricule(string matricule){
	this->matricule=matricule;
}
string Etudiant::getMatricule(){
	return this->matricule;
}

void Etudiant::setNom(string nom){
	this->nom=nom;
}
string Etudiant::getNom(){
	return this->nom;
}

void Etudiant::setPrenom(string prenom){
	this->prenom=prenom;
}
string Etudiant::getPrenom(){
	return this->prenom;
}

void Etudiant::setDate(string date){
	this->date=date;
}
string Etudiant::getDate(){
	return this->date;
}

void Etudiant::setGenre(string genre){
	this->genre=genre;
}
string Etudiant::getGenre(){
	return this->genre;
}

void Etudiant::setCode_cl(string code_cl){
	this->code_cl=code_cl;
}
string Etudiant::getCode_cl(){
	return this->code_cl;
}

