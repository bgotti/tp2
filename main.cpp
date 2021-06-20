#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm> // utilisé pour std::sort()

#include <vector>

#include "etudiant.hpp"

int main()
{

	std::vector<Etudiant> tab_etudiant;
	int index_tab_etudiant = 0;

	/*std::vector<std::string> inputLines;*/
	std::string lire_fichier;
	std::string identifiant;
	long matricule;
	int qte_notes;
	int une_note;

	//-------------------------------------------------------------------------------------------------------------------------------
	//Lecture du fichier donneesbrutes.txt
	std::ifstream lecteur;
	lecteur.open("donneesbrutes.txt", std::ios::in);
	if (lecteur.is_open())
	{

		std::cout << "Lecture du fichier donneesbrutes.txt"
							<< "\n"
							<< std::endl;

		while (getline(lecteur, lire_fichier))
		{

			std::stringstream analyse_fichier(lire_fichier); //On va utiliser pour lire le fichier
			std::cout << " - " << lire_fichier << std::endl;
			analyse_fichier >> identifiant;
			analyse_fichier >> matricule;
			analyse_fichier >> qte_notes;

			tab_etudiant.push_back(Etudiant(identifiant, matricule));

			while (true)
			{
				analyse_fichier >> une_note;
				if (analyse_fichier.fail())
					break;
				tab_etudiant[index_tab_etudiant].ajouterNote(une_note);
			}

			index_tab_etudiant++;
		}
		lecteur.close();
	}
	else
		std::cout << "Erreur. Le fichier donneesbrutes.txt est introuvable!";

	//-----------------------------------------------------------------------------------------------------------------------------

	std::cout << "\n\n"
						<< "---------------------------------------"
						<< "\n\n\n";

	std::cout << "L'écriture du fichier moyennes.txt"
						<< "\n"
						<< std::endl;

	// l'ecriture du fichier moyennes.txt dans le terminal (les matricules en ordre croissant et les moyennes des notes obtenues )
	std::sort(tab_etudiant.begin(), tab_etudiant.end());

	for (int i = 0; i < tab_etudiant.size(); i++)
	{

		std::cout << " - " << tab_etudiant[i].getMatricule() << " " << tab_etudiant[i].calculerMoyenne() << std::endl;
	}

	//-----------------------------------------------------------------------------------------------------------------------------

	std::ofstream ecrivain;
	ecrivain.open("moyennes.txt", std::ios::out);
	if (ecrivain.is_open() == true)
	{

		std::string ligne;

		for (int i = 0; i < tab_etudiant.size(); i++)
		{

			ligne = std::to_string(tab_etudiant[i].getMatricule()) + " " + std::to_string(tab_etudiant[i].calculerMoyenne()) + "\n";
			ecrivain << ligne;
		}
		ecrivain.close();
	}

	else
		std::cout << "Erreur. ";

	system("echo %cd%");

	return 0;
}