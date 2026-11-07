
#include "globals.hh"
#include <vector>
#include "Geometry/LVs/LCell.hh"
#include "G4LogicalVolume.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "Geometry/PVs/PCell.hh"
#include "Geometry/PVs/PNP.hh"
#include "Geometry/PVs/PNucleus.hh"
#include "Geometry/Solids/SCell.hh"
#include "Geometry/Solids/SNucleus.hh"
#include "Geometry/LVs/LNucleus.hh"

PCell::PCell(G4RotationMatrix* a, const G4ThreeVector b, LCell* c, const G4String d, G4LogicalVolume* e, G4bool f, G4int g, G4bool h):G4PVPlacement(a,b,c,d,e,f,g,h){
    fSolid = c->GetSolid();
    fLog = c;
    fName = d;
    fNucleusMaterial = fLog->GetMaterial();
    std::vector<G4double> dim = fSolid->GetDimensions();
    if (dim.size()==0) {
        std::cout << "WTF!!" << std::endl;
        return;
    } 
    //std::cout <<"Nucleus " << dim.at(0) << std::endl;
   // SetNucleus(fNucleusMaterial,dim.at(0)/3.);
};

void PCell::SetNPs(G4Material* mat){

}

void PCell::SetNucleus(G4Material* mat, G4double size){

}

PCell::~PCell(){
    if (fNucleus){
        delete fNucleus;
    }
    for (int i=0;i<fNPs.size();i++){
        if (fNPs.at(i)) delete fNPs.at(i);
    }
};
