#ifndef B1LNucleus_h
#define B1LNucleus_h 1

#include "globals.hh"
#include "G4VSolid.hh"
#include <vector>
#include "G4LogicalVolume.hh"


class SNucleus;
class G4Material;
class G4FieldMAnager;
class G4VSensitiveDetector;
class G4UserLimits;

class LNucleus: public G4LogicalVolume{
    public:
    LNucleus(SNucleus*, G4Material*,
        const G4String&,
        G4FieldManager* d=0, G4VSensitiveDetector* e=0, G4UserLimits* f=0, G4bool g=true);
    ~LNucleus();

    private:


};    

#endif