#ifndef B1PNP_h
#define B1PNP_h 1

#include "globals.hh"
#include <vector>

#include "G4PVPlacement.hh"

class LNP;
class G4Material;
class G4FieldMAnager;
class G4SensitiveDetector;
class G4UserLimits;
class LCell;

class PNP: public G4PVPlacement {
    public:
         PNP(G4RotationMatrix*, const G4ThreeVector, LNP*, const G4String, G4LogicalVolume*, G4bool, G4int, G4bool);
        ~PNP();

    // custom methods 

        G4String GetName(){
            return fName;
        }

    private:
        G4String fName; 
};

#endif