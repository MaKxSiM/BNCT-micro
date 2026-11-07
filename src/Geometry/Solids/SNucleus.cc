#include "globals.hh"
#include "G4Ellipsoid.hh"
#include <vector>
#include "Geometry/Solids/SNucleus.hh"

SNucleus::SNucleus(G4String name,G4double px,G4double py,G4double pz):G4VSolid(name){ 
   fActualShape = new G4Ellipsoid(name, px/2, py/2, pz/2);
};    
SNucleus::~SNucleus() {
    delete fActualShape;
}

EInside SNucleus::Inside(const G4ThreeVector& p) const {
    return fActualShape->Inside(p);
}

G4ThreeVector SNucleus::SurfaceNormal(const G4ThreeVector& p) const {
    return fActualShape->SurfaceNormal(p);
}
G4double SNucleus::DistanceToIn(const G4ThreeVector& p, const G4ThreeVector& v) const {
    return fActualShape->DistanceToIn(p, v);
}
G4double SNucleus::DistanceToIn(const G4ThreeVector& p) const {
    return fActualShape->DistanceToIn(p);
}
G4double SNucleus::DistanceToOut(const G4ThreeVector& p, const G4ThreeVector& v, const G4bool calcNorm, G4bool *validNorm, G4ThreeVector *n) const {
    return fActualShape->DistanceToOut(p, v, calcNorm, validNorm, n);
}
G4double SNucleus::DistanceToOut(const G4ThreeVector& p) const {
    return fActualShape->DistanceToOut(p);
}
void SNucleus::ComputeDimensions(G4VPVParameterisation* p, const G4int n, const G4VPhysicalVolume* pRep) {
    fActualShape->ComputeDimensions(p, n, pRep);
}
G4GeometryType SNucleus::GetEntityType() const {
    return fActualShape->GetEntityType();
}
G4VSolid* SNucleus::Clone() const {
    return fActualShape->Clone();
}
std::ostream& SNucleus::StreamInfo(std::ostream& os) const {
    return fActualShape->StreamInfo(os);
}
    
void SNucleus::DescribeYourselfTo (G4VGraphicsScene &scene) const {
      return fActualShape->DescribeYourselfTo(scene);
};

G4bool SNucleus::CalculateExtent (const EAxis pAxis, const G4VoxelLimits &pVoxelLimit, const G4AffineTransform &pTransform, G4double &pMin, G4double &pMax) const {
    return fActualShape->CalculateExtent(pAxis, pVoxelLimit,pTransform,  pMin, pMax);
}; 

G4ThreeVector SNucleus::GetPointOnSurface () const {
      return fActualShape->GetPointOnSurface();
};

void SNucleus::BoundingLimits(G4ThreeVector& pMin, G4ThreeVector& pMax) const {
    return fActualShape->BoundingLimits(pMin,pMax);
};