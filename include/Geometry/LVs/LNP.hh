#ifndef B1LNP_h
#define B1LNP_h 1

#include "globals.hh"
#include <vector>
#include "G4LogicalVolume.hh"
#include "Geometry/Solids/SNP.hh"

class G4Material;
class G4FieldMAnager;
class G4VSensitiveDetector;
class G4UserLimits;

class LNP: public G4LogicalVolume {
    public:
        LNP(SNP*, G4Material*,
        const G4String&,
        G4FieldManager* d=0, G4VSensitiveDetector* e=0, G4UserLimits* f=0, G4bool g=true);
        ~LNP();
//  custom methids



    private:
        SNP* fSolid = nullptr;
};

#endif