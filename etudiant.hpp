#pragma once

 

#include <string>
#include <vector>
#include <iostream>

 


class Etudiant
{
private:
  std::vector<int>tableau_notes;
  std::string identifiant;
  long matricule;

 

public:
  Etudiant(std::string un_identifiant, long un_matricule) ;

 

  void ajouterNote(int une_note);
  std::string getEtude();
  long getMatricule();

 

  void defilerNote();
  double calculerMoyenne();

 

  bool operator<(const Etudiant& etudiant_a_droite) const;

 

};

 

