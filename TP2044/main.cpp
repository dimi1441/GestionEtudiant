#include <iostream>
#include <fstream>
#include <string>
#include "Traitements.h"

using namespace std;


main() {
	
	
	Traitements tr;//Objet qui nous permettra d'appeler nos methodes metiers
	
	Etudiant E[10000];//contiendra la liste des etudiants extraits du fichier
	tr.lireDansFichierEtudiant(E);
	int NombreEtudiants=tr.getNombreEtudiants(E);
	
	Matiere M[10000];
	tr.lireDansFichierMatiere(M);
	int NombreMatieres=tr.getNombreMatieres(M);
	
	Classe C[10000];
	tr.lireDansFichierClasse(C);
	int NombreClasses=tr.getNombreClasses(C);
	
	Note N[10000];
	tr.lireDansFichierNote(N);
	int NombreNotes=tr.getNombreNotes(N);
	
	
	
	
	int continuer=0;
	do{
		int choix;
		cout<<"Bienvenue sur notre plateforme\n"<<endl;
		cout<<"Que voulez-vous faire?\n\n 1.Enregistrer des classes.\n 2.Enregistrer des matieres.\n 3.Enregistrer un etudiant\n 4.Rechercher une classe.\n 5.Rechercher une matiere.\n 6.Rechercher un etudiant\n 7.Modifier une classe.\n 8.Modifier une matiere.\n 9.Modifier un etudiant\n 10.Supprimer une classe.\n 11.Supprimer une matiere.\n 12.Supprimer un etudiant\n 13.Afficher la liste des matières d’une classe donnée\n 14.Afficher la liste des étudiants d’une classe donnée\n 15.Afficher la liste des classes du département avec leur effectif respectif\n 16.Enregistrer des notes\n 17.Afficher les notes des étudiants pour une matière donnée\n 18.Afficher toutes les notes d’un étudiant donné\n 19.Afficher la liste des étudiants et leur moyenne pour une classe donnée\n 20.Afficher la liste des notes et la moyenne obtenu pour un étudiant donné \n 21.Fermer l'application\n";
		cout<<"Choix:";
		cin>>choix;
		switch(choix){
			
			case 1: 
			{
				bool ex=false;
				int nb;
				cout<<"Entrez le nombre de classes a inserer:";
				cin>>nb;
				for(int i=0;i<nb;i++){
				
					Classe cl;
					string nm,cd;
					cout<<"Classe"<<i<<endl;
					cout<<"Code de la classe:";if(i==0)getline(cin,cd);getline(cin,cd);
					if(tr.rechercheClasse(C,NombreClasses,cd)==-1){
						cout<<"Nom de la classe:";getline(cin,nm);
						cl.setCode_cl(cd);
						cl.setNom_cl(nm);
						tr.insererClasse(C,NombreClasses,cl);
					}else{
						cout<<"!!!Cette classe existe deja!!!";
					}
				}
				
				tr.ecrireDansFichierClasse(C,NombreClasses);
			};break;
			
			case 2:
			{	
				int nb1;
				cout<<"Entrez le nombre de matieres a inserer:";
				cin>>nb1;
				for(int i=0;i<nb1;i++){
					Matiere mt;
					string nm,cd,cdcl;
					string cf;
					cout<<"Matiere"<<i<<endl;
					cout<<"Code de la matiere:";getline(cin,cd);if(i==0)getline(cin,cd);
					if(tr.rechercheMatiere(M,NombreMatieres,cd)==-1){
						cout<<"Nom de la matiere:";getline(cin,nm);
						cout<<"Code de la classe dans laquelle est enseignee la matiere:";getline(cin,cdcl);
						if(tr.rechercheClasse(C,NombreClasses,cdcl)!=-1){
							cout<<"Coefficient:";getline(cin,cf);
							if(tr.verifNum(cf)){
								mt.setCode_Mat(cd);
								mt.setNom_Mat(nm);
								mt.setCode_Cl(cdcl);
								mt.setCoef(atoi(cf.c_str()));
								tr.insererMatiere(M,NombreMatieres,mt);
							}else{
								cout<<"!!Entree invalide!!"<<endl;
							}
						}else{
							cout<<"Attention!!! Cette classe n'existe pas! Impossibilite d'enregistrement!!"<<endl;
						}
					}else{
						cout<<"!!!Cette matiere existe deja!!!"<<endl;
					}
				}
				tr.ecrireDansFichierMatiere(M,NombreMatieres);
			};break;	
			case 3:
			{
				int nb2;
				cout<<"Entrez le nombre d'etudiants a inserer:";
				cin>>nb2;
				for(int i=0;i<nb2;i++){
					Etudiant et;
					string mtr,nm,pnm,dt,gr,cdcl;
					cout<<"Etudiant"<<i<<endl;
					cout<<"Matricule de l'etudiant:";if(i==0) getline(cin,mtr);getline(cin,mtr);
					if(tr.rechercheEtudiant(E,NombreEtudiants,mtr)==-1){
						cout<<"Nom de l'etudiant:";getline(cin,nm);
						cout<<"Prenom de l'etudiant:";getline(cin,pnm);
						cout<<"Date de naissance de l'etudiant(j/m/aaaa):";getline(cin,dt);
						cout<<"Genre de l'etudiant(M/F):";getline(cin,gr);
						cout<<"Code de la classe de l'etudiant:";getline(cin,cdcl);
					
						if(tr.rechercheClasse(C,NombreClasses,cdcl)!=-1){
							et.setMatricule(mtr);
							et.setNom(nm);
							et.setPrenom(pnm);
							et.setDate(dt);
							et.setGenre(gr);
							et.setCode_cl(cdcl);
							tr.insererEtudiant(E,NombreEtudiants,et);
						}else{
							cout<<"Attention!!! Cette classe n'existe pas! Impossibilite d'enregistrement";
						}
					}else{
						cout<<"!!!Cet etudiant existe deja!!!";
					}
				}
				tr.ecrireDansFichierEtudiant(E,NombreEtudiants);
			};break;
			case 4:
			{
				int pos;
				string cd;
				cout<<"Entrez le code de la classe a rechercher :"; getline(cin,cd);getline(cin,cd);
				pos=tr.rechercheClasse(C,NombreClasses,cd);
				cout<<"Resultats:"<<endl;
				if(pos==-1){
					cout<<"!!!Cette classe n'existe pas!!!"<<endl;
				}else{
					cout<<"Code_classe:"<<C[pos].getCode_cl()<<"\nNom_classe:"<<C[pos].getNom_cl();
				}
			}
			;break;
			case 5:
			{
				int pos;
				string cd;
				cout<<"Entrez le code de la matiere a rechercher :"; getline(cin,cd);getline(cin,cd);
				pos=tr.rechercheMatiere(M,NombreMatieres,cd);
				cout<<"Resultats:"<<endl;
				if(pos==-1){
					cout<<"!!!Cette matiere n'existe pas!!!"<<endl;
				}else{
					cout<<"Code_matiere:"<<M[pos].getCode_Mat()<<"\nNom_matiere:"<<M[pos].getNom_Mat() <<"\nCode_classe:"<<M[pos].getCode_Cl()<<"\nCoef:"<<M[pos].getCoef();
				}
			};break;
			case 6:
			{
				int pos;
				string cd;
				cout<<"Entrez le matricule de l'etudiant a rechercher :"; getline(cin,cd);getline(cin,cd);
				pos=tr.rechercheEtudiant(E,NombreEtudiants,cd);
				cout<<"Resultats:"<<endl;
				if(pos==-1){
					cout<<"!!!Cet etudiant n'existe pas!!!"<<endl;
				}else{
					cout<<"Matricule:"<<E[pos].getMatricule()<<"\nNom:"<<E[pos].getNom()<<"\nPrenom:"<<E[pos].getPrenom()<<"\nGenre:"<<E[pos].getGenre()<<"\nDate de naissance:"<<E[pos].getDate()<<"\nClasse:"<<E[pos].getCode_cl();
				}
			};break;
			case 7:
			{
				int ind,mod;
				string id,val;
				
				cout<<"Entrez le code de la classe a modifier:";getline(cin,id);getline(cin,id);
				do{
					cout<<"Quel est l'element que vous souhaitez modifier?\n1.code de la classe\n2.nom de la classe\n";cin>>ind;
					cout<<"Inserez la nouvelle valeur:";getline(cin,val);getline(cin,val);
					tr.modifierClasse(C,NombreClasses,id,ind,val);
					cout<<"Voulez vous modifier un autre champ?(1:oui/0:non)";cin>>mod;
				}while(mod==1);
				tr.ecrireDansFichierClasse(C,NombreClasses);
			};break;
			case 8:
			{
				int ind,mod;
				string id,val;
				
				cout<<"Entrez le code de la matiere a modifier:";getline(cin,id);getline(cin,id);
				do{
					cout<<"Quel est l'element que vous souhaitez modifier?\n1.code de la matiere\n2.nom de la matiere\n3.code de la classe\n4.coef\n";cin>>ind;
					cout<<"Inserez la nouvelle valeur:";getline(cin,val);getline(cin,val);
					tr.modifierMatiere(M,NombreMatieres,id,ind,val);
					cout<<"Voulez vous modifier un autre champ?(1:oui/0:non)";cin>>mod;
				}while(mod==1);
				tr.ecrireDansFichierMatiere(M,NombreMatieres);
			};break;
			case 9:
			{
				int ind,mod;
				string id,val;
				
				cout<<"Entrez le matricule de l'etudiant a modifier:";getline(cin,id);getline(cin,id);
				do{
					cout<<"Quel est l'element que vous souhaitez modifier?\n1.matricule\n2.nom\n3.prenom\n4.genre\n5.date de naissance\n6.code classe\n";cin>>ind;
					cout<<"Inserez la nouvelle valeur:";getline(cin,val);getline(cin,val);
					tr.modifierEtudiant(E,NombreEtudiants,id,ind,val);
					cout<<"Voulez vous modifier un autre champ?(1:oui/0:non)";cin>>mod;
				}while(mod==1);
				tr.ecrireDansFichierEtudiant(E,NombreEtudiants);
			}
			;break;
			case 10:
			{
				string id;
				cout<<"Inserer le code de la classe a supprimer:";getline(cin,id);getline(cin,id);
				tr.supprimerClasse(C,NombreClasses,id);
				tr.ecrireDansFichierClasse(C,NombreClasses);
			};break;
			case 11:
			{
				string id;
				cout<<"Inserer le code de la matiere a supprimer:";getline(cin,id);getline(cin,id);
				tr.supprimerMatiere(M,NombreMatieres,id);
				tr.ecrireDansFichierMatiere(M,NombreMatieres);
			};break;
			case 12:
			{
				string id;
				cout<<"Inserer le matricule de l'etudiant a supprimer:";getline(cin,id);getline(cin,id);
				tr.supprimerEtudiant(E,NombreEtudiants,id);
				tr.ecrireDansFichierEtudiant(E,NombreEtudiants);
			};break;
			case 13:{
				string id;
				cout<<"Inserer le code de la classe dont vous voulez la liste des matieres:";getline(cin,id);getline(cin,id);
				tr.listeMatCls(M,NombreMatieres,id);
			};break;
			case 14:{
				string id;
				cout<<"Inserer le code de la classe dont vous voulez la liste des etudiants:";getline(cin,id);getline(cin,id);
				tr.listeEtuCls(E,NombreEtudiants,id);
			}
			;break;
			case 15:
				tr.listeClsEff(C,NombreClasses,E,NombreEtudiants);
			;break;
			case 16:{
				int nb3;
				cout<<"Entrez le nombre de notes a inserer:";
				cin>>nb3;
				for(int i=0;i<nb3;i++){
					Note nt;
					string mtr,cdm;
					double note;
					cout<<"Note"<<i<<endl;
					cout<<"Matricule de l'etudiant disposant de la note':";getline(cin,mtr);getline(cin,mtr);
					if(tr.rechercheEtudiant(E,NombreEtudiants,mtr)!=-1){
						cout<<"Code de la matiere dans laquelle la note est attribuee:";getline(cin,cdm);
						if(tr.rechercheMatiere(M,NombreMatieres,cdm)!=-1){
							cout<<"Valeur de la note sur 20:";cin>>note;
							nt.setMatricule_Et(mtr);
							nt.setCode_Mat(cdm);
							nt.setNote(note);
							tr.insertNotesEt(N,NombreNotes,nt);
						}else{
							cout<<"Attention!!! Cette matiere n'existe pas! Impossibilite d'enregistrement!";
						}
					}else{
						cout<<"Attention!!! Cet etudiant n'existe pas! Impossibilite d'enregistrement!";
					}
				}
				tr.ecrireDansFichierNote(N,NombreNotes);
			};break;
			case 17:{
				string id;
				cout<<"Entrez le code de la matiere dont vous voulez les notes des etudiants: ";getline(cin,id);getline(cin,id);
				tr.afficheNotesEtMat(N,NombreNotes,id);
			};break;
			case 18:{
				string id;
				cout<<"Entrez le matricule de l'etudiant dont vous voulez les notes: ";getline(cin,id);getline(cin,id);
				tr.afficheNotesEt(N,NombreNotes,id);
			};break;
			case 19:{
				string id;
				cout<<"Entrez le code de la classe dont vous voulez la liste des etudiants et leurs moyennes: ";getline(cin,id);getline(cin,id);
				tr.EtudiantsMoyennes(E,NombreEtudiants,id,N,NombreNotes,M,NombreMatieres);
			};break;
			case 20:{
				string id;
				cout<<"Entrez le matricule de l'etudiant dont vous voulez les notes et la moyenne:";getline(cin,id);getline(cin,id);
				tr.EtudiantsNotesMoyennes(id,N,NombreNotes,M,NombreMatieres);
			};break;
			
		}
		cout<<"Voulez-vous continuer?(1:oui/0:non)";
		cin>>continuer;
	}while(continuer==1);
}
