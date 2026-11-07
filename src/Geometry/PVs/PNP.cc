#include "globals.hh"
#include <vector>
#include "Geometry/LVs/LNP.hh"
#include "G4LogicalVolume.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "Geometry/PVs/PNP.hh"

PNP::PNP(G4RotationMatrix* a, const G4ThreeVector b, LNP* c, const G4String d, G4LogicalVolume* e, G4bool f, G4int g, G4bool h):G4PVPlacement(a,b,c,d,e,f,g,h){
    fName = d;
};




PNP::~PNP(){};