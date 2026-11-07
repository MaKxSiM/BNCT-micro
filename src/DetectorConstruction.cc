//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file DetectorConstruction.cc
/// \brief Implementation of the B1::DetectorConstruction class

#include <vector>

#include "DetectorConstruction.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"
#include "G4VUserDetectorConstruction.hh"

#include "G4MaterialPropertiesTable.hh"
#include "G4MaterialPropertyVector.hh"
#include "G4MaterialTable.hh"
#include "G4Material.hh"
//#include "HumanCell.hh"

#include "Geometry/Solids/SCell.hh"
#include "Geometry/LVs/LCell.hh"
#include "Geometry/PVs/PCell.hh"

#include "G4SystemOfUnits.hh"
#include "G4Ellipsoid.hh"
#include "G4IntersectionSolid.hh"

#include "Geometry/Solids/SNucleus.hh"
#include "Geometry/LVs/LNucleus.hh"
#include "Geometry/PVs/PNucleus.hh"

DetectorConstruction::DetectorConstruction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{
  delete fStepLimit;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{


//  ============== Just world  ===================================
  G4NistManager* nist = G4NistManager::Instance();
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_Galactic");


  G4Box* solidWorld = new G4Box
  (
    "World",                       //its name
    0.5*world_sizeXY,
    0.5*world_sizeXY,
    0.5*world_sizeZ
  );

  G4LogicalVolume* logicWorld = new G4LogicalVolume
  (
    solidWorld,          //its solid
    world_mat,           //its material
    "World"
  );            //its name

  G4VPhysicalVolume* physWorld = new G4PVPlacement(
                      0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      true                   //overlaps checking
  );

//  ============== end world  of world defention ===================================


// define solids 
  G4Material* cell_mat = nist->FindOrBuildMaterial("G4_WATER");
  auto fSolEnv = new G4Box
  (
    "Envelope",                       //its name
    0.5*env_sizeXY,
    0.5*env_sizeXY,
    0.5*env_sizeZ
  );

  auto fLogEnv = new G4LogicalVolume
  (
    fSolEnv,          //its solid
    cell_mat,           //its material
    "logEnvelope"
  );  

 
  G4VPhysicalVolume* fPhysEnv = new G4PVPlacement(
                      0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      fLogEnv,            //its logical volume
                      "World",               //its name
                      logicWorld,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      true                   //overlaps checking
  );


  auto fSolCell = new SCell("Cell", 30*micrometer,20*micrometer);
  auto fLogCell = new LCell(fSolCell, cell_mat, "logCell");

  auto fSolNucleus = new SNucleus("SolNucleus",10*micrometer,10*micrometer,10*micrometer);
  auto fLogNucleus = new LNucleus(fSolNucleus,cell_mat,"logNucleus");
  auto fPhysNucleus = new PNucleus(                      0,                     //no rotation
                      G4ThreeVector(0,0,0),       //at (0,0,0)
                      fLogNucleus,            //its logical volume
                      "PhysNucleus",               //its name
                      fLogCell,                     //its mother  volume
                      true,                 //no boolean operation
                      0,                     //copy number
                      true                   //overlaps checking))
        );

  std::vector<G4PVPlacement*> Cells;
  G4int N = 5;
  G4double dbox = 45*micrometer; 

  G4double bl = (N/2==0)? dbox/2 -(N/2)*dbox: ((N-1)/2)*dbox;
  G4String tempstring;

  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      for (int k=0;k<N;k++){
        tempstring = "cell_" + std::to_string(i) + "_" + std::to_string(j) + "_" + std::to_string(k);
        Cells.push_back(new PCell(                      0,                     //no rotation
                      G4ThreeVector(-bl + i*dbox,-bl + j*dbox,-bl + k*dbox),       //at (0,0,0)
                      fLogCell,            //its logical volume
                      tempstring,               //its name
                      fLogEnv,                     //its mother  volume
                      true,                 //no boolean operation
                      0,                     //copy number
                      true                   //overlaps checking))
        ));
      }
    }
  }
  return physWorld;

}

void DetectorConstruction::ConstructScoringVolumes(){







}
