#include <iostream>
#include <string>
#include<fstream>
#include<stdlib.h>
#include "Etudiant.h"
#include "Matiere.h"
#include "Note.h"
#include "Classe.h"

using namespace std;

class Traitements{
	
	public :

	bool verifNum(string);
	int rechercheEtudiant(Etudiant t[],int NombreEtudiant,string Id);
	void insererEtudiant(Etudiant t[],int &NombreEtudiant,Etudiant Nouveau);
	void supprimerEtudiant(Etudiant t[],int &NombreEtudiant,string Id);
	void modifierEtudiant(Etudiant t[],int NombreEtudiant,string Id,int ind,string val);
	
	int rechercheMatiere(Matiere t[],int NombreMatiere,string Id);
	void insererMatiere(Matiere t[],int &NombreMatiere,Matiere Nouveau);
	void supprimerMatiere(Matiere t[],int &NombreMatiere,string Id);
	void modifierMatiere(Matiere t[],int NombreMatiere,string Id,int ind,string val);
	
	int rechercheClasse(Classe t[],int NombreClasse,string Id);
	void insererClasse(Classe t[],int &NombreClasse,Classe Nouveau);
	void supprimerClasse(Classe t[],int &NombreClasse,string Id);
	void modifierClasse(Classe t[],int NombreClasse,string Id,int ind,string val);
	
	int Effectif(Etudiant t[],int NombreEtudiant,string Id);
	void listeMatCls(Matiere t[],int NombreMatiere,string Id);//liste des matières d’une classe donnée
	void listeEtuCls(Etudiant t[],int NombreEtudiant,string Id);//liste des étudiants d’une classe donnée
	void listeClsEff(Classe t1[],int NombreClasse,Etudiant t2[],int NombreEtudiant);//Liste des classe et leur effectif
	void insertNotesEt(Note t[],int &NombreNote,Note Nouveau);//saisie des notes d'etudiants
	void afficheNotesEtMat(Note t[],int NombreNote,string Id);
	void afficheNotesEt(Note t[],int NombreNote,string Id);

	void ecrireDansFichierEtudiant(Etudiant t[],int);
	void ecrireDansFichierMatiere(Matiere t[],int);
	void ecrireDansFichierClasse(Classe t[],int);
	void ecrireDansFichierNote(Note t[],int);
	double Moyenne(string Id,Note t1[],int NombreNote,Matiere t2[],int NombreMatiere);
	void EtudiantsMoyennes(Etudiant t[], int NombreEtudiant,string Id,Note t1[],int NombreNote,Matiere t2[],int NombreMatiere);
	void EtudiantsNotesMoyennes(string id,Note t1[],int NombreNote,Matiere t2[],int NombreMatiere);
	
	void lireDansFichierEtudiant(Etudiant t[]);
	void lireDansFichierMatiere(Matiere t[]);
	void lireDansFichierClasse(Classe t[]);
	void lireDansFichierNote(Note t[]);
	
	int getNombreEtudiants(Etudiant t[]);
	int getNombreMatieres(Matiere t[]);
	int getNombreClasses(Classe t[]);
	int getNombreNotes(Note t[]);
	
};

bool Traitements::verifNum(string val){
	
	for(int i=0;i<val.length();i++){
		if(!isdigit(val[i])){
			return false;
		}
	}
	
	return true;
}

int Traitements::rechercheEtudiant(Etudiant t[],int NombreEtudiant,string Id){
	
	int i=0;
	while(i< NombreEtudiant){
		if(t[i].getMatricule()==Id){
			return i;
		}
		else{
			i+=1;
		}
	} 
	return -1; 		
}

void Traitements::modifierEtudiant(Etudiant t[],int NombreEtudiant,string Id,int ind,string val){
	int position=rechercheEtudiant(t,NombreEtudiant,Id);//Est ce que je peux utiliser cette fonction sans la passer en parametre en c++?
	if(position!=-1){
		switch(ind){
			case 1:t[position].setMatricule(val);break;
			case 2:t[position].setNom(val);break;
			case 3:t[position].setPrenom(val);break;
			case 4:t[position].setDate(val);break;
			case 5:t[position].setGenre(val);break;
			case 6:t[position].setCode_cl(val);break;
		}
		
	}
}

void Traitements::insererEtudiant(Etudiant t[],int &NombreEtudiant,Etudiant Nouveau){
	if(NombreEtudiant<100/*Cette valeur est la taille maximale du tableau, il sera preferable de stoquer cette valeur dans une constante*/){
		t[NombreEtudiant]= Nouveau;
		NombreEtudiant+=1;
	}
}

void Traitements::supprimerEtudiant(Etudiant t[],int &NombreEtudiant,string Id){
	int compteur=rechercheEtudiant(t,NombreEtudiant,Id);
	if(compteur!=-1){
		while(compteur!=NombreEtudiant){
			t[compteur]=t[compteur+1];
			compteur++;
		}
		NombreEtudiant--;
	}
}

//----

int Traitements::rechercheMatiere(Matiere t[],int NombreMatiere,string Id){
	
	int i=0;
	while(i< NombreMatiere){
		if(t[i].getCode_Mat()==Id){
			return i;
		}
		else{
			i+=1;
		}
	} 
	return -1; 		
}

void Traitements::modifierMatiere(Matiere t[],int NombreMatiere,string Id,int ind,string val){
	int position=rechercheMatiere(t,NombreMatiere,Id);//Est ce que je peux utiliser cette fonction sans la passer en parametre en c++?
	if(position!=-1){
		switch(ind){
			case 1:t[position].setCode_Mat(val);break;
			case 2:t[position].setNom_Mat(val);break;
			case 3:t[position].setCode_Cl(val);break;
			case 4:t[position].setCoef(atoi(val.c_str()));break;
		}
	}
}

void Traitements::insererMatiere(Matiere t[],int &NombreMatiere,Matiere Nouveau){
	if(NombreMatiere<100/*Cette valeur est la taille maximale du tableau, il sera preferable de stoquer cette valeur dans une constante*/){
		t[NombreMatiere]= Nouveau;
		NombreMatiere+=1;
	}
}

void Traitements::supprimerMatiere(Matiere t[],int &NombreMatiere,string Id){
	int compteur=rechercheMatiere(t,NombreMatiere,Id);
	if(compteur!=-1){
		while(compteur!=NombreMatiere){
			t[compteur]=t[compteur+1];
			compteur++;
		}
		NombreMatiere--;
	}
}

//----

int Traitements::rechercheClasse(Classe t[],int NombreClasse,string Id){
	
	int i=0;
	while(i< NombreClasse){
		if(t[i].getCode_cl()==Id){
			return i;
		}
		else{
			i+=1;
		}
	} 
	return -1; 		
}

void Traitements::modifierClasse(Classe t[],int NombreClasse,string Id,int ind,string val){
	int position=rechercheClasse(t,NombreClasse,Id);//Est ce que je peux utiliser cette fonction sans la passer en parametre en c++?
	if(position!=-1){
		switch(ind){
			case 1:t[position].setCode_cl(val);break;
			case 2:t[position].setNom_cl(val);break;
		}
	}
}

void Traitements::insererClasse(Classe t[],int &NombreClasse,Classe Nouveau){
	if(NombreClasse<100/*Cette valeur est la taille maximale du tableau, il sera preferable de stoquer cette valeur dans une constante*/){
		t[NombreClasse]= Nouveau;
		NombreClasse+=1;
	}
}

void Traitements::supprimerClasse(Classe t[],int &NombreClasse,string Id){
	int compteur=rechercheClasse(t,NombreClasse,Id);
	if(compteur!=-1){
		while(compteur!=NombreClasse){
			t[compteur]=t[compteur+1];
			compteur++;
		}
		NombreClasse--;
	}
}

//----

void Traitements::listeMatCls(Matiere t[],int NombreMatiere,string Id){//Id de la classe
	for(int i=0;i< NombreMatiere;i++){
		if(t[i].getCode_Cl()==Id){
			cout << "Code de la matiere :" << t[i].getCode_Mat() << endl;
			cout << "Nom :" << t[i].getNom_Mat() << endl;
			cout << "Code de la classe :" << t[i].getCode_Cl() << endl;
			cout << "Coefficient :" << t[i].getCoef() << endl;
			cout << endl;
		}
	}
}
//Question 3
void Traitements::listeEtuCls(Etudiant t[],int NombreEtudiant,string Id){//Id de la classe
	for(int i=0;i< NombreEtudiant;i++){
		if(t[i].getCode_cl()==Id){
			cout << "Matricule :" << t[i].getMatricule() << endl;
			cout << "Nom :" << t[i].getNom() << endl;
			cout << "Prenom :" << t[i].getPrenom() << endl;
			cout << "Genre :" << t[i].getGenre() << endl;
			cout << "Date :" << t[i].getDate() << endl;
			cout << endl;
		}
	}
}

int Traitements::Effectif(Etudiant t[],int NombreEtudiant,string Id){// Id est l identifiant de la classe.
	int nombre=0;
	for(int i=0;i< NombreEtudiant;i++){
		if(t[i].getCode_cl()==Id){
			nombre+=1;
		}
	}
	return nombre;
}

//Question4
void Traitements::listeClsEff(Classe t1[],int NombreClasse,Etudiant t2[],int NombreEtudiant){
	for(int i=0;i< NombreClasse;i++){
		int effectif=Effectif(t2,NombreEtudiant,t1[i].getCode_cl());
		cout <<"Code de la classe:" << t1[i].getCode_cl() << endl;
		cout <<"Effectif:" << effectif << endl;
	}
}


//Question5
void Traitements::insertNotesEt(Note t[],int &NombreNote,Note Nouveau){
	if(NombreNote<100){
		t[NombreNote]=Nouveau;
		NombreNote++;
	}
}
//Question 6
void Traitements::afficheNotesEtMat(Note t[],int NombreNote,string Id){//Id est l identifiant de la matiere.
	for(int i=0;i< NombreNote;i++){
		if(t[i].getCode_Mat()==Id){
			cout << "Matricule :" << t[i].getMatricule_Et() << endl;
			cout << "Note :" << t[i].getNote() << endl;
			cout << endl;
		}
	}
}
//question7
void Traitements::afficheNotesEt(Note t[],int NombreNote,string Id){//Id est l identifiant de l'etudiant.
	for(int i=0;i< NombreNote;i++){
		if(t[i].getMatricule_Et()==Id){
			cout << "Code matiere :" << t[i].getCode_Mat() << endl;
			cout << "Note :" << t[i].getNote() << endl;
			cout << endl;
		}
	}
}



void Traitements::ecrireDansFichierEtudiant(Etudiant t[],int NombreEtudiant){
    string const nomfichier("Etudiant.txt");//Nom du fichier dans lequel nous devons ecrire.
    ofstream monFlux(nomfichier.c_str());

    if(monFlux)    
    {
	for(int i=0;i<NombreEtudiant;i++){
       	monFlux << t[i].getMatricule() << endl;
       	monFlux << t[i].getNom() << endl;
       	monFlux << t[i].getPrenom() << endl;
        monFlux << t[i].getDate() << endl;
		monFlux << t[i].getGenre() << endl;
		monFlux << t[i].getCode_cl() << endl;
		monFlux << "--------------------------------------------------------------------------------------------------------" << endl;
	}
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}

void Traitements::ecrireDansFichierMatiere(Matiere t[],int NombreMatiere){
    string const nomfichier("Matiere.txt");//Nom du fichier dans lequel nous devons ecrire.
    ofstream monFlux(nomfichier.c_str());

    if(monFlux)    
    {
	for(int i=0;i<NombreMatiere;i++){
       	monFlux << t[i].getCode_Mat() << endl;
       	monFlux << t[i].getNom_Mat() << endl;
       	monFlux << t[i].getCode_Cl() << endl;
        monFlux << t[i].getCoef() << endl;
		monFlux << "--------------------------------------------------------------------------------------------------------" << endl;
	}
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}

void Traitements::ecrireDansFichierClasse(Classe t[],int NombreClasse){
    string const nomfichier("Classe.txt");//Nom du fichier dans lequel nous devons ecrire.
    ofstream monFlux(nomfichier.c_str());

    if(monFlux)    
    {
	for(int i=0;i<NombreClasse;i++){
       	monFlux << t[i].getCode_cl() << endl;
       	monFlux << t[i].getNom_cl() << endl;
		monFlux << "--------------------------------------------------------------------------------------------------------" << endl;
	}
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}

void Traitements::ecrireDansFichierNote(Note t[],int NombreNote){
    string const nomfichier("Note.txt");//Nom du fichier dans lequel nous devons ecrire.
    ofstream monFlux(nomfichier.c_str());

    if(monFlux)    
    {
	for(int i=0;i<NombreNote;i++){
       	monFlux << t[i].getNote() << endl;
       	monFlux << t[i].getMatricule_Et() << endl;
       	monFlux << t[i].getCode_Mat() << endl;
		monFlux << "--------------------------------------------------------------------------------------------------------" << endl;
	}
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}
	
void Traitements::lireDansFichierEtudiant(Etudiant t[]){
	string LesTirets;
	string const nomfichier("Etudiant.txt");//Nom du fichier dans lequel nous devons ecrire.
	ifstream fichier(nomfichier.c_str());
	
	if(fichier){
		int i=0;
		while(!fichier.eof())
		{
			string val="";
			getline(fichier,val);
			t[i].setMatricule(val);
        	getline(fichier,val);
        	t[i].setNom(val);
        	getline(fichier,val);
        	t[i].setPrenom(val);
       		getline(fichier,val);
       		t[i].setDate(val);
			getline(fichier,val);
			t[i].setGenre(val);
			getline(fichier,val);
			t[i].setCode_cl(val);
			getline(fichier,LesTirets);
			i++;
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

}

void Traitements::lireDansFichierMatiere(Matiere t[]){
	string LesTirets;
	string const nomfichier("Matiere.txt");//Nom du fichier dans lequel nous devons ecrire.
	ifstream fichier(nomfichier.c_str());
	
	if(fichier){
		int i=0;
		while(!fichier.eof())
		{
			string val="";
			getline(fichier,val);
			t[i].setCode_Mat(val);
        	getline(fichier,val);
        	t[i].setNom_Mat(val);
        	getline(fichier,val);
        	t[i].setCode_Cl(val);
       		getline(fichier,val);
       		t[i].setCoef(atoi(val.c_str()));
			getline(fichier,LesTirets);
			i++;
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

}

void Traitements::lireDansFichierClasse(Classe t[]){
	string LesTirets;
	string const nomfichier("Classe.txt");//Nom du fichier dans lequel nous devons ecrire.
	ifstream fichier(nomfichier.c_str());
	
	if(fichier){
		int i=0;
		while(!fichier.eof())
		{
			string val="";
			getline(fichier,val);
			t[i].setCode_cl(val);
        	getline(fichier,val);
        	t[i].setNom_cl(val);
			getline(fichier,LesTirets);
			i++;
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

}

void Traitements::lireDansFichierNote(Note t[]){
	string LesTirets;
	string const nomfichier("Note.txt");//Nom du fichier dans lequel nous devons ecrire.
	ifstream fichier(nomfichier.c_str());
	
	if(fichier){
		int i=0;
		while(!fichier.eof())
		{
			string val="";
			getline(fichier,val);
			t[i].setNote(atoi(val.c_str()));
        	getline(fichier,val);
        	t[i].setMatricule_Et(val);
        	getline(fichier,val);
        	t[i].setCode_Mat(val);
			getline(fichier,LesTirets);
			i++;
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

}

double Traitements::Moyenne(string Id,Note t1[],int NombreNote,Matiere t2[],int NombreMatiere){//Id correspond au matricule de l' etudiant
	double moy=0;
	int nbre=0;//nbre-somme des coefficients , note-note courante , coef- coefficient note courant
	for(int j=0;j<NombreNote;j++){
		int coef=0,note=0;
		if(t1[j].getMatricule_Et()==Id){
			note=t1[j].getNote();
			//Recherche du coeficient
			int k=0;
			while(t1[j].getCode_Mat()!=t2[k].getCode_Mat()){//on ne s'arrete lorsqu'on a trouve la matiere en question
				k++;
			}
			coef=t2[k].getCoef();
			nbre+=coef;
			//Fin de la recherche du coeficient.
		}
		moy+=coef*note;
	}
	return moy/nbre;
}

//question 9
void Traitements::EtudiantsMoyennes(Etudiant t[], int NombreEtudiant,string Id,Note t1[],int NombreNote,Matiere t2[],int NombreMatiere){//Id correspond au code de la classe.
	double moy;
	for(int i=0;i<NombreEtudiant;i++){
		if(t[i].getCode_cl()==Id){
			moy=Moyenne(t[i].getMatricule(),t1,NombreNote,t2,NombreMatiere);
			cout << "Matricule : " << t[i].getMatricule() << endl;
			cout << "Moyenne : " << moy << endl;
		}
	}	
}

void Traitements::EtudiantsNotesMoyennes(string id,Note t1[],int NombreNote,Matiere t2[],int NombreMatiere){
		afficheNotesEt(t1,NombreNote,id);
		float moy=Moyenne(id,t1,NombreNote,t2,NombreMatiere);
		cout << "Moyenne : " << moy << endl;
}

//void Traitements::EtudiantsNotesMoyennes(Etudiant t[],int NombreEtudiant,Note t1[],int NombreNote,Matiere t2[],int NombreMatiere){
//	for(int i=0;i<NombreEtudiant;i++){
//		afficheNotesEt(t1,NombreNote,t[i].getMatricule());
//		float moy=Moyenne(t[i].getMatricule(),t1,NombreNote,t2,NombreMatiere);
//		cout << "Moyenne : " << moy << endl;
//	}
//}

int Traitements::getNombreEtudiants(Etudiant t[]){
	int n=0;
	
	while(t[n].getMatricule()!=""){
		n++;
	}
	
	return n;
}

int Traitements::getNombreMatieres(Matiere t[]){
	int n=0;
	
	while(t[n].getCode_Mat()!=""){
		n++;
	}
	
	return n;
}

int Traitements::getNombreClasses(Classe  t[]){
	int n=0;
	
	while(t[n].getCode_cl()!=""){
		n++;
	}
	
	return n;
}

int Traitements::getNombreNotes(Note t[]){
	int n=0;
	
	while(t[n].getMatricule_Et()!=""){
		n++;
	}
	
	return n;
}
