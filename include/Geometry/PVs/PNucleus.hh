#ifndef B1PONucleus_h
#define B1PNucleus_h 1

#include "globals.hh"
#include <vector>
#include "G4PVPlacement.hh"



class LNucleus;
class G4Material;
class G4FieldMAnager;
class G4SensitiveDetector;
class G4UserLimits;
class LCell;

class PNucleus: public G4PVPlacement {
    public:
         PNucleus(G4RotationMatrix*, const G4ThreeVector, LNucleus*, const G4String, G4LogicalVolume*, G4bool, G4int, G4bool);
        ~PNucleus();

//  custom methods

        G4String GetName(){
            return fName;
        }

    private:
        G4String fName;
};

#endif