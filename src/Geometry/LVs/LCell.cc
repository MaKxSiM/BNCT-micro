
#include "globals.hh"
#include <vector>
#include "Geometry/Solids/SCell.hh"
#include "Geometry/LVs/LCell.hh"
#include "G4LogicalVolume.hh"


LCell::LCell(SCell* a, G4Material* b, const G4String& c, G4FieldManager* d, G4VSensitiveDetector* e, G4UserLimits* f, G4bool g):G4LogicalVolume(a,b,c,d,e,f,g){
    fSolid = a;
};

LCell::~LCell(){};
