#ifndef REGLES_ACCES_H
#define	REGLES_ACCES_H

#include <string>

const string PERIODE_ACCES_MATIN =	"Matin"
const string PERIODE_ACCES_SOIR	 = "Soir"
const string PERIODE_ACCES_NUIT = "Nuit"


using namespace std;

class RegleAcces
{
public:
	RegleAcces();
	RegleAcces(unsigned int niveau, const string& local, const string& periode);

	string			getLocal()				const;
	unsigned int	getNiveauAccesRequis()	const;
	string			getPeriode()			const;

	bool operator==(const RegleAcces& regle) const;

private:
	string			local_;
	unsigned int	niveauAccesRequis_;
	string			periode_;
};

#endif	//REGLES_ACCES_H