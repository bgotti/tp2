#include "etudiant.hpp"

Etudiant::Etudiant(std::string un_identifiant, long un_matricule)
{
    this->identifiant = un_identifiant;
    this->matricule = un_matricule;
}

void Etudiant::ajouterNote(int une_note)
{
    this->tableau_notes.push_back(une_note);
}

std::string Etudiant::getEtude()
{
    return this->identifiant;
}
long Etudiant::getMatricule()
{
    return this->matricule;
}

double Etudiant::calculerMoyenne()
{
    double somme = 0;
    double moyenne;

    for (unsigned int i = 0; i < tableau_notes.size(); i++)
    {

        somme += this->tableau_notes[i];
    }
    moyenne = somme / tableau_notes.size();

    return moyenne;
}
bool Etudiant::operator<(const Etudiant &etudiant_a_droite) const
{
    if (this->matricule < etudiant_a_droite.matricule)
        return true;
    return false;
}