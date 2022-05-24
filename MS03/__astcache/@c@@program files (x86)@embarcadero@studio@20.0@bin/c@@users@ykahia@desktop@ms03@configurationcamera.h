//---------------------------------------------------------------------------

#ifndef ConfigurationCameraH
#define ConfigurationCameraH
//---------------------------------------------------------------------------

class ConfigurationCamera{

private:
	 char adressIP[20];
	 unsigned short port;
	 char identifiant[30];
	 char motDePasse[30];

public:
	ConfigurationCamera();
	void LireConfiguration(const char * fichier);
	void AfficherConfiguration();
	const char*AdresseIP();
	const char*Port();
	const char*Identifiant();
    const char*MotDePasse();
};

#endif
