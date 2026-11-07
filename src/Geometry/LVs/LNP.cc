#include "globals.hh"
#include <vector>
#include "Geometry/Solids/SNP.hh"
#include "Geometry/LVs/LNP.hh"
#include "G4LogicalVolume.hh"


LNP::LNP(SNP* a, G4Material* b, const G4String& c, G4FieldManager* d, G4VSensitiveDetector* e, G4UserLimits* f, G4bool g):G4LogicalVolume(a,b,c,d,e,f,g){
    
};    
LNP::~LNP(){};