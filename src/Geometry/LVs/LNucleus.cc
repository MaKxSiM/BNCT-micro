#include "globals.hh"
#include "G4VSolid.hh"
#include <vector>
#include "Geometry/Solids/SNucleus.hh"
#include "Geometry/LVs/LNucleus.hh"
#include "G4LogicalVolume.hh"


LNucleus::LNucleus(SNucleus* a, G4Material* b, const G4String& c, G4FieldManager* d, G4VSensitiveDetector* e, G4UserLimits* f, G4bool g):G4LogicalVolume(a,b,c,d,e,f,g){
    
}    
LNucleus::~LNucleus(){};    