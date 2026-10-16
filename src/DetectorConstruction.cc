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
#include "HumanCell.hh"


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



  //ConstructScoringVolumes();


  auto pCell= new HumanCell ("HumanCell", 0 * um, 0 * um, 0 * um, logicWorld, 10*nm );



  return physWorld;
}

void DetectorConstruction::ConstructScoringVolumes(){



/*

  G4int  N_cells_XY = int(env_sizeXY/cell_size_XY);
  G4int  N_cells_Z = int(env_sizeZ/cell_size_Z);

  G4Box* templatebox =  new G4Box("Cube", 0.5*cell_size_XY, 0.5*cell_size_XY, 0.5*cell_size_Z);     //its size

  logictempl = new G4LogicalVolume(templatebox,          //its solid
                        nist->FindOrBuildMaterial(env_mat_name),           //its material
                        "Cube");

  G4String temp_str;
  const G4String pref = "Cube_";

  G4VPhysicalVolume* phys_vol;
  G4double pos_X, pos_Y, pos_Z;


  for (G4int i = 0; i<N_cells_XY; i++){
    for (G4int j = 0; j<N_cells_XY; j++){
      for (G4int k = 0; k<N_cells_Z; k++){

          temp_str = pref +std::to_string(i)+"_"+std::to_string(j)+"_"+std::to_string(k);
          pos_X = -0.5*(env_sizeXY-cell_size_XY)+ cell_size_XY*i;
          pos_Y = -0.5*(env_sizeXY-cell_size_XY)+ cell_size_XY*j;
          pos_Z = -0.5*(env_sizeZ-cell_size_Z)+ cell_size_Z*k;

          vPos_X.push_back(pos_X);
          vPos_Y.push_back(pos_Y);
          vPos_Z.push_back(pos_Z);

          //std::cout<<"       DetectorConstruction   " << pos_X << "   "
          //<<pos_Y<< "   " <<pos_Z<< std::endl;

            phys_vol = new G4PVPlacement(0,                    //no rotation
                    G4ThreeVector(pos_X, pos_Y, pos_Z),
                    logictempl,                //its logical volume
                    temp_str,                     //its name
                    logicEnv,                     //its mother  volume
                    false,                        //no boolean operation
                    0,                            //copy number
                    checkOverlaps);                        //overlaps checking
                    fScoringVolumes.push_back(phys_vol);

      }
    }
  };

*/



}
